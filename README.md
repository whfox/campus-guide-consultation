# 校园导游咨询
## 概述
本课程设计为校园导游咨询，基于Windows开发环境编写，添加Windows自带库，输出可执行文件只能在Windows上运行，生成在Windows上可运行的exe文件。该设计由C语言开发，visual C++ IDE编译通过。算法采用无向图解决路径查询问题，利用二维数组存储路径及长度，用Floyd算法求解最短路径长度。
## 问题描述
题目：校园导游咨询

问题描述：
1. 设计校园平面图，所含景点不少于10个。以图中定点表示学校各景点，存放景点名称、代号、简介等信息，以边表示路径，存放路径长度等相关信息。
2. 为来访客人提供图中任意景点的问路查询，即查询任意两个景点之间的一条最短的简单路径
3. 为来访客人提供图中任意景点相关信息的查询

测试数据：由读者根据实际情况指定。

实现提示：一般情况下，校园的道路是双向通行的，可设校园平面图是一个无向图。顶点和边均含有相关信息。
## 需求分析
### 基本需求：
1. 平面图
该部分直接采用逐行打印字符的方式展示平面图，在平面图上编辑各景点编号。
而后用二维数组的方式存储各结点间路径及长度，并依次输入景点相关信息。
2. 最短路径查询
采用Floyd算法求解最短路径
3. 查询景点相关信息
创建一个新的数组作为用户输入，变量m=0作为标志位，用来确认是否找到该景点。用for循环依次将存储的代号和用户输入进行比较，找到则更新标志位m=1并输出结点信息，反之输出查询错误警告。
### 扩展：
1. 景点信息编辑
同上景点信息查询，用标志位确认用户输入是否合法，合法则用for循环找到用户输入结点，并依次替换代号、名称和介绍等相关信息。
## 基本算法
程序算法设计流程图如下：

![flow chart](https://github.com/whfox/campus-guide-consultation/img/flow.png)
## 数据结构及程序块设计
### 定义相关头文件
程序里面需要用到的特殊功能函数或操作如字符串操作、文字输入输出等函数都是库中自带的类型。
### 定义函数结构以及相关属性
1. 定义景点信息：定义三个数组，用来存放名称、代号和介绍
2. 定义景点编号：定义num，用来存放平面图中编号
3. 定义图：定义一个图和二维结构体数组，每个结构体变量存储一个权值和边（弧的信息）
### 菜单界面
1. void DisplayTu()；打印平面图
2. void init(AMGraph &AM)；输入景点信息及无向图
3. void Display(AMGraph AM)；列出景点编号 
4. void Edit(AMGraph &AM)；修改景点信息 
5. void Query(AMGraph AM)；查询景点信息
6. void ShortestPath(AMGraph AM)；Floyd求解最短路径
7. void Menu()：功能菜单
## 成果展示
实现的主要功能有：
1. 用户菜单栏选择

![pic](https://github.com/whfox/campus-guide-consultation/img/1.png)

2. 矿大校园平面图

![pic](https://github.com/whfox/campus-guide-consultation/img/2.png)

3. 基本信息修改

![pic](https://github.com/whfox/campus-guide-consultation/img/3.png)

4. 景点信息查询

![pic](https://github.com/whfox/campus-guide-consultation/img/4.png)

5. 景点最短路径查询

![pic](https://github.com/whfox/campus-guide-consultation/img/5.png)