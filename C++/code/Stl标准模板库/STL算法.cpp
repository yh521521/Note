#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<numeric>
#include<set>



void myPrint(int val) {
	cout << val << "  ";
	
}
// ���õĿ������滻�㷨 

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
//	cout << "�滻ǰ " << endl;
//
//	for_each(v.begin(), v.end(), myPrint);
//	cout << endl;
//
//	//��20  �滻Ϊ 222
//
//	replace(v.begin(), v.end(),20,222 );
//
//	cout << "�滻�� " << endl;
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
//	cout << "�滻ǰ" << endl;
//
//	for_each(v.begin(), v.end(), myPrint);
//	cout << endl;
//	
//	// ����20 ���滻Ϊ444
//	replace_if(v.begin(), v.end(), Greater30(), 444);
//
//	cout << "�滻�� " << endl;
//
//	for_each(v.begin(), v.end(), myPrint);
//	cout << endl;
//
//
//}


// ���� swap 

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
//	cout << " ����ǰ" << endl;
//	for_each(v1.begin(), v1.end(), myPrint);
//	cout << endl;
//	for_each(v2.begin(), v2.end(), myPrint);
//	cout << endl;
//
//	cout << " ������" << endl;
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
//	// ��ʼ�ۼ�ֵ 1000 
//	int total = accumulate(v.begin(),v.end(),1000);
//	cout << "�ܺ�:    " << total << endl;
//}

// �������
//void test01() {
//	vector<int>v;
//	v.resize(10);
//	
//
//	// �����������
//	fill(v.begin(), v.end(), 100);
//	for_each(v.begin(), v.end(), myPrint);
//	cout << endl;
//}


// ���ü����㷨
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
//	// Ŀ������
//	vector <int> vTarget;
//
//	// Ŀ��������Ҫ���ٿռ�
//	//��������� ����������С���� ���ٿռ� ȡС������size ����
//	vTarget.resize(min(v1.size(), v2.size()));
//
//	// ��ȡ����
//	vector<int>::iterator itEnd =   set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
//	for_each(vTarget.begin(), itEnd, myPrint);
//	cout << endl;
//
//
//}
//

//����  
void test01() {
	vector <int> v1;
	vector <int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);

	}

	// Ŀ������
	vector <int> vTarget;
	// ���ٿռ� 
	// ��������� ��������û�н���  ��������size ���

	vTarget.resize(v1.size()+v2.size());

	vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myPrint);
	cout << endl;

}


// �  

void test02() {
	vector <int> v1;
	vector <int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);

	}

	// Ŀ������
	vector <int> vTarget;
	// ���ٿռ� 
	// ��������� ��������û�н���  ȡ���������д� ��size ��Ϊ���ٿռ�
	vTarget.resize(max(v1.size(),v2.size()));

	cout << "v1 ��v2 �ĲΪ" << endl;

	vector<int>::iterator itEnd=    set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myPrint);
	cout << endl;


	cout << "v2 ��v1 �ĲΪ" << endl;

	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myPrint);
	cout << endl;
}
int main() { 
	
	test02();
	system("pause");
	return 0;
}
