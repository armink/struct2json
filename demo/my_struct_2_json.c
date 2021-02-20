#include "mc_usr_def.h"
#include "my_struct_2_json.inc"
#include "my_struct_2_json.h"


#ifdef __cplusplus
extern "C" {
#endif
    
#if 0
typedef struct UsrDefOrdrS
{
	char usrName[8];
	int64 usrSqno;
}UsrDefOrdrT, *pUsrDefOrdrT;
#endif
cJSON *struct_to_json_UsrDefOrdrT(void* struct_obj)
{
	s2j_create_json_obj(json_obj_);
	UsrDefOrdrT *struct_obj_ = (UsrDefOrdrT *)struct_obj;
	s2j_json_set_basic_element(json_obj_, struct_obj_, string, usrName);
	s2j_json_set_basic_element(json_obj_, struct_obj_, int, usrSqno);
	return json_obj_;
}

void *json_to_struct_UsrDefOrdrT(cJSON* json_obj)
{
	s2j_create_struct_obj(struct_obj_, UsrDefOrdrT);
	s2j_struct_get_basic_element(struct_obj_,json_obj,string, usrName);
	s2j_struct_get_basic_element(struct_obj_,json_obj, int, usrSqno);
	return struct_obj_;
}

#if 0
typedef struct McBaseOrdrS
{
	int64 ordrNo;
	int64 intrlOrdrNo;
	int64 exePrc;
	int64 elstcPrc;
	int64 ordrQty;
	int64 effectTime;
	int32 ordSide;
	int32 ordrType;
	int32 usrSqno;
	int32 prdctSqno;
	int32 orgSqno;
	int32 extOrdType;
	int32 ordrRestr;
} McBaseOrdrT, *pMcBaseOrdrT;
#endif
cJSON *struct_to_json_McBaseOrdrT(void* struct_obj)
{
	s2j_create_json_obj(json_obj_);
	McBaseOrdrT *struct_obj_ = (McBaseOrdrT *)struct_obj;
	s2j_json_set_basic_element(json_obj_, struct_obj_, int, ordrNo);
	s2j_json_set_basic_element(json_obj_, struct_obj_, int, intrlOrdrNo);
	s2j_json_set_basic_element(json_obj_, struct_obj_, int, exePrc);
	s2j_json_set_basic_element(json_obj_, struct_obj_, int, elstcPrc);
	s2j_json_set_basic_element(json_obj_, struct_obj_, int, ordrQty);
	s2j_json_set_basic_element(json_obj_, struct_obj_, int, effectTime);
	s2j_json_set_basic_element(json_obj_, struct_obj_, int, ordSide);
	s2j_json_set_basic_element(json_obj_, struct_obj_, int, ordrType);
	s2j_json_set_basic_element(json_obj_, struct_obj_, int, usrSqno);
	s2j_json_set_basic_element(json_obj_, struct_obj_, int, prdctSqno);
	s2j_json_set_basic_element(json_obj_, struct_obj_, int, orgSqno);
	s2j_json_set_basic_element(json_obj_, struct_obj_, int, extOrdType);
	s2j_json_set_basic_element(json_obj_, struct_obj_, int, ordrRestr);
	return json_obj_;
}

void *json_to_struct_McBaseOrdrT(cJSON* json_obj)
{
	s2j_create_struct_obj(struct_obj_, McBaseOrdrT);
	s2j_struct_get_basic_element(struct_obj_,json_obj, int, ordrNo);
	s2j_struct_get_basic_element(struct_obj_,json_obj, int, intrlOrdrNo);
	s2j_struct_get_basic_element(struct_obj_,json_obj, int, exePrc);
	s2j_struct_get_basic_element(struct_obj_,json_obj, int, elstcPrc);
	s2j_struct_get_basic_element(struct_obj_,json_obj, int, ordrQty);
	s2j_struct_get_basic_element(struct_obj_,json_obj, int, effectTime);
	s2j_struct_get_basic_element(struct_obj_,json_obj, int, ordSide);
	s2j_struct_get_basic_element(struct_obj_,json_obj, int, ordrType);
	s2j_struct_get_basic_element(struct_obj_,json_obj, int, usrSqno);
	s2j_struct_get_basic_element(struct_obj_,json_obj, int, prdctSqno);
	s2j_struct_get_basic_element(struct_obj_,json_obj, int, orgSqno);
	s2j_struct_get_basic_element(struct_obj_,json_obj, int, extOrdType);
	s2j_struct_get_basic_element(struct_obj_,json_obj, int, ordrRestr);
	return struct_obj_;
}

#if 0
typedef struct McBaseOrdrArray
{
	McBaseOrdrT mcBaseOrdrArray[2] ;
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
	McBaseOrdrT mcBaseOrdr;
	void * pUsrDef;
} McOcoBaseOrdrT, *pMcOcoBaseOrdrT;
#endif
cJSON *struct_to_json_McOcoBaseOrdrT(void* struct_obj)
{
	s2j_create_json_obj(json_obj_);
	McOcoBaseOrdrT *struct_obj_ = (McOcoBaseOrdrT *)struct_obj;
	s2j_json_set_struct_element_by_func(json_obj_, struct_obj_,McBaseOrdrT,mcBaseOrdr);
	s2j_json_set_basic_element(json_obj_, struct_obj_, int,  pUsrDef);
	return json_obj_;
}

void *json_to_struct_McOcoBaseOrdrT(cJSON* json_obj)
{
	s2j_create_struct_obj(struct_obj_, McOcoBaseOrdrT);
	s2j_struct_get_struct_element_by_func(struct_obj_, json_obj, McBaseOrdrT,mcBaseOrdr);
	s2j_struct_get_basic_element(struct_obj_,json_obj, int,  pUsrDef);
	return struct_obj_;
}
#ifdef DEBUGS2J 
 int main(void)
 {
	
    char file_name[] = "struct_define.json";
	FILE *fp;

	fp = fopen(file_name, "w");
	if (NULL == fp) return 1;
	fprintf(fp,"{\n\t\"struct\": [\n\t\t{\n\t\t\t\"type\": \"void*\",\n\t\t\t\"value\": \"null\"\n\t\t}"); 

	TEST_S2J_STRUCT(UsrDefOrdrT, 0 , fp);
	TEST_S2J_STRUCT(McBaseOrdrT, 0 , fp);
	TEST_S2J_STRUCT(McBaseOrdrArrayT, 0 , fp);
	TEST_S2J_STRUCT(McOcoBaseOrdrT, 0 , fp);
	
	fprintf(fp,"\n\t]\n}");
	fclose(fp);
	return 0;
}


#endif// DEBUGS2J

#ifdef __cplusplus
}
#endif /* end of __cplusplus */