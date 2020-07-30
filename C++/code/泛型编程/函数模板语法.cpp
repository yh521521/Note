#include <iostream>
using namespace std;

//函数模板

//两个整型交换函数
//void swapInt(int& a, int& b) {
//	int temp = a;
//	a = b;
//	b = temp;
//};
////两个浮点型交换函数
////void swapDouble(double& a, double& b) {
////	double temp = a;
////	a = b;
////	b = temp;
////};
//
//
////函数模板
//template<typename T>
////声明一个模板 告诉编译器后面代码中紧跟着的T 不要报错 
////T 是一个通用数据类型
//
//void mySwap(T& a, T& b) {
//	T temp = a;
//	a = b;
//	b = temp;
//
//}
//void test01() {
//	int a = 10;
//	int b = 20;
//	//swapInt(a, b);
//
//	//利用函数模板交换  两种方式使用函数模板
//	//1 自动类型推导
//	//mySwap(a, b);
//
//
//	//2 显示指定数据类型
//	mySwap<int>(a, b);
//
//
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//
//	//double c = 10.11;
//	//double d = 20.22;
//	//swapDouble(c, d);
//	//cout << "c = " << c << endl;
//	//cout << "d = " << d << endl;
//}
//



//template<class T> //typename 可以替换成class 
//void mySwap(T& a, T& b) {
//
//	T temp = a;
//	a = b;
//	b = temp;
//};
//
//template<class T>
//void func() {
//	cout << "func 调用" << endl;
//}
//void test02() {
//	//func();
//	func<int>();
//}
//void test01() {
//	int  a = 10;
//	int b = 12;
//	char c = 'c';
//	mySwap(a, b);
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//
//}

// 交换函数的模板
//template<class T>
//void mySwap(T&a,T&b) {
//	T temp = a;
//	a = b;
//	b = temp;
//}
//
//
////实现一个通用的数组进行排序的函数 从大到小  选择排序
////测试char  int 数组
//template<class T>
//void mySort(T arr[],int len) {
//	
//	for (int i = 0; i < len; i++)
//	{
//		int max = i;// 最大值的下标
//		for (int j = i+1; j < len; j++)
//		{
//			//认定的最大值 比遍历出的数值要小  说明j 下标对应的元素才是最大值
//			if (arr[max] < arr[j]) {
//				max = j;
//			}
//		}
//
//		if (max !=i) {
//			//交换max 和i 元素
//			mySwap(arr[max], arr[i]);
//		}
//	}
//}
//
//
////打印数组的模板
//template<class T>
//void printArray(T arr[], int len) {
//
//	for (int i = 0; i < len; i++)
//	{
//		cout << arr[i] << "  ";
//
//	}
//	cout << endl;
//}
//void test01() {
//	
//	char charArr[] = "badefyhcx";
//	int num = sizeof(charArr) / sizeof(char);
//	mySort(charArr, num);
//	printArray(charArr, num);
//
//}
//
//void test02() {
//
//	int  intArr[] = {1,66,22,4,7,2};
//	int num = sizeof(intArr) / sizeof(int);
//	mySort(intArr, num);
//	printArray(intArr, num);
//
//}


//普通函数与函数模板的区别

//1 普通函数调用可以发生隐式类型转换 
// 函数模板 自动类型推导 不能发生隐式类型转换
//3函数模板 显示指定类型 可以发生类型转换

//普通函数
//int myAdd01(int a,int b) {
//	
//	return a + b;
//}
//
//template<class T>
//T myAdd02(T a, T b) {
//	return a + b;
//}
//void test01() {
//	int a = 10;
//	int b = 20;
//	int c = 'c'; // a 对应的ascii 码 97 
//	cout << myAdd01(a, c) << endl;
//
//	//自动类型推导 
//	cout <<"自动类型模板"<< myAdd02(a, c) << endl;
//
//	//显示类型指定
//	cout << "显示类型指定" << myAdd02<int>(a, c) << endl;
//
//}
//
////函数模板


