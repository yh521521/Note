#include <iostream>
using namespace std;


//��Ա�����ͳ�Ա���� �ֿ��洢

//class Person {
//	
//	int m_A; // �Ǿ�̬��Ա���� ������Ķ����� 
//
//	static int m_B; //��̬��Ա���� ������ �������
//	// �Ǿ�̬��Ա���� �������������
//
//
//	void func() {
//		
//	}
//};
//void test01() {
//	Person p;
//	// �ն���ռ���ڴ�ռ� 1  c++ ���������ÿ���ն������һ���ֽ�
//	//���ֿն���ռ���ڴ��λ��  ÿһ���ն���ҲӦ���ж�һ�޶���λ��
//	cout << "size of p =" << sizeof(p) << endl;
//}


// ������Ƴ�ͻ  ���ض����� * this 
//class Person {
//
//public :
//	Person(int age) {
//		//m_age = age;
//
//		// this ָ��ָ����Ǳ����õĳ�Ա���� �����Ķ���
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
//	//cout << "p1 ������Ϊ" << p1.m_age << endl;
//	cout << "p1 ������Ϊ" << p1.age << endl;
//}
//
//void test02() {
//	Person p1(10);
//	Person p2(10);
//	//p2.PersonAdd(p1);
//	// ��ʽ���˼�� 
//	p2.PersonAdd(p1).PersonAdd(p1).PersonAdd(p1);
//	cout << "p2������Ϊ" << p2.age << endl;
//}

//��ָ�� ���ʳ�Ա���� 
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

// ������
//class Person {
//public:
//
//	
//	//this ָ��ı��� ��ָ�볣�� ָ���ָ���ǲ������޸ĵ�
//	//��ָ�뺯�������const ���ε���this ָ��
//	// ��ָ��ָ���ֵ �������޸�
//	void showPerson() const{
//		//this = NULL;  // thisָ��  �������޸�ָ���ָ��
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
////������ 
//void test02() {
//	//������ 
//	const Person p;
//	//p.m_A = 1;
//	p.m_B = 100; 
//	// ������ֻ�ܵ��ó�����
//	p.showPerson();
//	p.func();
//
//
//}

////�� Ԫ
//class Building {
//
//	friend void gooGay(Building* building);
//public:
//	Building() {
//		m_SittingRoom = "����";
//		m_BedRoom = "����";
//	}
//public:
//	string m_SittingRoom;// ����
//private :
//	string m_BedRoom; // ���� 
//
//};
//
////ȫ�ֺ���
//
//void gooGay(Building *building) {
//	cout << "�û��ѵ�ȫ�ֺ��� ���ڷ���" << building->m_SittingRoom << endl;
//	cout << "�û��ѵ�ȫ�ֺ��� ���ڷ���" << building->m_BedRoom << endl;
//
//}
//void test01() {
//	Building building;
//	gooGay(&building);
//}

// ������ Ԫ
//class Building; 
//class GoodGay {
//public:
//	GoodGay();
//	void visit();// �ιۺ��� ����Building �е�����
//	Building * building;
//
//};
//
//class Building {
//	//GoodGay ���Ǳ���ĺ����ѿ��Է������е�˽�г�Ա
//	friend class GoodGay;
//public:
//	Building();
//
//public:
//	
//	string m_SittingRoom;// ����
//private:
//	string m_BedRoom;// ���� 
//
//};
//
//// ����д��Ա����
//Building::Building() {
//	m_SittingRoom = "����";
//	m_BedRoom = "����";
//};
//GoodGay::GoodGay() {
//	//�������������
//	buildi/*ng = new Building;
//}
//void GoodGay::visit() {
//	cout << "�û��������ڷ���"<<building->m_SittingRoom<<endl;
//	cout << "�û��������ڷ���"<<building->m_BedRoom<<endl;
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
	string m_SittingRoom;// ����
private:
	string m_BedRoom;// ����

};
// ����ʵ�ֳ�Ա����
Building::Building() {
	m_SittingRoom = "����";
	m_BedRoom = "����";
}

GoodGay::GoodGay() {
	building = new Building;
};

void GoodGay::visit() {
	cout << "visit �������ڷ���" << building->m_SittingRoom << endl;
	cout << "visit �������ڷ���" << building->m_BedRoom << endl;
};
void GoodGay::visit2() {
	cout << "visit2 �������ڷ���" << building->m_SittingRoom << endl;
	//cout << "visit �������ڷ���" << building->m_BedRoom << endl;

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