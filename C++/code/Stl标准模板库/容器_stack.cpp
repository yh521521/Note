#include<iostream>
using namespace std;
#include <stack>
#include <queue>
#include <list>
#include<set>
#include<map>


////ջ���� 
//void test01() {
//	//�ص� �����Ƚ�������ݽṹ
//	stack<int>s;
//
//	//��ջ
//	s.push(10);
//	s.push(20);
//	s.push(30);
//	s.push(40);
//	s.push(50); 
//	cout << "ջ�Ĵ�С:" << s.size() << endl;
//
//
//	//ֻҪջ��Ϊ�� �鿴ջ�� ����ִ�г�ջ���� 
//	while (!s.empty()) {
//		
//		//�鿴ջ��Ԫ�� 
//		cout << "ջ��Ԫ��Ϊ:" << s.top() << endl;
//
//		//��ջ
//		s.pop();
//		cout << "ջ�Ĵ�С:" << s.size() << endl;
//
//	}
//
//
//}

//queue    �������� �Ƚ��ȳ� 
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
//	//׼������
//	Person p1 ("����",10);
//	Person p2 ("�ŷ�", 20);
//	Person p3 ("����", 30);
//	Person p4 ("����", 40);
//
//	//���
//	q.push(p1);
//	q.push(p2);
//	q.push(p3);
//	q.push(p4);
//
//	//�ж�ֻҪ���в�Ϊ�� �鿴��ͷ  �鿴��β ����
//	while (!q.empty()) {
//		//�鿴��ͷԪ��
//		cout << "��ͷԪ��--����:" << q.front().m_Name << "����" << q.front().m_Age<<endl;
//		cout << "��βԪ��--����:" << q.back().m_Name << "����" << q.back().m_Age<<endl;
//		//����
//		q.pop();
//
//
//	
//	
//	
//	}
//
//	cout << "���д�СΪ:" << q.size() << endl;
//}
//
//


//����list ����

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
//	//�������
//	L1.push_back(10);
//	L1.push_back(20);
//	L1.push_back(30);
//	L1.push_back(40);
//
//	//�������� 
//	printList(L1);
//	//���䷽ʽ���� 
//	list<int>L2(L1.begin(), L1.end());
//	printList(L2);
//
//	// ��������
//	list<int >L3(L2);
//	printList(L3);
//
//	//n ��elem 
//	list<int>L4(10, 155);
//	printList(L4);
//
//
//}

//��ֵ 
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


//���� 
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
//	cout << "����ǰ" << endl;
//	printList(L1);
//	printList(L2);
//
//	cout << "������" << endl;
//	L1.swap(L2);
//	printList(L1);
//	printList(L2);*/
//
//	printList(L1);
//	if (L1.empty()) {
//		cout << "L1 Ϊ��" << endl;
//	}
//	else {
//		cout << "L1�� Ϊ��" << endl;
//		cout << "L1 �ĸ���Ϊ" << L1.size() << endl;
//	}
//
//	//����ָ����С
//	L1.resize(10);
//	printList(L1);
//
//
//
//}


//void test01() {
//	list<int>L;
//	//β��
//	L.push_back(10);
//	L.push_back(20);
//	L.push_back(30);
//
//	//ͷ�� 
//	L.push_front(22);
//	L.push_front(33);
//	L.push_front(44);
//
//
//	printList(L);
//	//βɾ
//	L.pop_back();
//	//ͷɾ
//	L.pop_front();
//
//	printList(L);
//
//	//insert ���� 
//	list<int>::iterator it = L.begin();
//	L.insert(++it, 88);
//	//L.insert(L.begin(),456);
//	printList(L);
//
//	//ɾ��
//	it = L.begin();
//	L.erase(++it);
//	printList(L);
//
//	//�Ƴ�
//	L.push_back(2000);
//	printList(L);
//	L.remove(2000);  //remove ɾ�� ���� ƥ���2000 
//	printList(L);
//	
//	//���
//	L.clear();
//	printList(L);
//
//
//}

// list ���ݴ�ȡ
// ��list ���������ݽ��д�ȡ 

//void test01() {
//	list<int> L1;
//	L1.push_back(10);
//	L1.push_back(20);
//	L1.push_back(30);
//	L1.push_back(40);
//
//	cout << "��һ��Ԫ��Ϊ" << L1.front() << endl;
//	cout << "���һ��Ԫ��Ϊ" << L1.back() << endl;
//
//	// ��֤��������֧���������
//	list<int>::iterator it = L1.begin();
//	it++; //֧��˫��
//	it--;
//	//it = it+1  ��֧��������� 
//
//	printList(L1);
//
//}

