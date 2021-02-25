#!/usr/bin/python3
import re
struct_txt = "struct_defination.txt"
with open(struct_txt,"r") as f:
    lines = f.readlines()
#注意:结构体后面不能加任何注释，仅仅是结构体的一般定义就好，不然会解析出问题
#将文件中定义的结构体定义由多行转换为一行，方便后续使用字符串进行相关的处理
struct_str = ""
for line in lines:
    struct_str += ' '.join(line.split())
struct_str = re.sub(r'((?<=\n)|^)[\t]*\/\*.*?\*\/\n?|\/\*.*?\*\/|((?<=\n)|^)[\t]*\/\/[^\n]*\n|\/\/[^\n]*', '',struct_str)

return_code = ""
#使用typedef进行元素分割，并去除列表中空元素
struct_str_split_list = [x for x in struct_str.split("typedef") if x!=""]
#print(struct_str_split_list)
struct_name_return = ""
fun_list = []
error_print_json2bin=""
error_print_bin2json=""
#使用(进行元素分割，先获取结构体参数
for item in struct_str_split_list:
    s2j_code_str_concat_return = "" #定义最后返回的 struct to json 字符串
    j2s_code_str_concat_return = "" #定义最后返回的 json to struct 字符串
    struct_name = item.split("{")[1].split("}")[1].split(",")[0].strip()  # 获取结构体名称
    #print(struct_name)
    if struct_name.find(";")!=-1:
        struct_name=struct_name[:-1]
    #print(struct_name)
    error_print_json2bin = error_print_json2bin+"struct_para_json2bin("+struct_name+",bin_para,type,value)\n" 
    error_print_bin2json = error_print_bin2json+"struct_para_bin2json("+struct_name+",bin_para,type,json_para)\n"

    para_list = [ x for x in item.split("{")[1].split("}")[0].split(";") if x !=""]#获取参数列表,并去除列表中空元素
    #print(para_list)
    #解析参数列表中的参数类型和参数名称，其中参数类型有 基本类型 和 结构体类型，enum和指针按int处理，不支持union和位域
    #数组类型:支持基本类型一维数组，结构体一维数组，字符二维数组（字符串数组）
    #struct to json 的字符串
    #print(struct_name)
    s2j_code_fun_str = "cJSON *struct_to_json_" + struct_name + "(void* struct_obj)"
    s2j_code_str = s2j_code_fun_str + "\n" + "{\n" + "\ts2j_create_json_obj(json_obj_);\n\t" + struct_name + " *struct_obj_ = (" + struct_name + " *)struct_obj;\n\t"
    fun_list.append(s2j_code_fun_str)
    # json to struct 的字符串
    j2s_code_fun_str = "void *json_to_struct_" + struct_name + "(cJSON* json_obj)"
    fun_list.append(j2s_code_fun_str)
    j2s_code_str = j2s_code_fun_str + "\n" + "{\n" + "\ts2j_create_struct_obj(struct_obj_, " + struct_name + ");\n\t"
    for para in para_list:
        s2j_code_str_concat = "" #定义 struct to json 的初始连接字符串
        j2s_code_str_concat = "" #定义 json to struct 的初始连接字符串
        para_item = para.split(" ")
        if len(para_item)==2:
            para_type = para_item[0] # 参数类型
            #print(para_type)
            para_name = para_item[1] # 参数名称
            #print(para_name)
        elif len(para_item) > 2:
            para_type = para_item[0] # 包含空格的参数类型
            for index in range(1, len(para_item)-2):
                para_type = para_type + " " + para_item[index]
            #print(para_type)
            para_name = para_item[-1] # 参数名称
            #print(para_name)

        #根据参数类型不同进行处理
        if para.find("*")!=-1: # 指针类型
            last_station = para.rfind("*")
            para_name=para[last_station+1:]
            #print(para_name)
            if "[" in para_name:
                left_symbol = para_name.find("[")  # 找到[位置
                right_symbol = para_name.find("]")  # 找到]位置
                array_para_name_size = para_name[left_symbol+1:right_symbol]
                #print(array_para_name_size)
                para_name = para_name.split("[")[0]
                s2j_code_str_concat = s2j_code_str_concat + "s2j_json_set_array_element(json_obj_, struct_obj_, int, "+ para_name + ","+ array_para_name_size+");\n\t"
                j2s_code_str_concat = j2s_code_str_concat +"s2j_struct_get_array_element(struct_obj_,json_obj, int, "+para_name + ");\n\t"
            else:
                s2j_code_str_concat = s2j_code_str_concat + "s2j_json_set_basic_element(json_obj_, struct_obj_, int, "+para_name+");\n\t"
                j2s_code_str_concat = j2s_code_str_concat + "s2j_struct_get_basic_element(struct_obj_,json_obj, int, "+para_name+");\n\t"
        elif para_type.find("enum")!=-1 or para_type.find("CbT")!=-1:  # enum或函数指针（根据实际命名规范识别）
            #print(para_type)
            if "[" in para_name:
                left_symbol = para_name.find("[")  # 找到[位置
                right_symbol = para_name.find("]")  # 找到]位置
                array_para_name_size = para_name[left_symbol+1:right_symbol]
                #print(array_para_name_size)
                para_name = para_name.split("[")[0]
                s2j_code_str_concat = s2j_code_str_concat + "s2j_json_set_array_element(json_obj_, struct_obj_, int, "+ para_name + ","+ array_para_name_size+");\n\t"
                j2s_code_str_concat = j2s_code_str_concat +"s2j_struct_get_array_element(struct_obj_,json_obj, int, "+para_name + ");\n\t"
            else:
                s2j_code_str_concat = s2j_code_str_concat + "s2j_json_set_basic_element(json_obj_, struct_obj_, int, "+para_name+");\n\t"
                j2s_code_str_concat = j2s_code_str_concat + "s2j_struct_get_basic_element(struct_obj_,json_obj, int, "+para_name+");\n\t"
        else: #基本类型
            if para_type in ("char","unsigned char","signed char","int","unsigned","unsigned int","signed int","short","unsigned short","signed short","long","unsigned long","signed long","long long","unsigned long long","signed long long","BOOL","bool","size_t","uint8_t","uint16_t","uint32_t","uint64_t","int8_t","int16_t","int32_t","int64_t","uint8","uint16","uint32","uint64","int8","int16","int32","int64","uint_fast64_t","__int128_t","__uint128_t","float","double","long double"):
                if para_type in ("float","double","long double","__int128_t","__uint128_t"): #浮点型、128位整型
                    if "[" in para_name:
                        #print(para_name)
                        left_symbol = para_name.find("[")  # 找到[位置
                        right_symbol = para_name.find("]")  # 找到]位置
                        array_para_name_size = para_name[left_symbol+1:right_symbol]
                        para_name = para_name.split("[")[0]
                        s2j_code_str_concat = s2j_code_str_concat + "s2j_json_set_array_element(json_obj_, struct_obj_, double, "+ para_name + ","+ array_para_name_size+");\n\t"
                        j2s_code_str_concat = j2s_code_str_concat +"s2j_struct_get_array_element(struct_obj_,json_obj, double, "+para_name + ");\n\t"
                    else:
                        s2j_code_str_concat = s2j_code_str_concat + "s2j_json_set_basic_element(json_obj_, struct_obj_, double, "+para_name+");\n\t"
                        j2s_code_str_concat = j2s_code_str_concat +"s2j_struct_get_basic_element(struct_obj_,json_obj, double, "+para_name+");\n\t"
                elif para_type =="char" : # 字符串
                    if "[" in para_name: 
                        para_name_item = para_name.split("[")
                        if len(para_name_item)==2: # 处理字符数组的情况，只取名字，舍弃中括号部分
                            para_name = para_name_item[0]
                            s2j_code_str_concat = s2j_code_str_concat+ "s2j_json_set_basic_element(json_obj_, struct_obj_, string, " + para_name + ");\n\t"
                            j2s_code_str_concat = j2s_code_str_concat + "s2j_struct_get_basic_element(struct_obj_,json_obj, string, " + para_name + ");\n\t"
                        elif len(para_name_item)==3: # 处理二维字符数组的情况
                            para_name = para_name_item[0]
                            # left_symbol = 0  # 找到[位置
                            right_symbol = para_name_item[1].find("]")  # 找到]位置
                            array_para_name_size = para_name_item[1][0:right_symbol]
                            s2j_code_str_concat = s2j_code_str_concat + "s2j_json_set_array_element(json_obj_, struct_obj_, string, "+ para_name + ","+ array_para_name_size+");\n\t"
                            j2s_code_str_concat = j2s_code_str_concat +"s2j_struct_get_array_element(struct_obj_,json_obj, string, "+para_name + ");\n\t"
                    else:
                        s2j_code_str_concat = s2j_code_str_concat + "s2j_json_set_basic_element(json_obj_, struct_obj_, int, " + para_name + ");\n\t"
                        j2s_code_str_concat = j2s_code_str_concat + "s2j_struct_get_basic_element(struct_obj_,json_obj, int, " + para_name + ");\n\t"
                else: #其它常规整型
                    if "[" in para_name:
                        #print(para_name)
                        left_symbol = para_name.find("[")  # 找到[位置
                        right_symbol = para_name.find("]")  # 找到]位置
                        array_para_name_size = para_name[left_symbol+1:right_symbol]
                        #print(array_para_name_size)
                        para_name = para_name.split("[")[0]
                        s2j_code_str_concat = s2j_code_str_concat + "s2j_json_set_array_element(json_obj_, struct_obj_, int, "+ para_name + ","+ array_para_name_size+");\n\t"
                        j2s_code_str_concat = j2s_code_str_concat +"s2j_struct_get_array_element(struct_obj_,json_obj, int, "+para_name + ");\n\t"
                    else:
                        s2j_code_str_concat = s2j_code_str_concat + "s2j_json_set_basic_element(json_obj_, struct_obj_, int, "+para_name+");\n\t"
                        j2s_code_str_concat = j2s_code_str_concat +"s2j_struct_get_basic_element(struct_obj_,json_obj, int, "+para_name+");\n\t"
            else: #结构体类型的参数
                if "[" in para_name:
                    # usrDefLst[MAX_LIST_MEM_TYPE]
                    left_sym = para_name.find("[") #找到[位置
                    right_sym = para_name.find("]") #找到]位置
                    list_size = para_name[left_sym+1:right_sym]
                    para_name = para_name.split("[")[0]
                    s2j_code_str_concat = s2j_code_str_concat + "s2j_json_set_struct_array_element_by_func(json_obj_, struct_obj_, "+ para_type +","+para_name+ ","+list_size+");\n\t"
                    j2s_code_str_concat = j2s_code_str_concat + "s2j_struct_get_struct_array_element_by_func(struct_obj_, json_obj, "+ para_type +","+para_name+");\n\t"
                else:
                    s2j_code_str_concat = s2j_code_str_concat + "s2j_json_set_struct_element_by_func(json_obj_, struct_obj_, "+ para_type +","+para_name+ ");\n\t"
                    j2s_code_str_concat = j2s_code_str_concat + "s2j_struct_get_struct_element_by_func(struct_obj_, json_obj, " + para_type + "," + para_name + ");\n\t"

        s2j_code_str_concat_return = s2j_code_str_concat_return + s2j_code_str_concat # #"return json_obj_;\n}"
        j2s_code_str_concat_return = j2s_code_str_concat_return + j2s_code_str_concat  # #"return json_obj_;\n}"
    # 处理每一行的结构体,然后分别进行拼装处理，作为注释打印出来
    #print(item)
    struct_item = item.split("{")
    struct_item_header = struct_item[0] # 结构体头部
    struct_item_body = struct_item[1].split("}")[0].strip() # 结构体body，包含参数部分，待会要对参数进行处理
    #print(struct_item_body)
    struct_item_tail = struct_item[1].split("}")[1] # 结构体尾部
    struct_item_body_list = struct_item_body.split(";")
    struct_item_body_str = ""
    struct_item_body_list_len = len(struct_item_body_list)
    for i in range(struct_item_body_list_len-1):
        struct_item_body_str = struct_item_body_str + "\t" + struct_item_body_list[i] + ";\n"
    #print(struct_item_body_str)
    # 将结构体定义作为注释打印出来
    return_struct_to_json_code = "\n#if 0\n" + "typedef" + struct_item_header + "\n{\n" + struct_item_body_str + "}" + struct_item_tail +"\n#endif\n" + s2j_code_str + s2j_code_str_concat_return + "return json_obj_;\n}"
    return_json_to_struct_code = j2s_code_str + j2s_code_str_concat_return + "return struct_obj_;\n}"
    #print(item)


    return_code =return_code + return_struct_to_json_code+"\n\n"+return_json_to_struct_code+"\n"
    struct_name_return = (struct_name_return + " " + struct_name).strip()

