"""
    注意结构体后面不能加任何注释，仅仅是结构体的一般定义就好，不然会解析出问题
"""
struct_txt = "struct_def.h"
with open(struct_txt,"r") as f:
    lines = f.readlines()
#将文件中定义的结构体定义由多行转换为一行，方便后续使用字符串进行相关的处理
struct_str = ""
for line in lines:
    struct_str += ' '.join(line.split())
return_code = ""
#使用typedef进行元素分割，并去除列表中空元素
struct_str_split_list = [x for x in struct_str.split("typedef") if x!=""]
#print(struct_str_split_list)
struct_name_return = ""
#使用(进行元素分割，先获取结构体参数
for item in struct_str_split_list:
    s2j_code_str_concat_return = "" #定义最后返回的 struct to json 字符串
    j2s_code_str_concat_return = "" #定义最后返回的 json to struct 字符串
    struct_name = item.split("{")[1].split("}")[1].split(",")[0].strip()  # 获取结构体名称
    #print(struct_name)
    para_list = [ x for x in item.split("{")[1].split("}")[0].split(";") if x !=""]#获取参数列表,并去除列表中空元素
    #print(para_list)
    #解析参数列表中的参数类型和参数名称，其中参数类型有 基本类型 和 结构体类型
    #struct to json 的字符串
    s2j_code_str = "cJSON *struct_to_json_" + struct_name + "(void* struct_obj)\n" + "{\n" + "\ts2j_create_json_obj(json_obj_2);\n\t" + struct_name + " *struct_obj_2 = (" + struct_name + " *)struct_obj;\n\t"

    # json to struct 的字符串
    j2s_code_str = "void *json_to_struct_" + struct_name + "(cJSON* json_obj)\n" + "{\n" + "\ts2j_create_struct_obj(struct_obj_2, " + struct_name + ");\n\t"
    for para in para_list:
        s2j_code_str_concat = "" #定义 struct to json 的初始连接字符串
        j2s_code_str_concat = "" #定义 json to struct 的初始连接字符串
        para_item = para.split(" ")
        para_type = para_item[0] # 参数类型
        #print(para_type)
        para_name = para_item[1] # 参数名称
        #print(para_name)
        #基本类型的参数
        if para_type in ("uint8","uint16","uint32","uint64","int8","int16","int32","int64","char"):
            if para_type in ("uint32","uint32","int64","uint64"):
                if "[" in para_name:
                    left_symbol = para_name.find("[")  # 找到[位置
                    #right_symbol = para_name.find("]")  # 找到]位置
                    array_para_name_size = para_name[left_symbol+1]
                    para_name = para_name.split("[")[0]
                    s2j_code_str_concat = s2j_code_str_concat + "s2j_json_set_array_element(json_obj_2, struct_obj_2, double, "+ para_name + ","+ array_para_name_size+");\n\t"
                    j2s_code_str_concat = j2s_code_str_concat +"s2j_struct_get_array_element(struct_obj_2,json_obj, double, "+para_name + ");\n\t"
                else:
                    s2j_code_str_concat = s2j_code_str_concat + "s2j_json_set_basic_element(json_obj_2, struct_obj_2, double, "+para_name+");\n\t"
                    j2s_code_str_concat = j2s_code_str_concat +"s2j_struct_get_basic_element(struct_obj_2,json_obj, double, "+para_name+");\n\t"
            elif para_type =="char" :
                if "[" in para_name: # 处理字符数组的情况，只取名字，舍弃中括号部分
                    para_name = para_name.split("[")[0]
                s2j_code_str_concat = s2j_code_str_concat+ "s2j_json_set_basic_element(json_obj_2, struct_obj_2, string, " + para_name + ");\n\t"
                j2s_code_str_concat = j2s_code_str_concat + "s2j_struct_get_basic_element(struct_obj_2,json_obj,string, " + para_name + ");\n\t"

            else:
                s2j_code_str_concat = s2j_code_str_concat+ "s2j_json_set_basic_element(json_obj_2, struct_obj_2, int, " + para_name + ");\n\t"
                j2s_code_str_concat = j2s_code_str_concat +"s2j_struct_get_basic_element(struct_obj_2,json_obj, int, "+para_name+");\n\t"
        else: #结构体类型的参数
            if "[" in para_name:
                # usrDefLst[MAX_LIST_MEM_TYPE]
                left_sym = para_name.find("[") #找到[位置
                right_sym = para_name.find("]") #找到]位置
                list_size = para_name[left_sym+1:right_sym]
                para_name = para_name.split("[")[0]

                s2j_code_str_concat = s2j_code_str_concat + "s2j_json_set_struct_array_element_by_func(json_obj_2, struct_obj_2, "+ para_type +","+para_name+ ","+list_size+");\n\t"
                j2s_code_str_concat = j2s_code_str_concat + "s2j_struct_get_struct_array_element_by_func(struct_obj_2, json_obj, "+ para_type +","+para_name+");\n\t"

            else:
                s2j_code_str_concat = s2j_code_str_concat + "s2j_json_set_struct_element_by_func(json_obj_2, struct_obj_2,"+ para_type +","+para_name+ ");\n\t"
                j2s_code_str_concat = j2s_code_str_concat + "s2j_struct_get_struct_element_by_func(struct_obj_2, json_obj, " + para_type + "," + para_name + ");\n\t"

        s2j_code_str_concat_return = s2j_code_str_concat_return + s2j_code_str_concat # #"return json_obj_2;\n}"
        j2s_code_str_concat_return = j2s_code_str_concat_return + j2s_code_str_concat  # #"return json_obj_2;\n}"
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
    for i in range(struct_item_body_list_len):
        if i != struct_item_body_list_len -1:
            struct_item_body_str = struct_item_body_str + struct_item_body_list[i] + ";\n\t"
        else:
            struct_item_body_str = struct_item_body_str  +struct_item_body_list[i] +"\n"
    #print(struct_item_body_str)
    # 将结构体定义作为注释打印出来
    return_struct_to_json_code = "/*\n"+"typedef" + struct_item_header + "\n{\n\t" + struct_item_body_str + "}" + struct_item_tail +"\n*/\n" + s2j_code_str + s2j_code_str_concat_return + "return json_obj_2;\n}"
    return_json_to_struct_code = j2s_code_str + j2s_code_str_concat_return + "return struct_obj_2;\n}"
    #print(item)

    return_code = return_code + return_struct_to_json_code+"\n"+return_json_to_struct_code+"\n"
    struct_name_return = (struct_name_return + " " + struct_name).strip()

str_return = ""
for i in range(len(struct_name_return.split())):
    str_return = str_return + "\tTEST_S2J_STRUCT(" + struct_name_return.split()[i] + ", 0);\n\t"
str_return = return_code + "int main(void)\n" +" {\n\t" + str_return + "return 0;\n" + "}"
#print(str_return)

# 将转换的代码写入文件中
with open("code.c","w") as f:
    f.write(str_return)