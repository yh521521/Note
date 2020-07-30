# C++ 2020--06-17

C++ 是一种静态类型的、编译式的、通用的、大小写敏感的、不规则的编程语言，支持过程化编程、面向对象编程和泛型编程。

C++ 被认为是一种**中级**语言，它综合了高级语言和低级语言的特点。

C++ 是由 Bjarne Stroustrup 于 1979 年在新泽西州美利山贝尔实验室开始设计开发的。C++ 进一步扩充和完善了 C 语言，最初命名为带类的C，后来在 1983 年更名为 C++。

C++ 是 C 的一个超集，事实上，任何合法的 C 程序都是合法的 C++ 程序。



```
#include <iostream>
using namespace std;

int main() {

	cout << "hello world " << endl;
	system("pause");
		return 0;
}

"\n" 和"endl" 都是换行操作
```

 

##### 注释

// 单行注释

/**/  多行注释



##### 变量

作用 给一段指定的内存空间起名 方便这段内容

int a = 10;

​        #define Day 7  

宏常量 不能修改  

const 修饰的变量 也不能进行修改操作

#### 关键字或者标识符

跟java 中一样 尽量不要用关键字或者标识符定义变量

#### 标识符命名规则

(类比其它语言的语法)

标识符 不能是关键字

标识符只能由字母 数字下划线组成

第一个字符必须为字母或下划线

标识符字母区分大小写

#### 数据类型

数据类型存在的意义 给变量**分配合适的内存空间**

小技巧 : vs 注释多行的快捷键 Ctrl +K   Ctrl +C 

Ctrl +K  Ctrl +U  取消注释 

#### sizeof 关键字

统计数据类型所占内存大小 

vs 中源文件下只允许一个main 函数 

#### 浮点型

单精度 float  双精度 double  

typedef int int_自定义     为一个已有的类型取一个新的名字

#### 运算符

```
Exp1 ? Exp2 : Exp3;   类似于Java 中的三元运算符
```

#### 函数

c++ 定义函数要先进行声明 

```
#include <iostream>
using namespace std;

//函数声明  
int max(int num1, int num2);

int  main() {
	//局部变量声明
	int a = 100;
	int b = 200;
	int ret;
	//调用函数来获取最大值
	ret = max(a, b);
	cout << "Max value is:" << ret << endl;
	return 0;
}

//函数返回两个数中较大的那个数
int max(int num1, int num2) {
	//局部变量声明
	int result;
	if (num1 > num2) {
		result = num1;
	}
	else {
		result = num2;
	}

	return result;
}
```

##### include <iostream>

c++ 中总是出现这个 

 头文件 作用是调用库函数  比如iostream 中含有 cin cout 函数

iomanip 含有new 函数

using namespace std 是标准库名字空间

setw设置间隔

```
//定义一个数组
	int n[10];
	//初始化数组元素
	for (int i = 0; i < 10;i++ ) {
		//修改其中的元素
		n[i] = i + 100;

	}
	cout << "Element" << setw(13) << "Value" << endl;

	//输出数组每个元素的值
	for (int j = 0; j < 10; j++) {
	// 间隔7 个位置  输出j ( j 为 0 到 10 ) 间隔13 个  输出 数组n[j] 换行
		cout << setw(7) << j << setw(13) << n[j] << endl;
	}

```

![](G:\git\gitself\img\c++\c_setw.png)

c 风格字符串

```
//输出字符串 
	char greeting[6] = { 'h','e','l','l','o','\0' };
	cout << "Greeting message : ";
	cout <<greeting << endl;
	
	
	
C 风格的字符串起源于 C 语言，并在 C++ 中继续得到支持。字符串实际上是使用 null 字符 '\0' 终止的一维字符数组。因此，一个以 null 结尾的字符串，包含了组成字符串的字符。
Greeting message : hello 
```

 **Bug 1** error C4996: 'strcpy': This function or variable may be unsafe. Consider using strcpy_s instead.

 是因为strcpy函数不安全造成的溢出。 error C4996: 'strcpy': This function or variable may be unsafe. Consider using strcpy_s instead.

