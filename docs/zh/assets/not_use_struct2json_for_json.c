void *json_to_struct(cJSON* json_obj) {
    cJSON *json_temp, *score, *score_element;
    Student *struct_student;
    size_t index = 0, score_size = 0;

    /* 创建Student结构体对象 */
    struct_student = s2j_malloc(sizeof(Student));
    if (struct_student) {
        memset(struct_student, 0, sizeof(Student));
    }

    /* 反序列化数据到Student结构体对象 */
    json_temp = cJSON_GetObjectItem(json_obj, "id");
    if (json_temp) {
        struct_student->id = json_temp->valueint;
    }
    score = cJSON_GetObjectItem(json_obj, "score")
    if (score) {
        score_size = cJSON_GetArraySize(score);
        while (index < score_size) {
            score_element = cJSON_GetArrayItem(score, index);
            if (score_element) {
                struct_student->score[index++] = score_element->valueint;
            }
        }
    }
    json_temp = cJSON_GetObjectItem(json_obj, "name");
    if (json_temp) {
        strcpy(struct_student->name, json_temp->valuestring);
    }
    json_temp = cJSON_GetObjectItem(json_obj, "weight");
    if (json_temp) {
        struct_student->weight = json_temp->valuedouble;
    }

    /* 反序列化数据到Student.Hometown结构体对象 */
    Hometown *struct_hometown = &(struct_student->hometown);
    cJSON *json_hometown = cJSON_GetObjectItem(json_obj, "hometown");
    json_temp = cJSON_GetObjectItem(json_hometown, "name");
    if (json_temp) {
        strcpy(struct_hometown->name, json_temp->valuestring);
    }

    /* 返回Student结构体对象指针 */
    return struct_student;
}
