#include <iostream>
using namespace std;

//// ��̳��﷨
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
////����  ��Ҫ�̳�base1 ��base2
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
//	//�������г���ͬ���ĳ�Ա��Ҫ������������
//	// cout << "m_A " << s.m_A << endl; ����  ������ 
//	cout << "base1 m_A " << s.Base1::m_A << endl;
//	cout << "base2 m_A " << s.Base2::m_A << endl;
//};

//������
//class Animal {
//public:
//	int m_Age;
//
//};
////������̳� ������� �̳е�����
////�̳�֮ǰ ���Ϲؼ��� virtual ��Ϊ��̳�
////Animal  �����
//class Sheep :virtual public Animal {
//
//
//};
////����
//class Tuo :virtual public Animal {
//
//};
////������
//class SheepTuo :public Sheep, public Tuo {
//
//
//};
//void test01() {
//	SheepTuo st;
//	st.Sheep::m_Age = 18;
//	st.Tuo::m_Age = 28;
//	cout << "sheep " << st.Sheep::m_Age << endl;
//	cout << "�� " << st.Tuo::m_Age << endl;
//	cout << "���� " << st.m_Age << endl;
//	//�����������֪�� ֻ��Ҫһ�����ݾͿ��� ���μ̳е��������˷�
//}

////��̬ 
//// ������ 
//class Animal {
//public:
//	 virtual void  speak() {
//		cout << "������˵��" << endl;
//
//	}
//};
//
//// è�� 
//class Cat :public Animal {
//
//	virtual void speak() {
//		cout << "Сè��˵��" << endl;
//	}
//};
//class Dog :public Animal {
//public :
//	 void speak(){
//		cout << "С����˵��" << endl;
//	}
//
//};
////ִ��˵���ĺ���
////��ַ��� �ڱ���׶�ȷ��������ַ
////�����ִ����è˵����ħ���������ַ�Ͳ�����ǰ��
////��Ҫ�����н׶ν��а�
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

// �ֱ�������ͨд���Ͷ�̬���� ʵ�ּ�����

//// ��ͨд��
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
//	//��������������
//	Calculator c;
//	c.m_Num1 = 10;
//	c.m_Num2 = 5;
//	cout << c.m_Num1 << "+" << c.m_Num2 << "=" << c.getResult("+") << endl;
//	cout << c.m_Num1 << "-" << c.m_Num2 << "-" << c.getResult("-") << endl;
//	cout << c.m_Num1 << "*" << c.m_Num2 << "*" << c.getResult("*") << endl;
//};
//// ���ö�̬ʵ�ּ�����
//// ʵ�ּ������ĳ����� 
//class AbstractCalculator {
//public:
//
//	virtual int getResult() {
//		return 0;
//	}
//	int m_Num1;
//	int m_Num2;
//};
////�ӷ�������
//class AddCalculator :public AbstractCalculator {
//public :
//	int getResult() {
//		return m_Num1 + m_Num2;
//	}
//};
//
////������������
//class JianCnalculator :public AbstractCalculator {
//public:
//	int getResult() {
//		return m_Num1 - m_Num2;
//	}
//};
////������������
//class MulCalculator :public AbstractCalculator {
//public:
//	int getResult() {
//		return m_Num1 * m_Num2;
//	}
//};
//void test02() {
//	//��̬ʹ������ 
//	// ����ָ���������ָ���������
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

//���麯�� �ͳ�����
//class Base {
//public :
//	//ֻҪ��һ�����麯�� ������Ϊ������ 
//	virtual void func() = 0; // ���麯��
//
//};
//
//
//class Son :public Base {
//
//public :
//	virtual void func() {
//		cout << "func ��������" << endl;
//	}
//};
//
//
//void test01() {
//	//Base b; // �������޷�ʵ��������
//	//Son  s;
//	//Son  s; // ���������д�����еĴ��麯�� �����޷�ʵ����
//	Base * base = new Son;
//	base->func();
//
////}


