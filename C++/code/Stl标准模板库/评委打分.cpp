#include<iostream>
using namespace std;
#include <vector> //����
#include <deque>// ����
#include <algorithm>
#include<ctime> // ���������Ҫ��ɣ
/*
	5��ѡ�� ѡ��abcde 10 ����ί��ֶ�ÿһ��ѡ�ִ�� ȥ����߷� 
	ȥ����ͷ� ȡ��ƽ����
*/

class Person {


public:
	Person(string name,int score){
	
		this->m_Name = name;
		this->m_Score = score;
	}
	
	
	
	string m_Name;//����
	  int m_Score;// ƽ����

};
void createPerson(vector<Person>&v) {

	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{	

		string name = "ѡ��";
		name += nameSeed[i];

		int score = 0;
		Person p(name,score);
		// ��������person ������뵽������
		v.push_back(p);
	}

}


//���
void getScore(vector<Person>&v) {
	
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//����ί�ķ������뵽deque ������
		deque<int>d;
		for (int  i = 0; i < 10; i++)
		{
			int score = rand()%41+60;// 60 -100 �����
			d.push_back(score);
		}

		// ������ί����ķ���
		cout << "ѡ��  " << it->m_Name << "  ����   " << it->m_Score<<endl;
		/*for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++) {


			cout << (*dit) << "    ";
		}
		cout << endl;*/


		// ���� �����㷨����  Ĭ������
		sort(d.begin(), d.end());
		// ȥ����߷� ȥ����ͷ�
		d.pop_back(); //ȥ�����һ��Ԫ��
		d.pop_front();//ȥ����һ��Ԫ��
		

		// ȡƽ����
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++) {
			

			sum += *dit;// �ۼ�ÿ����ί�ķ���
		}
		int avg = sum / d.size();
		//��ƽ���� ��ֵ��ѡ������
		it->m_Score = avg;
	}
}

void showScore(vector<Person>& v) {
	
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "����:   " << it->m_Name << "  ƽ����:  " << it->m_Score << endl;
	}

}
int main() {
	
	// ���������
	srand((unsigned int)time(NULL));

	// ����5��ѡ�� 
	vector<Person>v; // ���ѡ�ֵ�����
	createPerson(v);
	/*for (vector<Person>::iterator it = v.begin();it!= v.end(); it++)
	{
		cout << "��ӡ����  " << (*it).m_Name << "  ����   " << (*it).m_Score<<endl;
	}*/

	//2 ��5��ѡ�ִ��
	getScore(v);

	//3 ��ʾ���÷�
	showScore(v);
}