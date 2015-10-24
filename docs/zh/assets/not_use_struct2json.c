cJSON *struct_to_json(void* struct_obj) {
    Student *struct_student = (Student *) struct_obj;
    cJSON *score, *score_element;
    size_t index = 0;

    /* 创建Student JSON对象 */
    cJSON *json_student = cJSON_CreateObject();

    /* 序列化数据到Student JSON对象 */
    cJSON_AddNumberToObject(json_student, "id", struct_student->id);
    cJSON_AddNumberToObject(json_student, "weight", struct_student->weight);
    score = cJSON_CreateArray();
    if (score) {
        while (index < 8) {
            score_element = cJSON_CreateNumber(struct_student->score[index++]);
            cJSON_AddItemToArray(score, score_element);
        }
        cJSON_AddItemToObject(json_student, "score", score);
    }
    cJSON_AddStringToObject(json_student, "name", struct_student->name);

    /* 序列化数据到Student.Hometown JSON对象 */
    Hometown *hometown_struct = &(struct_student->hometown);
    cJSON *hometown_json = cJSON_CreateObject();
    cJSON_AddItemToObject(json_student, "hometown", hometown_json);
    cJSON_AddStringToObject(hometown_json, "name", hometown_struct->name);

    /* 返回Student JSON对象指针 */
    return json_student;
}
