/*
 * This file is the demo part of the struct2json Library.
 *
 * Copyright (c) 2021, YuXuebao, <yuxuebao@msn.com>
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
 * Function: It is an head file for this library. You can see all be called functions.
 * Created on: 2021-02-20
 */

/*
gcc ../cJSON/cJSON.c ../struct2json/src/*.c ./*.c -I ../cJSON/ -I ../struct2json/inc/ -lm -DDEBUGS2J  -g -o tests2j

*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "../cJSON/cJSON.h"
#include "../struct2json/inc/s2j.h"


#ifndef CHECK_NOT_NULL
#define CHECK_NOT_NULL(p)      \
do\
{\
    if (NULL == (p)) \
    {\
        fprintf (stdout, "\nWARNING: Null pointer accured(%s). [FUNCTION:%s, FILE:%s, LINE:%d]\n", #p,__FUNCTION__, __FILE__, __LINE__);     \
        return -1;    \
    }\
} while (0);
#endif


#define struct_para_json2bin(para_type,bin_para, type, value)    \
    else if (0 == strcmp( #para_type, type)){    \
        para_type* p_##para_type = (para_type*)json_to_struct_##para_type(value);        \
        *bin_para = p_##para_type;    \
    }    \


#define struct_para_bin2json(para_type,bin_para, type,json_para)    \
    else if (0 == strcmp( #para_type, type))     {    \
        cJSON* value_new = struct_to_json_##para_type(bin_para);    \
        cJSON_ReplaceItemInObject(*json_para,"value",value_new);    \
    }    \


#ifdef DEBUGS2J

#define TEST_S2J_STRUCT(type, value, file) \
            type struct_obj##type; \
            memset(&struct_obj##type, value, sizeof(type));  \
            cJSON *json_obj##type = struct_to_json_##type(&struct_obj##type); \
            char* str_json##type = cJSON_Print(json_obj##type); \
            printf("s2j:\n%s: %s\n",#type, str_json##type); \
            fprintf(file,",\n\t\t{\n\t\t\t\"type\": \"%s\",\n\t\t\t\"value\": %s\n\t\t}", #type, str_json##type); \
            cJSON *json_obj1##type =cJSON_Parse(str_json##type); \
            cJSON_bool json_cmp1##type = cJSON_Compare(json_obj ##type, json_obj1##type, 1); \
            printf("%s:json_cmp1:%d\n\n\n",#type, json_cmp1##type); \
            type *p_struct_obj##type =(type *)json_to_struct_##type(json_obj1##type); \
            int cmp##type = memcmp(p_struct_obj##type, &struct_obj##type, sizeof(type)); \
            printf("\n"); \
            cJSON *json_obj2##type = struct_to_json_##type(p_struct_obj##type); \
            char* str_json2##type = cJSON_Print(json_obj2##type); \
            printf("s2j2s2j:\n%s: %s\n",#type, str_json2##type); \
            int str_cmp##type = strcmp(str_json##type, str_json2##type); \
            printf("\n%s:strcmp:%d\n",#type, str_cmp##type); \
            cJSON_bool json_cmp2##type = cJSON_Compare(json_obj##type, json_obj2##type, 1); \
            printf("%s:json_cmp2:%d\n\n\n",#type, json_cmp2##type); \
            free(str_json##type);    \
            free(str_json2##type); \
            s2j_delete_struct_obj(p_struct_obj##type); \
            s2j_delete_json_obj(json_obj##type); \
            s2j_delete_json_obj(json_obj1##type); \
            s2j_delete_json_obj(json_obj2##type); \


#define TEST_S2J_JSON(type, size) \
    cJSON *json_struct_##type = NULL; \
    i = 0; \
    for (; i < size;i++) { \
        cJSON *json_struct_item = cJSON_GetArrayItem(json_struct, i); \
        cJSON *json_struct_item_type = cJSON_GetObjectItem(json_struct_item, "type"); \
        char* str_type = json_struct_item_type->valuestring; \
        if (0 == strcmp(#type, str_type))  { \
            json_struct_##type = cJSON_GetObjectItem(json_struct_item, "value"); \
            printf("\ntype:%s:\n",#type); \
            break; \
        } \
    } \
    if (json_struct_##type != NULL) { \
        cJSON * json_obj1##type = json_struct_##type; \
        char* str_json1##type = cJSON_Print(json_obj1##type); \
        printf("\nj2str:\n%s: %s\n",#type, str_json1##type); \
        type *p_struct_obj##type =(type *)json_to_struct_##type(json_obj1##type); \
        cJSON *json_obj2##type = struct_to_json_##type(p_struct_obj##type); \
        char* str_json2##type = cJSON_Print(json_obj2##type); \
        printf("\nj2s2j:\n%s: %s\n",#type, str_json2##type); \
        int str_cmp##type = strcmp(str_json1##type, str_json2##type); \
        printf("\n%s:strcmp:%d\n",#type, str_cmp##type); \
        cJSON_bool json_cmp##type = cJSON_Compare(json_obj1##type, json_obj2##type, 1); \
        printf("%s:json_cmp:%d\n\n\n",#type, json_cmp##type); \
        free(str_json1##type);    \
        free(str_json2##type); \
        s2j_delete_struct_obj(p_struct_obj##type); \
        s2j_delete_json_obj(json_obj1##type); \
        s2j_delete_json_obj(json_obj2##type); \
    }

#endif// DEBUGS2J

