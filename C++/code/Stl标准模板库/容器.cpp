#include <iostream>
using  namespace std;
#include <vector>
#include <algorithm>  // ��׼�㷨ͷ�ļ�
#include<deque>
//vector ���� ���������������


//void myPrint(int val ) {
//	cout << "��ӡ���"<< val << endl;
//}
//
//void test01() {
//
//	// ������һ��vector ����
//	vector<int > v;
//	// �������в�������
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(40);
//
//
//	// ��η�����  ͨ���������ķ�ʽ����
//	vector<int>::iterator itBegin = v.begin(); // ��ʼ������ ָ�������еĵ�һ��Ԫ��
//	vector<int>::iterator itEnd = v.end(); // ���������� ָ�����������һ��Ԫ�ص���һ��λ��
//
//	// ��һ�ֱ��� 
//	/*while(itBegin != itEnd )
//	{
//		cout << *itBegin << endl;
//		itBegin++;
//	}*/
//
//	// �ڶ��ֱ��� 
//	//for (vector<int>::iterator it = v.begin();it != v.end(); it++)
//	//{
//	//	cout << "*it ---- " << *it << endl;
//	//}
//
//	// �����ֱ�����ʽ
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
//	//���������������
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//	v.push_back(p4);
//	v.push_back(p5);
//
//	// ���������е����� (*it ) person ��������
//	for (vector<Person>::iterator it = v.begin();it!= v.end(); it++)
//	{
//		//cout << "���� : " << (*it).m_Name << "   ����:  " << (*it).m_Age << endl;
//		cout << "���� : " << it->m_Name << "   ����:  " << it->m_Age << endl;
//	}
//}
//// �Զ�����������
//void test02() {
//	vector<Person*> v;
//	Person p1("aaa", 10);
//	Person p2("aaa", 20);
//	Person p3("aaa", 30);
//	Person p4("aaa", 40);
//	Person p5("aaa", 50);
//
//	//���������������
//	v.push_back(&p1);
//	v.push_back(&p2);
//	v.push_back(&p3);
//	v.push_back(&p4);
//	v.push_back(&p5);
//
//	//�������� 
//	for (vector<Person *>::iterator it = v.begin();it != v.end();it++)
//	{
//		cout << "����: " << (*it)->m_Name << "���� :" << (*it)->m_Age << endl;
//	}
//}


////����Ƕ������
//
//void test01() {
//	//������
//	vector<vector<int>> v;
//	//����С����
//	vector<int> v1;
//	vector<int> v2;
//	vector<int> v3;
//	vector<int> v4;
//
//	//��С�����������
//	for (int i = 0; i < 4;i++) {
//		v1.push_back(i + 1);
//		v2.push_back(i + 2);
//		v3.push_back(i + 3);
//		v4.push_back(i + 4);
//	}
//
//	//С�������뵽��������
//	v.push_back(v1);
//	v.push_back(v2);
//	v.push_back(v3);
//	v.push_back(v4);
//
//	//ͨ�������� ���������ݱ���һ��
//	for (vector<vector<int>>::iterator it = v.begin(); it != v.end();it++) {
//		cout << "��ʼ��ӡ " <<endl;
//		
//		//(*it)  ----.vector<int>  ����һ������
//		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++) {
//			cout << *vit <<"  ";
//		}
//
//		cout << endl;
//	}
//
//}

//string �Ĺ��캯�� 


//void test01() {
//	string s1; // Ĭ�Ϲ���
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



//string �ĸ�ֵ����

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

//string �ַ���ƴ��

//void test01() {
//	string str1 = "��";
//	str1 += "������Ϸ";
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


//���Һ��滻
 ///1 ����

//void test01() {
//	string str1 = "abcdef";
//	int pos = str1.find("d");
//	if (pos == -1) {
//		cout << "δ�ҵ�" << endl;
//	}
//	else {
//		cout << "�ҵ�" << pos<< endl;
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
//// �滻 
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
		cout << "str1����str2" << endl;
	}else if (str1.compare(str2)>0) {
			cout << "str1����str2" << endl;
	}
}*/

//�ַ���ȡ string 

