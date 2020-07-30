#include<iostream>
using namespace std;
#include <stack>
#include <queue>
#include <list>
#include<set>
#include<map>


////栈容器 
//void test01() {
//	//特点 符合先进后出数据结构
//	stack<int>s;
//
//	//入栈
//	s.push(10);
//	s.push(20);
//	s.push(30);
//	s.push(40);
//	s.push(50); 
//	cout << "栈的大小:" << s.size() << endl;
//
//
//	//只要栈不为空 查看栈顶 并且执行出栈操作 
//	while (!s.empty()) {
//		
//		//查看栈顶元素 
//		cout << "栈顶元素为:" << s.top() << endl;
//
//		//出栈
//		s.pop();
//		cout << "栈的大小:" << s.size() << endl;
//
//	}
//
//
//}

//queue    队列容器 先进先出 
//class  Person {
//
//
//public:
//	Person(string name,int age) {
//		this->m_Name = name;
//		this->m_Age = age;
//	}
//	string m_Name;
//	int m_Age;
//};
//
//void test01() {
//	queue<Person>q;
//	//准备数据
//	Person p1 ("关于",10);
//	Person p2 ("张飞", 20);
//	Person p3 ("刘备", 30);
//	Person p4 ("赵云", 40);
//
//	//入队
//	q.push(p1);
//	q.push(p2);
//	q.push(p3);
//	q.push(p4);
//
//	//判断只要队列不为空 查看对头  查看队尾 出队
//	while (!q.empty()) {
//		//查看对头元素
//		cout << "队头元素--姓名:" << q.front().m_Name << "年龄" << q.front().m_Age<<endl;
//		cout << "队尾元素--姓名:" << q.back().m_Name << "年龄" << q.back().m_Age<<endl;
//		//出队
//		q.pop();
//
//
//	
//	
//	
//	}
//
//	cout << "队列大小为:" << q.size() << endl;
//}
//
//


//创建list 容器

void printList(const list<int> &L) {
	for ( list<int>::const_iterator lit = L.begin() ;lit!= L.end();lit++)
	{

		cout << (*lit) << "   ";
	}
	cout << endl;
}

void printSet(const set<int>& s) {
	for (set<int>::const_iterator sit = s.begin(); sit != s.end(); sit++)
	{

		cout << (*sit) << "   ";
	}
	cout << endl;
}
//void test01() {
//	
//	list<int> L1;
//	//添加数据
//	L1.push_back(10);
//	L1.push_back(20);
//	L1.push_back(30);
//	L1.push_back(40);
//
//	//遍历容器 
//	printList(L1);
//	//区间方式构造 
//	list<int>L2(L1.begin(), L1.end());
//	printList(L2);
//
//	// 拷贝构造
//	list<int >L3(L2);
//	printList(L3);
//
//	//n 个elem 
//	list<int>L4(10, 155);
//	printList(L4);
//
//
//}

//赋值 
//void test01() {
//	list<int> L1;
//	L1.push_back(10);
//	L1.push_back(20);
//	L1.push_back(30);
//	L1.push_back(40);
//
//	printList(L1);
//
//	list<int> L2;
//	L2 = L1;
//	printList(L2);
//	list<int >L3;
//	L3.assign(L2.begin(), L2.end());
//	printList(L3);
//	
//
//	list<int> L4;
//	L4.assign(10, 33);
//	printList(L4);
//
//
//}


//交换 
//void test02() {
//	list<int> L1;
//	L1.push_back(10);
//	L1.push_back(20);
//	L1.push_back(30);
//	L1.push_back(40);
//
//	/*list<int> L2;
//
//	L2.assign(10, 55);
//	cout << "交换前" << endl;
//	printList(L1);
//	printList(L2);
//
//	cout << "交换后" << endl;
//	L1.swap(L2);
//	printList(L1);
//	printList(L2);*/
//
//	printList(L1);
//	if (L1.empty()) {
//		cout << "L1 为空" << endl;
//	}
//	else {
//		cout << "L1不 为空" << endl;
//		cout << "L1 的个数为" << L1.size() << endl;
//	}
//
//	//重新指定大小
//	L1.resize(10);
//	printList(L1);
//
//
//
//}


