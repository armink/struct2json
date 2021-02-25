#include "inc/mc_usr_def.h"
#include "my_struct_2_json.inc"
#include "my_struct_2_json.h"


#ifdef __cplusplus
extern "C" {
#endif
    
#if 0
typedef struct McUsrInfoS
{
	int *pInt;
	int *pIntArray[2];
	fun_ptr_CbT fun;
	fun_ptr_CbT funArray[2];
	enum WEEK_DAY day1;
	enumWEEK_DAY_T day2;
	enumWEEK_DAY_T day2Array[2];
	unsigned char id;
	unsigned char idArray[2];
	char usrType;
	char usrName[8];
	char usrNameArray[2][8];
	int32 usrSqno;
	int32 ussSqnoArray[2];
	int64 jobSqno;
	int64 jobSqnoArray[2];
	float rate;
	float rateArray[2];
	double price;
	double priceArray[2];
} McUsrInfoT, *pMcUsrInfoT;
#endif
cJSON *struct_to_json_McUsrInfoT(void* struct_obj)
{
	s2j_create_json_obj(json_obj_);
	McUsrInfoT *struct_obj_ = (McUsrInfoT *)struct_obj;
	s2j_json_set_basic_element(json_obj_, struct_obj_, int, pInt);
	s2j_json_set_array_element(json_obj_, struct_obj_, int, pIntArray,2);
	s2j_json_set_basic_element(json_obj_, struct_obj_, int, fun);
	s2j_json_set_array_element(json_obj_, struct_obj_, int, funArray,2);
	s2j_json_set_basic_element(json_obj_, struct_obj_, int, day1);
	s2j_json_set_basic_element(json_obj_, struct_obj_, int, day2);
	s2j_json_set_array_element(json_obj_, struct_obj_, int, day2Array,2);
	s2j_json_set_basic_element(json_obj_, struct_obj_, int, id);
	s2j_json_set_array_element(json_obj_, struct_obj_, int, idArray,2);
	s2j_json_set_basic_element(json_obj_, struct_obj_, int, usrType);
	s2j_json_set_basic_element(json_obj_, struct_obj_, string, usrName);
	s2j_json_set_array_element(json_obj_, struct_obj_, string, usrNameArray,2);
	s2j_json_set_basic_element(json_obj_, struct_obj_, int, usrSqno);
	s2j_json_set_array_element(json_obj_, struct_obj_, int, ussSqnoArray,2);
	s2j_json_set_basic_element(json_obj_, struct_obj_, int, jobSqno);
	s2j_json_set_array_element(json_obj_, struct_obj_, int, jobSqnoArray,2);
	s2j_json_set_basic_element(json_obj_, struct_obj_, double, rate);
	s2j_json_set_array_element(json_obj_, struct_obj_, double, rateArray,2);
	s2j_json_set_basic_element(json_obj_, struct_obj_, double, price);
	s2j_json_set_array_element(json_obj_, struct_obj_, double, priceArray,2);
	return json_obj_;
}

void *json_to_struct_McUsrInfoT(cJSON* json_obj)
{
	s2j_create_struct_obj(struct_obj_, McUsrInfoT);
	s2j_struct_get_basic_element(struct_obj_,json_obj, int, pInt);
	s2j_struct_get_array_element(struct_obj_,json_obj, int, pIntArray);
	s2j_struct_get_basic_element(struct_obj_,json_obj, int, fun);
	s2j_struct_get_array_element(struct_obj_,json_obj, int, funArray);
	s2j_struct_get_basic_element(struct_obj_,json_obj, int, day1);
	s2j_struct_get_basic_element(struct_obj_,json_obj, int, day2);
	s2j_struct_get_array_element(struct_obj_,json_obj, int, day2Array);
	s2j_struct_get_basic_element(struct_obj_,json_obj, int, id);
	s2j_struct_get_array_element(struct_obj_,json_obj, int, idArray);
	s2j_struct_get_basic_element(struct_obj_,json_obj, int, usrType);
	s2j_struct_get_basic_element(struct_obj_,json_obj, string, usrName);
	s2j_struct_get_array_element(struct_obj_,json_obj, string, usrNameArray);
	s2j_struct_get_basic_element(struct_obj_,json_obj, int, usrSqno);
	s2j_struct_get_array_element(struct_obj_,json_obj, int, ussSqnoArray);
	s2j_struct_get_basic_element(struct_obj_,json_obj, int, jobSqno);
	s2j_struct_get_array_element(struct_obj_,json_obj, int, jobSqnoArray);
	s2j_struct_get_basic_element(struct_obj_,json_obj, double, rate);
	s2j_struct_get_array_element(struct_obj_,json_obj, double, rateArray);
	s2j_struct_get_basic_element(struct_obj_,json_obj, double, price);
	s2j_struct_get_array_element(struct_obj_,json_obj, double, priceArray);
	return struct_obj_;
}

#if 0
typedef struct McBaseOrdrS
{
	short taskSqno;
	short taskSqnoArray[2];
	double price;
	double priceArray[2];
} McBaseOrdrT, *pMcBaseOrdrT;
#endif
cJSON *struct_to_json_McBaseOrdrT(void* struct_obj)
{
	s2j_create_json_obj(json_obj_);
	McBaseOrdrT *struct_obj_ = (McBaseOrdrT *)struct_obj;
	s2j_json_set_basic_element(json_obj_, struct_obj_, int, taskSqno);
	s2j_json_set_array_element(json_obj_, struct_obj_, int, taskSqnoArray,2);
	s2j_json_set_basic_element(json_obj_, struct_obj_, double, price);
	s2j_json_set_array_element(json_obj_, struct_obj_, double, priceArray,2);
	return json_obj_;
}

void *json_to_struct_McBaseOrdrT(cJSON* json_obj)
{
	s2j_create_struct_obj(struct_obj_, McBaseOrdrT);
	s2j_struct_get_basic_element(struct_obj_,json_obj, int, taskSqno);
	s2j_struct_get_array_element(struct_obj_,json_obj, int, taskSqnoArray);
	s2j_struct_get_basic_element(struct_obj_,json_obj, double, price);
	s2j_struct_get_array_element(struct_obj_,json_obj, double, priceArray);
	return struct_obj_;
}

#if 0
typedef struct McBaseOrdrArray
{
	McBaseOrdrT mcBaseOrdrArray[2];
} McBaseOrdrArrayT;
#endif
cJSON *struct_to_json_McBaseOrdrArrayT(void* struct_obj)
{
	s2j_create_json_obj(json_obj_);
	McBaseOrdrArrayT *struct_obj_ = (McBaseOrdrArrayT *)struct_obj;
	s2j_json_set_struct_array_element_by_func(json_obj_, struct_obj_, McBaseOrdrT,mcBaseOrdrArray,2);
	return json_obj_;
}

void *json_to_struct_McBaseOrdrArrayT(cJSON* json_obj)
{
	s2j_create_struct_obj(struct_obj_, McBaseOrdrArrayT);
	s2j_struct_get_struct_array_element_by_func(struct_obj_, json_obj, McBaseOrdrT,mcBaseOrdrArray);
	return struct_obj_;
}

#if 0
typedef struct McOcoBaseOrdrS
{
	McBaseOrdrArrayT mcBaseOrdrAry;
	void * pUsrDef;
} McOcoBaseOrdrT, *pMcOcoBaseOrdrT;
#endif
cJSON *struct_to_json_McOcoBaseOrdrT(void* struct_obj)
{
	s2j_create_json_obj(json_obj_);
	McOcoBaseOrdrT *struct_obj_ = (McOcoBaseOrdrT *)struct_obj;
	s2j_json_set_struct_element_by_func(json_obj_, struct_obj_, McBaseOrdrArrayT,mcBaseOrdrAry);
	s2j_json_set_basic_element(json_obj_, struct_obj_, int,  pUsrDef);
	return json_obj_;
}

void *json_to_struct_McOcoBaseOrdrT(cJSON* json_obj)
{
	s2j_create_struct_obj(struct_obj_, McOcoBaseOrdrT);
	s2j_struct_get_struct_element_by_func(struct_obj_, json_obj, McBaseOrdrArrayT,mcBaseOrdrAry);
	s2j_struct_get_basic_element(struct_obj_,json_obj, int,  pUsrDef);
	return struct_obj_;
}
#ifdef DEBUGS2J 
 int s2j_test(void)
 {
	
    char file_name[] = "struct_defination.json";
    FILE *fp;

    fp = fopen(file_name, "w");
    if (NULL == fp) return 1;
    fprintf(fp,"{\n\t\"struct\": [\n\t\t{\n\t\t\t\"type\": \"void*\",\n\t\t\t\"value\": null\n\t\t}"); 

    TEST_S2J_STRUCT(McUsrInfoT, 0 , fp);
    TEST_S2J_STRUCT(McBaseOrdrT, 0 , fp);
    TEST_S2J_STRUCT(McBaseOrdrArrayT, 0 , fp);
    TEST_S2J_STRUCT(McOcoBaseOrdrT, 0 , fp);
    
    fprintf(fp,"\n\t]\n}");
    fclose(fp);
    return 0;
}



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

    TEST_S2J_JSON(McUsrInfoT, array_size);
    TEST_S2J_JSON(McBaseOrdrT, array_size);
    TEST_S2J_JSON(McBaseOrdrArrayT, array_size);
    TEST_S2J_JSON(McOcoBaseOrdrT, array_size);
    
    fclose(fp);
    free(p);
    return 0;
}


#endif// DEBUGS2J

#ifdef __cplusplus
}
#endif /* end of __cplusplus */