#include <iostream>
using namespace std;


//成员变量和成员函数 分开存储

//class Person {
//	
//	int m_A; // 非静态成员变量 属于类的对象上 
//
//	static int m_B; //静态成员变量 不属于 类对象上
//	// 非静态成员函数 不属于类对象上
//
//
//	void func() {
//		
//	}
//};
//void test01() {
//	Person p;
//	// 空对象占用内存空间 1  c++ 编译器会给每个空对象分配一个字节
//	//区分空对象占用内存的位置  每一个空对象也应该有独一无二的位置
//	cout << "size of p =" << sizeof(p) << endl;
//}


// 解决名称冲突  返回对象本身 * this 
//class Person {
//
//public :
//	Person(int age) {
//		//m_age = age;
//
//		// this 指针指向的是被调用的成员函数 所属的对象
//		this->age = age;
//	}
//	//int m_age
//	int age;
//
//	Person  PersonAdd(Person &p) {
//		this->age += p.age;
//		return *this;
//	}
//};
//
//void test01() {
//	Person p1(18);
//	//cout << "p1 的年龄为" << p1.m_age << endl;
//	cout << "p1 的年龄为" << p1.age << endl;
//}
//
//void test02() {
//	Person p1(10);
//	Person p2(10);
//	//p2.PersonAdd(p1);
//	// 链式编程思想 
//	p2.PersonAdd(p1).PersonAdd(p1).PersonAdd(p1);
//	cout << "p2的年龄为" << p2.age << endl;
//}

//空指针 访问成员函数 
//class Person {
//
//public:
//	void showClassName() {
//		cout << "this is person  class" << endl;
//	}
//	void showPersonAge() {
//		if (this == NULL) {
//			return;
//		}
//		cout << "age" << this->m_Age << endl;
//	}
//	int m_Age;
//};
//void test01() {
//	Person* p = NULL;
//
//	p->showClassName();
//	p->showPersonAge();
//}

// 常函数
//class Person {
//public:
//
//	
//	//this 指针的本质 是指针常量 指针的指向是不可以修改的
//	//在指针函数后面加const 修饰的是this 指向
//	// 让指针指向的值 不可以修改
//	void showPerson() const{
//		//this = NULL;  // this指针  不可以修改指针的指向
//		//this->m_A = 100;
//		this->m_B = 100;
//	}
//	void func() {
//	
//	}
//	int m_A;
//	mutable int m_B;
//};
//void test01() {
//	Person p;
//	p.showPerson();
//}
////常对象 
//void test02() {
//	//常对象 
//	const Person p;
//	//p.m_A = 1;
//	p.m_B = 100; 
//	// 常对象只能调用常函数
//	p.showPerson();
//	p.func();
//
//
//}

////友 元
//class Building {
//
//	friend void gooGay(Building* building);
//public:
//	Building() {
//		m_SittingRoom = "客厅";
//		m_BedRoom = "卧室";
//	}
//public:
//	string m_SittingRoom;// 客厅
//private :
//	string m_BedRoom; // 卧室 
//
//};
//
////全局函数
//
//void gooGay(Building *building) {
//	cout << "好基友的全局函数 正在访问" << building->m_SittingRoom << endl;
//	cout << "好基友的全局函数 正在访问" << building->m_BedRoom << endl;
//
//}
//void test01() {
//	Building building;
//	gooGay(&building);
//}

// 类做友 元
//class Building; 
//class GoodGay {
//public:
//	GoodGay();
//	void visit();// 参观函数 访问Building 中的属性
//	Building * building;
//
//};
//
//class Building {
//	//GoodGay 类是本类的好朋友可以访问类中的私有成员
//	friend class GoodGay;
//public:
//	Building();
//
//public:
//	
//	string m_SittingRoom;// 客厅
//private:
//	string m_BedRoom;// 卧室 
//
//};
//
//// 类外写成员函数
//Building::Building() {
//	m_SittingRoom = "客厅";
//	m_BedRoom = "卧室";
//};
//GoodGay::GoodGay() {
//	//创建建筑物对象
//	buildi/*ng = new Building;
//}
//void GoodGay::visit() {
//	cout << "好基友类正在访问"<<building->m_SittingRoom<<endl;
//	cout << "好基友类正在访问"<<building->m_BedRoom<<endl;
//}
//
//void test01() {
//	GoodGay gg;
//	gg.visit();
//}*/

class Building;
class GoodGay {
public:
	GoodGay();
	void visit();
	void visit2();
	Building* building;

};
class Building {
	friend void GoodGay::visit();
public:
	Building();
public :
	string m_SittingRoom;// 客厅
private:
	string m_BedRoom;// 卧室

};
// 类外实现成员函数
Building::Building() {
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}

GoodGay::GoodGay() {
	building = new Building;
};

void GoodGay::visit() {
	cout << "visit 函数正在访问" << building->m_SittingRoom << endl;
	cout << "visit 函数正在访问" << building->m_BedRoom << endl;
};
void GoodGay::visit2() {
	cout << "visit2 函数正在访问" << building->m_SittingRoom << endl;
	//cout << "visit 函数正在访问" << building->m_BedRoom << endl;

};
void test01() {
	GoodGay gg;
	gg.visit();
	gg.visit2();
};
int main() {
	test01();
	system("pause");
	return 0;
}