//void test01() {
//	string  str = "hello";
//	cout << "str---" << str << endl;
//
//	//ͨ��[] ���ʵ����ַ� 
//	//for (int  i = 0; i < str.size(); i++)
//	//{
//	//	cout << " str[i]---" << str[i] << "    ";
//	//	
//	//}
//
//	//ͨ��at ��ʽ���ʵ����ַ�
//	for (int i = 0; i < str.size(); i++)
//	{
//		cout << str.at(i) << "    ";
//	}
//	cout << endl;
//	//�޸ĵ����ַ� 
//	/*str[0] = 'x';
//	cout << "str---" << str << endl;*/
//
//	str.at(1) = 'a';
//	cout << "str---" << str << endl;
//}


// �ַ����Ĳ����ɾ��
//void test01() {
//	string str = "helloyh";
//	// ����
//	str.insert(1, "1111");
//	cout << "str===" << str << endl;
//
//	//ɾ��
//	str.erase(1,2);
//	cout << "str===" << str << endl;
//
//}



// ���ַ����л�ȡ��Ҫ���ִ�

//void test01() {
//	string str = "abcdef";
//	string subStr = str.substr(1, 3);
//	cout << "subStr=" << subStr << endl;
//}
//void test02() {
//	string email = "zhangsan@qq.com";
//
//	//���ʼ���ַ�л�ȡ�û���Ϣ
//
//	int pos =email.find("@");
//	string usrName = email.substr(0, pos);
//	cout << "usrName=" << usrName << endl;
//}



//vector ��������

//��ӡ 
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
//	//ͨ�����䷽ʽ���й���
//	vector<int> v2(v1.begin(), v1.end());
//	printVector(v2);
//
//
//	// n ��elem ��ʽ����
//	vector<int> v3(10, 12);
//	printVector(v3);
//
//	//��������
//	vector<int> v4(v3);
//	printVector(v4);
//
//}

//vector ��ֵ 

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
//	// ��ֵ 
//	vector <int> v2;
//	v2 = v1;
//	printVector(v2);
//
//	//assigm ��ֵ
//	vector<int> v3;
//	v3.assign(v1.begin(), v1.end());
//	printVector(v3);
//
//	// N ��elem ��ʽ��ֵ
//	vector<int> v4;
//	v4.assign(10, 1123);
//	printVector(v4);
//
//}


//vector �����������ʹ�С����


// ��ӡ���
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
//	if (v1.empty()) { // Ϊ�� ����Ϊ��
//		cout << " ����Ϊ��" << endl;
//	}
//	else {
//		cout << " ������Ϊ��" << endl;
//		cout << " ����Ϊ" << v1.capacity()<< endl;
//		cout << " ��СΪ" << v1.size()<< endl;
//
//	}
//
//	// ����ָ����С
//	//v1.resize(15);
//	v1.resize(15,23); // �������صİ汾 ����ָ������Ĭ��ֵ  ����2 
//	printVector(v1); // �������ָ���ı�ԭ������ Ĭ����0 ȥ���
//
//	v1.resize(5); // �����ԭ���Ķ��� �������ֻᱻɾ��
//	
//	printVector(v1);
//}


// �����ɾ��

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
//	//β��
//	v1.push_back(10);
//	v1.push_back(20);
//	v1.push_back(30);
//	v1.push_back(40);
//

//	//����
//	printVector(v1);
//
//	//βɾ
//	v1.pop_back();
//	printVector(v1);
//
//	//����
//	v1.insert(v1.begin(), 100);
//	printVector(v1);
//	v1.insert(v1.begin(),2, 1001);
//	printVector(v1);
//
//	//ɾ��
//	v1.erase(v1.begin());
//	printVector(v1);
//	//v1.erase(v1.begin(),v1.end());
//	v1.clear();
//	cout << " @@@@@@@@@@@@@@@@@@@@@@@" << endl;
//	printVector(v1);
//}




 //vector �������ݴ�ȡ

 //void test01() {
	// vector<int> v1;
	// for (int i = 0; i < 10;i++) {
	//	 v1.push_back(i);
	// }

	// //for (int  i = 0; i < v1.size(); i++)
	// //{
	//	// cout << v1[i] << "   ";
	// //}

 //vector �������� 


 //void test01() {
	// vector<int> v1;
	// for (int i = 0; i < 10; i++)
	// {
	//	 v1.push_back(i);

	// }
	// cout << "����ǰ " << endl;
	// printVector(v1);

	// vector<int>v2;
	// for (int i = 10; i >0; i--)
	// {
	//	 v2.push_back(i);
	// }

	// printVector(v2);

	// cout << "������  " << endl;

	// v1.swap(v2);
	// printVector(v1);
	// printVector(v2);
 //}

 ////ʵ����;
 //void test02() {
	// vector<int> v;
	// for (int i = 0; i < 10000; i++)
	// {
	//	 v.push_back(i);

	// }

	// cout << "v�������� " << v.capacity() << endl;
	// cout << "v�Ĵ�С�� " << v.size() << endl;

	// v.resize(3);
	// cout << "v�������� " << v.capacity() << endl; //��������
	// cout << "v�Ĵ�С�� " << v.size() << endl;

	// //����swap �����ڴ� 
	// vector<int>(v).swap(v);
	// cout << "v�������� " << v.capacity() << endl; 
	// cout << "v�Ĵ�С�� " << v.size() << endl;

 //}
	// cout << endl;

	// //����at ��ʽ����Ԫ��
	// for (int i = 0; i < v1.size(); i++)
	// {
	//	 cout << v1.at(i) << "   ";
	// }

	// cout << endl;

	// //���ص�һ��Ԫ��
	// cout << "��һ��Ԫ��Ϊ:" << v1.front() << endl;

	// cout << "���һ��Ԫ��Ϊ:" << v1.back() << endl;
 //}



