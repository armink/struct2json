/*
 * This file is part of the struct2json Library.
 *
 * Copyright (c) 2018, YuXuebao, <yuxuebao@msn.com>
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
 * Created on: 2018-06-20
 */

#ifndef __S2J_EX_H__
#define __S2J_EX_H__

#include "s2j.h"

#ifdef __cplusplus
extern "C" {
#endif

/* struct2json software version number */
/*#define S2J_SW_VERSION                "2.0.4"*/

/* Set child structure type element for JSON object by function [cJSON * struct_to_json_##type(void*)] */
#define s2j_json_set_struct_element_by_func(to_json, from_struct, type, element) \
	cJSON_AddItemToObject(to_json, #element, struct_to_json_##type(&((from_struct)->element)))


/* Set child structure array type element for JSON object by function [cJSON * struct_to_json_##type(void*)] */
#define s2j_json_set_struct_array_element_by_func(to_json, from_struct, type, element, array_size) \
	cJSON * j_array_##element = cJSON_CreateArray();	\
	cJSON_AddItemToObject(to_json, #element, j_array_##element); \
	int j_index_##element = 0; \
	for (; j_index_##element < array_size; j_index_##element++) { \
		cJSON_AddItemToArray(j_array_##element, struct_to_json_##type(&((from_struct)->element[j_index_##element])));  \
	}  \


/* Get child structure type element for structure object by function [void *json_to_struct_#type(cJSON*)]*/
#define s2j_struct_get_struct_element_by_func(to_struct, from_json, type, element) \
		S2J_STRUCT_GET_STRUCT_ELEMENT(struct_##element, to_struct, json_##element, from_json, type, element)	 \
		if (json_##element){	\
			type * p_##element = (type *)json_to_struct_##type(json_##element); \
			*(struct_##element) = *(p_##element); 	\
			s2j_delete_struct_obj(p_##element);		\
		}	\
		else {	\
			fprintf (stdout, "\nWARNING: Invalid json element(%s). [FUNCTION:%s, FILE:%s, LINE:%d]\n", #element,__FUNCTION__, __FILE__, __LINE__);	\
		}


/* Get struct array type element for structure object by function [void *json_to_struct_#type(cJSON*)] */
#define s2j_struct_get_struct_array_element_by_func(to_struct, from_json, type, element) \
	{ \
		cJSON *array_##element, *array_item_##element; \
		size_t index_##element = 0, size_##element = 0; \
		array_##element = cJSON_GetObjectItem(from_json, #element); \
		if (array_##element) { \
			size_##element = cJSON_GetArraySize(array_##element); \
			for (;index_##element < size_##element; index_##element++) { \
				array_item_##element = cJSON_GetArrayItem(array_##element, index_##element); \
				if (array_item_##element) { \
					type *struct_##element = &((to_struct)->element[index_##element]); \
					type * p##element = (type *)json_to_struct_##type(array_item_##element); \
					*(struct_##element) = *(p##element); \
					s2j_delete_struct_obj(p##element); \
				} \
			} \
		} \
		else {	\
			fprintf (stdout, "\nWARNING: Invalid json element(%s). [FUNCTION:%s, FILE:%s, LINE:%d]\n", #element,__FUNCTION__, __FILE__, __LINE__);	\
		}	\
	}

#ifdef __cplusplus
}
#endif /* end of __cplusplus */

#endif /* __S2J_EX_H__ */
