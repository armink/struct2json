#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
cJSON *struct_to_json_CppStructInfoT(void* struct_obj);

void *json_to_struct_CppStructInfoT(cJSON* json_obj);
#endif
cJSON *struct_to_json_McUsrInfoT(void* struct_obj);

void *json_to_struct_McUsrInfoT(cJSON* json_obj);

cJSON *struct_to_json_McBaseOrdrT(void* struct_obj);

void *json_to_struct_McBaseOrdrT(cJSON* json_obj);

cJSON *struct_to_json_McBaseOrdrArrayT(void* struct_obj);

void *json_to_struct_McBaseOrdrArrayT(cJSON* json_obj);

cJSON *struct_to_json_McOcoBaseOrdrT(void* struct_obj);

void *json_to_struct_McOcoBaseOrdrT(cJSON* json_obj);

#ifdef __cplusplus
}
#endif /* end of __cplusplus */