// list ��ת 
//void test01() {
//	
//	list<int> L1;
//	L1.push_back(10);
//	L1.push_back(20);
//	L1.push_back(30);
//	L1.push_back(40);
//	L1.push_back(50);
//	
//	cout << "��תǰ" << endl;
//	printList(L1);
//	//��ת��
//	cout << "��ת��" << endl;
//	L1.reverse();
//	printList(L1);
//
//
//}



//bool myCompare(int v1,int v2) {
//	
//	// ����  �õ�һ���� > �ڶ�����
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
//	cout << "����ǰ" << endl;
//	printList(L1);
//	//��ת��
//	cout << "�����" << endl;
//	L1.sort(); // Ĭ������
//	printList(L1);
//
//	// ����
//	L1.sort(myCompare);
//	printList(L1);
//
//
//}



// �Զ��������� 
 // ����������� ���������ͬ������߽��н���

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
////ָ���������
//bool comparePerson(Person &p1,Person &p2) {
//	
//	//���������ͬ ������߽���
//	if (p1.m_Age == p2.m_Age) {
//		return  p1.m_Height > p2.m_Height;
//	}
//	//������������ 
//	return p1.m_Age < p2.m_Age;
//
//}




//void test01() {
//
//	list<Person> L; // ��������
//
//	Person p1("����" ,35  ,175);
//	Person p2("�ܲ�" ,45  ,180);
//	Person p3("��Ȩ" , 40 ,170);
//	Person p4("����" , 25 ,190);
//	Person p5("�ŷ�" , 35 ,160);
//	Person p6("����" ,  35,200);
//
//	//��������
//	L.push_back(p1);
//	L.push_back(p2);
//	L.push_back(p3);
//	L.push_back(p4);
//	L.push_back(p5);
//	L.push_back(p6);
//
//	for (list<Person>::iterator it = L.begin(); it != L.end();it++) {
//	
//		cout << "���� : " << (*it).m_Name << "   ����  " << (*it).m_Age << "  ���  " << (*it).m_Height << endl;
//	}
//	//����
//	cout << "�����: " << endl;
//	L.sort(comparePerson);
//	for (list<Person>::iterator it = L.begin(); it != L.end(); it++) {
//
//		cout << "���� : " << (*it).m_Name << "   ����  " << (*it).m_Age << "  ���  " << (*it).m_Height << endl;
//	}
//	
//}

//set �����Ĺ���͸�ֵ
//void  test01() {
//	set<int> s1;
//
//	//��������ֻ��insert  ��ʽ
//	s1.insert(10);
//	s1.insert(210);
//	s1.insert(30);
//	s1.insert(4);
//	s1.insert(6); //���������ظ��� 
//	s1.insert(6);
//
//
//	//�������� 
//	printSet(s1);
//
//	//�������� 
//	set<int>s2(s1);
//	printSet(s2);
//
//	//��ֵ
//	set<int>s3;
//	s3 = s2;
//	printSet(s3);
//}

//set ������С �ͽ��� 

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
//	//����ǰ
//
//	//�ж��Ƿ�Ϊ��
//	if (s1.empty()) {
//		cout << "s1 Ϊ��" << endl;
//	}
//	else {
//		cout << "s1 ��Ϊ��" << endl;
//		cout << "s1 ��size"<<s1.size() << endl;
//	}
//
//
//
//	//������
//	s1.swap(s2);
//	cout << "������" << endl;
//	printSet(s1);
//	printSet(s2);
//}
// set  ����ɾ��

//void test01() {
//	set<int> s1;
//	s1.insert(10);
//	s1.insert(30);
//	s1.insert(20);
//	s1.insert(60);
//	printSet(s1);
//
//	//ɾ��
//
//	s1.erase(s1.begin());
//	printSet(s1);
//
//	//ɾ�������ذ汾
//	s1.erase(30);
//	printSet(s1);
//
//
//	//��� 
//	s1.erase(s1.begin(), s1.end());
//	cout << "��ӡ" << endl;
//	printSet(s1);
//}


// set �����Ĳ��Һ�ͳ�� 
//void test01() {
//	//����
//	set<int>s1;
//
//	//��������
//	s1.insert(10);
//	s1.insert(30);
//	s1.insert(40);
//	s1.insert(60);
//
//	
//	set<int>::iterator pos = s1.find(300);
//	if (pos != s1.end()) {
//		cout << "�ҵ�Ԫ��" << *pos << endl;
//	}else {
//		cout << "δ �ҵ�Ԫ��" << endl;
//	}
//}
//
//
//void test02() {
//	
//	//����
//	set<int>s1;
//
//	//��������
//	s1.insert(10);
//	s1.insert(30);
//	s1.insert(30);
//	s1.insert(30);
//	s1.insert(40);
//	s1.insert(60);
//
//	// ͳ��30 �ĸ���
//	// ����set ���� ͳ�ƽ��ҪĪ` ��0 Ҫ�� �� 1 
//	int num = s1.count(30);
//	cout << "num = " << num << endl;
//}

