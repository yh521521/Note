#include <iostream>
using namespace std;
#include<vector>
#include<algorithm> // c++ 自带的算法
#include<functional> // 内建的函数对象
#include <ctime>




//
//class MyAdd {
//public:
//
//	int operator()(int v1, int v2) {
//		return v1 + v2;
//	}
//};
//void test01() {
//	MyAdd myAdd;
//	cout << myAdd(10, 22) << endl;
//}


// //函数对象超出普通对象 的概念 函数对象可以用有自己的 状态 
//class MyPrint {
//
//public:
//
//	MyPrint() {
//		this->count = 0;
//	}
//	void operator()(string test) {
//		
//		cout << test << endl;
//		this->count++;
//	}
//
//	int count; //内部自己的状态
//};
//
//void test02() {
//	MyPrint myPrint;
//	myPrint("you are my ");
//	myPrint("you are my ");
//	myPrint("you are my ");
//	myPrint("you are my ");
//
//	cout << "myPrint 调用的次数" << myPrint.count << endl;
//}
//
//
//
//
//
//// 3 函数对象可以作为参数传递
//
//void doPrint(MyPrint&mp,string test) {
//	mp(test);
//}
//void test01() {
//
//	MyPrint myPrint;
//	doPrint(myPrint, "Hello c++");
//
//}

// 仿函数 返回值类型未bool 类型 称之为谓词
// 一元 谓词 

//class GreaterFive {
//	
//public:
//	bool operator()(int val) {
//		return val > 5;
//	}
//
//};
//
//
//void test01() {
//	vector<int>v;
//	for (int i = 0; i < 10; i++) {
//		v.push_back(i);
//	}
//
//	//查找容器中有没有大于5 的数字  匿名函数对象
//
//	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
//	if (it == v.end()) {
//		cout << "未找到 " << endl;
//	}
//	else {
//		cout << "已找到 " <<*it << endl;
//	}
//}

//// 二元谓词 
//class MyCompare {
//public:
//	bool operator()(int v1,int v2) {
//		return v1 > v2;
//	}
//
//};
//
//
//void test01() {
//	vector<int>v;
//	v.push_back(10);
//	v.push_back(220);
//	v.push_back(31);
//	v.push_back(4);
//
//	sort(v.begin(), v.end());
//	for (vector<int>::iterator it = v.begin(); it != v.end();it++) {
//		cout << " -----" << *it ;
//	}
//	cout << endl;
//
//	// 使用函数对象改变算法策略  变为排序规则未从大到小
//
//	sort(v.begin(), v.end(), MyCompare());
//
//	cout <<"----------------"<< endl;
//
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
//		cout << " -----" << *it;
//	}
//	cout << endl;
//
//}


// 内建 函数对象

// 算数仿函数

//void test01() {
//	
//	negate<int> n;  
//	cout << n(50);  // 取反的仿函数 
//}
//void test02() {
//	plus<int>p;
//	cout << p(10, 22);
//
//}


// 关系仿函数
//class myCompare {
//
//public:
//	bool operator()(int v1,int v2) {
//		return v1 > v2;
//	}
//};
//void test01() {
//	vector<int> v;
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(550);
//	v.push_back(0);
//
//	for (vector<int>::iterator it = v.begin(); it != v.end();it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//
//	// 降序 
//	//sort(v.begin(), v.end(), myCompare());
//	// 系统内建的函数对象
//	sort(v.begin(), v.end(), greater<int>());
//
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}

//逻辑仿函数
//逻辑非

//void test01() {
//	vector<bool>v;
//	v.push_back(true);
//	v.push_back(false);
//	v.push_back(true);
//	v.push_back(false);
//
//	 for (vector<bool>::iterator it = v.begin(); it != v.end(); it++) {
//				cout << *it << " ";
//	 	}
//	 cout << endl;
//
//	 // 利用逻辑非 将容器v 搬运到容器v2 中 并执行取反操作
//
//	 cout <<"-------------------";
//	 vector<bool>v2;
//	 v2.resize(v.size());
//	 transform(v.begin(), v.end(), v2.begin(),logical_not<bool>());
//	 for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++) {
//		 cout << *it << " ";
//	 }
//	 cout << endl;
//}


/// <summary>
///  
/// </summary>
/// <returns></returns>

//常用的遍历算法 

////普通函数
//void  print01(int val) {
//	cout << val << "   ";
//}
//
//// 仿函数
//class print02 {
//public:
//	void  operator()(int val) {
//		cout << val << "   ";
//	}
//	
//};
//void test01() {
//	vector<int> v;
//	for (int i = 0; i < 10;i++) {
//		v.push_back(i);
//	}
//	for_each(v.begin(), v.end(), print01);
//	cout << endl;
//
//	cout << "+++++++++++++";
//	cout << endl;
//	for_each(v.begin(), v.end(), print02());
//}

