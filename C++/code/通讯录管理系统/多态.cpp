#include <iostream>
using namespace std;

//// 多继承语法
//class Base1 {
//
//public:
//	Base1() {
//		m_A = 100;
//	}
//	int m_A;
//};
//class Base2 {
//
//public:
//	Base2() {
//		m_A = 100;
//	}
//	int m_A;
//};
//
////子类  需要继承base1 和base2
//class Son :public Base1, public Base2 {
//public:
//	Son() {
//		m_C = 333;
//		m_D = 444;
//	}
//	int m_C;
//	int m_D;
//
//};
//void test01() {
//	Son s;
//	cout << "Sizeof son " << sizeof(s) << endl;
//	//当父类中出现同名的成员需要加作用域区分
//	// cout << "m_A " << s.m_A << endl; 报错  二义性 
//	cout << "base1 m_A " << s.Base1::m_A << endl;
//	cout << "base2 m_A " << s.Base2::m_A << endl;
//};

//动物类
//class Animal {
//public:
//	int m_Age;
//
//};
////利用虚继承 解决菱形 继承的问题
////继承之前 加上关键字 virtual 变为虚继承
////Animal  虚基类
//class Sheep :virtual public Animal {
//
//
//};
////驼类
//class Tuo :virtual public Animal {
//
//};
////羊驼类
//class SheepTuo :public Sheep, public Tuo {
//
//
//};
//void test01() {
//	SheepTuo st;
//	st.Sheep::m_Age = 18;
//	st.Tuo::m_Age = 28;
//	cout << "sheep " << st.Sheep::m_Age << endl;
//	cout << "驼 " << st.Tuo::m_Age << endl;
//	cout << "调用 " << st.m_Age << endl;
//	//这份数据我们知道 只需要一分数据就可以 菱形继承导致数据浪费
//}

////多态 
//// 动物类 
//class Animal {
//public:
//	 virtual void  speak() {
//		cout << "动物在说话" << endl;
//
//	}
//};
//
//// 猫类 
//class Cat :public Animal {
//
//	virtual void speak() {
//		cout << "小猫在说话" << endl;
//	}
//};
//class Dog :public Animal {
//public :
//	 void speak(){
//		cout << "小狗在说话" << endl;
//	}
//
//};
////执行说话的函数
////地址早绑定 在编译阶段确定函数地址
////如果像执行让猫说话那魔这个函数地址就不能提前绑定
////需要在运行阶段进行绑定
//void doSpeak(Animal &animal) {
//	animal.speak();
//}
//void test01() {
//	Cat cat;
//	doSpeak(cat);
//	Dog dog;
//	doSpeak(dog);
//};
//void test02() {
//	cout << "sizeof animal " << sizeof(Animal) << endl;
//}
//mao

// 分别利用普通写法和多态技术 实现计算器

//// 普通写法
//class Calculator {
//public:
//
//	int getResult(string oper) {
//		if (oper == "+") {
//			return m_Num1 + m_Num2;
//		}
//		else if (oper == "-") {
//			return m_Num1 - m_Num2;
//		}
//		else if (oper == "*") {
//			return m_Num1 * m_Num2;
//		}
//	}
//	int m_Num1;
//	int m_Num2;
//};
//void test01() {
//	//创建计算器对象
//	Calculator c;
//	c.m_Num1 = 10;
//	c.m_Num2 = 5;
//	cout << c.m_Num1 << "+" << c.m_Num2 << "=" << c.getResult("+") << endl;
//	cout << c.m_Num1 << "-" << c.m_Num2 << "-" << c.getResult("-") << endl;
//	cout << c.m_Num1 << "*" << c.m_Num2 << "*" << c.getResult("*") << endl;
//};
//// 利用多态实现计算器
//// 实现计算器的抽象类 
//class AbstractCalculator {
//public:
//
//	virtual int getResult() {
//		return 0;
//	}
//	int m_Num1;
//	int m_Num2;
//};
////加法计算器
//class AddCalculator :public AbstractCalculator {
//public :
//	int getResult() {
//		return m_Num1 + m_Num2;
//	}
//};
//
////减法法计算器
//class JianCnalculator :public AbstractCalculator {
//public:
//	int getResult() {
//		return m_Num1 - m_Num2;
//	}
//};
////减法法计算器
//class MulCalculator :public AbstractCalculator {
//public:
//	int getResult() {
//		return m_Num1 * m_Num2;
//	}
//};
//void test02() {
//	//多态使用条件 
//	// 父类指针或者引用指向子类对象
//	AbstractCalculator* abc = new AddCalculator;
//	abc->m_Num1 = 10;
//	abc->m_Num2 = 5;
//	cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->getResult()<< endl;
//	
//	delete abc;
//	abc = new JianCnalculator;
//	abc->m_Num1 = 10;
//	abc->m_Num2 = 5;
//	cout << abc->m_Num1 << "-" << abc->m_Num2 << "=" << abc->getResult() << endl;
//
//
//
//}	\

//纯虚函数 和抽象类
//class Base {
//public :
//	//只要有一个纯虚函数 这个类称为抽象类 
//	virtual void func() = 0; // 纯虚函数
//
//};
//
//
//class Son :public Base {
//
//public :
//	virtual void func() {
//		cout << "func 函数调用" << endl;
//	}
//};
//
//
//void test01() {
//	//Base b; // 抽象类无法实例化对象
//	//Son  s;
//	//Son  s; // 子类必须重写父类中的纯虚函数 否则无法实例化
//	Base * base = new Son;
//	base->func();
//
////}