visual studio  --- 项目 ----属性 ---- c++   预处理器 --- 处理器定义--- 点击编辑  添加

 _CRT_SECURE_NO_WARNINGS  在进行调试就不会报错了



地址值 & 

指针 * 



I/O 库 头文件

<iostream> <iomanip> <fstream>

ctrl + enter 当前行 上方插入空行  

ctrl + shift + enter  当前行下方插入空行 



C++ 调用方法  必须要先声明该方法

```
// 头文件
#include<iostream>
#include <cstring>
using namespace std;
// 声明函数
void printBook(struct Books book);
// 声明一个结构体类型
struct Books {
	char title[50];
	char author[50];
	char subject[100];
	int book_id;
};


int main() {

	Books Book1;// 定义结构体类型Books 的变量Book1 

	//Book1 详述 
	strcpy(Book1.title, "css教程");
	strcpy(Book1.author, "Runoob");
	strcpy(Book1.subject, "编程语言");
	Book1.book_id = 12345;
	//输出Book1 信息
	//cout << "第一本书标题" << Book1.title << endl;
	//cout << "第一本书作者" << Book1.author<< endl;
	//cout << "第一本书类目" << Book1.subject << endl;
	//cout << "第一本书ID" << Book1.book_id << endl;
	printBook(Book1);

	return 0;
}

void printBook(struct Books book ) {
	cout << "书标题" << book.title << endl;
	cout << "书作者" << book.author << endl;
	cout << "书类目" << book.subject << endl;
	cout << "书ID" << book.book_id << endl;

}
```

C 面向过程编程  C++ 面向对象编程。

C++ 多继承 java 单继承多实现

C++ 数据抽象 

例如，您的程序可以调用 **sort()** 函数，而不需要知道函数中排序数据所用到的算法。实际上，函数排序的底层实现会因库的版本不同而有所差异，只要接口不变，函数调用就可以照常工作。

```
#include <iostream>
using namespace std;
 
int main( )
{
   cout << "Hello C++" <<endl;
   return 0;
}

这个不需要理解 cout  是如何在用户的屏幕上显示文本。您只需要知道公共接口即可，cout 的底层实现可以自由改变。
```



析构函数 

```
析构函数（Destructor）也是一种特殊的成员函数，没有返回值，不需要程序员显式调用（程序员也没法显式调用），而是在销毁对象时自动执行。构造函数的名字和类名相同，而析构函数的名字是在类名前面加一个~符号。

Box() {
			cout << "调用构造函数" << endl;

		}
		~Box() {
			cout << "调用析构函数" << endl;
		}
```

**::** 

 C++ 作用域 符 

如果想调用namespace std中的cout成员，你就写成std::cout  相当于using namespace std；cout

System::Math::Sqrt() 相当于System.Math.Sqrt()；

C++为例避免不同的类有名称相同的成员而采用作用域的方式进行区分。
如：A,B表示两个类，在A,B中都有成员member。那么
A::member就表示类A中的成员member，B::member就表示类B中的成员member。

#### 命名 空间

```
假设这样一种情况，当一个班上有两个名叫 Zara 的学生时，为了明确区分它们，我们在使用名字之外，不得不使用一些额外的信息，比如他们的家庭住址，或者他们父母的名字等等。

同样的情况也出现在 C++ 应用程序中。例如，您可能会写一个名为 xyz() 的函数，在另一个可用的库中也存在一个相同的函数 xyz()。这样，编译器就无法判断您所使用的是哪一个 xyz() 函数。

因此，引入了命名空间这个概念，专门用于解决上面的问题，它可作为附加信息来区分不同库中相同名称的函数、类、变量等。使用了命名空间即定义了上下文。本质上，命名空间就是定义了一个范围。

格式如下
namespace namespace_name {
   // 代码声明
}


using 指令 指令会告诉编译器，后续的代码将使用指定的命名空间中的名称。
```

**#** 和 **##** 运算符

​    

```
# 字符串化的意思，出现在宏定义中的#是把跟在后面的参数转换成一个字符串。
当用作字符串化操作时，# 的主要作用是将宏参数不经扩展地转换成字符串常量。

  ##  连接符号，把参数连在一起。 

```