#打印生成的函数列表

#print(fun_list)

#将函数列表添加到指定的头文件中
file = open('my_struct_2_json.h','w')
h_header = r"""
#ifdef __cplusplus
extern "C" {
#endif
"""
h_tail = r"""    
#ifdef __cplusplus
}
#endif /* end of __cplusplus */
"""
content = h_header
for i in range(len(fun_list)):
    content = content + "\n" + fun_list[i] +";\n"

content = content + h_tail
file.write(content.strip())
file.close()

head_str = r"""
#include "inc/mc_usr_def.h"
#include "my_struct_2_json.inc"
#include "my_struct_2_json.h"


#ifdef __cplusplus
extern "C" {
#endif
    """

void_main_header = r"""
    char file_name[] = "struct_defination.json";
    FILE *fp;

    fp = fopen(file_name, "w");
    if (NULL == fp) return 1;
    fprintf(fp,"{\n\t\"struct\": [\n\t\t{\n\t\t\t\"type\": \"void*\",\n\t\t\t\"value\": null\n\t\t}"); 

"""

str_return = ""
str_s2j_test = ""
for i in range(len(struct_name_return.split())):
    str_s2j_test = str_s2j_test + "    TEST_S2J_STRUCT(" + struct_name_return.split()[i] + ", 0 , fp);\n"
    #print(str_s2j_test)

