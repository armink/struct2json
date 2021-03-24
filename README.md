# C结构体与 JSON 快速互转库

---

## struct2json

[struct2json](https://github.com/armink/struct2json) 是一个开源的C结构体与 JSON 快速互转库，它可以快速实现 **结构体对象** 与 **JSON 对象** 之间序列化及反序列化要求。快速、简洁的 API 设计，大大降低直接使用 JSON 解析库来实现此类功能的代码复杂度。

## 起源

把面向对象设计应用到C语言中，是当下很流行的设计思想。由于C语言中没有类，所以一般使用结构体 `struct` 充当类，那么结构体变量就是对象。有了对象之后，很多时候需要考虑对象的序列化及反序列化问题。C语言不像很多高级语言拥有反射等机制，使得对象序列化及反序列化被原生的支持。

对于C语言来说，序列化为 JSON 字符串是个不错的选择，所以就得使用 [cJSON](https://github.com/kbranigan/cJSON) 这类 JSON 解析库，但是使用后的代码冗余且逻辑性差，所以萌生对cJSON库进行二次封装，实现一个 struct 与 JSON 之间快速互转的库。 struct2json 就诞生于此。下面是 struct2json 主要使用场景：

- **持久化** ：结构体对象序列化为 JSON 对象后，可直接保存至文件、Flash，实现对结构体对象的掉电存储；
- **通信** ：高级语言对JSON支持的很友好，例如： Javascript、Groovy 就对 JSON 具有原生的支持，所以 JSON 也可作为C语言与其他语言软件之间的通信协议格式及对象传递格式；
- **可视化** ：序列化为 JSON 后的对象，可以更加直观的展示到控制台或者 UI 上，可用于产品调试、产品二次开发等场景；

## 如何使用

### 声明结构体

如下声明了两个结构体，结构体 `Hometown` 是结构体 `Student` 的子结构体

```C
/* 籍贯 */
typedef struct {
    char name[16];
} Hometown;

/* 学生 */
typedef struct {
    uint8_t id;
    uint8_t score[8];
    char name[10];
    double weight;
    Hometown hometown;
} Student;
```

### 将结构体对象序列化为 JSON 对象

|使用前（[源文件](https://github.com/armink/struct2json/blob/master/docs/zh/assets/not_use_struct2json.c)）|使用后（[源文件](https://github.com/armink/struct2json/blob/master/docs/zh/assets/used_struct2json.c)）|
|:-----:|:-----:|
|![结构体转JSON-使用前](https://git.oschina.net/Armink/struct2json/raw/master/docs/zh/images/not_use_struct2json.png)| ![结构体转JSON-使用后](https://git.oschina.net/Armink/struct2json/raw/master/docs/zh/images/used_struct2json.png)|

### 将 JSON 对象反序列化为结构体对象

|使用前（[源文件](https://github.com/armink/struct2json/blob/master/docs/zh/assets/not_use_struct2json_for_json.c)）|使用后（[源文件](https://github.com/armink/struct2json/blob/master/docs/zh/assets/used_struct2json_for_json.c)）|
|:-----:|:-----:|
|![JSON转结构体-使用前](https://git.oschina.net/Armink/struct2json/raw/master/docs/zh/images/not_use_struct2json_for_json.png)| ![JSON转结构体-使用后](https://git.oschina.net/Armink/struct2json/raw/master/docs/zh/images/used_struct2json_for_json.png)|

### V2.0版本新增功能【yuxuebao】
#### 1) 更新cJSON库至1.7.12版本，并扩充实现，支持int64 (long long)类型数据。PS：cJSON原来int64类型以double方式处理，如果超过16位会有精度损失。
#### 2) 扩展struct2json功能，增加支持结构体内包含结构体成员，支持包含数组成员。
#### 3) 增加struct2json 结构体与JSON转换代码自动生成的Python脚本，支持从头文件中提取结构体定义，并根据结构体定义自动生成结构体与JSON互转代码，并提供相关示例。

### V2.1版本新增功能【yuxuebao】
#### 1) 扩展struct2json功能，增加支持C++结构体,支持string,bool类型成员和数组。


### V2.x 使用说明：
#### 1) 提取结构体定义:
		将头文件（eg:mc_usr_def.h）放在demo\inc目录下；
		执行generate_struct_defination.py，生成struct_defination.txt；
#### 2) 生成结构体与JSON互转代码:
		执行generate_s2j_code.py，根据结构体定义自动生成结构体与JSON互转代码：my_struct_2_json.c,my_struct_2_json.h；
		该脚本支持的参数类型有 基本类型 和 结构体类型，enum和指针按int处理，不支持union和位域；
		支持的数组类型:支持基本类型一维数组，结构体一维数组，字符二维数组（字符串数组）
#### 3) 测试结构体与JSON转换:
		cd demo
		编译测试代码，
        V2.0:  gcc ../cJSON/cJSON.c ../struct2json/src/*.c ./*.c -I ../cJSON/ -I ../struct2json/inc/ -lm  -g -DDEBUGS2J -o tests2j
        V2.1+: g++ ../cJSON/cJSON.c ../struct2json/src/*.c ./*.c -I ../cJSON/ -I ../struct2json/inc/ -fpermissive -lm  -g -DDEBUGS2J -o tests2j
		测试 ./tests2j 
		查看output输出和生成的JSON样例文件struct_defination.json；
		预期输出：*:strcmp:0     *:strcmp:0*:json_cmp:1

欢迎大家 **fork and pull request**([Github](https://github.com/armink/struct2json)|[OSChina](http://git.oschina.net/armink/struct2json)|[Coding](https://coding.net/u/armink/p/struct2json/git)) 。如果觉得这个开源项目很赞，可以点击[项目主页](https://github.com/armink/struct2json) 右上角的**Star**，同时把它推荐给更多有需要的朋友。

## 文档

具体内容参考[`\docs\zh\`](https://github.com/armink/struct2json/tree/master/docs/zh)下的文件。务必保证在 **阅读文档** 后再使用。

## 许可
- Armink (original author)
- Yu Xuebao (current maintainer)
- and the other contributors (CONTRIBUTORS.md)

MIT Copyright (c) armink.ztl@gmail.com
