#include <iostream>
using namespace std;
#include "point.h" 
#include "circle.h" 
//
//class Point {
//public:
//	//set get 方法
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



	//set get 方法
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
	





// 点和圆关系案例
//圆类 
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

//判断点和圆的关系
void isInCircle(Circle &c ,Point &p) {
	// 两点之间距离的平方 
	int dist = (c.getCenter().getX() - p.getX())* (c.getCenter().getX() - p.getX()) + (c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
	//半径的平方
	int rDistance = c.getR() * c.getR();
	if (dist==rDistance) {
		cout << "点在圆上" << endl;
	}
	else if (dist > rDistance) {
		cout << "点在圆外" << endl;
	}
	else {
		cout << "点在圆内" << endl;
	}
}

//定义一个学生类
//class Student {
//
//	//权限
//public:
//	//公共属性
//	string m_Name;//姓名
//	int m_Id;//学号
//	//
//
//	//方法
//	void showStudent() {
//		cout << "姓名" << m_Name << "学号" << m_Id << endl;
//	}
//
//	//给姓名赋值
//	void setName(string name) {
//
//		m_Name = name;
//	
//	}
//	//给学号赋值
//	void setId(int id) {
//		m_Id = id;
//	}
//};

//
////访问权限 public private protected
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
//		m_Name = "张三";
//		m_Car = "拖拉机";
//		m_Password = 123456;
//	}
//};
////struct 默认权限是public class默认权限是私有private 
//
//class C1 {
//
//	int m_A;//默认权限是私有
//};
//
//struct C2 {
//
//	int m_A; //默认权限 公有
//};
//
////成员属性设置位私有  控制读写权限 
//class  Person1 {
//
//public :
//	void setName(string name) {
//		m_Name = name;
//		
//	}
//	//获取姓名
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
//	//设置姓名
//	void setName(string name) {
//		m_Name = name;
//	}
//	//获取姓名
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
//			cout << "你这个老妖精" << endl;
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


// 立方体类设计
// 创建立方体类 
// 设计属性和行为
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
//	//获取面机
//	int getMianJi() {
//		return 2*(m_L * m_W + m_L * m_H + m_W * m_H);
//	}
//
//	//获取体积
//	int getTiJi() {
//		return m_L * m_W * m_H;
//	}
//
//	//利用成员函数 判断两个立方体 是否相等
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
////利用全局函数 判断两个立方体 是否相等
//bool isSame(Cube &c1 ,Cube &c2) {
//	if (c1.getL() == c2.getL()&& c1.getW() == c2.getW()&& c1.getH() == c2.getH()) {
//		return true;
//	}
//	return false;
//}
////

int main() {

	//创建圆
	Circle c;
	c.setR(10);
	//圆心 
	Point center;
	center.setX(10);
	center.setY(0);
	c.setCenter(center);

	//创建点
	Point p;
	
	p.setX(10);
	p.setY(9);
	//判断关系
	isInCircle(c, p);


	////创建立方体对象
	//Cube c1;
	//c1.setL(2);
	//c1.setW(2);
	//c1.setH(2);
	//cout << "面积" << c1.getMianJi() << endl;
	//cout << "体积" << c1.getTiJi() << endl;
	////创建第二个立方体
	//Cube c2;
	//c2.setL(2);
	//c2.setW(2);
	//c2.setH(2);

	//bool result = isSame(c1, c2);
	//if (result) {
	//	cout << "c1 和c2 相等"<<endl;
	//}
	//else {
	//	cout << "c1 和c2 不 相等" << endl;
	//}

	//bool res = c1.isSameByClass(c2);
	//if (res) {
	//	cout << "c1 和c2 相等" << endl;
	//}
	//else {
	//	cout << "c1 和c2 不 相等" << endl;
	//}

	//Person11 p11;
	//p11.setName("袁航111");
	//cout << "姓名为"<<p11.getName()<<endl;
	//p11.setAge(100);
	//cout << "读到年龄为" <<p11.getAge()<< endl;
	//p11.setLover("苍老师");
	//
	////Person1 p1;
	////p1.setName("张三");
	////C1 c1;
	

	/*C2 c2;
	c2.m_A = 100;*/
	//实例化对象
//	Person p1;
	//p1.m_Name = "王五";
	//p1.func();

	////创建一个具体的学生 ,实例化对象
	//Student s1;

	////给s1 对象进行属性赋值操作
	//s1.m_Name = "袁航";
	//s1.m_Id = 1;
	//s1.showStudent();

	//Student s2;
	//	s2.setName("李四");
	//	//s2.m_Id = 2;
	//	s2.setId(33);
	//	s2.showStudent();

	////给姓名赋值

}