// set ������multiset ����������

//void test01() {
//
//	set<int> s;
//	pair<set<int>::iterator,bool> ret = s.insert(10);
//	if(ret.second){
//		cout <<"��һ�β���ɹ�"<<endl;
//	}
//	else {
//		cout << "��һ�β���ʧ��" << endl;
//	}
//
//	 ret = s.insert(10);
//
//	 if (ret.second) {
//		 cout << "�ڶ��β���ɹ�" << endl;
//	 }
//	 else {
//		 cout << "�ڶ��β���ʧ��" << endl;
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


// pari ���鴴�� 
// �ɶԳ��ֵ����� �������ö��鷵����������

//void test01() {
//
//	// ��һ�ַ�ʽ
//	pair<string, int> p("tom",10);
//
//	cout << "����   " << p.first << "����   " << p.second << endl;
//
//	// �ڶ��ַ�ʽ
//	pair<string, int> p2 = make_pair("jerry", 30);
//	cout << "����   " << p2.first << "����   " << p2.second << endl;
//
//}



// set ��������  
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



//set �������� ����Զ�����������

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
//// �º���
//
//class comparePerson {
//
//public:
//	bool operator()(const Person&p1, const Person&p2)const
//	{
//		// �����併������
//		return p1.m_Age > p2.m_Age;
//	}
//};
//void test01() {
//
//
//	set<Person, comparePerson> s;
//	//����person ����  
//	Person p1("����",24 );
//	Person p2("����", 22);
//	Person p3("�ŷ�", 28);
//	Person p4("���� ",30 );
//
//	s.insert(p1);
//	s.insert(p2);
//	s.insert(p3);
//	s.insert(p4);
//	for (set<Person, comparePerson>::iterator it = s.begin(); it != s.end(); it++) {
//		cout << "  ���� " << it->m_Name << "����  " << it->m_Age << endl;
//	}
//}

// map ���� 


//��ӡmap ����
void printMap(map<int,int> &m) {
	for (map<int, int>::iterator it = m.begin(); it != m.end();it++) {
		cout <<"key ---" <<it->first <<  "value   " << (*it).second<< endl;
	}
	
}

//void test01() {
//
//	//����map����
//	map<int, int >m;
//	m.insert(pair<int, int>(1, 10));
//	m.insert(pair<int, int>(2, 20));
//	m.insert(pair<int, int>(3, 30));
//	m.insert(pair<int, int>(4, 40));
//
//	printMap(m);
//
//	// ��������
//	map<int, int>m2(m);
//	printMap(m2);
//
//	//��ֵ
//	map<int, int > m3;
//	m3 = m2;
//	printMap(m3);
//
//
//}


//map ������С�ͽ��� 
//void test01() {
//	map<int, int >m;
//
//	m.insert(pair<int, int>(1, 10));
//	m.insert(pair<int, int>(2, 30));
//	m.insert(pair<int, int>(3, 40));
//
//	if (m.empty()) {
//		cout << "m Ϊ��" << endl;
//	}
//	else {
//		cout << "m ��Ϊ��" << endl;
//		cout << "m ��С"<<m.size() << endl;
//	}
//
//	map<int, int >m1;
//
//	m1.insert(pair<int, int>(4, 110));
//	m1.insert(pair<int, int>(5, 310));
//	m1.insert(pair<int, int>(6, 410));
//
//	cout << "����ǰ" << endl;
//	printMap(m);
//	printMap(m1);
//
//	cout << "������ " << endl;
//	m.swap(m1);
//	printMap(m);
//	printMap(m1);
//
//}


//map �����ɾ��

//void test01() {
//	//����
//	map<int, int>m;
//	m.insert(pair<int, int>(1, 10));
//
//	m.insert(make_pair(2, 22));
//
//	m.insert(map<int, int>::value_type(4, 33));
//	m[5] = 55;
//	cout << m[6] << endl;  //m[6] = 0 ��������
//	// ���ǿ�����key ������value 
//
//	//ɾ��
//	m.erase(m.begin());
//
//	//cout << m[2] << endl;
//	printMap(m);
//	m.erase(5);
//	printMap(m);
//
//	cout << "������" << endl;
//	m.erase(m.begin(),m.end());
//	printMap(m);
//}


// map �������Һ�ͳ�� 
//void test01() {
//	// ����
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
//		cout << "�鵽��Ԫ��key " << (*pos).first << "value = " << pos->second << endl;
//		
//	}else {
//		cout << "δ�ҵ���Ԫ�� " << endl;
//	}
//
//	//ͳ�� map �� ����������ظ�key Ԫ��
//	int num = m.count(3);
//	cout << "num ===  " << num<< endl;
//}



// map ����
void printMap1(map<int, int>& m) {
	

}
class myCompareMap {

public:
	bool operator()(int v1,int v2) const{
		
		// ����
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