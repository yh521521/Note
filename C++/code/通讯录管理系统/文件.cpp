#include <iostream>
using namespace std;
#include <fstream> // 包含头文件


////文本文件写文件
//void test01() {
//	//1 包含头文件
//
//	//2 创建流对象
//
//	ofstream ofs;
//
//	//3 指定打开的方式
//	ofs.open("test.txt", ios::out);
//
//	//4 写内容
//	ofs << "姓名: 张三" << endl;
//	ofs << "性别: 男" << endl;
//	ofs << "年龄: 18" << endl;
//
//	// 5 关闭文件
//	ofs.close();
//
//};


//读文件

//void test02() {
//	//1 引入头文件 
//	// 2 创建流对象
//	ifstream ifs;
//	//打开文件判断是否打开成功
//	ifs.open("test.txt", ios::in);
//	if (!ifs.is_open()) {
//		cout << " 文件打开失败" << endl;
//		return;
//	}
//	// 读数据
//	//第一种
//	/*char buf[1024] = { 0 };
//	while (ifs >> buf) {
//		cout <<buf << endl;
//	}*/
//	//第二种读取 0  初始化数组
//	/*char buf[1024] = { 0 };  
//	while (ifs.getline(buf,sizeof(buf))) {
//		cout << buf << endl;
//	}*/
//
//	//第三种
//	// EOF end  of file  文件尾部 
//	char c;
//	while ((c = ifs.get())!= EOF) {
//		cout << c ;
//	}
//	
//	//关流
//	ifs.close();
//
//}

// 二进制文件  写文件

//class Person {
//		
//public:
//	char m_Num[64]; //姓名
//	int m_Age;
//};
//void test01() {
//	// 1 包含头文件
//	//2 创建流对象
//	// 我需要写入
//	ofstream ofs("person.txt", ios::out | ios::binary);
//	
//	//3 打开文件
//	//ofs.open("person.txt",ios::out||ios::binary);
//	// 4 写文件
//	Person p = { "袁航",18 };
//
//	ofs.write((const char*)&p,sizeof(Person));
//
//	//关闭文件
//	ofs.close();
//}

// 
class Person {

public:
	char m_Name[64];
	int m_Age;

};

// 二进制文件  读文件
void test01() {
	// 包含头文件   fstream 
	// 创建流对象
	ifstream ifs;
	// 打开文件
	//判断文件是否可以打开成功
	ifs.open("person.txt", ios::in | ios::binary);
	if (!ifs.is_open()) {
		cout << "文件打开失败";
			return;
	}

	// 读文件
	Person p;
	ifs.read((char*)&p, sizeof(Person));
	cout << "姓名是   " << p.m_Name << "年龄   " << p.m_Age << endl;

	//关闭文件
	ifs.close();
	
}
int main() {
	test01();
}