C++ 标准库 分为两部分 

#### 标准函数库 分为下面几类

```
输入/输出 I/O
字符串和字符处理
数学
时间、日期和本地化
动态分配
其他
宽字符函数
```

#### 面向对象类库

```
标准的 C++ I/O 类
String 类
数值类
STL 容器类
STL 算法
STL 函数对象
STL 迭代器
STL 分配器
本地化库
异常处理类
杂项支持库
```

a  ---> 97  A-- 65  (ASCII)



前置和后置区别

// 前置和后置的区别
​	

	cout << "再次输出a++ *10 为 :" << a++ * 10 << endl; //100 
	cout << "再次输出++a1 *10 为 :" << ++a1 * 10 << endl; //110
	
	前置递增  先让变量+1 然后进行表达式运算
	后置递增 先进性表达式运算 后让变量+1 
	
	cout << "再次输出a-- *10 为 :" << a-- * 10 << endl; //100 
	cout << "再次输出--a1 *10 为 :" << --a1 * 10 << endl; //90
c++ 中 true 1  false 0 

除了0 都为真 

```
	cout << "1 XXXX" << endl;
	goto FLAG;
	cout << "2 XXXX" << endl;
	cout << "3 XXXX" << endl;
	FLAG:
	cout << "5 XXXX" << endl;	
	
	
	不建议使用goto 语句
```

#### 函数

 作用将一段经常使用的代码封装起来 减少重复代码

函数的定义

1 返回值类型

2 函数名

3 参数列表

4函数体语句

5 return 表达式	

定义的函数要在main   函数上方 跟其他语言开不一样   

 值传递的时候 形参发生任何改变  实参都不会改变



函数的常见样式 4 种 

无参 无返回值

无参 有返回值

有参 无返回值

有参 有返回值



函数的声明意义所在  ===>> 提前告诉编译器的存在 

自己定义的函数 必须放在main 函数上方   main 函数调用 这个函数 正常运行

放在main 后面就不能 运行 

可以在先进行函数的声明   函数 放在哪都行 

声明可以声明多次 ,但是定义却只能一次

函数的分文件编写 



```
不可能把所有的代码写到一个cpp 文件中
函数声明  函数定义 main 函数写在不同文件中


步骤如下:
1 创建.h 后缀名的头文件
2 创建.cpp 后缀名的源文件
3 在头文件中写函数的声明
4 在源文件中写函数的定义
```

#### 指针

指针的作用 : 可以通过指针间接访问内存

内存编号是从0 开始记录的,一般用16 进制 数字表示

可以利用指针保存地址

32 位操作系统 下 占用4 个字节空间

64 位操作系统下  占8个字节空间

空指针和野指针

空指针 : 指针变量指向内存中编号位0 的空间

用途 初始化指针变量  

注意 : 空指针指向的内存是不可以访问的

0 -255之间的内存是系统占用的,因此不可以访问

野指针 : 指针变量指向非法的内存空间 



空指针和 野指针都不是我们申请的空间 ,因此不要随意访问

const 修饰指针 的三种情况

 1    const 修饰指针 --常量指针

2	const 修饰常量 --- 指针常量

3      const   既修饰指针 又修饰常量



#### 常量指针 

const int * p = &a;

特点 指针的指向可以修改 但是指针指向的值不可以改

#### 指针常量

int  * const p = &a;

 特点 指针的指向不可以改,指针指向的值可以改 



const  int *  const p = &a;

特点 指针的指向和指针指向的值 都不可以修改



##### 结构体

结构体属于用户自定义的数据类型 允许用户存储不同的数据类型

结构体定义的时候不能省略struct  创建的时候可以省略struct 



switch  中  case 语句 只有形如以下操作

```
case 1:  // 添加联系人
			addPerson(&abs);
			break;
			
不会报错
但是有多多段代码的话 会报错 加上{} 称为一个代码段 
case 3:
		{
			cout << "请输入删除联系人姓名" << endl;
			string name;
			cin >> name;
			if (isExist(&abs, name) == -1) {
				cout << "查无此人" << endl;
			}
			else {
				cout << "找到此人" << endl;
			}
		}
			break;
```