//vector Ԥ���ռ�

 //void test01() {
	// vector<int> v;


	// // ����everse Ԥ���ռ�
	// v.reserve(1000000);

	// int num = 0;
	// int* p = NULL;
	// for (int  i = 0; i < 1000000; i++)
	// {
	//	 v.push_back(i);

	//	 if (p != &v[0]) {
	//		 cout << "��ӡp----- " << p << endl;
	//		 p = &v[0];
	//		 num++;
	//		 cout << "��ӡnum ---- " << num << endl;
	//	 }
	// }

	// cout << "num" << num << endl;
 //}

//////deque �Ĺ��캯��
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

//deque ��ֵ����
 //void test01() {
	// deque<int> d1;
	// for (int i = 0; i < 10; i++)
	// {
	//	 d1.push_back(i);
	// }

	// printVector(d1);

	//  //operator = ��ֵ
	// deque<int>d2;
	// d2 = d1;
	// printVector(d2);

	// //asign ��ֵ 
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
	//	 cout << "d1 Ϊ��" << endl;
	// }
	// else {
	//	 cout << "d1 ��Ϊ��" << endl;
	//	 cout << "d1 ��С" << d1.size() <<endl;
	//	//deque ����û��  ��������

	//	 //����ָ����С
	//	 //d1.resize(16);
	//	// d1.resize(16,1);
	//	 d1.resize(4);
	//	 printVector(d1);

	// }
 //}


//deque ���� 
 //void test01() {
	// deque<int> d1;

	// //β��
	// d1.push_back(10);
	// d1.push_back(20);
	// //ͷ�� 
	// d1.push_front(100);
	// d1.push_front(200);

	// printDeque(d1);

	// //βɾ
	// d1.pop_back();
	// printDeque(d1);

	// //ͷɾ
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

	// //inset ����
	// d1.insert(d1.begin(), 1000);
	// printDeque(d1);


	// d1.insert(d1.begin(),2, 520);
	// printDeque(d1);


	// //����������в��� 
	// deque<int> d2;
	// d2.push_back(1);
	// d2.push_back(2);
	// d2.push_front(3);
	// d2.push_front(4);

	// d1.insert(d1.begin(), d2.begin(), d2.end());
	// printDeque(d1);
	// //ɾ�� 
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
	// // β��ͷ�� 
	// d.push_back(10);
	// d.push_back(20);
	// d.push_back(30);
	// d.push_front(100);
	// d.push_front(200);
	// d.push_front(300);

	//// ͨ��[] �����hi����Ԫ��
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

	// cout << "��һ��Ԫ��Ϊ" << d.front() <<endl;
	// cout << "���һ��Ԫ��Ϊ" << d.back() <<endl;
 //}


//deque �������� 
 void test01() {
	 deque<int> d;
	 d.push_back(10);
	 d.push_back(20);
	 d.push_back(30);
	 d.push_front(100);
	 d.push_front(200);
	 d.push_front(300);
	

	 printDeque(d);


	 //deque �������� algorithm

	// Ĭ������ 
	 cout << "����� " << endl;
	 sort(d.begin(), d.end());
	 printDeque(d);
 }

int main() {
	test01();
	system("pause");
	return 0;
}