//void test01() {
//	list<int>L;
//	//尾插
//	L.push_back(10);
//	L.push_back(20);
//	L.push_back(30);
//
//	//头插 
//	L.push_front(22);
//	L.push_front(33);
//	L.push_front(44);
//
//
//	printList(L);
//	//尾删
//	L.pop_back();
//	//头删
//	L.pop_front();
//
//	printList(L);
//
//	//insert 插入 
//	list<int>::iterator it = L.begin();
//	L.insert(++it, 88);
//	//L.insert(L.begin(),456);
//	printList(L);
//
//	//删除
//	it = L.begin();
//	L.erase(++it);
//	printList(L);
//
//	//移除
//	L.push_back(2000);
//	printList(L);
//	L.remove(2000);  //remove 删除 所有 匹配的2000 
//	printList(L);
//	
//	//清空
//	L.clear();
//	printList(L);
//
//
//}

// list 数据存取
// 对list 容器中数据进行存取 

//void test01() {
//	list<int> L1;
//	L1.push_back(10);
//	L1.push_back(20);
//	L1.push_back(30);
//	L1.push_back(40);
//
//	cout << "第一个元素为" << L1.front() << endl;
//	cout << "最后一个元素为" << L1.back() << endl;
//
//	// 验证迭代器不支持随机访问
//	list<int>::iterator it = L1.begin();
//	it++; //支持双向
//	it--;
//	//it = it+1  不支持随机访问 
//
//	printList(L1);
//
//}

// list 反转 
//void test01() {
//	
//	list<int> L1;
//	L1.push_back(10);
//	L1.push_back(20);
//	L1.push_back(30);
//	L1.push_back(40);
//	L1.push_back(50);
//	
//	cout << "反转前" << endl;
//	printList(L1);
//	//反转后
//	cout << "反转后" << endl;
//	L1.reverse();
//	printList(L1);
//
//
//}



//bool myCompare(int v1,int v2) {
//	
//	// 降序  让第一个数 > 第二个数
//	return v1 > v2;
//}
//void test02() {
//	
//	list<int> L1;
//	L1.push_back(10);
//	L1.push_back(2);
//	L1.push_back(22);
//	L1.push_back(99);
//	L1.push_back(15);
//	
//	cout << "排序前" << endl;
//	printList(L1);
//	//反转后
//	cout << "排序后" << endl;
//	L1.sort(); // 默认升序
//	printList(L1);
//
//	// 降序
//	L1.sort(myCompare);
//	printList(L1);
//
//
//}



// 自定义排序案例 
 // 年龄进行升序 如果年龄相同按照身高进行降序

//class Person {
//
//public:
//	Person(string name,int age ,int height) {
//		
//		this->m_Name = name;
//		this->m_Age = age;
//		this->m_Height = height;
//	}
//	string m_Name;
//	int m_Age;
//	int m_Height;
//
//};
//
////指定排序规则
//bool comparePerson(Person &p1,Person &p2) {
//	
//	//如果年龄形同 按照身高降序
//	if (p1.m_Age == p2.m_Age) {
//		return  p1.m_Height > p2.m_Height;
//	}
//	//按照年龄升序 
//	return p1.m_Age < p2.m_Age;
//
//}




//void test01() {
//
//	list<Person> L; // 创建数据
//
//	Person p1("刘备" ,35  ,175);
//	Person p2("曹操" ,45  ,180);
//	Person p3("孙权" , 40 ,170);
//	Person p4("赵云" , 25 ,190);
//	Person p5("张飞" , 35 ,160);
//	Person p6("关羽" ,  35,200);
//
//	//插入数据
//	L.push_back(p1);
//	L.push_back(p2);
//	L.push_back(p3);
//	L.push_back(p4);
//	L.push_back(p5);
//	L.push_back(p6);
//
//	for (list<Person>::iterator it = L.begin(); it != L.end();it++) {
//	
//		cout << "姓名 : " << (*it).m_Name << "   年龄  " << (*it).m_Age << "  身高  " << (*it).m_Height << endl;
//	}
//	//排序
//	cout << "排序后: " << endl;
//	L.sort(comparePerson);
//	for (list<Person>::iterator it = L.begin(); it != L.end(); it++) {
//
//		cout << "姓名 : " << (*it).m_Name << "   年龄  " << (*it).m_Age << "  身高  " << (*it).m_Height << endl;
//	}
//	
//}

//set 容器的构造和赋值
//void  test01() {
//	set<int> s1;
//
//	//插入数据只有insert  方式
//	s1.insert(10);
//	s1.insert(210);
//	s1.insert(30);
//	s1.insert(4);
//	s1.insert(6); //不允许有重复数 
//	s1.insert(6);
//
//
//	//遍历容器 
//	printSet(s1);
//
//	//拷贝构造 
//	set<int>s2(s1);
//	printSet(s2);
//
//	//赋值
//	set<int>s3;
//	s3 = s2;
//	printSet(s3);
//}

