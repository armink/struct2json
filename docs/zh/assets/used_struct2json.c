cJSON *struct_to_json(void* struct_obj) {
    Student *struct_student = (Student *)struct_obj;

    /* 创建Student JSON对象 */
    s2j_create_json_obj(json_student);

    /* 序列化数据到Student JSON对象 */
    s2j_json_set_basic_element(json_student, struct_student, int, id);
    s2j_json_set_basic_element(json_student, struct_student, double, weight);
    s2j_json_set_array_element(json_student, struct_student, int, score, 8);
    s2j_json_set_basic_element(json_student, struct_student, string, name);

    /* 序列化数据到Student.Hometown JSON对象 */
    s2j_json_set_struct_element(json_hometown, json_student, struct_hometown, struct_student, Hometown, hometown);
    s2j_json_set_basic_element(json_hometown, struct_hometown, string, name);

    /* 返回Student JSON对象指针 */
    return json_student;
}
