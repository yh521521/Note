#include <iostream>
using namespace std;

//����ĳ�ʼ��������
//class Person {
//public:
//	// 1 ���캯�� ���г�ʼ������
//
//	Person() {
//		cout << "person ���캯���ĵ���" << endl;
//	}
//
//
//	//2 �������������������
//	~Person() {
//		cout << "person ����������"<<endl;
//	}
//
//};
//
//void test01() {
//	Person p;
//}

//class Person {
//public:
//	int age;
//	//���� ����
//	Person() {
//		// �޲� Ҳ��Ĭ�ϲ���
//		cout << "person �Ĺ��캯�� �޲�" << endl;
//	}
//	Person(int a) {
//		age = a;
//		cout << "person �Ĺ��캯���в�" << endl;
//	}
//
//	//�������캯��
//	Person(const Person &p) {
//		age = p.age;
//		cout << "person �Ŀ�������" << endl;
//
//	}
//	~Person() {
//		cout << "person ����������" << endl;
//	}
//};
//void test01(){
//	//
//
//	//1 ���ŷ� 
//	Person p;// Ĭ�Ϲ��캯��
//	// 2 ��ʾ�� 
//
//	//3  ��ʽת����
//
//}
// copy ����  	
//class Person {
//public:
//	Person(){
//		cout << "person Ĭ�Ϲ��캯������" << endl;
//	}
//
//	Person(int age) {
//		cout << "person �вι��캯������" << endl;
//
//		m_Age = age;
//	}
//	Person(const Person &p) {
//		cout << "person �������캯������" << endl;
//
//		m_Age = p.m_Age;
//	}
//	~Person() {
//		cout << "Person ������������" << endl;
//	}
//
//	int m_Age;
//};
//
//void doWork(Person p ) {
//	
//}
//
//Person  doWork2() {
//	Person p1;
//	cout << "��ӡ��ַ" << (int*)&p1 << endl;
//	return p1;
//}
//void test01() {
//	Person p1(20);
//	Person p2(p1);
//	cout << "p2 ������Ϊ:" <<p2.m_Age <<  endl;
//}
//
//void test02() {
//	Person p;
//	doWork(p);
//}
//
//void test03() {
//	Person p = doWork2();
//	cout << "��ӡ��ַ" << (int*)&p << endl;
//}


//class Person {
//public :
//	/*Person() {
//		cout << "Person Ĭ�Ϲ��캯������" << endl;
//	}*/
//	/*~Person() {
//		cout << "Person �������캯������" << endl;
//
//	}*/
//	/*Person(int age) {
//		cout << "Person �вι��캯������" << endl;
//		m_Age = age;
//	}*/
//	Person(const Person &p ) {
//		cout << "Person �������캯������" << endl;
//		m_Age = p.m_Age;
//	}
//	int m_Age;
//};
//void test01() {
//	//Person p;
//	//p.m_Age = 19;
//	//Person p2(p);
//	// << "p2 ������Ϊ" << p2.m_Age <<endl;
//}
//
//void test02(){
//	/*Person p(181);
//	Person p2(p);
//	cout << "p2������Ϊ"<<p2.m_Age << endl;*/
//	Person p;
//}

// ���ǳ���� 
//class Person {
//public:
//	Person() {
//		cout << "Person Ĭ�Ϲ��캯������" << endl;
//	}
//	~Person() {
//		cout << "Person �������캯������" << endl;
//		if (m_Height != NULL) {
//			delete m_Height;
//			m_Height = NULL;
//		}
//
//	}
//	Person(int age,int height) {
//		cout << "Person �вι��캯������" << endl;
//		m_Height = new int(height);
//		m_Age = age;
//	}
//
//	//�Լ�ʵ�ֿ����Ĺ��캯�����ǳ���� �ظ��ͷ��ڴ����
//	Person(const Person& p) {
//		cout << "Person ��ȿ������캯������" << endl;
//		m_Age = p.m_Age;
//		//���
//		m_Height = new int(*p.m_Height);
//	}
//	/*Person(const Person &p ) {
//		cout << "Person �������캯������" << endl;
//		m_Age = p.m_Age;
//	}*/
//	int m_Age;
//	int *m_Height;
//
//};
//
//void test01() {
//	Person p1(18,160);
//	cout << "p1 ������Ϊ" << p1.m_Age  << "    ��� "<<*p1.m_Height << endl;
//	Person p2(p1);
//	cout << "p2 ������Ϊ" << p2.m_Age << "    ��� " << *p2.m_Height << endl;
//}

