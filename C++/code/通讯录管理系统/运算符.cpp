#include <iostream>
using namespace std;

//class Person {
//
//public:
//
//	// 1 ��Ա�������� +
//	/*Person operator+(Person &p) {
//		Person temp;
//		temp.m_A = this->m_A + p.m_A;
//		temp.m_B = this->m_B + p.m_B;
//		return temp;
//	}*/
//	int m_A;
//	int m_B;
//	
//};
////ȫ�ֺ�������+
////Person operator+(Person &p1,Person &p2) {
////	Person temp;
////	temp.m_A = p1.m_A + p2.m_A;
////	temp.m_B = p2.m_B + p2.m_B;
////	return temp;
////}
//Person operator+(Person &p1,int num) {
//	Person temp;
//	temp.m_A = p1.m_A + num;
//	temp.m_B = p1.m_B + num;
//	return temp;
//}
//void test01() {
//	Person p1;
//	p1.m_A = 10;
//	p1.m_B = 11;
//	Person p2;
//	p2.m_A = 10;
//	p2.m_B = 11;
//	//Person p3 = p1 + p2;
//	//Person p3 = operator+(p1,p2);
//	Person p3 = p1 + 123;
//	cout << "p3.m_A" << p3.m_A << endl;
//	cout << "p3.m_B" << p3.m_B << endl;
//}
//
//// �Ӻ� ���������
//// 1 ��Ա�������� +
//
////ȫ�ֺ�������+

//�������������
//class Person {
//
//public:
//	int m_A;
//	int m_B;
//
//	//���ó�Ա�������� ���������
//	/*void operator<<(Person &p) {
//	
//	}*/
//
//};
//
////��ȫ�ֺ����������������
//ostream& operator<<(ostream& cout ,Person &p) {
//	cout << "m_A=" << p.m_A << "      m_b" << p.m_B;
//	return cout;
//}
//void test01() {
//	Person p;
//	p.m_B = 11;
//	p.m_A = 9;
//	cout << p<<"hello world  "<<endl;
//	//cout <<"m_A" <<p.m_A <<endl;
//}

//������������� 
//ͨ�����ص��������  ʵ���Լ�����������
//class MyInteger {
//	friend ostream& operator<<(ostream& cout, MyInteger mInt);
//public :
//	MyInteger() {
//		 m_Num =0;
//	}
//	//����ǰ�� ++ �����
//	MyInteger& operator++() {
//
//		m_Num++;
//		//�� ��������з���
//		return *this;
//	};
//	//���غ��� ++ �����
//	//void operator++(int) int ����ռλ����
//	MyInteger operator++(int ) {
//
//		//�ȼ�¼��ʱ���
//		MyInteger temp = *this;
//		// �����
//		m_Num++;
//		//����¼��� ����
//		return temp;
//		//�����
//	};
//private:
//	int m_Num;
//};
//ostream & operator<<(ostream & cout ,MyInteger myInt) {
//	cout << myInt.m_Num;
//	return cout;
//}
//void test01() {
//	MyInteger myInt;
//	cout << ++(++myInt) << endl; // ��ͬһ�����ݽ��в���
//	cout << myInt << endl;
//}
//
//void test02() {
//	MyInteger myInt;
//	cout <<myInt++ << endl; // ��ͬһ�����ݽ��в���
//	cout << myInt << endl;
//}




//��ֵ����� = 
//class Person {
//public:
//	Person(int age) {
//		m_Age = new int(age);
//
//	}
//
//	~Person() {
//		if (m_Age != NULL) {
//			delete m_Age;
//			m_Age = NULL;
//		}
//	};
//
//	//���� ��ֵ����� 
//	Person & operator = (Person& p) {
//		//�������ṩ��ǳ����
//		// Ӧ�����ж��Ƿ��������ڶ��� ��������ͷŸɾ� Ȼ�������
//		if(m_Age != NULL){
//			delete m_Age;
//			m_Age = NULL;
//		}
//		//���
//		m_Age = new int(*p.m_Age);
//		//���ض�������
//		return *this;
//	}
//	int *m_Age;
//
//};
//void  test01() {
//	Person p1(18);
//
//	Person p2(22);
//	Person p3(33);
//	p2 = p1=p3;
//	cout << "p1 ����Ϊ" << *p1.m_Age << endl;
//	cout << "p2 ����Ϊ" << *p2.m_Age << endl;
//	cout << "p3 ����Ϊ" << *p3.m_Age << endl;
//
//};