删除操作 

| 张三   | 李四   | 王五   | 赵六   |      |
| ---- | ---- | ---- | ---- | ---- |
|      |      |      |      |      |

要删除李四  ,将李四后的数据向前移动 ,并让通讯录记录的人员个数做一个 -1 的操作

清空联系人   将通讯录中的所有联系人删除即可  将size 设置为0  做一个逻辑删除

c++ 编程

核心编程 面向对象编程



内存分区模型

代码区 : 存放函数体的二进制代码 由操作系统进行管理

全局区:  存放全局变量和静态变量以及常量

栈区:由编译器自动分配始放 存放函数的参数值  局部变量等

堆区 : 程序员分配和始放 若程序员不释放 程序结束是由操作系统回收





代码区 (程序运行前)

共享 --> 目的是对于频繁被执行的程序 只需要在内存中有一份代码即可

 只读 防止程序意外的修改他的指令 



全局区 (程序运行前)

全局变量 和静态变量 存放在此  还包括常量区 字符串常量 和其它常量也存放在此

该区域的数据在程序结束后由操作系统释放

全局变量和静态变量挨得比较近 

栈区 由编译器自动分配释放 存放函数的参数值 局部变量

不要返回局部变量的地址 社区开辟的数据由编译器去自动始放



```

int* p = func();
	cout << "栈区1 :" << *p << endl; // 第一次没问题
	cout << "栈区2 :" << *p << endl; //地址不一样 

栈区1 :10
栈区2 :2035067280


```

堆区数据由程序员管理开辟和释放

堆区数据利用new 关键字进行开辟内存



值传递     形参改变         不会修改实参

地址传递   形参改变  会修改实参 

引用传递  ,形参改变   会修改实参 

c++ 推荐引用技术 语法方便引用的本质是指针常量 但是所有的指针操作 编译器帮我们做了



默认实参不在形参列表的结尾

```
int  func2(int a, int b = 3, int c) {

	return a + b + c;
}
如果某个位置已经有了默认参数那魔从这个位置往后 从左到右都必须由默认值
```

声明和实现只能有一个默认值



函数占位参数

C++中函数的形参列表里面可以有占位参数  用来做占位 调用函数是必须填补该位置

函数重载

函数的返回值不可以作为函数重载的条件

C++ 面向对象的三大特性行为       封装继承多态

实例化  

将成员属性私有 可以自己控制读写权限

将成员属性设置为私有 可以控制读写权限 对于写权限 可以检测数据的有效性



###### # pragma once  

防止头文件重复包含

构造函数 : 主要用于在创建对象是为对象的成员属性赋值 构造函数又编译器自动调用 无需手动调用

```
构造函数  
 没有返回值 不用写void 
 函数名 与类名相同
 构造函数可以有参数 可以发生重载
 创建对象的时候 构造函数会自动调用  知回调用一次
```

析构函数 主要作用域对象销毁前系统自动调用 执行一些清理工作



无参 构造 有参构造  拷贝构造

拷贝函数的调用时机

```2 
1 使用一个已经创建完毕的对象来初始化一个新对象 
2 值传递的方式给函数参数传值 
3 值方式 返回局部对象

```

more情况下  c++ 编译器至少给一个类型添加 3 个函数

1 默认构造函数 (无参 函数体为空)

2 默认析构含函数(无参 函数体为空)

3 默认拷贝函数 堆属性进行值拷贝 

如果用户提供有参构造函数  不会提供无参构造  会提供默认 拷贝构造

##### 浅拷贝深拷贝

如果定义拷贝构造函数 不提供其它构造函数

浅拷贝 问题  堆区的内存重复释放

浅拷贝 简单的赋值拷贝操作

深拷贝 在堆区重新申请空间进行拷贝操作

如果属性在堆区开品 一定要自己提供拷贝构造函数防止浅拷贝带来的问题



	//初始化列表初始化属性
	Person() :m_A(10), m_B(20), m_C(30) {
	
	}
	Person(int a,int b,int c) :m_A(a), m_B(b), m_C(c) {
	
	}
c++ 类中的成员可以是另一个类的对象 我们称 该成员 为对象成员

