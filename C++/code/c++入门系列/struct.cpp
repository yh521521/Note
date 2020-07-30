// 头文件
#include<iostream>
#include <cstring>
using namespace std;
//// 声明函数
//void printBook(struct Books  *book);
//// 声明一个结构体类型
//struct Books {
//	char title[50];
//	char author[50];
//	char subject[100];
//	int book_id;
//};
//
//
//int main() {
//
//	Books Book1;// 定义结构体类型Books 的变量Book1 
//
//	//Book1 详述 
//	strcpy(Book1.title, "css教程");
//	strcpy(Book1.author, "Runoob");
//	strcpy(Book1.subject, "编程语言");
//	Book1.book_id = 12345;
//	//输出Book1 信息
//	//cout << "第一本书标题" << Book1.title << endl;
//	//cout << "第一本书作者" << Book1.author<< endl;
//	//cout << "第一本书类目" << Book1.subject << endl;
//	//cout << "第一本书ID" << Book1.book_id << endl;
//	printBook(&Book1);
//
//	return 0;
//}
//
//void printBook(struct Books *book ) {
//	cout << "书标题" << book->title << endl;
//	cout << "书作者" << book->author << endl;
//	cout << "书类目" << book->subject << endl;
//	cout << "书ID" << book->book_id << endl;

//定义一个类  public 类比java  类的访问属性 
//class  Box {
//
//public:
//	double length; // 长度
//	double wideth;//宽度
//	double height; //高度
//
//};


//class Shape {
//
//public:
//	void setWidth(int w) {
//		width = w;
//	}
//	void setHeight(int h) {
//		height = h;
//	}
//protected:
//	int width;
//	int height;
//
//};
//
//class PaintCost {
//	public:
//		int getCost(int area) {
//			return area * 70;
//		}
//};
//class Rectangle : public Shape ,public PaintCost{
//
//public:
//	int getArea() {
//		return width * height;
//
//
//	}
//
//};
//
//
//// 函数的重载
//class printData {
//	public:
//		void print(int i) {
//			cout << "整数位" << i << endl;
//		}
//		void print(double f) {
//			cout << "浮点数" << f << endl;
//		}
//		void print(char c[]) {
//			cout << "字符串为" << c << endl;
//		}
//};
//int main( ) {
//
//	//Box box1; //声明变量 box1 类型为Box 
//	//double volume = 0.0;
//	////设置参数
//	//box1.height = 5.0;
//	//box1.length = 6.0;
//	//box1.wideth = 7.0;
//
//	//// 求体积
//	//volume = box1.height * box1.length * box1.wideth;
//	//cout << "体积为:" << volume << endl;
//
//
//	//           继承 
//	Rectangle rect;
//	int area;
//	rect.setWidth(5);
//	rect.setHeight(7);
//	area = rect.getArea();
//	//输出对象的面机
//	cout << "total area : " << rect.getArea() << endl;
//	//输出总花费
//	cout << "total cost : " << rect.getCost(area) << endl;
//
//	printData pd;
//	pd.print(5);
//	pd.print(5.233);
//	char c[] = " hello c++";
//	pd.print(c);
//
//
//
//	return 0;
//	
//}

//class Shape {
//	protected:
//		int width, height;
//	public:
//		Shape(int a = 0, int b = 0) {
//			width = a;
//			height = b;
//		}
//
//		virtual int area() {
//			cout << "Parent class area :" << endl;
//			return 0;
//		}
//};
//
//class Rectangle : public Shape {
//		public:
//			Rectangle(int a = 0, int b = 0) :Shape(a, b) {}
//			int area() {
//				cout << "Rectangle class area" << endl;
//				return (width * height);
//			}
//};
//class Triangle :public Shape {
//	public:
//		Triangle(int a = 0, int b = 0) :Shape(a, b) {}
//		int area()
//		{
//			cout << "Triangle class area :" << endl;
//			return (width * height / 2);
//		}
//};
////main 函数 
//int main() {
//	Shape  *shape;
//	Rectangle rec(10, 7);
//	Triangle   tri(10, 5);
//	// 存储矩形的地址
//	shape = &rec;
//	//调用举行的求面积函数 area 
//	shape->area();
//
//
//	// 存储三角形的地址
//	shape = &tri;
//	//调用求三角形的求面积函数area
//	shape->area();
//	
//	return 0;
//}


// 数据的抽象
class Adder{
	public:
	//构造函数
		Adder(int i = 0) {
			total = i;

		}
		//对外的机狗
		void  addNum(int number) {
			total += number;
		}
		//对外的接口
		int getTotal() {
			return total;
		}
	private:
		//对外隐藏的数据
		int total;
};
// main 入口

int main() {
	Adder a;
	a.addNum(10);
	a.addNum(20);
	a.addNum(330);
	cout << "total " << a.getTotal() << endl;
	return 0;
}