//多态制作饮品 功能
//class AbstractDrinking {
//
//public :
//	//煮水
//	virtual void Boil() = 0;
//	//冲泡 
//	virtual void Brew() = 0;
//	//倒入杯中
//	virtual void PourInCup() = 0;
//	//加入辅料 
//	virtual void PutSomething() = 0;
//
//	//制作饮品
//	void makeDrink() {
//		Boil();
//		Brew();
//		PourInCup();
//		PutSomething();
//	}
//};
////制作咖啡
//
//class Coffee :public  AbstractDrinking {
//
//public :
//	virtual void Boil() {
//		cout << "煮农夫山泉" << endl;
//	}
//	//冲泡 
//	virtual void Brew() {
//		cout << "冲泡咖啡" << endl;
//	}
//	//倒入杯中
//	virtual void PourInCup() {
//		cout << "倒入杯中" << endl;
//	}
//	//加入辅料 
//	virtual void PutSomething() {
//		cout << "加入糖和牛奶" << endl;
//	}
//};
//
//class Tea :public  AbstractDrinking {
//
//public:
//	virtual void Boil() {
//		cout << "煮矿泉水" << endl;
//	}
//	//冲泡 
//	virtual void Brew() {
//		cout << "冲泡茶叶" << endl;
//	}
//	//倒入杯中
//	virtual void PourInCup() {
//		cout << "倒入杯中" << endl;
//	}
//	//加入辅料 
//	virtual void PutSomething() {
//		cout << "加入枸杞" << endl;
//	}
//};
//
//void doWork(AbstractDrinking *abs) {
//	abs->makeDrink();
//	delete  abs;
//}
//void test01() {
//	//制作咖啡
//	doWork(new Coffee);
//	cout << "---------------------" << endl;
//	//制作查野
//	doWork(new Tea);
//	
//	
//}

//虚析构和纯虚函数
//class Animal {
//public:
//	Animal() { 
//		cout << "Animal 构造函数调用" << endl;
//	}
//	// 利用虚析构可以解决父类指针释放子类对象是不干净的问题
//	/*virtual~Animal() {
//		cout << "Animal析构 构造函数调用" << endl;
//	}*/
//
//	// 纯虚析构
//	virtual ~Animal() = 0;
//	virtual void speak() = 0;
//
//};
//Animal ::~Animal() {
//	cout << "Anima纯析构 构造函数调用" << endl;
//}
//
//class Cat :public Animal {
//public:
//	Cat(string name) {
//		cout << "cat 构造函数调用" << endl;
//		m_Name = new string(name);
//	}
//	virtual void speak() {
//		cout <<*m_Name << "小猫在说话" << endl;
// 	}
//	string* m_Name;
//	~Cat() {
//		if (m_Name != NULL) {
//			cout << "cat 析构函数调用" << endl;
//			delete m_Name;
//			m_Name = NULL;
//		}
//	}
//
//};
//void test01() {
//	Animal* animal = new Cat("tom");
//	animal->speak();
//	// 父类指针在析构的时候 不会调用子类中析构函数 导致堆区中友属性 则存在 内存泄漏
//	delete animal;
//}

// 抽象不同零件类 
//抽象cpu 类 
class CPU {
public :
	//抽象的计算函数
	virtual  void calculate() = 0;

};

//抽象显卡 类 
class VideoCard {
public:
	//抽象的计算函数
	virtual  void display() = 0;

};
//抽象内存条类 
class Memory {
public:
	//抽象的计算函数
	virtual  void storage() = 0;

};

class Computer {

public :
	Computer(CPU *cpu ,VideoCard * vc,Memory *mem) {
		
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	void work() {
		//让零件工作起来 调用接口
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();

	}
	~Computer(){
		//释放cpu 
		if (m_cpu != NULL) {
			delete m_cpu;
			m_cpu = NULL;
		}
		//释放显卡
		if (m_vc != NULL) {
			delete m_vc;
			m_vc = NULL;
		}
		//释放内存条
		if (m_mem != NULL) {
			delete m_mem;
			m_mem = NULL;
		}
	}


private :
	CPU* m_cpu;
	VideoCard* m_vc;
	Memory*  m_mem;


};
//具体的厂商
class InterCPU :public CPU {
public:
	virtual void calculate() {
		cout << "Inter 的cpu 开始计算了" << endl;

	}
};

class InterVideoCard :public VideoCard {
public:
	virtual void display() {
		cout << "Inter 的显卡开始显示" << endl;

	}
};

class InterMemory :public Memory {
public:
	virtual void storage() {
		cout << "Inter 的内存条开始存储" << endl;

	}
};


//具体的厂商
class LGCPU :public CPU {
public:
	virtual void calculate() {
		cout << "LG 的cpu 开始计算了" << endl;

	}
};

class LGVideoCard :public VideoCard {
public:
	virtual void display() {
		cout << "LG 的显卡开始显示" << endl;

	}
};

class LGMemory :public Memory {
public:
	virtual void storage() {
		cout << "LG 的内存条开始存储" << endl;

	}
};
void test01() {
	//第一台电脑零件
	
	CPU* interCPU = new InterCPU;
	VideoCard* interVC = new InterVideoCard;
	Memory* interMem = new InterMemory;

	//创建第一台电脑
	Computer* computer1 = new Computer(interCPU, interVC, interMem);
	computer1->work();
	delete computer1;
	

	cout << "第二台电脑开始工作" << endl;
	//创建第一台电脑
	Computer* computer2 = new Computer(new LGCPU, new LGVideoCard, new LGMemory);
	computer2->work();
	delete computer2;

}
int main() {
	test01();
	//test02();


	system("pause");
	return 0;


}
