#include <iostream>
// 为了使用数学运算的函数引入 <cmath>
#include<cmath>
//系统时间 
#include <ctime> 
#include <iomanip>
#include <cstdlib>
using namespace std;
//using std::setw;

////函数声明
//int max(int num1, int num2);
//
int  main() {
//	//局部变量声明
//	int a = 100;
//	int b = 200;
//	int ret;
//	//调用函数来获取最大值
//	ret = max(a, b);
//	cout << "Max value is:" << ret << endl;
//	return 0;
//}
//
////函数返回两个数中较大的那个数
//int max(int num1, int num2) {
//	//局部变量声明
//	int result;
//	if (num1 > num2) {
//		result = num1;
//	}
//	else {
//		result = num2;
//	}
//
//	return result;
//}

////函数声明  相当于给一个默认值  没给b 传值 则用默认
//int sum(int a, int  b = 20) {
//	int result;
//	result = a + b;
//	return result;
//}
//int main() {
//	//局部变量声明
//	int a = 100;
//	int b = 200;
//	int result;
//
//	//调用 函数给 b 赋值
//	result = sum(a, b);
//	cout << "total value is :" << result << endl;
//
//	//调用函数 不给b 赋值   使用默认 
//	result = sum(a);
//	cout << "total value is :" << result << endl;
//	//数字定义
//	short s;
//	int i;
//	long l;
//	float f;
//	double d;
//	//数字赋值
//	s = 10;
//	i = 1000;
//	l = 1000000;
//	f = 230.44;
//	d = 3333.1234;
//
//	//数字输出
//	cout << "short s is :" << s << endl;
//	cout << "int i is :" << i << endl;
//	cout << "long l is :" << l << endl;
//	cout << "float f is :" << f << endl;
//	cout << "double d is :" << d << endl;
//
//
//	//数学运算
//	cout << "sin(d)" << sin(d) << endl;
//	cout << "abs(i)" << abs(i) << endl;
//	cout << "sqrt(f)" << sqrt(f) << endl;
//	cout << "pow(d,2)" << pow(d, 2) << endl;
//
//	int y, z;
//	//设置种子
//	//srand((unsigned)time(NULL));
//	//生成10 个随机数
//	for (y = 0; y < 10; y++) {
//		//生成实际的随机数
//		z = rand();
//		cout << "随机数" << z << endl;
//
//	}
//	//定义一个数组
//	int n[10];
//	//初始化数组元素
//	for (int i = 0; i < 10;i++ ) {
//		//修改其中的元素
//		n[i] = i + 100;
//
//	}
//	cout << "Element" << setw(13) << "Value" << endl;
//
//	//输出数组每个元素的值
//	for (int j = 0; j < 10; j++) {
//		cout << setw(7) << j << setw(13) << n[j] << endl;
//	}
//	//输出字符串 
//	char greeting[6] = { 'h','e','l','l','o','\0' };
//	cout << "Greeting message : ";
//	cout <<greeting << endl;

	//字符串的基本操作
	char str1[11] = "Hello";
	char str2[11] = "World";
	char str3[11];
	int len;

	//复制 str1 到str3 
	strcpy(str3, str1);
	cout << "字符串的copy 操作 " << str3 << endl;
	//cat 连接操作
	strcat(str1, str2);
	cout << "字符串的cat 操作 " << str1 << endl;
	//连接后 str1 的总长度
	len = strlen(str1);
	cout << "字符串长度为 " << len << endl;

	int var1;
	char var2[10];
	cout << "var1 的变量地址 " << &var1 << endl;
	cout << "var2 的变量地址 " << &var2 << endl;

	//int *ip;// 一个整型 的指针
	//double *dp; //一个double的指针
	//float *fp;//一个浮点型的指针
	//char *ch; // 一个字符型的指针

	int var = 20;
	int *ip;
	ip = &var;//在指针变量中存储var 的 地址
	//输出在指针变量中存储的地址
	cout << "address in ip variable:  " << ip << endl;
		//访问指针中地址的值 

	cout << "address in ip variable:   " << *ip << endl;

	//声明简单的变量
	int i;
	double d;

	//声明引用变量

	int& r = i;
	double& s = d;
	i = 5;
	cout << "value of i " << i << endl;

	cout << "value of i reference " << r << endl;
	d = 11.7;
	cout << "value of d " << d << endl;
	 
	cout << "value of d reference " << s << endl;
	// 引入 <ctime>

	////基于当前系统的当前日期 时间
	//time_t now = time(0);

	//	// 把 now 转换为字符串形式
	//char* dt = ctime(&now);
	//cout << "本地时间和日期" << dt << endl;

	////把 now 转为tm 结构
	//tm* gmtm = gmtime(&now);
	//dt = asctime(gmtm);

	//cout << "UTC本地时间和日期" << dt << endl;
	//
	// 基于目前系统的当前日期 /时间

	time_t now = time(0);
	cout << "1970 到目前经过秒数" << now << endl;
	tm* ltm = localtime(&now);

	//输出tm 结构的各个组成部分

	cout << "年" << 1900 + ltm->tm_year << endl;
	cout << "月" << 1 + ltm->tm_mon << endl;
	cout << "日" << ltm->tm_mday << endl;
	cout << "时间" <<ltm->tm_hour << endl;
	cout  << ltm->tm_min << ":";

	cout <<  ltm->tm_sec << endl;


	//c++ 的基本输入输出
	//标准输出流
	char str[] = " Hello C++";
	cout << "Value of str is :" << str << endl;
	//标准输入流

	char name[50];

	cout <<"请输入你的名称";
	cin >> name;

	cout << "您的名称是:" << name << endl;

	// 标准错误流
	char str22[] = "Unable to read ....";
	cerr << "Error message :" << str22 << endl;
	//标准日志流 
	char str33[] = "Unable to read....";
	clog << "Error message:" << str33 << endl;
	return 0;
}