当其他类的对象作为本类成员  构造时候先构造类对象 在构造自身 析构(释放对象)的顺序刚好相反





cout << "size of p =" << sizeof(p) << endl;  空对象占用的内存  是1 

mutable int m_B;  可以修改常量



常函数 常对象  mutable 可变的

friend void gooGay(Building* building); 友 元



class Python :public  BasePage 公共继承

继承中的对象模型

```
class Base {

public :
	int m_A;
protected :
	int m_B;
private :
	int m_C;

};
class Son :public Base {

public :
	int m_D;
};

void test01() {
	// 父类中所有非静态成员属性都会被字类继承下去 
	// 父类中私有成员属性 被编译器隐藏了 因此是访问不到 但是确实被继承下去了
	cout << "size of Son " << sizeof(Son) << endl;  16 
}
```

![](G:\git\gitself\img\c++\sizeof.png)



vbptr 虚基类 指针 virtual  base pointer 指向虚基列表vbtable

多态满足条件:

有继承关系 字类重写父类中的虚函数 

多态使用条件 

父类指针或引用指向子类 对象





多级指针 



以三级指针 p3 为例来分析上面的代码。`***p3`等价于`*(*(*p3))`。*p3 得到的是 p2 的值，也即 p1 的地址；*(*p3) 得到的是 p1 的值，也即 a 的地址；经过三次“取值”操作后，*(*(*p3)) 得到的才是 a 的值。

![](G:\git\gitself\img\c++\many-points.png)

```
#include <stdio.h>
int main(){
    int a =100;
    int *p1 = &a;
    int **p2 = &p1;
    int ***p3 = &p2;
    printf("%d, %d, %d, %d\n", a, *p1, **p2, ***p3);
    printf("&p2 = %#X, p3 = %#X\n", &p2, p3);
    printf("&p1 = %#X, p2 = %#X, *p3 = %#X\n", &p1, p2, *p3);
    printf(" &a = %#X, p1 = %#X, *p2 = %#X, **p3 = %#X\n", &a, p1, *p2, **p3);
    return 0;
}
运行结果 

100, 100, 100, 100
&p2 = 0X28FF3C, p3 = 0X28FF3C
&p1 = 0X28FF40, p2 = 0X28FF40, *p3 = 0X28FF40
 &a = 0X28FF44, p1 = 0X28FF44, *p2 = 0X28FF44, **p3 = 0X28FF44
```

**堆(heap)、栈(stack)**

eof() 函数文件末尾



C++中文件输入输出有三个类：ofstream,ifstream,fstream。 
ifstream从一个给定的文件读取数据，ofstream向一个给定的文件写入数据，fstream可以读写给定的文件。 
这三个类的使用和iostream和stringstream很相似，可以使用**<<**   写入  ,**>>**  读取    ，进行文件的读取操作。

C++ 面向对象  泛型编程 

泛型编程主要利用的是模板

模板机制 分为函数模板 和类模板

**普通函数和函数模板的区别**

普通函数调用时可以发生自动类型转换 (隐式类型转换) 

函数模板调用是 如果利用自动类型推导 不会发生隐式类型转换

如果利用显示指定类型的方式 可以发生隐式类型转换



函数模板和普通函数都可以调用时  优先调用普通函数 

模板的局限性  模板并不是万能的 有些特定数据类型 需要用具体化方式做特殊实现

利用具体化的模板 可以解决自定义类型的通用化

学习模板并不是为了写模板 ,而是在stl 能够运用系统提供的模板



类模板 分文件编写

// 分文件编写 第一种 直接包含源文件 

​    include "person.cpp"



类模板 与友元 建议 全局函数类内识别 用法简单 而且可以编译器 直接识别

STL 标准模板库 

stl 广义上可分为 容器 算法 迭代器  ,容器和算法之间 通过迭代器进行无缝连接 Stl 几乎所有的代码都采用了模板类 或模板函数

常用的容器迭代器类分为双向迭代器  和随机访问迭代器



string 本质是一个类  类内封装了 char *   char* 是一个指针

vector 和普通数组 的区别 

数组是静态空间   vector 可以动态扩展 

