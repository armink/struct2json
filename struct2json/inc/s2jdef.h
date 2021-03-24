/*
 * This file is part of the struct2json Library.
 *
 * Copyright (c) 2015, Armink, <armink.ztl@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * 'Software'), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * Function: It is an head file for this library.
 * Created on: 2015-10-14
 */

#ifndef __S2JDEF_H__
#define __S2JDEF_H__

#include "cJSON.h"
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

#define S2J_ARRAY_SIZE(arr) (sizeof(arr)/sizeof((arr)[0]))


typedef struct {
    void *(*malloc_fn)(size_t sz);
    void (*free_fn)(void *ptr);
} S2jHook, *S2jHook_t;

#define S2J_STRUCT_GET_int_ELEMENT(to_struct, from_json, _element) \
    json_temp = cJSON_GetObjectItem(from_json, #_element); \
    if (json_temp) (to_struct)->_element = json_temp->valueint;

#define S2J_STRUCT_GET_int_ELEMENT_EX(to_struct, from_json, _element, _defval) \
    { \
        if (from_json) { \
            json_temp = cJSON_GetObjectItem(from_json, #_element); \
            if (json_temp) (to_struct)->_element = json_temp->valueint; \
            else (to_struct)->_element = _defval; \
        } else { \
            (to_struct)->_element = _defval; \
        } \
    }

#define S2J_STRUCT_GET_string_ELEMENT(to_struct, from_json, _element) \
    json_temp = cJSON_GetObjectItem(from_json, #_element); \
    if (json_temp) strncpy((to_struct)->_element, json_temp->valuestring,sizeof((to_struct)->_element)-1);

#define S2J_STRUCT_GET_string_ELEMENT_EX(to_struct, from_json, _element, _defval) \
    { \
        if (from_json) { \
            json_temp = cJSON_GetObjectItem(from_json, #_element); \
            if (json_temp) strncpy((to_struct)->_element, json_temp->valuestring,sizeof((to_struct)->_element)-1); \
            else strncpy((to_struct)->_element, _defval,sizeof((to_struct)->_element)-1); \
        } else { \
            strncpy((to_struct)->_element, _defval,sizeof((to_struct)->_element)-1); \
        } \
    }

#define S2J_STRUCT_GET_double_ELEMENT(to_struct, from_json, _element) \
    json_temp = cJSON_GetObjectItem(from_json, #_element); \
    if (json_temp) (to_struct)->_element = json_temp->valuedouble;

#define S2J_STRUCT_GET_double_ELEMENT_EX(to_struct, from_json, _element, _defval) \
    { \
        if (from_json) { \
            json_temp = cJSON_GetObjectItem(from_json, #_element); \
            if (json_temp) (to_struct)->_element = json_temp->valuedouble; \
            else (to_struct)->_element = _defval; \
        } else { \
            (to_struct)->_element = _defval; \
        } \
    }

#define S2J_STRUCT_ARRAY_GET_int_ELEMENT(to_struct, from_json, _element, index) \
    (to_struct)->_element[index] = from_json->valueint;

#define S2J_STRUCT_ARRAY_GET_string_ELEMENT(to_struct, from_json, _element, index) \
    strncpy((to_struct)->_element[index], from_json->valuestring,sizeof((to_struct)->_element[0])-1);

#define S2J_STRUCT_ARRAY_GET_double_ELEMENT(to_struct, from_json, _element, index) \
    (to_struct)->_element[index] = from_json->valuedouble;

#define S2J_STRUCT_ARRAY_GET_ELEMENT(to_struct, from_json, type, _element, index) \
    S2J_STRUCT_ARRAY_GET_##type##_ELEMENT(to_struct, from_json, _element, index)

#define S2J_STRUCT_ARRAY_GET_int_ELEMENT_EX(to_struct, from_json, _element, index, _defval) \
    if (from_json) (to_struct)->_element[index] = from_json->valueint; \
    else (to_struct)->_element[index] = _defval;

#define S2J_STRUCT_ARRAY_GET_string_ELEMENT_EX(to_struct, from_json, _element, index, _defval) \
    if (from_json) strncpy((to_struct)->_element[index], from_json->valuestring,sizeof((to_struct)->_element[0])-1); \
    else strncpy((to_struct)->_element[index], _defval,sizeof((to_struct)->_element[0])-1);

#define S2J_STRUCT_ARRAY_GET_double_ELEMENT_EX(to_struct, from_json, _element, index, _defval) \
    if (from_json) (to_struct)->_element[index] = from_json->valuedouble; \
    else (to_struct)->_element[index] = _defval;

#define S2J_STRUCT_ARRAY_GET_ELEMENT_EX(to_struct, from_json, type, _element, index, _defval) \
    S2J_STRUCT_ARRAY_GET_##type##_ELEMENT_EX(to_struct, from_json, _element, index, _defval)

#define S2J_JSON_SET_int_ELEMENT(to_json, from_struct, _element) \
    cJSON_AddIntToObject(to_json, #_element,(long long)(from_struct)->_element);

#define S2J_JSON_SET_double_ELEMENT(to_json, from_struct, _element) \
    cJSON_AddNumberToObject(to_json, #_element, (double)(from_struct)->_element);

#define S2J_JSON_SET_string_ELEMENT(to_json, from_struct, _element) \
    (from_struct)->_element[sizeof((from_struct)->_element)-1] = '\0'; \
    cJSON_AddStringToObject(to_json, #_element, (from_struct)->_element);

#define S2J_JSON_ARRAY_SET_int_ELEMENT(to_json, from_struct, _element, index) \
    cJSON_AddItemToArray(to_json, cJSON_CreateInt((from_struct)->_element[index]));

#define S2J_JSON_ARRAY_SET_double_ELEMENT(to_json, from_struct, _element, index) \
    cJSON_AddItemToArray(to_json, cJSON_CreateNumber((from_struct)->_element[index]));

#define S2J_JSON_ARRAY_SET_string_ELEMENT(to_json, from_struct, _element, index) \
    (from_struct)->_element[index][sizeof((from_struct)->_element[0])-1] = '\0'; \
    cJSON_AddItemToArray(to_json, cJSON_CreateString((from_struct)->_element[index]));

#define S2J_JSON_ARRAY_SET_ELEMENT(to_json, from_struct, type, _element, index) \
    S2J_JSON_ARRAY_SET_##type##_ELEMENT(to_json, from_struct, _element, index)


#define S2J_CREATE_JSON_OBJECT(json_obj) \
    cJSON *json_obj = cJSON_CreateObject();

#define S2J_DELETE_JSON_OBJECT(json_obj) \
    cJSON_Delete(json_obj);

#define S2J_JSON_SET_BASIC_ELEMENT(to_json, from_struct, type, _element) \
    S2J_JSON_SET_##type##_ELEMENT(to_json, from_struct, _element)

#define S2J_JSON_SET_ARRAY_ELEMENT(to_json, from_struct, type, _element, size) \
    { \
        cJSON *array_##_element; \
        size_t index_##_element = 0; \
        array_##_element = cJSON_CreateArray(); \
        if (array_##_element) { \
            for (;index_##_element < size;index_##_element++) { \
                S2J_JSON_ARRAY_SET_ELEMENT(array_##_element, from_struct, type, _element, index_##_element); \
            } \
            cJSON_AddItemToObject(to_json, #_element, array_##_element); \
        } \
    }

#define S2J_JSON_SET_STRUCT_ELEMENT(child_json, to_json, child_struct, from_struct, type, _element) \
    type *child_struct = &((from_struct)->_element); \
    cJSON *child_json = cJSON_CreateObject(); \
    if (child_json) cJSON_AddItemToObject(to_json, #_element, child_json);

#define S2J_CREATE_STRUCT_OBJECT(struct_obj, type) \
    cJSON *json_temp; \
    type *struct_obj = (type *)s2jHook.malloc_fn(sizeof(type)); \
    if (struct_obj) memset(struct_obj, 0, sizeof(type));

#define S2J_DELETE_STRUCT_OBJECT(struct_obj) \
    s2jHook.free_fn(struct_obj);

#define S2J_STRUCT_GET_BASIC_ELEMENT(to_struct, from_json, type, _element) \
    S2J_STRUCT_GET_##type##_ELEMENT(to_struct, from_json, _element)

#define S2J_STRUCT_GET_BASIC_ELEMENT_EX(to_struct, from_json, type, _element, _defval) \
    S2J_STRUCT_GET_##type##_ELEMENT_EX(to_struct, from_json, _element, _defval)

#define S2J_STRUCT_GET_ARRAY_ELEMENT(to_struct, from_json, type, _element) \
    { \
        cJSON *array_##_element, *array_item_##_element; \
        size_t index_##_element = 0, size_##_element = 0, realsize_##_element = 0; \
        size_##_element = S2J_ARRAY_SIZE((to_struct)->_element); \
        array_##_element = cJSON_GetObjectItem(from_json, #_element); \
        if (array_##_element) { \
            realsize_##_element = cJSON_GetArraySize(array_##_element); \
            for (;index_##_element < realsize_##_element && index_##_element < size_##_element ;index_##_element++) { \
                array_item_##_element = cJSON_GetArrayItem(array_##_element, index_##_element); \
                if (array_item_##_element) { \
                    S2J_STRUCT_ARRAY_GET_ELEMENT(to_struct, array_item_##_element, type, _element, index_##_element); \
                } \
            } \
        } \
    }

#define S2J_STRUCT_GET_ARRAY_ELEMENT_EX(to_struct, from_json, type, _element, size, _defval) \
    { \
        size_t index_##_element = 0, size_##_element = 0, realsize_##_element = 0; \
        if (from_json) { \
            cJSON *array_##_element = NULL, *array_item_##_element = NULL; \
            array_##_element = cJSON_GetObjectItem(from_json, #_element); \
            if (array_##_element) { \
                realsize_##_element = cJSON_GetArraySize(array_##_element); \
                for (;index_##_element < realsize_##_element && index_##_element < size; index_##_element++) { \
                    array_item_##_element = cJSON_GetArrayItem(array_##_element, index_##_element); \
                    if (array_item_##_element) { \
                        S2J_STRUCT_ARRAY_GET_ELEMENT_EX(to_struct, array_item_##_element, type, _element, index_##_element, _defval); \
                    }\
                } \
            } else { \
                for (;index_##_element < realsize_##_element && index_##_element < size; index_##_element++) { \
                    S2J_STRUCT_ARRAY_GET_ELEMENT_EX(to_struct, array_##_element, type, _element, index_##_element, _defval); \
                } \
            } \
        } else { \
            for (;index_##_element < realsize_##_element && index_##_element < size; index_##_element++) { \
                S2J_STRUCT_ARRAY_GET_ELEMENT_EX(to_struct, from_json, type, _element, index_##_element, _defval); \
            } \
        } \
    }

#define S2J_STRUCT_GET_STRUCT_ELEMENT(child_struct, to_struct, child_json, from_json, type, _element) \
    type *child_struct = &((to_struct)->_element); \
    cJSON *child_json = cJSON_GetObjectItem(from_json, #_element);

#define S2J_JSON_SET_STRUCT_ELEMENT_BY_FUNC(to_json, from_struct, type, element) \
    cJSON_AddItemToObject(to_json, #element, struct_to_json_##type(&((from_struct)->element)))

#define S2J_JSON_SET_STRUCT_ARRAY_ELEMENT_BY_FUNC(to_json, from_struct, type, element, array_size) \
    { \
        cJSON * j_array_##element = cJSON_CreateArray();    \
        cJSON_AddItemToObject(to_json, #element, j_array_##element); \
        int j_index_##element = 0; \
        for (; j_index_##element < array_size; j_index_##element++) { \
            cJSON_AddItemToArray(j_array_##element, struct_to_json_##type(&((from_struct)->element[j_index_##element])));  \
        } \
    }

#define S2J_STRUCT_GET_STRUCT_ELEMENT_BY_FUNC(to_struct, from_json, type, element) \
    { \
        S2J_STRUCT_GET_STRUCT_ELEMENT(struct_##element, to_struct, json_##element, from_json, type, element)     \
        if (json_##element){    \
            type * p_##element = (type *)json_to_struct_##type(json_##element); \
            *(struct_##element) = *(p_##element);    \
            s2j_delete_struct_obj(p_##element);        \
        }    \
        else {    \
            fprintf (stdout, "\nWARNING: Invalid json element(%s). [FUNCTION:%s, FILE:%s, LINE:%d]\n", #element,__FUNCTION__, __FILE__, __LINE__);    \
        } \
    }

#define S2J_STRUCT_GET_STRUCT_ARRAY_ELEMENT_BY_FUNC(to_struct, from_json, type, element) \
    { \
       cJSON *array_##element, *array_item_##element; \
       size_t index_##element = 0, size_##element = 0, realsize_##element = 0; \
       size_##element = S2J_ARRAY_SIZE((to_struct)->element); \
       array_##element = cJSON_GetObjectItem(from_json, #element); \
       if (array_##element) { \
          realsize_##element = cJSON_GetArraySize(array_##element); \
          for (;index_##element < realsize_##element && index_##element < size_##element; index_##element++) { \
             array_item_##element = cJSON_GetArrayItem(array_##element, index_##element); \
             if (array_item_##element) { \
                 type *struct_##element = &((to_struct)->element[index_##element]); \
                 type * p##element = (type *)json_to_struct_##type(array_item_##element); \
                 *(struct_##element) = *(p##element); \
                 s2j_delete_struct_obj(p##element); \
             } \
          } \
       } \
       else {    \
          fprintf (stdout, "\nWARNING: Invalid json element(%s). [FUNCTION:%s, FILE:%s, LINE:%d]\n", #element,__FUNCTION__, __FILE__, __LINE__);    \
       }    \
    }



#ifdef __cplusplus
}
#endif

#endif /* __S2JDEF_H__ */
