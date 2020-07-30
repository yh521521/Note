#include<iostream>
#include <fstream>
#include<exception>
#include<string>
#include <cstdlib>
#include<stdexcept>
#include<vector>
using namespace std;

//基类 
//class Shape {
//	public:
//		//提供接口框架的纯虚函数
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
//// 派生类
//class Rectangle : public Shape {
//	public:
//		int getArea() {
//			return (width * height);
//
//		}
//
//};
//
//// 派生类
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
//	//输出对象的面积 
//	cout << "Total Rectangle area: " << rect.getArea() << endl;
//	
//	tri.setWidth(5);
//	tri.setHeight(7);
//
//	//输出对象的面积 
//	cout << "Total Triangle  area: " << tri.getArea() << endl;
//	return 0;
//
//}

//int main() {
//	char data[100];
//
//	//以写模式打开文件
//	ofstream outfile;
//	outfile.open("G:/AiDataSet/test.txt");
//	cout << "writing to the file " << endl;
//	cout << "Enter your name;";
//	cin.getline(data, 100);
//	//像文件写入用户输入的数据
//	outfile << data << endl;
//
//	cout << "Enter your age ";
//	cin >> data;
//	cin.ignore();
//
//	//再次向文件写入用户输入的数据
//	outfile << data << endl;	
//	//关闭打开的文件
//	outfile.close();
//	//以读模式打开文件
//	ifstream infile;
//	infile.open("G:/AiDataSet/test.txt");
//
//	cout << "reading from the file" << endl;
//
//	infile >> data;
//
//	//在屏幕上写入数据
//	cout << data << endl;
//	// 再次从文件读取数据  并显示它 
//	infile >> data;
//	cout << data << endl;
//
//	//关闭打开的文件
//	infile.close();
//
//	return  0;
//
//}

//异常 
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


//定义结构体类型
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
//		//其它错误
//	}
//}
//
//int main() {
//	//初始化为null 的指针
//	double* pvalue = NULL;
//	//给变量请求内存
//	pvalue = new double; 
//	// 分配的地址存储值 
//	*pvalue = 2949.99;
//	cout << "Value of pvalue" << *pvalue << endl;
//	//释放内存
//	delete pvalue;
//	return 0;
//
//}

//对象的动态内存分配

//class Box {
//
//
//	public :
//		Box() {
//			cout << "调用构造函数" << endl;
//
//		}
//		~Box() {
//			cout << "调用析构函数" << endl;
//		}
//};
//
//int main() {
//	Box* myBoxArray = new Box[4];
//
//	//删除数组
//	delete[]myBoxArray;
//	return 0;
//}

//自定义一个命名空间
//namespace first_space {
//	void func() {
//		cout << " 第一个命名空间" << endl;
//	}
//}
//namespace second_space {
//	void func() {
//		cout << " 第二个命名空间" << endl;
//	}
//}
// 嵌套命名空间
//namespace first_space {
//	void func() {
//		cout << " 第一个命名空间" << endl;
//	}
//	namespace second_space {
//		void func() {
//			cout << " 第二个命名空间" << endl;
//		}
//}
//
//}
//
////using namespace first_space;
//using namespace first_space::second_space;
//using std::cout;
////using 指令也可以用来指定命名空间中的特定项目。例如，
////如果您只打算使用 std 命名空间中的 cout 部分，您可以使用如下的语句：
//int main() {
//	//// 调用第一个命名空间的函数
//	//first_space::func();
//	////调用第二个命名空间的函数
//	//second_space:: func();
//
//	func();
//	cout << "用std  的cout 部分 " << std::endl;
//
//
//	// 嵌套的命名空间
//
//	return 0;
//}

// 函数模板 
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
	    vector<T> elems;//元素
    public:
        void push(T const&);// 入栈 
		void pop();//出栈
	T top() const;// 返回栈顶元素
	bool empty() const {
		return elems.empty();
	}
};

template <class T>
void Stack<T>::push(T const& elem)
{
    // 追加传入元素的副本
    elems.push_back(elem);
};


template <class T>

void Stack<T>::pop()
{
    if (elems.empty()) {
        throw out_of_range("Stack<>::pop(): empty stack");
    }
    // 删除最后一个元素
    elems.pop_back();
}

template <class T>
T Stack<T>::top() const
{
    if (elems.empty()) {
        throw out_of_range("Stack<>::top(): empty stack");
    }
    // 返回最后一个元素的副本 
    return elems.back();
};
int main() {

    try {
        Stack<int> intStack; // int 型的栈
        Stack<string> stringStack;//string 型的栈 
        //操作int 类型的栈 
        intStack.push(7);
        cout << intStack.top() << endl;

        //操作string 型的栈 
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