//set 容器大小 和交换 

//void test01() {
//
//	set<int> s1;
//
//
//	s1.insert(10);
//	s1.insert(30);
//	s1.insert(20);
//	s1.insert(60);
//
//	printSet(s1);
//	set<int> s2;
//
//
//	s2.insert(11);
//	s2.insert(330);
//	s2.insert(23);
//	s2.insert(66);
//
//	printSet(s2);
//	//交换前
//
//	//判断是否为空
//	if (s1.empty()) {
//		cout << "s1 为空" << endl;
//	}
//	else {
//		cout << "s1 不为空" << endl;
//		cout << "s1 的size"<<s1.size() << endl;
//	}
//
//
//
//	//交换后
//	s1.swap(s2);
//	cout << "交换后" << endl;
//	printSet(s1);
//	printSet(s2);
//}
// set  插入删除

//void test01() {
//	set<int> s1;
//	s1.insert(10);
//	s1.insert(30);
//	s1.insert(20);
//	s1.insert(60);
//	printSet(s1);
//
//	//删除
//
//	s1.erase(s1.begin());
//	printSet(s1);
//
//	//删除的重载版本
//	s1.erase(30);
//	printSet(s1);
//
//
//	//清空 
//	s1.erase(s1.begin(), s1.end());
//	cout << "打印" << endl;
//	printSet(s1);
//}


// set 容器的查找和统计 
//void test01() {
//	//查找
//	set<int>s1;
//
//	//插入数据
//	s1.insert(10);
//	s1.insert(30);
//	s1.insert(40);
//	s1.insert(60);
//
//	
//	set<int>::iterator pos = s1.find(300);
//	if (pos != s1.end()) {
//		cout << "找到元素" << *pos << endl;
//	}else {
//		cout << "未 找到元素" << endl;
//	}
//}
//
//
//void test02() {
//	
//	//查找
//	set<int>s1;
//
//	//插入数据
//	s1.insert(10);
//	s1.insert(30);
//	s1.insert(30);
//	s1.insert(30);
//	s1.insert(40);
//	s1.insert(60);
//
//	// 统计30 的个数
//	// 对于set 而言 统计结果要莫` 是0 要摸 是 1 
//	int num = s1.count(30);
//	cout << "num = " << num << endl;
//}

// set 容器和multiset 容器的区别

//void test01() {
//
//	set<int> s;
//	pair<set<int>::iterator,bool> ret = s.insert(10);
//	if(ret.second){
//		cout <<"第一次插入成功"<<endl;
//	}
//	else {
//		cout << "第一次插入失败" << endl;
//	}
//
//	 ret = s.insert(10);
//
//	 if (ret.second) {
//		 cout << "第二次插入成功" << endl;
//	 }
//	 else {
//		 cout << "第二次插入失败" << endl;
//	 }
//
//
//	 multiset<int > ms;
//	 ms.insert(10);
//	 ms.insert(10);
//
//	 for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
//	 {
//		 cout << "*it        "<< *it <<endl;
//	 }
//
//	 
//	
//}


// pari 队组创建 
// 成对出现的数据 可以利用队组返回两个数据

//void test01() {
//
//	// 第一种方式
//	pair<string, int> p("tom",10);
//
//	cout << "姓名   " << p.first << "年龄   " << p.second << endl;
//
//	// 第二种方式
//	pair<string, int> p2 = make_pair("jerry", 30);
//	cout << "姓名   " << p2.first << "年龄   " << p2.second << endl;
//
//}



// set 容器排序  
//class MyCompare {
//public:
//	bool operator()(int v1, int v2)const {
//		return v1>v2;
//	}
//};
//
//
//void test02(){
//	set<int, MyCompare> s2;
//	s2.insert(10);
//	s2.insert(44);
//	s2.insert(20);
//	s2.insert(1);
//	s2.insert(66);
//	for (set<int, MyCompare>::iterator it = s2.begin(); it != s2.end();it++) {
//		cout << *it << "   ";
// 	}
//	cout << endl;
//}



//set 容器排序 存放自定义数据类型

