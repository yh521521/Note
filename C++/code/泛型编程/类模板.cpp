#include <iostream>
using namespace std;

#include "MyArray.hpp"


// 分文件编写 第一种 直接包含源文件   不提倡
//#include "person.cpp"
// 第二种方式 
// 将.h  文件 和.cpp 中 的内容写到一起 将后缀名改为.hpp 文件
//#include "person.hpp"
// 类模板对象做函数参数

//template <class T1,class T2>
//
//class Person {
//
//public:
//	Person(T1 name,T2 age) {
//		this->m_Name = name;
//		this->m_Age =age;
//	}
//	void showPerson() {
//		cout << "姓名:" << this->m_Name << "年龄" << this->m_Age << endl;
//	}
//
//	T1 m_Name;
//	T2 m_Age;
//};
//void printPerson1(Person<string, int>& p) {
//	p.showPerson();
//}
//void test01() {
//	Person<string, int> p("zhangsan ", 11);
//	printPerson1(p);
//};
//template <class T1, class T2>
//void printPerson2(Person<T1, T2> &p) {
//	p.showPerson();// typeid 类型
//	cout << "T1的类型为 " << typeid(T1).name() << endl;
//	cout << "T2的类型为 " << typeid(T2).name() << endl;
//};
//void test02() {
//	Person<string, int> p("lisi ", 222);
//	printPerson2(p);
//};
//
//// 整个类模板化
//template <class T>
//void printPerson3(T& p) {
//	p.showPerson();
//	cout << "T1的类型为 " << typeid(T).name() << endl;
//};
//
//void test03() {
//	Person<string, int> p("王五", 123);
//	printPerson3(p);
//};


//类模板与继承
//template<class T>
//class Base {
//
//	T m;
//
//};
// class Son :public Base { 错误  必须知道父类中的T 类型 才能继承给子类 
//class Son :public Base<int > {
//
//};
//void test01() {
//	Son s1;
//}
//
//// 如果想灵活指定父类中的T 类型  子类必须要变为类模板
//template<class T1,class T2>
//class Son2 :public Base<T2 > {
//public:
//	Son2() {
//		cout << "T1 de 类型为" << typeid(T1).name() << endl;
//		cout << "T2 de 类型为" << typeid(T2).name() << endl;
//	}
//	T1 obj;
//};
//
//void test02() {
//	Son2<int, char> s2;
//
//
//}

//// 类模板 成员函数类外实现
//template<class T1,class T2>
//class Person {
//
//public:
//	Person(T1 name, T2 age);
//	/*{
//		this->m_Name = name ;
//		this->m_Age = age;
//	}*/
//	void showPerson();
//	/*{
//		cout << "姓名 " << this->m_Name << "年龄" << this->m_Age << endl;
//	}*/
//	T1 m_Name;
//	T2 m_Age;
//
//};
//// 构造函数类外实现
//template<class T1, class T2>
//Person<T1, T2>::Person(T1 name, T2 age) {
//	this->m_Name = name;
//	this->m_Age = age;
//}
//// 成员函数类外实现
//template<class T1, class T2>
//void Person<T1, T2>::showPerson() {
//	cout << "姓名 " << this->m_Name << "年龄" << this->m_Age << endl;
//
//}
//
//
//
//void test01() {
//	Person <string, int> p("Tom",20);
//	p.showPerson();
//}

// 类模板的分文件编写问题及解决
//template <class T1,class T2>
//class Person {
//public:
//
//	Person(T1 name, T2 age);
//
//	void showPerson();
//	T1 m_Name;
//	T2 m_Age;
//
//};
//template <class T1, class T2>
//Person<T1, T2>::Person(T1 name, T2 age) {
//	this->m_Name = name;
//	this->m_Age = age;
//}
//template <class T1, class T2>
//void Person<T1, T2>::showPerson() {
//	cout << "姓名" << this->m_Name << "年龄 " << this->m_Age << endl;
//}
//void test01() {
//	Person<string, int > p("jerry", 11);
//	p.showPerson();
//}

// 提前让编译器知道person 类存在 
//template <class T1, class T2>
//class Person;
//// 全局函数  类外实现
////
//template <class T1, class T2>
//void printPerson2(Person<T1, T2> p) {
//	cout << "类外实现的    姓名是 : " << p.m_Name << "年龄: " << p.m_Age << endl;
//
//}
//// 通过全局函数打印person 信息 
//template <class T1,class T2>
//class Person {
//
//	// 全局函数  类内实现
//	friend void printPerson(Person<T1,T2> p) {
//		 cout << "姓名是 : " << p.m_Name << "年龄: " << p.m_Age << endl;
//	}
//
//	friend void printPerson2<>(Person<T1, T2> p);
//	
//public:
//	Person(T1 name,T2 age) {
//		this->m_Name = name;
//		this->m_Age = age;
//	}
//
//private:
//	T1 m_Name;
//	T2 m_Age;
//
//};
//
//void test01() {
//	Person<string, int> p("tom", 20);
//	printPerson(p);
//}
//
//// 类外实现
//void test02() {
//	Person<string, int> p("yh", 18);
//	printPerson2(p);
//}


//打印输出
void printIntArr(MyArray<int>& arr) {
	
	for (int  i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << endl;
	}
}

void test01() {
	MyArray<int > arr1(5);
	for (int  i = 0; i < 5; i++)
	{
		// 利用尾插法像数组中插入数据
		arr1.Push_Back(i);
	}
	cout << "arr1 的打印输出为:"<< endl;
	printIntArr(arr1);

	cout << "arr1 的容量为:"<<arr1.getCapacity() << endl;
	cout << "arr1 的大小为:"<<arr1.getSize() << endl;

	MyArray<int > arr2(arr1);
	cout << "arr2 的打印输出为:" << endl;
	printIntArr(arr2);

	//尾删
	arr2.Pop_Back();
	cout << "尾删后 为:" << endl;
	cout << "arr2 的容量为:" << arr2.getCapacity() << endl;
	cout << "arr2的大小为:" << arr2.getSize() << endl;

	/*MyArray<int > arr2(arr1);
	MyArray<int > arr3(100);
	arr3 = arr1;*/
}


//测试自定义类型
class Person {

public:
	Person() {};
	Person(string name, int age) {
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int  m_Age;
};

void printPersonArray(MyArray<Person>& arr) {
	
	for (int  i = 0; i < arr.getSize(); i++)
	{
		cout << "姓名" << arr[i].m_Name << "年龄为 "<<arr[i].m_Age << endl;
	}
}
void test02() {
	
	MyArray<Person> arr(10);
	Person p1("刘备", 22);
	Person p2("张飞", 11);
	Person p3("关于", 33);
	Person p4("赵云", 44);

	//将数据插入到数据中
	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4);
	
	//打印数组
	printPersonArray(arr);

	//输出容量
	cout << "arr 容量为" << arr.getCapacity() << endl;

	//输出大小
	cout << "arr size为" << arr.getSize() << endl;
}

int main() {
	//test03();
	test02();


	system("pause");
	return 0;
}