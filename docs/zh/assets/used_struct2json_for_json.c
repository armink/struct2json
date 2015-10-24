void *json_to_struct(cJSON* json_obj) {
    /* 创建Student结构体对象 */
    s2j_create_struct_obj(struct_student, Student);

    /* 反序列化数据到Student结构体对象 */
    s2j_struct_get_basic_element(struct_student, json_obj, int, id);
    s2j_struct_get_array_element(struct_student, json_obj, int, score);
    s2j_struct_get_basic_element(struct_student, json_obj, string, name);
    s2j_struct_get_basic_element(struct_student, json_obj, double, weight);

    /* 反序列化数据到Student.Hometown结构体对象 */
    s2j_struct_get_struct_element(struct_hometown, struct_student, json_hometown, json_obj, Hometown, hometown);
    s2j_struct_get_basic_element(struct_hometown, json_hometown, string, name);

    /* 返回Student结构体对象指针 */
    return struct_student;
}