// ��ϵ����� ����
//
// ����������������
//class MyPrint {
//
//public :
//	//���غ������������  
//	void operator()(string test) {
//		cout << test <<endl;
//	}
//
//};
//void MyPrint02(string test) {
//	cout << test << endl;
//}
//void test01() {
//	MyPrint myPrint;
//	//����ʹ�������ǳ������뺯������  ��Ϊ�º���
//	myPrint("hello world");
//	MyPrint02("hello wwww");
//};
////�ӷ�
//class MyAdd {
//public:
//	int operator()(int num1, int num2) {
//		return num1 + num2;
//	}
//
//};
//void test02() {
//	MyAdd myAdd;
//	int ret = myAdd(11, 22);
//	cout << "���Ϊ" << ret << endl;
//	cout << "��������Ϊ" << MyAdd()(11,222) << endl;
//}

//class Java {
//
//public :
//	void header() {
//		cout << "��ҳ �����ε�¼ע�� " << endl;
//	}
//	void footer() {
//		cout << "�������� �������� " << endl;
//	}
//	void left() {
//		cout << "java php python  " << endl;
//	}
//	void content() {
//		cout << "java ѧ��  " << endl;
//	}
//};
//
//
//class Python {
//
//public:
//	void header() {
//		cout << "��ҳ �����ε�¼ע�� " << endl;
//	}
//	void footer() {
//		cout << "�������� �������� " << endl;
//	}
//	void left() {
//		cout << "java php python  " << endl;
//	}
//	void content () {
//		cout << "python ѧ��  " << endl;
//	}
//};
//class BasePage {
//
//public:
//	void header() {
//		cout << "��ҳ �����ε�¼ע�� " << endl;
//	}
//	void footer() {
//		cout << "�������� �������� " << endl;
//	}
//	void left() {
//		cout << "java php python  " << endl;
//	}
//};
//// Javaҳ�� 
//class Java :public  BasePage {
//public:
//	void content() {
//			cout << "java ѧ��  " << endl;
//		}
//
//};
//
//class Python :public  BasePage {
//public:
//	void content() {
//		cout << "Python ѧ��  " << endl;
//	}
//
//};
//
//void test01() {
//	Java ja;
//	ja.header();
//	ja.footer();
//	ja.left();
//	ja.content();
//}
//
//
//void test02() {
//	Python  py;
//	py.header();
//	py.footer();
//	py.left();
//	py.content();
//}

////�����̳�
//class Base1 {
//public :
//	int m_A;
//protected :
//	int m_B;
//private :
//	int m_C;
//
//};
//
//class Son1 :public Base1 {
//public :
//
//	void func() {
//		m_A = 10; // �����еĹ���Ȩ�޳�Ա ����������Ȼ�ǹ���Ȩ��
//		m_B = 10;// �����б���Ȩ�޳�Ա ����������Ȼ�Ǳ���Ȩ��
//		//m_C = 10; //������˽��Ȩ�޳�Ա �������з��ʲ���
//	}
//};
//
//
//void test01(){
//	Son1 s1;
//	s1.m_A; = 100;
//	//s1.m_B = 11;//�����޷�����
//}
////�����̳�
//class Base2 {
//public:
//	int m_A;
//protected:
//	int m_B;
//private:
//	int m_C;
//
//};
//class Son2 :protected Base2 {
//public :
//
//	void func() {
//		m_A = 10; // �����еĹ���Ȩ�޳�Ա ����������Ȼ�Ǳ���Ȩ��
//		m_B = 10;// �����б���Ȩ�޳�Ա ����������Ȼ�Ǳ���Ȩ��
//		//m_C = 10; //������˽��Ȩ�޳�Ա �������з��ʲ���
//	}
//};
//
//void test02() {
//	Son2 s1;
//	//s1.m_A = 100;// �޷�����
//	//s1.m_B = 100;// �޷�����
//};
//
////˽�м̳�
//class Base3 {
//public:
//	int m_A;
//protected:
//	int m_B;
//private:
//	int m_C;
//
//};
//class Son3 :private Base3 {
//public:
//
//	void func() {
//		m_A = 10; // �����еĹ���Ȩ�޳�Ա ����������Ȼ��˽��Ȩ��
//		m_B = 10;// �����б���Ȩ�޳�Ա ����������Ȼ��˽��Ȩ��
//		//m_C = 10; //������˽��Ȩ�޳�Ա �������з��ʲ���
//	}
//};
//
//void test03() {
//	Son3 s1;
//	//s1.m_A = 100;// �޷�����
//	//s1.m_B = 100;// �޷�����
//
//};
//class GrandSon3 :public Son3 {
//public:
//	void func() {
//		//m_A == 1000; ����
//		//m_B == 1000; ����
//	}
//};

