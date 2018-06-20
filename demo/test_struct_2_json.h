/*
yuxuebao 20180525
*/

#ifdef __cplusplus
extern "C" {
#endif


cJSON *struct_to_json_McBaseOrdrT(void* struct_obj) ;
void *json_to_struct_McBaseOrdrT(cJSON* json_obj) ;

cJSON *struct_to_json_OrderFT(void* struct_obj) ;
void *json_to_struct_OrderFT(cJSON* json_obj) ;

cJSON *struct_to_json_osSListEntryT(void* struct_obj) ;
void *json_to_struct_osSListEntryT(cJSON* json_obj) ;

cJSON *struct_to_json_OrderTT(void* struct_obj) ;
void *json_to_struct_OrderTT(cJSON* json_obj) ;

cJSON *struct_to_json_OrderT(void* struct_obj) ;
void *json_to_struct_OrderT(cJSON* json_obj) ;


#ifdef DEBUG2

#define TEST_S2J_STRUCT(type, value, file) \
    type struct_obj##type; \
    memset(&struct_obj##type, value, sizeof(type));  \
	cJSON *json_obj##type = struct_to_json_##type(&struct_obj##type); \
	char* str_json##type = cJSON_Print(json_obj##type);	\
    printf("%s:%s\n",#type, str_json##type); \
    fprintf(file,",\n	  {\n		\"-type\": \"%s\",\n		\"value\": %s\n	  }", #type, str_json##type); \
	free(str_json##type);	\
    type *p_struct_obj##type =(type *)json_to_struct_##type(json_obj##type); \
    int cmp##type = memcmp(p_struct_obj##type, &struct_obj##type, sizeof(type)); \
    printf("%s:memcmp:%d\n",#type, cmp##type); \
    cJSON *json_obj2##type = struct_to_json_##type(p_struct_obj##type); \
	str_json##type = cJSON_Print(json_obj2##type); \
    printf("%s:%s\n",#type, str_json##type); \
	free(str_json##type); \
    s2j_delete_struct_obj(p_struct_obj##type); \
    s2j_delete_json_obj(json_obj##type); \
    s2j_delete_json_obj(json_obj2##type); \

#endif// DEBUG2

#ifdef __cplusplus
}
#endif /* end of __cplusplus */