//class Person {
//public:
//	//��ͳ��ʼ��
//	/*Person(int a,int b,int c) {
//		m_A = a;
//		m_B = b;
//		m_C = c;
//	}
//	*/
//
//	//��ʼ���б��ʼ������
//	/*Person() :m_A(10), m_B(20), m_C(30) {
//		
//	}*/
//	Person(int a,int b,int c) :m_A(a), m_B(b), m_C(c) {
//
//	}
//	int m_A;
//	int m_B;
//	int m_C;
//
//};
//void test01() {
//	//Person p(19, 29, 30);
//	Person p(11,12,155);
//	cout << "m_A �Ƕ��� " << p.m_A << endl;
//	cout << "m_ B�Ƕ��� " << p.m_B << endl;
//	cout << "m_ C�Ƕ��� " << p.m_C << endl;
//};

//�������Ϊ���Ա
//<< "�˵Ĺ��캯��" << endl;
//	}
//	~Person() {
//		cout << "�˵��������캯��" << endl;
	//}
	/*class Phone {

public:

	Phone(string pName) {
		m_PName = pName;
		cout << "�ֻ��Ĺ��캯��"<<endl;
	} 
	~Phone() {
		cout << "�ֻ����������캯��" << endl;
	}
	string m_PName;

};

class Person {
		
public :

	Person(string name ,string pName):m_Name(name ),m_Phone(pName) {
			
		cout */
//	string m_Name;
//	Phone m_Phone;
//};
//
//
//void test01() {
//	Person p("����", "ƻ��max ");
//	cout << p.m_Name << " ����:" << p.m_Phone.m_PName << endl;
//}


	
//��̬�ĳ�Ա����  ���еĶ�����ͬһ������
//��̬��Ա����ֻ�ܷ��ʾ�̬��Ա���� 
class Person {
public:
	//��̬��Ա����
	static void func() {
		m_A = 100;
		//m_B = 22;  ���� 
		cout << "static void func ����" << endl;
	}

	static int m_A; //��̬��Ա����
	int m_B;
	//��̬����Ҳ���ַ���Ȩ�޵�
private :
	static void func2() {
		
		cout << "static void func2 ����" << endl;
	}
};

int Person::m_A = 0;

void test01() {
	//1 ͨ��������� 
	Person p;
	p.func();

	//2 ͨ����������
	Person::func();
	// Person::func2(); ���ܷ���
}
int main() {
	test01();






















	//test01();
	//test02();
	//test03();
	//test02();
	//test01();
	//Person p; // ��Ĭ�ϵ��޲�

	//1 ���ŷ� 
	/*Person p2(10);
	Person p3(p2);
	cout << "p2������Ϊ" <<p2.age<< endl;
	cout << "p3������Ϊ" << p3.age << endl;
	*/
	//����Ĭ�Ϲ��캯����ʱ�� ��Ҫ�� ()
	// ���������Ϊ ��һ����������  ������Ϊ�ڴ�������
	
	//Person p();
	// ��ʾ�� 
/*	Person p1;
	Person p2 =  Person(10);
	Person p3 = Person(p2);
	Person(10);*/// �������� ��ǰִ�н����� ϵͳ����������������
	//cout << "aaa"<<endl;
	//��Ҫ�ÿ������캯�� ��ʼ����������
	//Person(p3);

	//��ʽת����
	/*Person p4 = 10;
	Person p5 = p4;*/


	system("pause");
	return 0;
}