str_s2j_test_tail = r"""    
    fprintf(fp,"\n\t]\n}");
    fclose(fp);
    return 0;
}

"""

str_s2j_test2_header = r"""

 int s2j_test2(void)
 {

    char file_name[] = "struct_defination.json";
    FILE *fp;

    fp = fopen(file_name, "rb");
    if (NULL == fp) return 1;

   fseek(fp,0L,SEEK_END);
   int flen=ftell(fp);
   char* p=(char *)malloc(flen+1);
   if(p==NULL)
   {
        fclose(fp);
        return 0;
    }
    fseek(fp,0L,SEEK_SET);
    fread(p,flen,1,fp);
    p[flen]=0;

    printf("\nstruct_defination.json:\n%s\n",p);

    cJSON *json_obj =cJSON_Parse(p);
    CHECK_NOT_NULL(json_obj)
    cJSON *json_struct = cJSON_GetObjectItem(json_obj, "struct");
    CHECK_NOT_NULL(json_struct)

    int array_size = cJSON_GetArraySize(json_struct);
    printf("\nsize:\n%d\n",array_size);
    int i = 0; \

"""

str_s2j_test2 = ""
for i in range(len(struct_name_return.split())):
    str_s2j_test2 = str_s2j_test2 + "    TEST_S2J_JSON(" + struct_name_return.split()[i] + ", array_size);\n"
    #print(str_s2j_test2)


void_main_tail = r"""    
    fclose(fp);
    free(p);
    return 0;
}


#endif// DEBUGS2J

#ifdef __cplusplus
}
#endif /* end of __cplusplus */
"""
str_return = head_str + return_code + "#ifdef DEBUGS2J \n int s2j_test(void)\n" +" {\n\t" + void_main_header + str_s2j_test + str_s2j_test_tail + str_s2j_test2_header + str_s2j_test2 + void_main_tail
#print(str_return)

error_return = error_print_json2bin + "\n" + "*************************************" + "\n" + error_print_bin2json
print(error_return)
# 将转换的代码写入文件中
with open("my_struct_2_json.c","w") as f:
    f.write(str_return.strip())
with open("error_print.txt","w") as f:
    f.write(error_return.strip())