动态扩展 :

并不是在原有空间之后续接新空间,而是找更大的内存空间 然后将元数据拷贝到新空间 释放原空间

vector 容器的迭代器支持随机访问的迭代器

swap() 收缩内存

vector预留空间 减少vector 在动态扩展容时的扩展次数

**stack** 容器 先进后出 的数据结构 栈容器 

栈不允许有遍历行为

栈可以判断容器是否为空

可以反水元素的个数

入栈 push  出栈 pop  



**queue**    队列容器 先进先出 

###### 所有不支持随机访问迭代器的 容器不可以用标准算法

######  不支持随机访问迭代其的容器 内部会提供对应的一些算法 



set/multiset 容器  所有元素都会在插入时自动排序 

set/multiset 属于关联式容器  而底层结构用二叉树实现 

set 不允许容器中有重复的元素 

multiset 允许容器中有重复的元素 

find   查找key  元素是否存在 若存在 返回该键 的元素的迭代器 不存在 返回set.end 

 cout  统计key 的元素个数 



```
set里边大概是实例化了一个MyCompare 然后加了const限定符 之后调它的operator() 而operator没标const所以不让调

 仿函数 bool operator()(int v1, int v2) const  就能解决 c3848 
 

class MyCompare {
public:
bool operator()(int v1, int v2) {
return v1>v2;
}
};


void test02(){
set<int, MyCompare> s2;
s2.insert(10);
s2.insert(44);
s2.insert(20);
s2.insert(1);
s2.insert(66);
for (set<int, MyCompare>::iterator it = s2.begin(); it != s2.end();it++) {
cout << *it << "   ";
  }
cout << endl;


```



map 中所有的元素 都是pair  pair 中的第一个元素为key (键值 ) 起到索引作用第二个元素为value (实值)  所有元素都会根据元素的键值 自动排序 



本质 map /multimap 容器 属于关联式容器 底层结构 使用二叉树实现 



**区别**:

 map 不允许有重复的key 值元素

multimap 允许	容器中有重复的key 值元素

返回bool 类型的仿函数 称为谓词 

如果operator () 接受一个参数 那么叫做一元谓词两个参数 叫 二元谓词 

内建的函数对象  分为三类 :

​	算数仿函数

​	关系仿函数

​	逻辑仿函数

```
#include<algorithm> // c++ 自带的算法
#include<functional> // 内建的函数对象
```



stl 常用算法 

```
算法主要由 <algorithm> <functional> <numberic> 组成
<algorithm>  是所有stl 头文件中最大的一个 范围涉及到比较 交换查找 遍历 赋值修改等等
<numberic> 体积很小  只包括几个在序列上面进行简单数学运算的模板函数
<functional>  定义了一些模板类 用以声明函数对象

```

查找相邻的重复元素 **adjacent _find**



常用的排序算法 

sort 对容器内元素进行排序

random_shuffle 洗牌 指定范围内的元素随机调整次序  	srand((unsigned int)time(NULL));  随机种子 

merge 容器元素合并 并存储到另 已容器中

reverse  反转指定范围内的元素

replace  将容器内指定范围内的旧元素改为新元素

swap 互换   两容器必须是同容器 



算术 生成算法

accumulate // 计算容器元素累计总和 

fill 像容器中添加元素

常用的集合算法   交集 并集 差集 



// 获取交集

	vector<int>::iterator itEnd =   set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myPrint);
演讲比赛功能: 完成整届比赛流程 ,每个比赛阶段需要给用户一个提示 用户按任意键继续下一个阶段 



查看往届记录 查看之前比赛前三名结果 ,每次比赛都会记录到文件中 文件用.csv 保存





清空比赛记录 : 将文件中的数据清空



退出比赛程序 可以退出当前程序



为什莫会用csv 呢 早期阶段没有数据库   都是用csv 文件保存 

csv 还可以用记事本打开  是用逗号隔开的

也可以excel 表格打开



1 菜单功能实现

2 比赛流程 

 抽签 --> 开始演讲比赛--> 显示第一轮比赛结果

抽签 --> 开始演讲比赛--> 显示前三名结果 -->保存分数