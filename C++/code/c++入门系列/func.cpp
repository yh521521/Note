#include <iostream>
using namespace std;
#include "swap.h"

// 值传递
// 定义函数 实现两个数字进行交换
// 不需要 返回值 可以为void 

	//void swap(int num1, int num2) {
	//	cout << "交换前:" << endl;
	//	cout << "num1=:" <<num1 << endl;
	//	cout << "num2 = :"<<num2 << endl;


	//	int temp = num1;
	//	num1 = num2;
	//	num2 = temp;
	//	cout << "交换后:" << endl;
	//	cout << "num1=:" << num1 << endl;
	//	cout << "num2 = :" << num2 << endl;
	//}

	// 无参 无反
	//void test01() {
	//	cout << "this is test01" << endl;
	//}
	////有参 无返
	//void test02(int a) {
	//	cout << "this is test02   a = " <<a<< endl;
	//}
	////有参无返
	//int test03() {
	//	cout << "this is test03" << endl;
	//	return 100;
	//}
	////有参有返
	//int test04(int a) {
	//	cout << "this is test04" << endl;
	//	return a;
	//}

	//函数的声明
	//比较函数 实现两个数字进行比较 返回较大的指 
//int max(int a, int b);


// 函数的分文件编写
// 实现两个数字进行叫换的函数 
// 函数的声明
//void swap(int a, int b);
//// 函数的定义
//void swap(int a, int b) {
//	int temp = a;
//	a = b;
//	b = temp;
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//}

//void swap(int* p1, int* p2) {
//	int temp = *p1;
//	*p1 = *p2;
//	*p2 = temp;
//
//}

// 冒泡排序函数 参数1 数组的首地址 参数2 数组长度
void bubbleSort(int* arr, int len) {
	for (int i= 0;i < len -1;i++) {
		for (int j = 0; j < len - i - 1;j++) {
			if (arr[j] >arr[j+1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

}

// 打印数组
void printArray(int * arr,int len) {
	for (int i = 0; i < len ; i++) {
		cout << arr[i] << endl;
	}
}
int main() {
	
	//int a = 10;
	//int b = 22;
	//swap(a, b);
	//// ab 未发生改变 值传递的时候 形参发生任何改变  实参都不会改变
	//test01();
	//int a = 122323;
	//test02(100);
	//int num1 = test03();
	//cout << "this is num1" <<num1 << endl;

	//int num2 = test04(a);
	//cout << "this is num2---" << num2 << endl;

	//int a = 10;
	//int b = 22;
	//int c = max(a, b);
	//cout << c;

	//int a = 10;
	//int b = 22;
	//swap(a,b);

	// 定义指针
	//int a = 10;
	////指针定义的语法
	//int  * p;
	//// 让指针记录变量a 的地址
	//p = &a;
	//cout << "a的地址为" << &a << endl;

	//cout << "指针p 为:" << p << endl;

	//// 使用指针
	//// 可以通过引用的方式来找到指针指向的内存
	//// 指针前 加 一个 * 代表引用 找到指针指向的内存中的数据
	//*p = 1000;  // 将原来的10 修改为1000 

	//cout << "a" <<&a << endl;
	//cout << "指针p 为:" << *p << endl;

	//// 指针所占用内存空间
	//int a = 10;
	///*int   *    p;
	//p = &a;*/
	//// 等价于
	//int  *   p = &a;
	////在 32 位操作系统下指针占用4个字节空间大小 不管什莫数据类型
	////64 位操作系统下指针扎用8 个字节空间大小 不管什莫数据类型
	//cout << "sizeof (int  *)" << sizeof(int    *) << endl;

	// 空指针 用于给指针变量进行初始化 
	//int  *  p = NULL;
	// 空指针是不可以进行访问的
	//*p = 100; // 报异常 

	// 野指针
	//int* p = (int *)0x1100; // 程序中 尽量避免出现野指针  

	//cout << *p << endl; 会报错

	//1 const 修饰指针 常量指针 指针指向的值
	//不 可以改      指针的指向可以改
	//int a = 10;
	//int b = 10;
	//const int* p = &a;
	//// *p = 20; 报错
	//p = &b; // 正确
	////2 const 修饰常量

	//int*  const p2 = &a;  //指针的指向不可以改    值 可以改
	//*p2 = 100;
	////p2 = &b; 错误
	//// 3 const 修饰指针和常量
	//const int* const  p3 = &a;
	//// 都为错
	///**p3 = 100;
	//p3 = &b;*/

	//指针和数组
	// 利用指针访问数组中的元素
	//int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//cout << "数组中的第一元素" << arr[0]<<endl;
	//int* p = arr;// arr 就是数组首地址
	//cout << "指针获取数组中第一个的元素" << *p << endl;
	//p++;
	//cout << "指针获取数组中第二个的元素" << *p << endl;

	//int* p2 = arr;
	//for (int i = 0; i < 10;i++) {
	//	//cout << arr[i] <<endl;
	//	//用指针取出元素
	//	cout << *p2 << endl;
	//	p2++;
	//}
	// 指针和函数
	// 利用指针 
	// 地址传递可以修改实参的值 --

	//int a = 10;
	//int b = 20;
	////2地址传递
	//swap(&a,&b);
	//cout << "a= " << a << endl;
	//cout << "b = " << b << endl;
	//封装一个函数利用冒泡排序,实现对整型数组的升序排序

	
	//创建数组
	int arr[10] = { 4,3,5,8,10,1,6,2,9,7 };
	// 创建函数 实现冒泡函数
	int len = sizeof(arr) / sizeof(arr[0]);

	//创建函数 实现冒泡排序
	bubbleSort(arr, len);
	//打印拍寻后的数组
	printArray(arr, len);
	system("pause");
	return 0;
}

//int max(int a, int b) {
//	return a > b ? a : b;
//}