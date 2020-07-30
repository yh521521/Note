#include <iostream>
using  namespace std;
#include <vector>
#include <algorithm>  // 标准算法头文件
#include<deque>
//vector 容器 存放内置数据类型


//void myPrint(int val ) {
//	cout << "打印结果"<< val << endl;
//}
//
//void test01() {
//
//	// 创建了一个vector 数组
//	vector<int > v;
//	// 向容器中插入数据
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(40);
//
//
//	// 如何访问呢  通过迭代器的方式遍历
//	vector<int>::iterator itBegin = v.begin(); // 起始迭代器 指向容器中的第一个元素
//	vector<int>::iterator itEnd = v.end(); // 结束迭代器 指向容器中最后一个元素的下一个位置
//
//	// 第一种遍历 
//	/*while(itBegin != itEnd )
//	{
//		cout << *itBegin << endl;
//		itBegin++;
//	}*/
//
//	// 第二种遍历 
//	//for (vector<int>::iterator it = v.begin();it != v.end(); it++)
//	//{
//	//	cout << "*it ---- " << *it << endl;
//	//}
//
//	// 第三种遍历方式
//	for_each (v.begin(), v.end() , myPrint);
//	
//}

//class Person {
//
//public:
//	Person(string name,int age ) {
//		
//		this->m_Name = name;
//		this->m_Age = age;
//	}
//	string m_Name;
//	int m_Age;
//};
//
//void test01() {
//	vector<Person> v;
//	Person p1("aaa", 10);
//	Person p2("aaa", 20);
//	Person p3("aaa", 30);
//	Person p4("aaa", 40);
//	Person p5("aaa", 50);
//
//	//向容器中添加数据
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//	v.push_back(p4);
//	v.push_back(p5);
//
//	// 遍历容器中的数据 (*it ) person 数据类型
//	for (vector<Person>::iterator it = v.begin();it!= v.end(); it++)
//	{
//		//cout << "姓名 : " << (*it).m_Name << "   年龄:  " << (*it).m_Age << endl;
//		cout << "姓名 : " << it->m_Name << "   年龄:  " << it->m_Age << endl;
//	}
//}
//// 自定义数据类型
//void test02() {
//	vector<Person*> v;
//	Person p1("aaa", 10);
//	Person p2("aaa", 20);
//	Person p3("aaa", 30);
//	Person p4("aaa", 40);
//	Person p5("aaa", 50);
//
//	//向容器中添加数据
//	v.push_back(&p1);
//	v.push_back(&p2);
//	v.push_back(&p3);
//	v.push_back(&p4);
//	v.push_back(&p5);
//
//	//遍历容器 
//	for (vector<Person *>::iterator it = v.begin();it != v.end();it++)
//	{
//		cout << "姓名: " << (*it)->m_Name << "年龄 :" << (*it)->m_Age << endl;
//	}
//}


////容器嵌套容器
//
//void test01() {
//	//大容器
//	vector<vector<int>> v;
//	//创建小容器
//	vector<int> v1;
//	vector<int> v2;
//	vector<int> v3;
//	vector<int> v4;
//
//	//向小容器添加数据
//	for (int i = 0; i < 4;i++) {
//		v1.push_back(i + 1);
//		v2.push_back(i + 2);
//		v3.push_back(i + 3);
//		v4.push_back(i + 4);
//	}
//
//	//小容器插入到大容器中
//	v.push_back(v1);
//	v.push_back(v2);
//	v.push_back(v3);
//	v.push_back(v4);
//
//	//通过大容器 把所有数据遍历一下
//	for (vector<vector<int>>::iterator it = v.begin(); it != v.end();it++) {
//		cout << "开始打印 " <<endl;
//		
//		//(*it)  ----.vector<int>  还是一个容器
//		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++) {
//			cout << *vit <<"  ";
//		}
//
//		cout << endl;
//	}
//
//}

//string 的构造函数 


//void test01() {
//	string s1; // 默认构造
//	const char* str = "hello world";
//
//	string s2(str);
//
//	string s3(s2);
//	cout << "s2 = " << s2 << endl;
//	cout << "s3 = " << s3 << endl;
//
//	string s4(10,'a');
//	cout << "s4 = " << s4 << endl;
//}



//string 的赋值操作

