#include <iostream>
using namespace std;
#include<vector>
#include<algorithm> // c++ �Դ����㷨
#include<functional> // �ڽ��ĺ�������
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


// //�������󳬳���ͨ���� �ĸ��� ����������������Լ��� ״̬ 
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
//	int count; //�ڲ��Լ���״̬
//};
//
//void test02() {
//	MyPrint myPrint;
//	myPrint("you are my ");
//	myPrint("you are my ");
//	myPrint("you are my ");
//	myPrint("you are my ");
//
//	cout << "myPrint ���õĴ���" << myPrint.count << endl;
//}
//
//
//
//
//
//// 3 �������������Ϊ��������
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

// �º��� ����ֵ����δbool ���� ��֮Ϊν��
// һԪ ν�� 

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
//	//������������û�д���5 ������  ������������
//
//	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
//	if (it == v.end()) {
//		cout << "δ�ҵ� " << endl;
//	}
//	else {
//		cout << "���ҵ� " <<*it << endl;
//	}
//}

//// ��Ԫν�� 
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
//	// ʹ�ú�������ı��㷨����  ��Ϊ�������δ�Ӵ�С
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


// �ڽ� ��������

// �����º���

//void test01() {
//	
//	negate<int> n;  
//	cout << n(50);  // ȡ���ķº��� 
//}
//void test02() {
//	plus<int>p;
//	cout << p(10, 22);
//
//}


// ��ϵ�º���
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
//	// ���� 
//	//sort(v.begin(), v.end(), myCompare());
//	// ϵͳ�ڽ��ĺ�������
//	sort(v.begin(), v.end(), greater<int>());
//
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}

//�߼��º���
//�߼���

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
//	 // �����߼��� ������v ���˵�����v2 �� ��ִ��ȡ������
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

//���õı����㷨 

////��ͨ����
//void  print01(int val) {
//	cout << val << "   ";
//}
//
//// �º���
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

//������������һ�������� 
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
//	vector<int> v;// ԭ����
//	for (int i = 0; i < 10; i++)
//	{
//		v.push_back(i); 
//	}
//
//	vector<int> vTarget;// Ŀ������
//	vTarget.resize(v.size()); // ���ٿռ�
//	transform(v.begin(), v.end(),vTarget.begin(), Transform());
//	for_each(vTarget.begin(), vTarget.end(), myPrint());
//
//
//	cout << endl;
//
//}


// ���õĲ����㷨
//void test01() {
//	vector<int>v;
//	for (int i = 0; i < 10; i++)
//	{
//		v.push_back(i);
//	}
//
//	vector<int>::iterator it =  find(v.begin(),v.end(),5);
//	if (it == v.end()) {
//		cout << "û���ҵ�" << endl;
//	}else {
//		cout << "�ҵ�" << *it <<endl;
//	}
//
//	// �����������Ƿ��� 5    ����
//}
//
//// �����Զ����������� 
//
////����find �������������ҵ�ָ����Ԫ��  ����ֵ�ǵ�����
//class Person {
//
//public:
//	Person(string name,int age) {
//		this->m_Name = name;
//		this->m_Age = age;
//	}
//
//	// ���� == �ײ�find ֪����ζԱ�perso �������� 
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
//	//��������
//	Person p1("aa" ,10);
//	Person p2("bb" ,40);
//	Person p3("vv" ,20);
//	Person p4("dd" ,0);
//
//	//���뵽������
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//	v.push_back(p4);
//	vector<Person>::iterator it = find(v.begin(), v.end(), p3);
//	if (it == v.end()) {
//		cout << "û���ҵ�" << endl;
//	}
//	else {
//		cout << "�ҵ���  ����" << it->m_Name << "  ����  "<<it->m_Age<< endl;
//	}
//}
// ��������


// �����������в���Ԫ��
// ������������ģ��

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
//		cout << "û���ҵ�" << endl;
//	}
//	else {
//		cout << "�ҵ���  " <<*it<< endl;
//	}
//}
//
//
//// �Զ�����������
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
//	//��������
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
//	//�ҵ��������20 ����
//	vector<Person>::iterator it = find_if(v.begin(), v.end(), Grater20());
//	if (it == v.end()) {
//		cout << "û���ҵ�" << endl;
//	}
//	else {
//		cout << "�ҵ���  ���� " << it->m_Name  << "���� "<< it->m_Age << endl;
//	}
//
//}
//
//