//class Base {
//
//public :
//	int m_A;
//protected :
//	int m_B;
//private :
//	int m_C;
//
//};
//class Son :public Base {
//
//public :
//	int m_D;
//};
//
//void test01() {
//	// ���������зǾ�̬��Ա���Զ��ᱻ����̳���ȥ 
//	// ������˽�г�Ա���� �������������� ����Ƿ��ʲ��� ����ȷʵ���̳���ȥ��
//	cout << "size of Son " << sizeof(Son) << endl;
//}


// �̳��еĹ��������˳Ѱ
//
//class Base {
//public:
//	Base() {
//		cout << "Base ���캯��!" << endl;
//	}
//	~Base() {
//		cout << "Base ��������!" << endl;
//	}
//};
//
//class Son :public Base {
//		
//public:
//	Son() {
//		cout << "Son ���캯��!" << endl;
//	}
//	~Son() {
//		cout << "Son ��������!" << endl;
//	}
//};
//
//void test01() {
//	//Base b;
//	Son s; // base���� --.> son ���캯��--> son �������� -- Base��������
//}

//�̳��е�ͬ������ 
//class Base {
//
//public:
//	Base() {
//		m_A = 100;
//	}
//
//	void func() {
//		cout << "base -func��������" << endl;
//	}
//	void func(int a) {
//		cout << "base -func �вκ�������" << endl;
//	}
//	int m_A;
//};
//
//class Son :public Base {
//		
//public:
//
//	Son() {
//		m_A = 200;
//	}
//
//	void func() {
//		cout << "son -func��������" << endl;
//	}
//	int m_A;
//
//};
//void test01() {
//	Son s;
//	cout << "z����m_A= " << s.m_A << endl;
//	// ���ͨ��������� ���ʵ�������ͬ����Ա ��Ҫ����������
//	cout << "����m_A= " << s.Base::m_A << endl;
//};
//void test02() {
//	Son s;
//	s.func(); // �õ��������
//	s.Base::func();
//	// ��������г��ֺ͸���ͬ���ĳ�Ա���� �����ͬ����Ա�����ص�����������ͬ������
//	// �������ʵ������б����ص�ͬ������  ��Ҫ�������� 
//	s.Base::func(100);
//}


// �̳��е�ͬ����̬��Ա����ʽ
class Base {

public:
	static int m_A;
	static void func() {
		cout << "base  �� ��̬��func "  << endl;

	}
};

int Base::m_A = 100;

class Son :public Base {
public:
	static int m_A;
	static void func() {
		cout << "son   �� ��̬��func " << endl;

	}
};
int Son::m_A = 111;
//ͬ���ľ�̬��Ա����
void test01() {
	Son s;
	cout << "son  �� ��m_A" << s.m_A << endl;
	cout << "Base   �� ��m_A" << s.Base::m_A << endl;
	//ͨ������������
	cout << "ͨ������������" << endl;
	cout << "son  �� ��m_A" << Son::m_A << endl;
	// ��һ������ͨ��������ʽ������ �ڶ���������ʸ�����������
	cout << "Base   �� ��m_A" << Son::Base::m_A << endl;
}
//ͬ���ľ�̬��Ա����

void test02() {
	Son s;
	s.func();
	s.Base::func();

	//2 ��������
	Son::func();
	Son::Base::func();
}
int main() {
		//test01();
test02();


	//int a = 10;
	//int b = 10;
	//int c = 10;
	//a = b = c;
	//cout << "a" <<a <<endl;
	//cout << "b" <<b <<endl;
	//cout << "c" << c<<endl;
	////int a = 0;
	/*++a;
	cout << ++(++a)  */;
	system("pause");
	return 0;
}