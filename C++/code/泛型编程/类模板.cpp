#include <iostream>
using namespace std;

#include "MyArray.hpp"


// ���ļ���д ��һ�� ֱ�Ӱ���Դ�ļ�   ���ᳫ
//#include "person.cpp"
// �ڶ��ַ�ʽ 
// ��.h  �ļ� ��.cpp �� ������д��һ�� ����׺����Ϊ.hpp �ļ�
//#include "person.hpp"
// ��ģ���������������

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
//		cout << "����:" << this->m_Name << "����" << this->m_Age << endl;
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
//	p.showPerson();// typeid ����
//	cout << "T1������Ϊ " << typeid(T1).name() << endl;
//	cout << "T2������Ϊ " << typeid(T2).name() << endl;
//};
//void test02() {
//	Person<string, int> p("lisi ", 222);
//	printPerson2(p);
//};
//
//// ������ģ�廯
//template <class T>
//void printPerson3(T& p) {
//	p.showPerson();
//	cout << "T1������Ϊ " << typeid(T).name() << endl;
//};
//
//void test03() {
//	Person<string, int> p("����", 123);
//	printPerson3(p);
//};


//��ģ����̳�
//template<class T>
//class Base {
//
//	T m;
//
//};
// class Son :public Base { ����  ����֪�������е�T ���� ���ܼ̳и����� 
//class Son :public Base<int > {
//
//};
//void test01() {
//	Son s1;
//}
//
//// ��������ָ�������е�T ����  �������Ҫ��Ϊ��ģ��
//template<class T1,class T2>
//class Son2 :public Base<T2 > {
//public:
//	Son2() {
//		cout << "T1 de ����Ϊ" << typeid(T1).name() << endl;
//		cout << "T2 de ����Ϊ" << typeid(T2).name() << endl;
//	}
//	T1 obj;
//};
//
//void test02() {
//	Son2<int, char> s2;
//
//
//}

//// ��ģ�� ��Ա��������ʵ��
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
//		cout << "���� " << this->m_Name << "����" << this->m_Age << endl;
//	}*/
//	T1 m_Name;
//	T2 m_Age;
//
//};
//// ���캯������ʵ��
//template<class T1, class T2>
//Person<T1, T2>::Person(T1 name, T2 age) {
//	this->m_Name = name;
//	this->m_Age = age;
//}
//// ��Ա��������ʵ��
//template<class T1, class T2>
//void Person<T1, T2>::showPerson() {
//	cout << "���� " << this->m_Name << "����" << this->m_Age << endl;
//
//}
//
//
//
//void test01() {
//	Person <string, int> p("Tom",20);
//	p.showPerson();
//}

// ��ģ��ķ��ļ���д���⼰���
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
//	cout << "����" << this->m_Name << "���� " << this->m_Age << endl;
//}
//void test01() {
//	Person<string, int > p("jerry", 11);
//	p.showPerson();
//}

// ��ǰ�ñ�����֪��person ����� 
//template <class T1, class T2>
//class Person;
//// ȫ�ֺ���  ����ʵ��
////
//template <class T1, class T2>
//void printPerson2(Person<T1, T2> p) {
//	cout << "����ʵ�ֵ�    ������ : " << p.m_Name << "����: " << p.m_Age << endl;
//
//}
//// ͨ��ȫ�ֺ�����ӡperson ��Ϣ 
//template <class T1,class T2>
//class Person {
//
//	// ȫ�ֺ���  ����ʵ��
//	friend void printPerson(Person<T1,T2> p) {
//		 cout << "������ : " << p.m_Name << "����: " << p.m_Age << endl;
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
//// ����ʵ��
//void test02() {
//	Person<string, int> p("yh", 18);
//	printPerson2(p);
//}


//��ӡ���
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
		// ����β�巨�������в�������
		arr1.Push_Back(i);
	}
	cout << "arr1 �Ĵ�ӡ���Ϊ:"<< endl;
	printIntArr(arr1);

	cout << "arr1 ������Ϊ:"<<arr1.getCapacity() << endl;
	cout << "arr1 �Ĵ�СΪ:"<<arr1.getSize() << endl;

	MyArray<int > arr2(arr1);
	cout << "arr2 �Ĵ�ӡ���Ϊ:" << endl;
	printIntArr(arr2);

	//βɾ
	arr2.Pop_Back();
	cout << "βɾ�� Ϊ:" << endl;
	cout << "arr2 ������Ϊ:" << arr2.getCapacity() << endl;
	cout << "arr2�Ĵ�СΪ:" << arr2.getSize() << endl;

	/*MyArray<int > arr2(arr1);
	MyArray<int > arr3(100);
	arr3 = arr1;*/
}


//�����Զ�������
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
		cout << "����" << arr[i].m_Name << "����Ϊ "<<arr[i].m_Age << endl;
	}
}
void test02() {
	
	MyArray<Person> arr(10);
	Person p1("����", 22);
	Person p2("�ŷ�", 11);
	Person p3("����", 33);
	Person p4("����", 44);

	//�����ݲ��뵽������
	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4);
	
	//��ӡ����
	printPersonArray(arr);

	//�������
	cout << "arr ����Ϊ" << arr.getCapacity() << endl;

	//�����С
	cout << "arr sizeΪ" << arr.getSize() << endl;
}

int main() {
	//test03();
	test02();


	system("pause");
	return 0;
}