// �������ڵ��ظ�Ԫ�� adjacent _find
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
//		cout << " δ�ҵ������ظ�Ԫ��" << endl;
//	}
//	else {
//		cout << " �ҵ������ظ�Ԫ��" <<*pos << endl;
//	}
//
//}


// ���ֲ����㷨
//void test01() {
//	vector<int> v;
//	for (int i = 0; i < 10; i++)
//	{
//		v.push_back(i);
//
//	}
//	v.push_back(2);
//	// ��������������9 Ԫ��
//	// ��������������   �������������  �������δ֪�� 
//	bool ret = binary_search(v.begin(), v.end(), 9);
//	if (ret) {
//		cout << "�ҵ���" << endl;
//	}
//	else {
//		cout << "δ�ҵ� " << endl;
//	}
//}

// ͳ��Ԫ�ظ��� 
//void test01() {
//	vector<int>v;
//	v.push_back(10);
//	v.push_back(40);
//	v.push_back(50);
//	v.push_back(20);
//	v.push_back(40);
//
//	int num = count(v.begin(), v.end(), 40);
//	cout << "40 ��Ԫ�ظ���Ϊ " << num << endl;
//}
//
//// ͳ���Զ�����������
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
//	Person  p1("���� ",33 );
//	Person  p2(" ����",33 );
//	Person  p3(" �ŷ�",33 );
//	Person  p4(" �ܲ�",44 );
//	Person  p5("���� ",18 );
//	// ���뵽������
//	v.push_back(p1 );
//	v.push_back(p2 );
//	v.push_back(p3 );
//	v.push_back(p4 );
//	v.push_back(p5 );
//	Person p("�����", 33);
//	int num = count(v.begin(), v.end(), p);
//	cout << "�������ͬ�����Ա����Ϊ" <<num << endl;
//
//}

// ������������
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
//	cout << "�����д���20 �ĸ���" << num << endl;
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
//	// �ԱȵĹ����в���ȥ�޸���
//	bool operator()(const Person &p) {
//		return p.m_Age > 20;
//	}
//};
//void test02() {
//	
//	vector<Person> v;
//
//	Person  p1("���� ", 33);
//	Person  p2(" ����",33 );
//	Person  p3(" �ŷ�",33 );
//	Person  p4(" �ܲ�",44 );
//	Person  p5("���� ",18 );
//
//
//	v.push_back(p1 );
//	v.push_back(p2 );
//	v.push_back(p3 );
//	v.push_back(p4 );
//	v.push_back(p5 );
//	
//	int num = count_if(v.begin(), v.end(), AgeGreater20());
//	cout << "����20 �����Ա����Ϊ" <<num << endl;
//}

// ���õ������㷨
//void  myPrint(int val) {
//	cout << " ���" << val << endl;
//}
//void test01() {
//	vector<int> v;
//	v.push_back(12);
//	v.push_back(2);
//	v.push_back(33);
//	v.push_back(4);
//	v.push_back(0);
//	v.push_back(66);
//	// sort ���� Ĭ������
//	sort(v.begin(), v.end());
//	for_each(v.begin(), v.end(), myPrint);
//	cout << endl;
//
//	// �ı�Ϊ����
//	cout << " ---------------"<< endl;
//	sort(v.begin(), v.end(),greater<int>());
//	for_each(v.begin(), v.end(), myPrint);
//	cout << endl;
//
//}

// random_shuffle ���� 

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
//	// ����ϴ�� �㷨 ����˳��
//	random_shuffle(v.begin(), v.end());
//
//	for_each(v.begin(), v.end(), myPrint);
//	cout << endl;
//
//
//}

// merge �ϲ��㷨  ������������ �������





//void test01() {
//	vector<int> v1;
//	vector<int> v2;
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//		v2.push_back(i + 1);
//
//	}
//	// Ŀ������
//	vector<int> VTarget;
//	// ��Ŀ����������ռ�
//	VTarget.resize(v1.size() + v2.size());
//	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), VTarget.begin());
//	for_each(VTarget.begin(), VTarget.end(), myPrint);
//}


// reverse  ������Ԫ�ؽ��з�ת

void test01() {
	vector<int> v;
	v.push_back( 10);
	v.push_back( 20);
	v.push_back(30 );
	v.push_back(40 );
	v.push_back(50 );
	cout << "' ��תǰ " << endl;
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
	cout << "' ��ת��  " << endl;
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