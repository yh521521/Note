#include <iostream>
using namespace std;

//����ģ��

//�������ͽ�������
//void swapInt(int& a, int& b) {
//	int temp = a;
//	a = b;
//	b = temp;
//};
////���������ͽ�������
////void swapDouble(double& a, double& b) {
////	double temp = a;
////	a = b;
////	b = temp;
////};
//
//
////����ģ��
//template<typename T>
////����һ��ģ�� ���߱�������������н����ŵ�T ��Ҫ���� 
////T ��һ��ͨ����������
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
//	//���ú���ģ�彻��  ���ַ�ʽʹ�ú���ģ��
//	//1 �Զ������Ƶ�
//	//mySwap(a, b);
//
//
//	//2 ��ʾָ����������
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



//template<class T> //typename �����滻��class 
//void mySwap(T& a, T& b) {
//
//	T temp = a;
//	a = b;
//	b = temp;
//};
//
//template<class T>
//void func() {
//	cout << "func ����" << endl;
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

// ����������ģ��
//template<class T>
//void mySwap(T&a,T&b) {
//	T temp = a;
//	a = b;
//	b = temp;
//}
//
//
////ʵ��һ��ͨ�õ������������ĺ��� �Ӵ�С  ѡ������
////����char  int ����
//template<class T>
//void mySort(T arr[],int len) {
//	
//	for (int i = 0; i < len; i++)
//	{
//		int max = i;// ���ֵ���±�
//		for (int j = i+1; j < len; j++)
//		{
//			//�϶������ֵ �ȱ���������ֵҪС  ˵��j �±��Ӧ��Ԫ�ز������ֵ
//			if (arr[max] < arr[j]) {
//				max = j;
//			}
//		}
//
//		if (max !=i) {
//			//����max ��i Ԫ��
//			mySwap(arr[max], arr[i]);
//		}
//	}
//}
//
//
////��ӡ�����ģ��
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


//��ͨ�����뺯��ģ�������

//1 ��ͨ�������ÿ��Է�����ʽ����ת�� 
// ����ģ�� �Զ������Ƶ� ���ܷ�����ʽ����ת��
//3����ģ�� ��ʾָ������ ���Է�������ת��

//��ͨ����
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
//	int c = 'c'; // a ��Ӧ��ascii �� 97 
//	cout << myAdd01(a, c) << endl;
//
//	//�Զ������Ƶ� 
//	cout <<"�Զ�����ģ��"<< myAdd02(a, c) << endl;
//
//	//��ʾ����ָ��
//	cout << "��ʾ����ָ��" << myAdd02<int>(a, c) << endl;
//
//}
//
////����ģ��


//void myPrint(int a, int b)
//{
//	cout << "���õ���ͨ����" << endl;
//}
//template<class T>
//void myPrint(T a, T b) {
//
//	cout << "���õ�ģ�� ����" << endl;
//}
//
//
//template<class T>
//void myPrint(T a, T b,T c) {
//
//	cout << "���õ����ص�ģ�� ����" << endl;
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
//	//ͨ����ģ�� �����б� ǿ�Ƶ��ú���ģ��
//	//myPrint<>(a, b);
//		//myPrint (a, b, c);
//
//	//�������ģ��������õ�ƥ�� ���ȵ��ú���ģ��
//}


//�Ա����������Ƿ���Ⱥ���
//�Զ�����������
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
//// ���þ��廯��person �汾ʵ��  ���廯���ȵ���
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


////��ģ��
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
//	Person<string, int> p1("�����", 22);
//	p1.showPerson();
//}

// ��ģ���뺯��ģ�������
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
//// ���� 1 ��ģ��û���Զ������Ƶ�ʹ�÷�ʽ
//void test01() {
//	//Person p1("�����", 100); �޷��Զ������Ƶ�
//	Person<string, int >p("�����", 199);
//	p.showPerson();
//}
//
////2 ��ģ����ģ������б��п�����ģ�����
//void test02() {
//	Person<string >p("��˽�", 1299);
//	p.showPerson();
//}

//��ģ���г�Ա�����ڵ����ǲ�ȥ���� 
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
//	// ��ģ���еĳ�Ա����
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