#include <iostream>
using namespace std;
#include <fstream> // ����ͷ�ļ�


////�ı��ļ�д�ļ�
//void test01() {
//	//1 ����ͷ�ļ�
//
//	//2 ����������
//
//	ofstream ofs;
//
//	//3 ָ���򿪵ķ�ʽ
//	ofs.open("test.txt", ios::out);
//
//	//4 д����
//	ofs << "����: ����" << endl;
//	ofs << "�Ա�: ��" << endl;
//	ofs << "����: 18" << endl;
//
//	// 5 �ر��ļ�
//	ofs.close();
//
//};


//���ļ�

//void test02() {
//	//1 ����ͷ�ļ� 
//	// 2 ����������
//	ifstream ifs;
//	//���ļ��ж��Ƿ�򿪳ɹ�
//	ifs.open("test.txt", ios::in);
//	if (!ifs.is_open()) {
//		cout << " �ļ���ʧ��" << endl;
//		return;
//	}
//	// ������
//	//��һ��
//	/*char buf[1024] = { 0 };
//	while (ifs >> buf) {
//		cout <<buf << endl;
//	}*/
//	//�ڶ��ֶ�ȡ 0  ��ʼ������
//	/*char buf[1024] = { 0 };  
//	while (ifs.getline(buf,sizeof(buf))) {
//		cout << buf << endl;
//	}*/
//
//	//������
//	// EOF end  of file  �ļ�β�� 
//	char c;
//	while ((c = ifs.get())!= EOF) {
//		cout << c ;
//	}
//	
//	//����
//	ifs.close();
//
//}

// �������ļ�  д�ļ�

//class Person {
//		
//public:
//	char m_Num[64]; //����
//	int m_Age;
//};
//void test01() {
//	// 1 ����ͷ�ļ�
//	//2 ����������
//	// ����Ҫд��
//	ofstream ofs("person.txt", ios::out | ios::binary);
//	
//	//3 ���ļ�
//	//ofs.open("person.txt",ios::out||ios::binary);
//	// 4 д�ļ�
//	Person p = { "Ԭ��",18 };
//
//	ofs.write((const char*)&p,sizeof(Person));
//
//	//�ر��ļ�
//	ofs.close();
//}

// 
class Person {

public:
	char m_Name[64];
	int m_Age;

};

// �������ļ�  ���ļ�
void test01() {
	// ����ͷ�ļ�   fstream 
	// ����������
	ifstream ifs;
	// ���ļ�
	//�ж��ļ��Ƿ���Դ򿪳ɹ�
	ifs.open("person.txt", ios::in | ios::binary);
	if (!ifs.is_open()) {
		cout << "�ļ���ʧ��";
			return;
	}

	// ���ļ�
	Person p;
	ifs.read((char*)&p, sizeof(Person));
	cout << "������   " << p.m_Name << "����   " << p.m_Age << endl;

	//�ر��ļ�
	ifs.close();
	
}
int main() {
	test01();
}