//��̬������Ʒ ����
//class AbstractDrinking {
//
//public :
//	//��ˮ
//	virtual void Boil() = 0;
//	//���� 
//	virtual void Brew() = 0;
//	//���뱭��
//	virtual void PourInCup() = 0;
//	//���븨�� 
//	virtual void PutSomething() = 0;
//
//	//������Ʒ
//	void makeDrink() {
//		Boil();
//		Brew();
//		PourInCup();
//		PutSomething();
//	}
//};
////��������
//
//class Coffee :public  AbstractDrinking {
//
//public :
//	virtual void Boil() {
//		cout << "��ũ��ɽȪ" << endl;
//	}
//	//���� 
//	virtual void Brew() {
//		cout << "���ݿ���" << endl;
//	}
//	//���뱭��
//	virtual void PourInCup() {
//		cout << "���뱭��" << endl;
//	}
//	//���븨�� 
//	virtual void PutSomething() {
//		cout << "�����Ǻ�ţ��" << endl;
//	}
//};
//
//class Tea :public  AbstractDrinking {
//
//public:
//	virtual void Boil() {
//		cout << "���Ȫˮ" << endl;
//	}
//	//���� 
//	virtual void Brew() {
//		cout << "���ݲ�Ҷ" << endl;
//	}
//	//���뱭��
//	virtual void PourInCup() {
//		cout << "���뱭��" << endl;
//	}
//	//���븨�� 
//	virtual void PutSomething() {
//		cout << "�������" << endl;
//	}
//};
//
//void doWork(AbstractDrinking *abs) {
//	abs->makeDrink();
//	delete  abs;
//}
//void test01() {
//	//��������
//	doWork(new Coffee);
//	cout << "---------------------" << endl;
//	//������Ұ
//	doWork(new Tea);
//	
//	
//}

//�������ʹ��麯��
//class Animal {
//public:
//	Animal() { 
//		cout << "Animal ���캯������" << endl;
//	}
//	// �������������Խ������ָ���ͷ���������ǲ��ɾ�������
//	/*virtual~Animal() {
//		cout << "Animal���� ���캯������" << endl;
//	}*/
//
//	// ��������
//	virtual ~Animal() = 0;
//	virtual void speak() = 0;
//
//};
//Animal ::~Animal() {
//	cout << "Anima������ ���캯������" << endl;
//}
//
//class Cat :public Animal {
//public:
//	Cat(string name) {
//		cout << "cat ���캯������" << endl;
//		m_Name = new string(name);
//	}
//	virtual void speak() {
//		cout <<*m_Name << "Сè��˵��" << endl;
// 	}
//	string* m_Name;
//	~Cat() {
//		if (m_Name != NULL) {
//			cout << "cat ������������" << endl;
//			delete m_Name;
//			m_Name = NULL;
//		}
//	}
//
//};
//void test01() {
//	Animal* animal = new Cat("tom");
//	animal->speak();
//	// ����ָ����������ʱ�� ��������������������� ���¶����������� ����� �ڴ�й©
//	delete animal;
//}

// ����ͬ����� 
//����cpu �� 
class CPU {
public :
	//����ļ��㺯��
	virtual  void calculate() = 0;

};

//�����Կ� �� 
class VideoCard {
public:
	//����ļ��㺯��
	virtual  void display() = 0;

};
//�����ڴ����� 
class Memory {
public:
	//����ļ��㺯��
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
		//������������� ���ýӿ�
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();

	}
	~Computer(){
		//�ͷ�cpu 
		if (m_cpu != NULL) {
			delete m_cpu;
			m_cpu = NULL;
		}
		//�ͷ��Կ�
		if (m_vc != NULL) {
			delete m_vc;
			m_vc = NULL;
		}
		//�ͷ��ڴ���
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
//����ĳ���
class InterCPU :public CPU {
public:
	virtual void calculate() {
		cout << "Inter ��cpu ��ʼ������" << endl;

	}
};

class InterVideoCard :public VideoCard {
public:
	virtual void display() {
		cout << "Inter ���Կ���ʼ��ʾ" << endl;

	}
};

class InterMemory :public Memory {
public:
	virtual void storage() {
		cout << "Inter ���ڴ�����ʼ�洢" << endl;

	}
};


//����ĳ���
class LGCPU :public CPU {
public:
	virtual void calculate() {
		cout << "LG ��cpu ��ʼ������" << endl;

	}
};

class LGVideoCard :public VideoCard {
public:
	virtual void display() {
		cout << "LG ���Կ���ʼ��ʾ" << endl;

	}
};

class LGMemory :public Memory {
public:
	virtual void storage() {
		cout << "LG ���ڴ�����ʼ�洢" << endl;

	}
};
void test01() {
	//��һ̨�������
	
	CPU* interCPU = new InterCPU;
	VideoCard* interVC = new InterVideoCard;
	Memory* interMem = new InterMemory;

	//������һ̨����
	Computer* computer1 = new Computer(interCPU, interVC, interMem);
	computer1->work();
	delete computer1;
	

	cout << "�ڶ�̨���Կ�ʼ����" << endl;
	//������һ̨����
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