//void test01() {
//	
//	string str1;
//	str1 = "hello yh ";
//	cout << "str1:::" << str1 << endl;
//
//	string str2;
//	str2 = str1;
//	cout << "str2:::" << str2 << endl;
//
//	string str3;
//	str3 = "a";
//	cout << "str3:::" << str3 << endl;
//
//
//	string str4;
//	str4.assign("hello c++");
//	cout << "str4:::" << str4 << endl;
//	
//
//	string str5;
//	str5.assign("hello c++",4);
//	cout << "str5:::" << str5 << endl;
//
//	string str6;
//	str6.assign(str5);
//	cout << "str6:::" << str6 << endl;
//
//	string str7;
//	str7.assign(10,'w');
//	cout << "str7:::" << str7 << endl;
//}

//string 字符串拼接

//void test01() {
//	string str1 = "我";
//	str1 += "爱玩游戏";
//	cout << "str1 ::" << str1 << endl;
//
//	str1 += ":";
//
//	cout << "str1 ::" << str1 << endl;
//
//	string str2 = "LOL DNF";
//	str1 += str2;
//	cout << "str1 ::" << str1 << endl;
//
//	string  str3 = "I";
//	str3.append("love");
//	cout << "str3 =" << str3 << endl;
//
//	str3.append("game abcdde",4);
//	cout << "str3 =" << str3 << endl;
//	str3.append(str2, 4, 3);
//	cout << "str3 =" << str3 << endl;
//
//}


//查找和替换
 ///1 查找

//void test01() {
//	string str1 = "abcdef";
//	int pos = str1.find("d");
//	if (pos == -1) {
//		cout << "未找到" << endl;
//	}
//	else {
//		cout << "找到" << pos<< endl;
//	}
//	
//
//	pos = str1.rfind("e");
//
//
//
//	
//}
//
//// 替换 
//void test02() {
//	string str1 = "abcdef";
//	str1.replace(1, 3, "1111");
//	cout << "str1===" << str1 << endl;
//
//
//
//
//}

/*void test01() {

	string str1 = "xello";
	string str2 = "hello";
	if (str1.compare(str2) == 0) {
		cout << "str1等于str2" << endl;
	}else if (str1.compare(str2)>0) {
			cout << "str1大于str2" << endl;
	}
}*/

//字符存取 string 

//void test01() {
//	string  str = "hello";
//	cout << "str---" << str << endl;
//
//	//通过[] 访问单个字符 
//	//for (int  i = 0; i < str.size(); i++)
//	//{
//	//	cout << " str[i]---" << str[i] << "    ";
//	//	
//	//}
//
//	//通过at 方式访问单个字符
//	for (int i = 0; i < str.size(); i++)
//	{
//		cout << str.at(i) << "    ";
//	}
//	cout << endl;
//	//修改单个字符 
//	/*str[0] = 'x';
//	cout << "str---" << str << endl;*/
//
//	str.at(1) = 'a';
//	cout << "str---" << str << endl;
//}


// 字符串的插入和删除
//void test01() {
//	string str = "helloyh";
//	// 插入
//	str.insert(1, "1111");
//	cout << "str===" << str << endl;
//
//	//删除
//	str.erase(1,2);
//	cout << "str===" << str << endl;
//
//}



// 从字符串中获取想要的字串

//void test01() {
//	string str = "abcdef";
//	string subStr = str.substr(1, 3);
//	cout << "subStr=" << subStr << endl;
//}
//void test02() {
//	string email = "zhangsan@qq.com";
//
//	//从邮件地址中获取用户信息
//
//	int pos =email.find("@");
//	string usrName = email.substr(0, pos);
//	cout << "usrName=" << usrName << endl;
//}



//vector 容器构造

//打印 
//void printVector(vector<int> v) {
//	
//	for (vector<int>::iterator it = v.begin(); it != v.end();it++) {
//		
//		cout  << *it << "  ";
//	}
//	cout << endl;
//}
//
//
//void test01() {
//	vector<int> v1;
//	for (int  i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//	}
//	printVector(v1);
//	//通过区间方式进行构造
//	vector<int> v2(v1.begin(), v1.end());
//	printVector(v2);
//
//
//	// n 个elem 方式构造
//	vector<int> v3(10, 12);
//	printVector(v3);
//
//	//拷贝构造
//	vector<int> v4(v3);
//	printVector(v4);
//
//}

//vector 赋值 

//void printVector(vector<int> v) {
//	
//	for (vector<int>::iterator  it = v.begin();it != v.end();it++)
//	{
//		cout << *it << " ";
//
//	}
//	cout << endl;
//}
//
//void test01() {
//	vector<int> v1;
//	for (int  i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//
//	}
//	printVector(v1);
//	// 赋值 
//	vector <int> v2;
//	v2 = v1;
//	printVector(v2);
//
//	//assigm 赋值
//	vector<int> v3;
//	v3.assign(v1.begin(), v1.end());
//	printVector(v3);
//
//	// N 个elem 方式赋值
//	vector<int> v4;
//	v4.assign(10, 1123);
//	printVector(v4);
//
//}


