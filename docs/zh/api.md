# struct2json API 文档

---

所有支持的API接口都在 `\struct2json\inc\s2j.h` 中声明。以下内容较多，建议使用 CTRL+F 搜索。

## 1、用户使用接口

### 1.1 初始化

初始化的struct2json库。

> 注：目前主要初始化该库及cJSON库所需的内存管理方法。默认使用的 `malloc` 及 `free` 作为内存管理方法，如果使用默认内存管理方式，则无需初始化。

```C
void s2j_init(S2jHook *hook)
```

|参数                                    |描述|
|:-----                                  |:----|
|hook                                    |指定的内存管理方法|

### 1.2 将结构体对象转换（序列化）为JSON对象

注意：以下API均采用宏定义方式，在使用时与常用API方法形式略有不同，请注意查看Demo。

#### 1.2.1 创建JSON对象

```C
s2j_create_json_obj(json_obj)
```

|参数                                    |描述|
|:-----                                  |:----|
|json_obj                                |JSON对象|

#### 1.2.2 转换基本类型元素

注意：这里的结构体元素基本类型只支持 `int` 、 `string` 及 `double` ，其他类型转换时应考虑选取三者中的其中一种作目标类型，选择标准为两者类型间可被无损相互转换。例如：结构体元素类型为 `uint8_t` 、`uint16_t` 、`int16_t` 、 `size_t` 、`某指针地址` 等类型可以选择 `int` 作为入参。

```C
s2j_json_set_basic_element(to_json, from_struct, type, element)
```

|参数                                    |描述|
|:-----                                  |:----|
|to_json                                 |目标JSON对象|
|from_struct                             |源结构体对象|
|type                                    |源结构体对象元素类型，这里只支持int、string、double|
|element                                 |源结构体对象元素|

#### 1.2.3 转换数组类型元素

```C
s2j_json_set_array_element(to_json, from_struct, type, element, size)
```

|参数                                    |描述|
|:-----                                  |:----|
|to_json                                 |目标JSON对象|
|from_struct                             |源结构体对象|
|type                                    |源结构体对象元素的基本类型。参考1.2.2中对基本类型的要求|
|element                                 |源结构体对象元素|
|size                                    |源结构体对象数组元素的长度|

#### 1.2.4 转换结构体类型元素（即子结构体）

```C
s2j_json_set_struct_element(child_json, to_json, child_struct, from_struct, type, element)
```

|参数                                    |描述|
|:-----                                  |:----|
|child_json                              |目标JSON对象的子JSON对象|
|to_json                                 |目标JSON对象|
|child_struct                            |源结构体对象的子结构体对象|
|from_struct                             |源结构体对象|
|type                                    |源结构体对象元素（子结构体）类型|
|element                                 |源结构体对象元素|

例子：
```C
typedef struct {
    char name[16];
} Hometown;

typedef struct {
    uint8_t id;
    char name[10];
    Hometown hometown;
} Student;

Student orignal_struct_student = {
        .id = 24,
        .name = "armink",
        .hometown.name = "China",
}
Student *struct_student = &orignal_struct_student;
/* 创建空Student JSON对象 */
s2j_create_json_obj(json_student);
/* 序列化（转换）Student结构体的id元素 */
s2j_json_set_basic_element(json_student, struct_student, int, id);
/* 序列化Student结构体的name元素 */
s2j_json_set_basic_element(json_student, struct_student, string, name);
/* 序列化Student结构体的子结构体hometown元素 */
s2j_json_set_struct_element(json_hometown, json_student, struct_hometown, struct_student, Hometown, hometown);
/* 序列化Hometown结构体的name元素 */
s2j_json_set_basic_element(json_hometown, struct_hometown, string, name);
```

### 1.3 将JSON对象转换（反序列化）为结构体对象

#### 1.3.1 创建结构体对象

```C
s2j_create_struct_obj(struct_obj, type)
```

|参数                                    |描述|
|:-----                                  |:----|
|struct_obj                              |结构体对象|
|type                                    |结构体类型|

#### 1.3.2 转换基本类型元素

```C
s2j_struct_get_basic_element(to_struct, from_json, type, element)
```

|参数                                    |描述|
|:-----                                  |:----|
|to_struct                               |目标结构体对象|
|from_json                               |源JSON对象|
|type                                    |目标结构体对象元素类型。参考1.2.2中对基本类型的要求|
|element                                 |目标结构体对象元素|

#### 1.3.3 转换数组类型元素

```C
s2j_struct_get_array_element(to_struct, from_json, type, element)
```

|参数                                    |描述|
|:-----                                  |:----|
|to_struct                               |目标结构体对象|
|from_json                               |源JSON对象|
|type                                    |目标结构体对象元素类型。参考1.2.2中对基本类型的要求|
|element                                 |目标结构体对象元素|

#### 1.3.4 转换结构体类型元素（即子JSON）

```C
s2j_struct_get_struct_element(child_struct, to_struct, child_json, from_json, type, element)
```

|参数                                    |描述|
|:-----                                  |:----|
|child_struct                            |目标结构体对象的子结构体对象|
|to_struct                               |目标结构体对象|
|child_json                              |源JSON对象的子JSON对象|
|from_json                               |源JSON对象|
|type                                    |源JSON对象元素（子JSON）类型|
|element                                 |源JSON对象元素|

例子：
```C
typedef struct {
    char name[16];
} Hometown;

typedef struct {
    uint8_t id;
    char name[10];
    Hometown hometown;
} Student;

char orignal_json_string_student[] = "{\"id\":24, \"name\":\"armink\", \"hometown\":{\"name\":\"China\"}}";
/* 创建Student JSON对象 */
cJSON *json_student = cJSON_Parse(orignal_json_string_student);
/* 创建空Student结构体对象 */
s2j_create_struct_obj(struct_student, Student);
/* 反序列化Student结构体的id元素 */
s2j_struct_get_basic_element(struct_student, json_student, int, id);
/* 反序列化Student结构体的name元素 */
s2j_struct_get_basic_element(struct_student, json_student, string, name);
/* 反序列化Student结构体的子结构体hometown元素 */
s2j_struct_get_struct_element(struct_hometown, struct_student, json_hometown, json_student, Hometown, hometown);
/* 反序列化Hometown结构体的name元素 */
s2j_struct_get_basic_element(struct_hometown, json_hometown, string, name);
```

## 2、注意

- 该库只适用于C99及其以上标准编译器