//void myPrint(int a, int b)
//{
//	cout << "调用的普通函数" << endl;
//}
//template<class T>
//void myPrint(T a, T b) {
//
//	cout << "调用的模板 函数" << endl;
//}
//
//
//template<class T>
//void myPrint(T a, T b,T c) {
//
//	cout << "调用的重载的模板 函数" << endl;
//}
//
//void test02() {
//	int a = 10;
//
//	int b = 20;
//	int c = 11;
//	//myPrint(a, b);
//
//
//	//通过空模板 参数列表 强制调用函数模板
//	//myPrint<>(a, b);
//		//myPrint (a, b, c);
//
//	//如果函数模板产生更好的匹配 优先调用函数模板
//}


//对比两个数据是否相等函数
//自定义数据类型
//class Person {
//public:
//	Person(string name, int age) {
//		this->m_Name = name;
//		this->m_Age = age;
//	}
//	int m_Age;
//	string m_Name;
//};
//
//
//
//
//template<class T>
//bool myCompare(T& a, T& b) {
//	if (a == b) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//
//// 利用具体化的person 版本实现  具体化优先调用
//
//template<>bool  myCompare(Person& p1, Person& p2) {
//	
//	if (p1.m_Age == p2.m_Age && p1.m_Name ==p2.m_Name) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//
//
//
//void test01() {
//	int a = 10;
//	int b = 20;
//	bool ret = myCompare(a, b);
//	if (ret) {
//		cout << " a == b  " << endl;
//	}
//	else {
//		cout << " a != b  " << endl;
//
//	}
//};
//
//void test02() {
//	Person p1("tom", 122);
//	Person p2("tom", 10);
//	bool ret = myCompare(p1, p2);
//
//
//	if (ret) {
//		cout << " p1 ==p2  " << endl;
//	}
//	else {
//		cout << " p1 != p2  " << endl;
//
//	}
//}


////类模板
//template<class NameType,class AgeType>
//class Person {
//public:
//	Person(NameType name,AgeType age) {
//		this->m_Name = name;
//		this->m_Age = age;
//	}
//
//	void showPerson() {
//	
//		cout << " name :"<<this->m_Name << "age      " << this->m_Age << endl;
//	}
//	NameType m_Name;
//	AgeType m_Age;
//
//};
//void test01() {
//	Person<string, int> p1("孙悟空", 22);
//	p1.showPerson();
//}

// 类模板与函数模板的区别
//template<class NameType,class AgeType =int>
//class Person {
//public:
//
//	Person(NameType name, AgeType age) {
//		this->m_Name = name;
//		this->m_Age = age;
//	}
//
//	void showPerson() {
//		cout << " name :" << this->m_Name << "age      " << this->m_Age << endl;
//	}
//	NameType m_Name;
//	AgeType m_Age;
//
//};
//// 区别 1 类模板没有自动类型推导使用方式
//void test01() {
//	//Person p1("孙悟空", 100); 无法自动类型推导
//	Person<string, int >p("孙悟空", 199);
//	p.showPerson();
//}
//
////2 类模板在模板参数列表中可以有模板参数
//void test02() {
//	Person<string >p("猪八戒", 1299);
//	p.showPerson();
//}

//类模板中成员函数在调用是才去创建 
//class Person1 {
//public:
//	void showPerson1() {
//		cout << "person1 show" << endl;
//	}
//
//};
//class Person2 {
//public:
//	void showPerson2() {
//		cout << "person2 show" << endl;
//	}
//
//};
//template<class T>
//class MyClass {
//public:
//	T obj;
//	// 类模板中的成员函数
//	void func1() {
//		obj.showPerson1();
//	}
//	void func2() {
//		obj.showPerson2();
//	}
//
//};
//
//void test01() {
//	MyClass<Person2> m;
//	//m.func1();
//	m.func2();
//
//}
int main() {

	test01();
	
	system("pause");
	return 0;
}