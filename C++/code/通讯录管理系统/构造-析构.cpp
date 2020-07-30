#include <iostream>
using namespace std;

//对象的初始化和清理
//class Person {
//public:
//	// 1 构造函数 进行初始化操作
//
//	Person() {
//		cout << "person 构造函数的调用" << endl;
//	}
//
//
//	//2 析构函数进行清理操作
//	~Person() {
//		cout << "person 的析构函数"<<endl;
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
//	//构造 函数
//	Person() {
//		// 无参 也叫默认参数
//		cout << "person 的构造函数 无参" << endl;
//	}
//	Person(int a) {
//		age = a;
//		cout << "person 的构造函数有参" << endl;
//	}
//
//	//拷贝构造函数
//	Person(const Person &p) {
//		age = p.age;
//		cout << "person 的拷贝函数" << endl;
//
//	}
//	~Person() {
//		cout << "person 的析构函数" << endl;
//	}
//};
//void test01(){
//	//
//
//	//1 括号法 
//	Person p;// 默认构造函数
//	// 2 显示法 
//
//	//3  隐式转换法
//
//}
// copy 函数  	
//class Person {
//public:
//	Person(){
//		cout << "person 默认构造函数调用" << endl;
//	}
//
//	Person(int age) {
//		cout << "person 有参构造函数调用" << endl;
//
//		m_Age = age;
//	}
//	Person(const Person &p) {
//		cout << "person 拷贝构造函数调用" << endl;
//
//		m_Age = p.m_Age;
//	}
//	~Person() {
//		cout << "Person 析构函数调用" << endl;
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
//	cout << "打印地址" << (int*)&p1 << endl;
//	return p1;
//}
//void test01() {
//	Person p1(20);
//	Person p2(p1);
//	cout << "p2 的年龄为:" <<p2.m_Age <<  endl;
//}
//
//void test02() {
//	Person p;
//	doWork(p);
//}
//
//void test03() {
//	Person p = doWork2();
//	cout << "打印地址" << (int*)&p << endl;
//}


//class Person {
//public :
//	/*Person() {
//		cout << "Person 默认构造函数调用" << endl;
//	}*/
//	/*~Person() {
//		cout << "Person 析构构造函数调用" << endl;
//
//	}*/
//	/*Person(int age) {
//		cout << "Person 有参构造函数调用" << endl;
//		m_Age = age;
//	}*/
//	Person(const Person &p ) {
//		cout << "Person 拷贝构造函数调用" << endl;
//		m_Age = p.m_Age;
//	}
//	int m_Age;
//};
//void test01() {
//	//Person p;
//	//p.m_Age = 19;
//	//Person p2(p);
//	// << "p2 的年龄为" << p2.m_Age <<endl;
//}
//
//void test02(){
//	/*Person p(181);
//	Person p2(p);
//	cout << "p2的年龄为"<<p2.m_Age << endl;*/
//	Person p;
//}

// 深拷贝浅拷贝 
//class Person {
//public:
//	Person() {
//		cout << "Person 默认构造函数调用" << endl;
//	}
//	~Person() {
//		cout << "Person 析构构造函数调用" << endl;
//		if (m_Height != NULL) {
//			delete m_Height;
//			m_Height = NULL;
//		}
//
//	}
//	Person(int age,int height) {
//		cout << "Person 有参构造函数调用" << endl;
//		m_Height = new int(height);
//		m_Age = age;
//	}
//
//	//自己实现拷贝的构造函数解决浅拷贝 重复释放内存操作
//	Person(const Person& p) {
//		cout << "Person 深度拷贝构造函数调用" << endl;
//		m_Age = p.m_Age;
//		//深拷贝
//		m_Height = new int(*p.m_Height);
//	}
//	/*Person(const Person &p ) {
//		cout << "Person 拷贝构造函数调用" << endl;
//		m_Age = p.m_Age;
//	}*/
//	int m_Age;
//	int *m_Height;
//
//};
//
//void test01() {
//	Person p1(18,160);
//	cout << "p1 的年龄为" << p1.m_Age  << "    身高 "<<*p1.m_Height << endl;
//	Person p2(p1);
//	cout << "p2 的年龄为" << p2.m_Age << "    身高 " << *p2.m_Height << endl;
//}

//class Person {
//public:
//	//传统初始化
//	/*Person(int a,int b,int c) {
//		m_A = a;
//		m_B = b;
//		m_C = c;
//	}
//	*/
//
//	//初始化列表初始化属性
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
//	cout << "m_A 是多少 " << p.m_A << endl;
//	cout << "m_ B是多少 " << p.m_B << endl;
//	cout << "m_ C是多少 " << p.m_C << endl;
//};

//类对象做为类成员
//<< "人的构造函数" << endl;
//	}
//	~Person() {
//		cout << "人的析构构造函数" << endl;
	//}
	/*class Phone {

public:

	Phone(string pName) {
		m_PName = pName;
		cout << "手机的构造函数"<<endl;
	} 
	~Phone() {
		cout << "手机的析构构造函数" << endl;
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
//	Person p("张三", "苹果max ");
//	cout << p.m_Name << " 拿着:" << p.m_Phone.m_PName << endl;
//}


	
//静态的成员函数  所有的对象共享同一个函数
//静态成员函数只能访问静态成员变量 
class Person {
public:
	//静态成员函数
	static void func() {
		m_A = 100;
		//m_B = 22;  报错 
		cout << "static void func 调用" << endl;
	}

	static int m_A; //静态成员变量
	int m_B;
	//静态函数也是又访问权限的
private :
	static void func2() {
		
		cout << "static void func2 调用" << endl;
	}
};

int Person::m_A = 0;

void test01() {
	//1 通过对象访问 
	Person p;
	p.func();

	//2 通过类名访问
	Person::func();
	// Person::func2(); 不能访问
}
int main() {
	test01();






















	//test01();
	//test02();
	//test03();
	//test02();
	//test01();
	//Person p; // 走默认的无参

	//1 括号法 
	/*Person p2(10);
	Person p3(p2);
	cout << "p2的年龄为" <<p2.age<< endl;
	cout << "p3的年龄为" << p3.age << endl;
	*/
	//调用默认构造函数的时候 不要加 ()
	// 计算机会认为 是一个函数声明  不会人为在创建对象
	
	//Person p();
	// 显示法 
/*	Person p1;
	Person p2 =  Person(10);
	Person p3 = Person(p2);
	Person(10);*/// 匿名对象 当前执行结束后 系统立即回收匿名对象
	//cout << "aaa"<<endl;
	//不要用拷贝构造函数 初始化匿名对象
	//Person(p3);

	//隐式转换法
	/*Person p4 = 10;
	Person p5 = p4;*/


	system("pause");
	return 0;
}