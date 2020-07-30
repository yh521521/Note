#include <iostream>
using namespace std;

//class Person {
//
//public:
//
//	// 1 成员函数重载 +
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
////全局函数重载+
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
//// 加号 运算符重载
//// 1 成员函数重载 +
//
////全局函数重载+

//左移运算符重载
//class Person {
//
//public:
//	int m_A;
//	int m_B;
//
//	//利用成员函数重载 左移运算符
//	/*void operator<<(Person &p) {
//	
//	}*/
//
//};
//
////用全局函数重载左移运算符
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

//递增运算符重载 
//通过重载递增运算符  实现自己的整型数据
//class MyInteger {
//	friend ostream& operator<<(ostream& cout, MyInteger mInt);
//public :
//	MyInteger() {
//		 m_Num =0;
//	}
//	//重载前置 ++ 运算符
//	MyInteger& operator++() {
//
//		m_Num++;
//		//再 将自身进行返回
//		return *this;
//	};
//	//重载后置 ++ 运算符
//	//void operator++(int) int 代表占位参数
//	MyInteger operator++(int ) {
//
//		//先记录当时结果
//		MyInteger temp = *this;
//		// 后递增
//		m_Num++;
//		//将记录结果 返回
//		return temp;
//		//后递增
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
//	cout << ++(++myInt) << endl; // 对同一个数据进行操作
//	cout << myInt << endl;
//}
//
//void test02() {
//	MyInteger myInt;
//	cout <<myInt++ << endl; // 对同一个数据进行操作
//	cout << myInt << endl;
//}




//赋值运算符 = 
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
//	//重载 赋值运算符 
//	Person & operator = (Person& p) {
//		//编译器提供的浅拷贝
//		// 应该先判断是否友属性在堆区 如果友先释放干净 然后在深拷贝
//		if(m_Age != NULL){
//			delete m_Age;
//			m_Age = NULL;
//		}
//		//深拷贝
//		m_Age = new int(*p.m_Age);
//		//返回对象自身
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
//	cout << "p1 年龄为" << *p1.m_Age << endl;
//	cout << "p2 年龄为" << *p2.m_Age << endl;
//	cout << "p3 年龄为" << *p3.m_Age << endl;
//
//};


// 关系运算符 重载
//
// 函数调用运算重载
//class MyPrint {
//
//public :
//	//重载函数调用运算符  
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
//	//由于使用起来非常类似与函数调用  称为仿函数
//	myPrint("hello world");
//	MyPrint02("hello wwww");
//};
////加法
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
//	cout << "结果为" << ret << endl;
//	cout << "匿名函数为" << MyAdd()(11,222) << endl;
//}

//class Java {
//
//public :
//	void header() {
//		cout << "首页 公开课登录注册 " << endl;
//	}
//	void footer() {
//		cout << "帮助中心 交流合作 " << endl;
//	}
//	void left() {
//		cout << "java php python  " << endl;
//	}
//	void content() {
//		cout << "java 学科  " << endl;
//	}
//};
//
//
//class Python {
//
//public:
//	void header() {
//		cout << "首页 公开课登录注册 " << endl;
//	}
//	void footer() {
//		cout << "帮助中心 交流合作 " << endl;
//	}
//	void left() {
//		cout << "java php python  " << endl;
//	}
//	void content () {
//		cout << "python 学科  " << endl;
//	}
//};
//class BasePage {
//
//public:
//	void header() {
//		cout << "首页 公开课登录注册 " << endl;
//	}
//	void footer() {
//		cout << "帮助中心 交流合作 " << endl;
//	}
//	void left() {
//		cout << "java php python  " << endl;
//	}
//};
//// Java页面 
//class Java :public  BasePage {
//public:
//	void content() {
//			cout << "java 学科  " << endl;
//		}
//
//};
//
//class Python :public  BasePage {
//public:
//	void content() {
//		cout << "Python 学科  " << endl;
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

