// ͷ�ļ�
#include<iostream>
#include <cstring>
using namespace std;
//// ��������
//void printBook(struct Books  *book);
//// ����һ���ṹ������
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
//	Books Book1;// ����ṹ������Books �ı���Book1 
//
//	//Book1 ���� 
//	strcpy(Book1.title, "css�̳�");
//	strcpy(Book1.author, "Runoob");
//	strcpy(Book1.subject, "�������");
//	Book1.book_id = 12345;
//	//���Book1 ��Ϣ
//	//cout << "��һ�������" << Book1.title << endl;
//	//cout << "��һ��������" << Book1.author<< endl;
//	//cout << "��һ������Ŀ" << Book1.subject << endl;
//	//cout << "��һ����ID" << Book1.book_id << endl;
//	printBook(&Book1);
//
//	return 0;
//}
//
//void printBook(struct Books *book ) {
//	cout << "�����" << book->title << endl;
//	cout << "������" << book->author << endl;
//	cout << "����Ŀ" << book->subject << endl;
//	cout << "��ID" << book->book_id << endl;

//����һ����  public ���java  ��ķ������� 
//class  Box {
//
//public:
//	double length; // ����
//	double wideth;//���
//	double height; //�߶�
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
//// ����������
//class printData {
//	public:
//		void print(int i) {
//			cout << "����λ" << i << endl;
//		}
//		void print(double f) {
//			cout << "������" << f << endl;
//		}
//		void print(char c[]) {
//			cout << "�ַ���Ϊ" << c << endl;
//		}
//};
//int main( ) {
//
//	//Box box1; //�������� box1 ����ΪBox 
//	//double volume = 0.0;
//	////���ò���
//	//box1.height = 5.0;
//	//box1.length = 6.0;
//	//box1.wideth = 7.0;
//
//	//// �����
//	//volume = box1.height * box1.length * box1.wideth;
//	//cout << "���Ϊ:" << volume << endl;
//
//
//	//           �̳� 
//	Rectangle rect;
//	int area;
//	rect.setWidth(5);
//	rect.setHeight(7);
//	area = rect.getArea();
//	//�����������
//	cout << "total area : " << rect.getArea() << endl;
//	//����ܻ���
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
////main ���� 
//int main() {
//	Shape  *shape;
//	Rectangle rec(10, 7);
//	Triangle   tri(10, 5);
//	// �洢���εĵ�ַ
//	shape = &rec;
//	//���þ��е���������� area 
//	shape->area();
//
//
//	// �洢�����εĵ�ַ
//	shape = &tri;
//	//�����������ε����������area
//	shape->area();
//	
//	return 0;
//}


// ���ݵĳ���
class Adder{
	public:
	//���캯��
		Adder(int i = 0) {
			total = i;

		}
		//����Ļ���
		void  addNum(int number) {
			total += number;
		}
		//����Ľӿ�
		int getTotal() {
			return total;
		}
	private:
		//�������ص�����
		int total;
};
// main ���

int main() {
	Adder a;
	a.addNum(10);
	a.addNum(20);
	a.addNum(330);
	cout << "total " << a.getTotal() << endl;
	return 0;
}