//搬用容器到另一个容器中 
//class Transform {
//
//public:
//	int operator()(int v) {
//		return v+11;
//	}
//};
//
//class myPrint {
//
//public:
//	void operator()(int val) {
//		cout << val << "  ";
//		
//	}
//};
//void test01() {
//	vector<int> v;// 原容器
//	for (int i = 0; i < 10; i++)
//	{
//		v.push_back(i); 
//	}
//
//	vector<int> vTarget;// 目标容器
//	vTarget.resize(v.size()); // 开辟空间
//	transform(v.begin(), v.end(),vTarget.begin(), Transform());
//	for_each(vTarget.begin(), vTarget.end(), myPrint());
//
//
//	cout << endl;
//
//}


// 常用的查找算法
//void test01() {
//	vector<int>v;
//	for (int i = 0; i < 10; i++)
//	{
//		v.push_back(i);
//	}
//
//	vector<int>::iterator it =  find(v.begin(),v.end(),5);
//	if (it == v.end()) {
//		cout << "没有找到" << endl;
//	}else {
//		cout << "找到" << *it <<endl;
//	}
//
//	// 查找容器中是否有 5    容器
//}
//
//// 查找自定义数据类型 
//
////利用find 可以在容器中找到指定的元素  返回值是迭代器
//class Person {
//
//public:
//	Person(string name,int age) {
//		this->m_Name = name;
//		this->m_Age = age;
//	}
//
//	// 重载 == 底层find 知道如何对比perso 数据类型 
//	bool operator== (const Person & p) {
//		if (this->m_Name == p.m_Name  &&this->m_Age == p.m_Age) {
//			return true;
//		}else {
//			return false;
//		}
//	}
//	string m_Name;
//	int m_Age;
//};
//
//void test02() {
//	vector<Person> v;
//	//创建数据
//	Person p1("aa" ,10);
//	Person p2("bb" ,40);
//	Person p3("vv" ,20);
//	Person p4("dd" ,0);
//
//	//放入到容器中
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//	v.push_back(p4);
//	vector<Person>::iterator it = find(v.begin(), v.end(), p3);
//	if (it == v.end()) {
//		cout << "没有找到" << endl;
//	}
//	else {
//		cout << "找到了  姓名" << it->m_Name << "  年龄  "<<it->m_Age<< endl;
//	}
//}
// 查找内置


// 按照条件进行查找元素
// 查找内置数据模型

//class GraterFive {
//
//public:
//	bool operator()(int val) {
//		return val > 5;
//	}
//};
//
//
//void test01() {
//	vector<int>v;
//	for (int i = 0; i < 10; i++)
//	{
//		v.push_back(i);
//
//	}
//
//	vector<int>::iterator it =   find_if(v.begin(), v.end(), GraterFive());
//	if (it == v.end()) {
//		cout << "没有找到" << endl;
//	}
//	else {
//		cout << "找到了  " <<*it<< endl;
//	}
//}
//
//
//// 自定义数据类型
//
//
//class Person {
//public:
//	Person(string name,int age) {
//		this->m_Name = name;
//		this->m_Age = age;
//	}
//
//	string m_Name;
//	int m_Age;
//
//};
//
//class Grater20 {
//public:
//	bool operator()(Person &p) {
//		return p.m_Age > 20;
//	}
//
//};
//void test02() {
//	
//	vector<Person> v;
//
//	//创建数据
//	Person p1("aa",19);
//	Person p2("bb",29);
//	Person p3("cc",39);
//	Person p4("dd",49);
//
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//	v.push_back(p4);
//
//
//	//找到年龄大于20 的人
//	vector<Person>::iterator it = find_if(v.begin(), v.end(), Grater20());
//	if (it == v.end()) {
//		cout << "没有找到" << endl;
//	}
//	else {
//		cout << "找到了  姓名 " << it->m_Name  << "年龄 "<< it->m_Age << endl;
//	}
//
//}
//
//



// 查找相邻的重复元素 adjacent _find
//
//void test01() {
//	vector<int >v;
//	v.push_back(2);
//	v.push_back(1);
//	v.push_back(3);
//	v.push_back(4);
//	v.push_back(2);
//	v.push_back(3);
//	//v.push_back(3);
//	v.push_back(1);
//
//	vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
//	if (pos == v.end()) {
//		cout << " 未找到相邻重复元素" << endl;
//	}
//	else {
//		cout << " 找到相邻重复元素" <<*pos << endl;
//	}
//
//}


// 二分查找算法
//void test01() {
//	vector<int> v;
//	for (int i = 0; i < 10; i++)
//	{
//		v.push_back(i);
//
//	}
//	v.push_back(2);
//	// 查找容器是由有9 元素
//	// 必须是有序序列   如果是无序序列  结果就是未知了 
//	bool ret = binary_search(v.begin(), v.end(), 9);
//	if (ret) {
//		cout << "找到了" << endl;
//	}
//	else {
//		cout << "未找到 " << endl;
//	}
//}