//vector 容器的容量和大小操作


// 打印输出
//void printVector(vector<int> v) {
//	for (vector<int>::iterator it = v.begin(); it != v.end();it++ ) {
//		cout << *it << "   ";
//	}
//	cout << endl;
//}
//
//void test01() {
//	vector<int> v1;
//	for (int  i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//
//	}
//
//	printVector(v1);
//
//	if (v1.empty()) { // 为真 容器为空
//		cout << " 容器为空" << endl;
//	}
//	else {
//		cout << " 容器不为空" << endl;
//		cout << " 容量为" << v1.capacity()<< endl;
//		cout << " 大小为" << v1.size()<< endl;
//
//	}
//
//	// 重新指定大小
//	//v1.resize(15);
//	v1.resize(15,23); // 利用重载的版本 可以指定填充的默认值  参数2 
//	printVector(v1); // 如果重新指定的比原来查了 默认用0 去填充
//
//	v1.resize(5); // 如果比原来的短了 超出部分会被删掉
//	
//	printVector(v1);
//}


// 插入和删除

 void printDeque(const deque<int> v) {
		for (deque<int>::const_iterator it = v.begin(); it != v.end();it++ ) {
			cout << *it << "   ";
		}
		cout << endl;
	}
//void test01() {
//	vector<int>v1;
//	
//
//	//尾插
//	v1.push_back(10);
//	v1.push_back(20);
//	v1.push_back(30);
//	v1.push_back(40);
//

//	//遍历
//	printVector(v1);
//
//	//尾删
//	v1.pop_back();
//	printVector(v1);
//
//	//插入
//	v1.insert(v1.begin(), 100);
//	printVector(v1);
//	v1.insert(v1.begin(),2, 1001);
//	printVector(v1);
//
//	//删除
//	v1.erase(v1.begin());
//	printVector(v1);
//	//v1.erase(v1.begin(),v1.end());
//	v1.clear();
//	cout << " @@@@@@@@@@@@@@@@@@@@@@@" << endl;
//	printVector(v1);
//}




 //vector 容器数据存取

 //void test01() {
	// vector<int> v1;
	// for (int i = 0; i < 10;i++) {
	//	 v1.push_back(i);
	// }

	// //for (int  i = 0; i < v1.size(); i++)
	// //{
	//	// cout << v1[i] << "   ";
	// //}

 //vector 容器互换 


 //void test01() {
	// vector<int> v1;
	// for (int i = 0; i < 10; i++)
	// {
	//	 v1.push_back(i);

	// }
	// cout << "交换前 " << endl;
	// printVector(v1);

	// vector<int>v2;
	// for (int i = 10; i >0; i--)
	// {
	//	 v2.push_back(i);
	// }

	// printVector(v2);

	// cout << "交换后  " << endl;

	// v1.swap(v2);
	// printVector(v1);
	// printVector(v2);
 //}

 ////实际用途
 //void test02() {
	// vector<int> v;
	// for (int i = 0; i < 10000; i++)
	// {
	//	 v.push_back(i);

	// }

	// cout << "v的容量是 " << v.capacity() << endl;
	// cout << "v的大小是 " << v.size() << endl;

	// v.resize(3);
	// cout << "v的容量是 " << v.capacity() << endl; //容量不变
	// cout << "v的大小是 " << v.size() << endl;

	// //利用swap 收缩内存 
	// vector<int>(v).swap(v);
	// cout << "v的容量是 " << v.capacity() << endl; 
	// cout << "v的大小是 " << v.size() << endl;

 //}
	// cout << endl;

	// //利用at 方式访问元素
	// for (int i = 0; i < v1.size(); i++)
	// {
	//	 cout << v1.at(i) << "   ";
	// }

	// cout << endl;

	// //返回第一个元素
	// cout << "第一个元素为:" << v1.front() << endl;

	// cout << "最后一个元素为:" << v1.back() << endl;
 //}



//vector 预留空间

 //void test01() {
	// vector<int> v;


	// // 利用everse 预留空间
	// v.reserve(1000000);

	// int num = 0;
	// int* p = NULL;
	// for (int  i = 0; i < 1000000; i++)
	// {
	//	 v.push_back(i);

	//	 if (p != &v[0]) {
	//		 cout << "打印p----- " << p << endl;
	//		 p = &v[0];
	//		 num++;
	//		 cout << "打印num ---- " << num << endl;
	//	 }
	// }

	// cout << "num" << num << endl;
 //}

