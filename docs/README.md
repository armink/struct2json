# struct2json

Ultralightweight struct to JSON converter in ANSI C.

## Table of contents
* [License](#license)
* [Usage](#usage)
* [Enjoy struct2json!](#enjoy-struct2json)

## License

MIT License

>  Copyright (c) 2021, Yu Xuebao, <yuxuebao@msn.com>
>
>  Permission is hereby granted, free of charge, to any person obtaining a copy
>  of this software and associated documentation files (the "Software"), to deal
>  in the Software without restriction, including without limitation the rights
>  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
>  copies of the Software, and to permit persons to whom the Software is
>  furnished to do so, subject to the following conditions:
>
>  The above copyright notice and this permission notice shall be included in
>  all copies or substantial portions of the Software.
>
>  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
>  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
>  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
>  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
>  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
>  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
>  THE SOFTWARE.

## Usage

### Welcome to struct2json

struct2json 是一个开源的C结构体与 JSON 快速互转库，它可以快速实现 结构体对象 与 JSON 对象 之间序列化及反序列化要求。快速、简洁的 API 设计，大大降低直接使用 JSON 解析库来实现此类功能的代码复杂度。

把面向对象设计应用到C语言中，是当下很流行的设计思想。由于C语言中没有类，所以一般使用结构体 struct 充当类，那么结构体变量就是对象。有了对象之后，很多时候需要考虑对象的序列化及反序列化问题。C语言不像很多高级语言拥有反射等机制，使得对象序列化及反序列化被原生的支持。

对于C语言来说，序列化为 JSON 字符串是个不错的选择，所以就得使用 cJSON 这类 JSON 解析库，但是使用后的代码冗余且逻辑性差，所以萌生对cJSON库进行二次封装，实现一个 struct 与 JSON 之间快速互转的库。 struct2json 就诞生于此。下面是 struct2json 主要使用场景：

    持久化 ：结构体对象序列化为 JSON 对象后，可直接保存至文件、Flash，实现对结构体对象的掉电存储；
    通信 ：高级语言对JSON支持的很友好，例如： Javascript、Groovy 就对 JSON 具有原生的支持，所以 JSON 也可作为C语言与其他语言软件之间的通信协议格式及对象传递格式；
    可视化 ：序列化为 JSON 后的对象，可以更加直观的展示到控制台或者 UI 上，可用于产品调试、产品二次开发等场景；

V2.0版本新增功能【yuxuebao】
	1) 更新cJSON库至1.7.12版本，并扩充实现，支持int64 (long long)类型数据。PS：cJSON原来int64类型以double方式处理，如果超过16位会有精度损失。
	2) 扩展struct2json功能，增加支持结构体内包含结构体成员，支持包含数组成员。
	3) 增加struct2json 结构体与JSON转换代码自动生成的Python脚本，支持从头文件中提取结构体定义，并根据结构体定义自动生成结构体与JSON互转代码，并提供相关示例。

##如何使用
	1) 提取结构体定义
		将头文件（eg:mc_usr_def.h）放在generate_s2j_code\inc目录下；
		执行generate_struct_defination.py，生成struct_defination.txt；
	2) 生成结构体与JSON互转代码
		执行generate_s2j_code.py，根据结构体定义自动生成结构体与JSON互转代码；
	3) 测试结构体与JSON转换
		将生成代码my_struct_2_json.c,my_struct_2_json.h拷贝至demo目录；
		编译测试代码，gcc  ../cJSON/cJSON.c ../struct2json/src/*.c my_struct_2_json.c  -I../cJSON -lm -DDEBUGS2J -g -o tests2j
		测试 ./tests2j 
		查看output输出和生成的JSON样例文件struct_define.json；
		
# Enjoy struct2json!

- Armink (original author)
- Yu Xuebao (current maintainer)
- and the other contributors (CONTRIBUTORS.md)
