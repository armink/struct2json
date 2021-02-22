#!/usr/bin/python3
import os
import re

root = "./inc"
file_name_list = os.listdir(root)
#print(file_name_list)
h_file_list = []
for file_item in file_name_list:
    if file_item.rfind(".h")!=-1:
        h_file_list.append(file_item)
#print(h_file_list)
content = ""

for h_file in h_file_list:
    #print(h_file)
    with open(root + "/" + h_file, 'r', encoding='UTF-8') as f:
        content_file = f.read()
        content_file = re.sub(r'((?<=\n)|^)[\t]*\/\*.*?\*\/\n?|\/\*.*?\*\/|((?<=\n)|^)[\t]*\/\/[^\n]*\n|\/\/[^\n]*','',content_file)
        num_struct = content_file.count('typedef struct')
        keyword_start = 'typedef struct'
        keyword_middle = '}'
        keyword_end = ';'
        position_start = 0
        position_end=0
        flag=0
        content_struct=""
        for i in range(num_struct):
            content_temp=""
            position_start = content_file.find(keyword_start,position_start)
            position_middle = content_file.find(keyword_middle, position_start)
            position_end = content_file.find(keyword_end, position_middle)
            #print(position_end)
            if position_start !=-1:
                content_temp = content_file[position_start:position_end+2]
                position_start += 1
            content_struct = content_struct + "\n" + content_temp
        content=content+content_struct
#print(content)
with open("struct_defination.txt", "w") as f:
    f.write(content)