//class Person {
//public:
//	Person(string name,int age) {
//		this->m_Name = name;
//		this->m_Age = age;
//	}
//	string m_Name;
//	int m_Age ;
//};
//
//// 仿函数
//
//class comparePerson {
//
//public:
//	bool operator()(const Person&p1, const Person&p2)const
//	{
//		// 按年龄降序排列
//		return p1.m_Age > p2.m_Age;
//	}
//};
//void test01() {
//
//
//	set<Person, comparePerson> s;
//	//创建person 对象  
//	Person p1("刘备",24 );
//	Person p2("关羽", 22);
//	Person p3("张飞", 28);
//	Person p4("赵云 ",30 );
//
//	s.insert(p1);
//	s.insert(p2);
//	s.insert(p3);
//	s.insert(p4);
//	for (set<Person, comparePerson>::iterator it = s.begin(); it != s.end(); it++) {
//		cout << "  姓名 " << it->m_Name << "年龄  " << it->m_Age << endl;
//	}
//}

// map 容器 


//打印map 容器
void printMap(map<int,int> &m) {
	for (map<int, int>::iterator it = m.begin(); it != m.end();it++) {
		cout <<"key ---" <<it->first <<  "value   " << (*it).second<< endl;
	}
	
}

//void test01() {
//
//	//创建map容器
//	map<int, int >m;
//	m.insert(pair<int, int>(1, 10));
//	m.insert(pair<int, int>(2, 20));
//	m.insert(pair<int, int>(3, 30));
//	m.insert(pair<int, int>(4, 40));
//
//	printMap(m);
//
//	// 拷贝构造
//	map<int, int>m2(m);
//	printMap(m2);
//
//	//赋值
//	map<int, int > m3;
//	m3 = m2;
//	printMap(m3);
//
//
//}


//map 容器大小和交换 
//void test01() {
//	map<int, int >m;
//
//	m.insert(pair<int, int>(1, 10));
//	m.insert(pair<int, int>(2, 30));
//	m.insert(pair<int, int>(3, 40));
//
//	if (m.empty()) {
//		cout << "m 为空" << endl;
//	}
//	else {
//		cout << "m 不为空" << endl;
//		cout << "m 大小"<<m.size() << endl;
//	}
//
//	map<int, int >m1;
//
//	m1.insert(pair<int, int>(4, 110));
//	m1.insert(pair<int, int>(5, 310));
//	m1.insert(pair<int, int>(6, 410));
//
//	cout << "交换前" << endl;
//	printMap(m);
//	printMap(m1);
//
//	cout << "交换后 " << endl;
//	m.swap(m1);
//	printMap(m);
//	printMap(m1);
//
//}


//map 插入和删除

//void test01() {
//	//插入
//	map<int, int>m;
//	m.insert(pair<int, int>(1, 10));
//
//	m.insert(make_pair(2, 22));
//
//	m.insert(map<int, int>::value_type(4, 33));
//	m[5] = 55;
//	cout << m[6] << endl;  //m[6] = 0 不建议用
//	// 但是可以用key 来访问value 
//
//	//删除
//	m.erase(m.begin());
//
//	//cout << m[2] << endl;
//	printMap(m);
//	m.erase(5);
//	printMap(m);
//
//	cout << "最后测试" << endl;
//	m.erase(m.begin(),m.end());
//	printMap(m);
//}


// map 容器查找和统计 
//void test01() {
//	// 查找
//
//	map<int, int> m;
//	m.insert(pair<int, int>(1, 19));
//	m.insert(pair<int, int>(2, 29));
//	m.insert(pair<int, int>(3, 39));
//	m.insert(pair<int, int>(3, 39));
//	m.insert(pair<int, int>(3, 39));
//
//	map<int,int>::iterator pos = m.find(3);
//	if (pos != m.end()) {
//		cout << "查到了元素key " << (*pos).first << "value = " << pos->second << endl;
//		
//	}else {
//		cout << "未找到了元素 " << endl;
//	}
//
//	//统计 map 中 不允许插入重复key 元素
//	int num = m.count(3);
//	cout << "num ===  " << num<< endl;
//}



// map 排序
void printMap1(map<int, int>& m) {
	

}
class myCompareMap {

public:
	bool operator()(int v1,int v2) const{
		
		// 降序
		return v1 > v2;
	}
};


void test01() {
	map<int, int , myCompareMap> m;

	m.insert(make_pair(1, 19));
	m.insert(make_pair(2, 29));
	m.insert(make_pair(3, 49));
	m.insert(make_pair(4, 9));
	for (map<int, int, myCompareMap>::iterator it = m.begin(); it != m.end(); it++) {
		cout << "key ---" << it->first << "value   " << (*it).second << endl;
	}

}

//int  main() {
//	test01();
//	system("pause");
//	return 0;
//}