// 统计元素个数 
//void test01() {
//	vector<int>v;
//	v.push_back(10);
//	v.push_back(40);
//	v.push_back(50);
//	v.push_back(20);
//	v.push_back(40);
//
//	int num = count(v.begin(), v.end(), 40);
//	cout << "40 的元素个数为 " << num << endl;
//}
//
//// 统计自定义数据类型
//class Person {
//public:
//
//	Person(string name,int age) {
//		this->m_Name = name;
//		this->m_Age = age;
//	}
//	bool operator== (const Person &p) {
//		if (this->m_Age == p.m_Age) {
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//
//	string m_Name;
//	int m_Age;
//
//};
//
//
//void test02() {
//
//	vector<Person> v;
//	Person  p1("刘备 ",33 );
//	Person  p2(" 关羽",33 );
//	Person  p3(" 张飞",33 );
//	Person  p4(" 曹操",44 );
//	Person  p5("赵云 ",18 );
//	// 插入到容器中
//	v.push_back(p1 );
//	v.push_back(p2 );
//	v.push_back(p3 );
//	v.push_back(p4 );
//	v.push_back(p5 );
//	Person p("诸葛亮", 33);
//	int num = count(v.begin(), v.end(), p);
//	cout << "和诸葛亮同岁的人员个数为" <<num << endl;
//
//}

// 按照条件查找
//class Greater20 {
//public:
//
//	bool operator()(int val) {
//		return val > 20;
//	}
//};
//void test01() {
//	vector<int>v;
//	v.push_back(10);
//	v.push_back(22);
//	v.push_back(0);
//	v.push_back(6);
//	v.push_back(55);
//	v.push_back(44);
//	v.push_back(33);
//
//	int num = count_if(v.begin(), v.end(), Greater20());
//	cout << "容器中大于20 的个数" << num << endl;
//}

//

//class Person {
//public:
//	Person(string name, int age) {
//		this->m_Name = name;
//		this->m_Age = age;
//
//	}
//
//	string m_Name;
//	int m_Age;
//};
//class AgeGreater20 {
//
//public:
//	// 对比的过程中不能去修改他
//	bool operator()(const Person &p) {
//		return p.m_Age > 20;
//	}
//};
//void test02() {
//	
//	vector<Person> v;
//
//	Person  p1("刘备 ", 33);
//	Person  p2(" 关羽",33 );
//	Person  p3(" 张飞",33 );
//	Person  p4(" 曹操",44 );
//	Person  p5("赵云 ",18 );
//
//
//	v.push_back(p1 );
//	v.push_back(p2 );
//	v.push_back(p3 );
//	v.push_back(p4 );
//	v.push_back(p5 );
//	
//	int num = count_if(v.begin(), v.end(), AgeGreater20());
//	cout << "大于20 岁的人员个数为" <<num << endl;
//}

// 常用的排序算法
//void  myPrint(int val) {
//	cout << " 输出" << val << endl;
//}
//void test01() {
//	vector<int> v;
//	v.push_back(12);
//	v.push_back(2);
//	v.push_back(33);
//	v.push_back(4);
//	v.push_back(0);
//	v.push_back(66);
//	// sort 排序 默认升序
//	sort(v.begin(), v.end());
//	for_each(v.begin(), v.end(), myPrint);
//	cout << endl;
//
//	// 改变为降序
//	cout << " ---------------"<< endl;
//	sort(v.begin(), v.end(),greater<int>());
//	for_each(v.begin(), v.end(), myPrint);
//	cout << endl;
//
//}

// random_shuffle 打乱 

void  myPrint(int val) {
	cout  << val << "    ";
}
//void test01() {
//	srand((unsigned int)time(NULL));
//	vector<int> v;
//	for (int i = 0; i < 10; i++)
//	{
//		v.push_back(i);
//	}
//
//	// 利用洗牌 算法 打乱顺序
//	random_shuffle(v.begin(), v.end());
//
//	for_each(v.begin(), v.end(), myPrint);
//	cout << endl;
//
//
//}

// merge 合并算法  两个容器必须 是有序的





//void test01() {
//	vector<int> v1;
//	vector<int> v2;
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//		v2.push_back(i + 1);
//
//	}
//	// 目标容器
//	vector<int> VTarget;
//	// 给目标容器分配空间
//	VTarget.resize(v1.size() + v2.size());
//	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), VTarget.begin());
//	for_each(VTarget.begin(), VTarget.end(), myPrint);
//}


// reverse  容器内元素进行反转

void test01() {
	vector<int> v;
	v.push_back( 10);
	v.push_back( 20);
	v.push_back(30 );
	v.push_back(40 );
	v.push_back(50 );
	cout << "' 反转前 " << endl;
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
	cout << "' 反转后  " << endl;
	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}

int main() {

	

	//test01();
	test01();
	system("pause");
	return 0;
}