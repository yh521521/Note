#include <iostream>
using namespace std;
// 单行注释
/* 多行注释*/
#define Day 7 //宏常量 
//int 111main() {
	//在屏幕中输出helloworld 
	//变量
	int a = 10;
	//Day = 14;//day 是一个常量不能修改
	const	int month = 12;
	//month = 24; const 修饰的变量也称为常量

	int num1 = 10;
	int num2 = 20;
	int sum = num1 + num2;
	cout << "求和为" << sum  << endl;
	cout << "一周总共有" << Day <<"天"<< endl;
	cout << "一年总共有" << month  << endl;
	cout << "a == " << a << endl;
	cout << "hello world " << endl;
	system("pause");
		return 0;
}