//////deque 的构造函数
//// void test01() {
////	 deque<int > d1;
////	 for (int i = 0; i < 10; i++)
////	 {
////		 d1.push_back(i);
////
////	 }
////
////	 printVector(d1);
////	 deque<int> d2(d1.begin(), d1.end());
////	 printVector(d2);
////
////	 //deque<int>d3(10, 100);
////	 deque<int>d3(10, 100);
////		 printVector(d3);
////
////		 deque<int>d4(d3);
////		 printVector(d4);
////
//// }
////

//deque 赋值操作
 //void test01() {
	// deque<int> d1;
	// for (int i = 0; i < 10; i++)
	// {
	//	 d1.push_back(i);
	// }

	// printVector(d1);

	//  //operator = 赋值
	// deque<int>d2;
	// d2 = d1;
	// printVector(d2);

	// //asign 赋值 
	// deque<int> d3;
	// d3.assign(d1.begin(), d1.end());
	// printVector(d3);
	// 
	// deque<int>d4;
	// d4.assign(10,22);
	// printVector(d4);

 //}

 //void test01() {
	//
	// deque<int> d1;
	// for (int i = 0; i < 10; i++)
	// {
	//	 d1.push_back(i);

	// }
	// printVector(d1);

	// if (d1.empty()) {
	//	 cout << "d1 为空" << endl;
	// }
	// else {
	//	 cout << "d1 不为空" << endl;
	//	 cout << "d1 大小" << d1.size() <<endl;
	//	//deque 容器没有  容量概念

	//	 //重新指定大小
	//	 //d1.resize(16);
	//	// d1.resize(16,1);
	//	 d1.resize(4);
	//	 printVector(d1);

	// }
 //}


//deque 容器 
 //void test01() {
	// deque<int> d1;

	// //尾插
	// d1.push_back(10);
	// d1.push_back(20);
	// //头插 
	// d1.push_front(100);
	// d1.push_front(200);

	// printDeque(d1);

	// //尾删
	// d1.pop_back();
	// printDeque(d1);

	// //头删
	// d1.pop_front();
	// printDeque(d1);
 //}

 //void test02() {
	// deque<int> d1;
	// d1.push_back(10);
	// d1.push_back(20);
	// d1.push_back(30);
	// d1.push_back(40);
	// printDeque(d1);

	// //inset 插入
	// d1.insert(d1.begin(), 1000);
	// printDeque(d1);


	// d1.insert(d1.begin(),2, 520);
	// printDeque(d1);


	// //按照区间进行插入 
	// deque<int> d2;
	// d2.push_back(1);
	// d2.push_back(2);
	// d2.push_front(3);
	// d2.push_front(4);

	// d1.insert(d1.begin(), d2.begin(), d2.end());
	// printDeque(d1);
	// //删除 
	// deque<int>::iterator it = d1.begin();
	//	 it++;
	// d1.erase(it);
	// printDeque(d1);
	// d1.erase(d1.begin());
	// d1.erase(d1.begin(), d1.end());
	// printDeque(d1);
	// d1.clear();
	// printDeque(d1);



 //}

 //void test01() {
	//
	// deque<int> d;
	// // 尾插头插 
	// d.push_back(10);
	// d.push_back(20);
	// d.push_back(30);
	// d.push_front(100);
	// d.push_front(200);
	// d.push_front(300);

	//// 通过[] 反射光hi访问元素
	// for (int  i = 0; i < d.size(); i++)
	// {
	//	 cout << d[i] << "    ";
	// }
	// cout << endl;

	// for (int  i = 0; i < d.size(); i++)
	// {
	//	 cout << d.at(i) << "    ";
	// }

	// cout << endl;

	// cout << "第一个元素为" << d.front() <<endl;
	// cout << "最后一个元素为" << d.back() <<endl;
 //}


//deque 容器排序 
 void test01() {
	 deque<int> d;
	 d.push_back(10);
	 d.push_back(20);
	 d.push_back(30);
	 d.push_front(100);
	 d.push_front(200);
	 d.push_front(300);
	

	 printDeque(d);


	 //deque 容器排序 algorithm

	// 默认升序 
	 cout << "排序后 " << endl;
	 sort(d.begin(), d.end());
	 printDeque(d);
 }

int main() {
	test01();
	system("pause");
	return 0;
}