#include <iostream>
using namespace std;
#include "point.h" 
#include "circle.h" 
//
//class Point {
//public:
//	//set get ����
//	void setX(int x) {
//		m_X = x;
//	}
//	int getX() {
//		return m_X;
//	}
//	void setY(int y) {
//		m_Y = y;
//	}
//	int getY() {
//		return m_Y;
//	}
//	
//private :
//	
//	int m_X;
//	int m_Y;
//
//};



	//set get ����
	void Point::setX(int x) {
		m_X = x;
	}
	int Point::getX() {
		return m_X;
	}
	void Point::setY(int y) {
		m_Y = y;
	}
	int Point::getY() {
		return m_Y;
	}
	





// ���Բ��ϵ����
//Բ�� 
//class Circle {
//public:
//	void setR(int r) {
//		m_R = r;
//	}
//	int getR() {
//		return m_R;
//	}
//
//	void setCenter(Point center ) {
//		m_Center = center;
//	}
//	Point getCenter() {
//		return m_Center;
//	}
//private:
//	int m_R;
//	Point m_Center;
//};



	void Circle::setR(int r) {
		m_R = r;
	}
	int  Circle::getR() {
		return m_R;
	}

	void  Circle::setCenter(Point center) {
		m_Center = center;
	}
	Point  Circle::getCenter() {
		return m_Center;
	}

//�жϵ��Բ�Ĺ�ϵ
void isInCircle(Circle &c ,Point &p) {
	// ����֮������ƽ�� 
	int dist = (c.getCenter().getX() - p.getX())* (c.getCenter().getX() - p.getX()) + (c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
	//�뾶��ƽ��
	int rDistance = c.getR() * c.getR();
	if (dist==rDistance) {
		cout << "����Բ��" << endl;
	}
	else if (dist > rDistance) {
		cout << "����Բ��" << endl;
	}
	else {
		cout << "����Բ��" << endl;
	}
}

//����һ��ѧ����
//class Student {
//
//	//Ȩ��
//public:
//	//��������
//	string m_Name;//����
//	int m_Id;//ѧ��
//	//
//
//	//����
//	void showStudent() {
//		cout << "����" << m_Name << "ѧ��" << m_Id << endl;
//	}
//
//	//��������ֵ
//	void setName(string name) {
//
//		m_Name = name;
//	
//	}
//	//��ѧ�Ÿ�ֵ
//	void setId(int id) {
//		m_Id = id;
//	}
//};

//
////����Ȩ�� public private protected
//class Person {
//public:
//	string m_Name;//
//protected:
//	string m_Car;
//private :
//	int m_Password;
//
//public:
//	void func() {
//		m_Name = "����";
//		m_Car = "������";
//		m_Password = 123456;
//	}
//};
////struct Ĭ��Ȩ����public classĬ��Ȩ����˽��private 
//
//class C1 {
//
//	int m_A;//Ĭ��Ȩ����˽��
//};
//
//struct C2 {
//
//	int m_A; //Ĭ��Ȩ�� ����
//};
//
////��Ա��������λ˽��  ���ƶ�дȨ�� 
//class  Person1 {
//
//public :
//	void setName(string name) {
//		m_Name = name;
//		
//	}
//	//��ȡ����
//	string getName() {
//		return m_Name;
//	}
//
//private :
//	string m_Name;
//	int m_Age;
//	string m_Lover;
//};
//
//
//
//class Person11 {
//public :
//	//��������
//	void setName(string name) {
//		m_Name = name;
//	}
//	//��ȡ����
//	string getName() {
//		return m_Name;
//	}
//
//	int getAge() {
//		//m_Age = 0;
//		return m_Age;
//	}
//	void setAge(int age) {
//		
//		if (age <0 || age > 150) {
//			cout << "�����������" << endl;
//			return;
//		}
//		m_Age = age;
//	}
//
//
//	void  setLover(string lover) {
//		m_Lover = lover;
//	}
//private:
//	string m_Name;
//	int m_Age;
//	string m_Lover;
//};


// �����������
// ������������ 
// ������Ժ���Ϊ
//
//class Cube {
//
//public:
//	void setL(int l) {
//		m_L = l;
//	}
//	int getL() {
//		return m_L;
//	}
//
//	void setW(int w) {
//		m_W = w;
//	}
//	int getW() {
//		return m_W;
//	}
//	void setH(int h) {
//		m_H = h;
//	}
//	int getH() {
//		return m_H;
//	}
//
//	//��ȡ���
//	int getMianJi() {
//		return 2*(m_L * m_W + m_L * m_H + m_W * m_H);
//	}
//
//	//��ȡ���
//	int getTiJi() {
//		return m_L * m_W * m_H;
//	}
//
//	//���ó�Ա���� �ж����������� �Ƿ����
//	bool isSameByClass(Cube &c) {
//		if (m_L == c.getL() && m_W == c.getW() && m_H == c.getH()) {
//			return true;
//		}
//		return false;
//	}
//	
//private:
//	int m_L;
//	int m_W;
//	int m_H;
//
//	
//};
////����ȫ�ֺ��� �ж����������� �Ƿ����
//bool isSame(Cube &c1 ,Cube &c2) {
//	if (c1.getL() == c2.getL()&& c1.getW() == c2.getW()&& c1.getH() == c2.getH()) {
//		return true;
//	}
//	return false;
//}
////

int main() {

	//����Բ
	Circle c;
	c.setR(10);
	//Բ�� 
	Point center;
	center.setX(10);
	center.setY(0);
	c.setCenter(center);

	//������
	Point p;
	
	p.setX(10);
	p.setY(9);
	//�жϹ�ϵ
	isInCircle(c, p);


	////�������������
	//Cube c1;
	//c1.setL(2);
	//c1.setW(2);
	//c1.setH(2);
	//cout << "���" << c1.getMianJi() << endl;
	//cout << "���" << c1.getTiJi() << endl;
	////�����ڶ���������
	//Cube c2;
	//c2.setL(2);
	//c2.setW(2);
	//c2.setH(2);

	//bool result = isSame(c1, c2);
	//if (result) {
	//	cout << "c1 ��c2 ���"<<endl;
	//}
	//else {
	//	cout << "c1 ��c2 �� ���" << endl;
	//}

	//bool res = c1.isSameByClass(c2);
	//if (res) {
	//	cout << "c1 ��c2 ���" << endl;
	//}
	//else {
	//	cout << "c1 ��c2 �� ���" << endl;
	//}

	//Person11 p11;
	//p11.setName("Ԭ��111");
	//cout << "����Ϊ"<<p11.getName()<<endl;
	//p11.setAge(100);
	//cout << "��������Ϊ" <<p11.getAge()<< endl;
	//p11.setLover("����ʦ");
	//
	////Person1 p1;
	////p1.setName("����");
	////C1 c1;
	

	/*C2 c2;
	c2.m_A = 100;*/
	//ʵ��������
//	Person p1;
	//p1.m_Name = "����";
	//p1.func();

	////����һ�������ѧ�� ,ʵ��������
	//Student s1;

	////��s1 ����������Ը�ֵ����
	//s1.m_Name = "Ԭ��";
	//s1.m_Id = 1;
	//s1.showStudent();

	//Student s2;
	//	s2.setName("����");
	//	//s2.m_Id = 2;
	//	s2.setId(33);
	//	s2.showStudent();

	////��������ֵ

}