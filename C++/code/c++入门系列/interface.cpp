#include<iostream>
#include <fstream>
#include<exception>
#include<string>
#include <cstdlib>
#include<stdexcept>
#include<vector>
using namespace std;

//���� 
//class Shape {
//	public:
//		//�ṩ�ӿڿ�ܵĴ��麯��
//		virtual int getArea() = 0;
//		void setWidth(int w) {
//			width = w;
//
//		}
//		void setHeight(int h) {
//			height = h;
//		}
//	protected:
//		int width;
//		int height;
//};
//// ������
//class Rectangle : public Shape {
//	public:
//		int getArea() {
//			return (width * height);
//
//		}
//
//};
//
//// ������
//class Triangle : public Shape {
//public:
//	int getArea() {
//		return (width * height)/2;
//
//	}
//
//};
//
//int main() {
//	Rectangle rect;
//	Triangle tri;
//
//	rect.setWidth(5);
//	rect.setHeight(7);
//
//	//����������� 
//	cout << "Total Rectangle area: " << rect.getArea() << endl;
//	
//	tri.setWidth(5);
//	tri.setHeight(7);
//
//	//����������� 
//	cout << "Total Triangle  area: " << tri.getArea() << endl;
//	return 0;
//
//}

//int main() {
//	char data[100];
//
//	//��дģʽ���ļ�
//	ofstream outfile;
//	outfile.open("G:/AiDataSet/test.txt");
//	cout << "writing to the file " << endl;
//	cout << "Enter your name;";
//	cin.getline(data, 100);
//	//���ļ�д���û����������
//	outfile << data << endl;
//
//	cout << "Enter your age ";
//	cin >> data;
//	cin.ignore();
//
//	//�ٴ����ļ�д���û����������
//	outfile << data << endl;	
//	//�رմ򿪵��ļ�
//	outfile.close();
//	//�Զ�ģʽ���ļ�
//	ifstream infile;
//	infile.open("G:/AiDataSet/test.txt");
//
//	cout << "reading from the file" << endl;
//
//	infile >> data;
//
//	//����Ļ��д������
//	cout << data << endl;
//	// �ٴδ��ļ���ȡ����  ����ʾ�� 
//	infile >> data;
//	cout << data << endl;
//
//	//�رմ򿪵��ļ�
//	infile.close();
//
//	return  0;
//
//}

//�쳣 
//double division(int a, int b) {
//	if (b== 0) {
//		throw "Division by zero condition ";
//	}
//	return a / b;
//}
//
//int main() {
//	
//	int x = 50;
//	int y = 0;
//	double z = 0;
//	try {
//		z = division(x, y);
//		cout << z << endl;
//	}
//	catch (const char*  msg) {
//		cerr << msg << endl;
//	}
//
//	return 0;
//}


//����ṹ������
//struct MyException: public exception{
//	const char* what() const throw() {
//	return "C++ Exception";
//}
//
//};
//
//int main() {
//	try {
//		throw MyException();
//	}
//	catch (MyException& e) {
//		std::cout << "MyException caught" << std::endl;
//		std::cout << e.what() << std::endl;
//
//	}
//	catch (std:: exception& e) {
//		//��������
//	}
//}
//
//int main() {
//	//��ʼ��Ϊnull ��ָ��
//	double* pvalue = NULL;
//	//�����������ڴ�
//	pvalue = new double; 
//	// ����ĵ�ַ�洢ֵ 
//	*pvalue = 2949.99;
//	cout << "Value of pvalue" << *pvalue << endl;
//	//�ͷ��ڴ�
//	delete pvalue;
//	return 0;
//
//}

//����Ķ�̬�ڴ����

//class Box {
//
//
//	public :
//		Box() {
//			cout << "���ù��캯��" << endl;
//
//		}
//		~Box() {
//			cout << "������������" << endl;
//		}
//};
//
//int main() {
//	Box* myBoxArray = new Box[4];
//
//	//ɾ������
//	delete[]myBoxArray;
//	return 0;
//}

//�Զ���һ�������ռ�
//namespace first_space {
//	void func() {
//		cout << " ��һ�������ռ�" << endl;
//	}
//}
//namespace second_space {
//	void func() {
//		cout << " �ڶ��������ռ�" << endl;
//	}
//}
// Ƕ�������ռ�
//namespace first_space {
//	void func() {
//		cout << " ��һ�������ռ�" << endl;
//	}
//	namespace second_space {
//		void func() {
//			cout << " �ڶ��������ռ�" << endl;
//		}
//}
//
//}
//
////using namespace first_space;
//using namespace first_space::second_space;
//using std::cout;
////using ָ��Ҳ��������ָ�������ռ��е��ض���Ŀ�����磬
////�����ֻ����ʹ�� std �����ռ��е� cout ���֣�������ʹ�����µ���䣺
//int main() {
//	//// ���õ�һ�������ռ�ĺ���
//	//first_space::func();
//	////���õڶ��������ռ�ĺ���
//	//second_space:: func();
//
//	func();
//	cout << "��std  ��cout ���� " << std::endl;
//
//
//	// Ƕ�׵������ռ�
//
//	return 0;
//}

// ����ģ�� 
//template <typename T>
//
//inline T const& Max(T const& a, T const& b) {
//	return a < b ? b : a;
//}
//
//int main() {
//	
//	int i = 30;
//	int j = 21;
//	cout << "Max (i,j):" << Max(i, j) << endl;
//
//	double f1 = 13.5;
//	double f2 = 23.5;
//
//	cout << "Max (f1,f2):" << Max(f1, f2) << endl;
//
//	string s1 = "Hello";
//	string s2 = "world";
//	cout << "Max (s1,s2):" << Max(s1, s2) << endl;
//}


template <class T>
class Stack {

    private:
	    vector<T> elems;//Ԫ��
    public:
        void push(T const&);// ��ջ 
		void pop();//��ջ
	T top() const;// ����ջ��Ԫ��
	bool empty() const {
		return elems.empty();
	}
};

template <class T>
void Stack<T>::push(T const& elem)
{
    // ׷�Ӵ���Ԫ�صĸ���
    elems.push_back(elem);
};


template <class T>

void Stack<T>::pop()
{
    if (elems.empty()) {
        throw out_of_range("Stack<>::pop(): empty stack");
    }
    // ɾ�����һ��Ԫ��
    elems.pop_back();
}

template <class T>
T Stack<T>::top() const
{
    if (elems.empty()) {
        throw out_of_range("Stack<>::top(): empty stack");
    }
    // �������һ��Ԫ�صĸ��� 
    return elems.back();
};
int main() {

    try {
        Stack<int> intStack; // int �͵�ջ
        Stack<string> stringStack;//string �͵�ջ 
        //����int ���͵�ջ 
        intStack.push(7);
        cout << intStack.top() << endl;

        //����string �͵�ջ 
        stringStack.push("hello");
        cout << stringStack.top() << std::endl;
        stringStack.pop();
        stringStack.pop();
    }
    catch (exception const& ex) {
        cerr << "Exception:" << ex.what() << endl;
        return -1;
    }
}