////公共继承
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
//		m_A = 10; // 父类中的公共权限成员 到子类中依然是公共权限
//		m_B = 10;// 父类中保护权限成员 到子类中依然是保护权限
//		//m_C = 10; //父类中私有权限成员 到子类中访问不到
//	}
//};
//
//
//void test01(){
//	Son1 s1;
//	s1.m_A; = 100;
//	//s1.m_B = 11;//类外无法访问
//}
////保护继承
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
//		m_A = 10; // 父类中的公共权限成员 到子类中依然是保护权限
//		m_B = 10;// 父类中保护权限成员 到子类中依然是保护权限
//		//m_C = 10; //父类中私有权限成员 到子类中访问不到
//	}
//};
//
//void test02() {
//	Son2 s1;
//	//s1.m_A = 100;// 无法访问
//	//s1.m_B = 100;// 无法访问
//};
//
////私有继承
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
//		m_A = 10; // 父类中的公共权限成员 到子类中依然是私有权限
//		m_B = 10;// 父类中保护权限成员 到子类中依然是私有权限
//		//m_C = 10; //父类中私有权限成员 到子类中访问不到
//	}
//};
//
//void test03() {
//	Son3 s1;
//	//s1.m_A = 100;// 无法访问
//	//s1.m_B = 100;// 无法访问
//
//};
//class GrandSon3 :public Son3 {
//public:
//	void func() {
//		//m_A == 1000; 报错
//		//m_B == 1000; 报错
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
//	// 父类中所有非静态成员属性都会被字类继承下去 
//	// 父类中私有成员属性 被编译器隐藏了 因此是访问不到 但是确实被继承下去了
//	cout << "size of Son " << sizeof(Son) << endl;
//}


// 继承中的构造和析构顺寻
//
//class Base {
//public:
//	Base() {
//		cout << "Base 构造函数!" << endl;
//	}
//	~Base() {
//		cout << "Base 析构函数!" << endl;
//	}
//};
//
//class Son :public Base {
//		
//public:
//	Son() {
//		cout << "Son 构造函数!" << endl;
//	}
//	~Son() {
//		cout << "Son 析构函数!" << endl;
//	}
//};
//
//void test01() {
//	//Base b;
//	Son s; // base构造 --.> son 构造函数--> son 析构函数 -- Base析构函数
//}

//继承中的同名处理 
//class Base {
//
//public:
//	Base() {
//		m_A = 100;
//	}
//
//	void func() {
//		cout << "base -func函数调用" << endl;
//	}
//	void func(int a) {
//		cout << "base -func 有参函数调用" << endl;
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
//		cout << "son -func函数调用" << endl;
//	}
//	int m_A;
//
//};
//void test01() {
//	Son s;
//	cout << "z字类m_A= " << s.m_A << endl;
//	// 如果通过字类对象 访问到父类中同名成员 需要加上作用域
//	cout << "父类m_A= " << s.Base::m_A << endl;
//};
//void test02() {
//	Son s;
//	s.func(); // 拿到是子类的
//	s.Base::func();
//	// 如果子类中出现和父类同名的成员函数 子类的同名成员会隐藏掉父类中所有同名函数
//	// 如果想访问到父类中被隐藏的同名函数  需要加作用域 
//	s.Base::func(100);
//}


// 继承中的同名静态成员处理方式
class Base {

public:
	static int m_A;
	static void func() {
		cout << "base  下 静态的func "  << endl;

	}
};

int Base::m_A = 100;

class Son :public Base {
public:
	static int m_A;
	static void func() {
		cout << "son   下 静态的func " << endl;

	}
};
int Son::m_A = 111;
//同名的静态成员属性
void test01() {
	Son s;
	cout << "son  下 的m_A" << s.m_A << endl;
	cout << "Base   下 的m_A" << s.Base::m_A << endl;
	//通过类名来访问
	cout << "通过类名来访问" << endl;
	cout << "son  下 的m_A" << Son::m_A << endl;
	// 第一个代表通过类名方式来访问 第二个代表访问父类作用域下
	cout << "Base   下 的m_A" << Son::Base::m_A << endl;
}
//同名的静态成员函数

void test02() {
	Son s;
	s.func();
	s.Base::func();

	//2 类名访问
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