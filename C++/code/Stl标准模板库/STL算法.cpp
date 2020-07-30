#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<numeric>
#include<set>



void myPrint(int val) {
	cout << val << "  ";
	
}
// 常用的拷贝和替换算法 

class mPrint {

public:
	void operator()(int val) {
		cout << "  " << val;
	}
};

//void test01() {
//
//	vector<int> v1;
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//	}
//
//	vector<int> v2;
//	v2.resize(v1.size());
//	copy(v1.begin(),v1.end(),v2.begin());
//	for_each(v2.begin(), v2.end(), myPrint);
//
//	cout << endl;
//}


// replace

//void test01() {
//	vector<int> v;
//	v.push_back(20);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(11);
//	v.push_back(0);
//	v.push_back(22);
//	v.push_back(55);
//	cout << "替换前 " << endl;
//
//	for_each(v.begin(), v.end(), myPrint);
//	cout << endl;
//
//	//将20  替换为 222
//
//	replace(v.begin(), v.end(),20,222 );
//
//	cout << "替换后 " << endl;
//
//	for_each(v.begin(), v.end(), myPrint);
//	cout << endl;
//
//}


// replace if

class Greater30 {
public:
	bool operator()(int val) {
		return val >= 20;
	}
};

//void test01() {
//	vector<int> v;
//	v.push_back(20);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(11);
//	v.push_back(0);
//	v.push_back(22);
//	v.push_back(55);
//
//
//	cout << "替换前" << endl;
//
//	for_each(v.begin(), v.end(), myPrint);
//	cout << endl;
//	
//	// 大于20 的替换为444
//	replace_if(v.begin(), v.end(), Greater30(), 444);
//
//	cout << "替换后 " << endl;
//
//	for_each(v.begin(), v.end(), myPrint);
//	cout << endl;
//
//
//}


// 互换 swap 

//void test01() {
//	vector<int > v1;
//	vector<int > v2;
//
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//		v2.push_back(i+100);
//	}
//
//	cout << " 交换前" << endl;
//	for_each(v1.begin(), v1.end(), myPrint);
//	cout << endl;
//	for_each(v2.begin(), v2.end(), myPrint);
//	cout << endl;
//
//	cout << " 交换后" << endl;
//	cout << " ++++++++++++++" << endl;
//	swap(v1, v2);
//
//	for_each(v1.begin(), v1.end(), myPrint);
//	cout << endl;
//	for_each(v2.begin(), v2.end(), myPrint);
//	cout << endl;
//
//}


//void test01() {
//	vector<int>v;
//	for (int  i = 0; i <= 100; i++)
//	{
//		v.push_back(i);
//	}
//	// 起始累加值 1000 
//	int total = accumulate(v.begin(),v.end(),1000);
//	cout << "总和:    " << total << endl;
//}

// 填充数据
//void test01() {
//	vector<int>v;
//	v.resize(10);
//	
//
//	// 后期重新填充
//	fill(v.begin(), v.end(), 100);
//	for_each(v.begin(), v.end(), myPrint);
//	cout << endl;
//}


// 常用集合算法
//void test01() {
//	vector <int> v1;
//	vector <int> v2;
//	for (int  i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//		v2.push_back(i + 5);
//
//	}
//
//	// 目标容器
//	vector <int> vTarget;
//
//	// 目标容器需要开辟空间
//	//最特殊情况 大容器包含小容器 开辟空间 取小容器的size 即可
//	vTarget.resize(min(v1.size(), v2.size()));
//
//	// 获取交集
//	vector<int>::iterator itEnd =   set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
//	for_each(vTarget.begin(), itEnd, myPrint);
//	cout << endl;
//
//
//}
//

//并集  
void test01() {
	vector <int> v1;
	vector <int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);

	}

	// 目标容器
	vector <int> vTarget;
	// 开辟空间 
	// 最特殊情况 两个容器没有交集  并集就是size 相加

	vTarget.resize(v1.size()+v2.size());

	vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myPrint);
	cout << endl;

}


// 差集  

void test02() {
	vector <int> v1;
	vector <int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);

	}

	// 目标容器
	vector <int> vTarget;
	// 开辟空间 
	// 最特殊情况 两个容器没有交集  取两个容器中大 的size 作为开辟空间
	vTarget.resize(max(v1.size(),v2.size()));

	cout << "v1 和v2 的差集为" << endl;

	vector<int>::iterator itEnd=    set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myPrint);
	cout << endl;


	cout << "v2 和v1 的差集为" << endl;

	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myPrint);
	cout << endl;
}
int main() { 
	
	test02();
	system("pause");
	return 0;
}
