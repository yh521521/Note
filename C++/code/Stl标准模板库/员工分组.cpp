#include<iostream>
using namespace std;
#include<vector>
#include<ctime>
#include<map>


#define CEHUA 0
#define MEISHU 1
#define YANFA 2


class Worker {
public:
	string m_Name;
	int m_salary;
};

void createWorker(vector<Worker>&v) {
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10;i++) {
		Worker worker;
		worker.m_Name = "Ա��";
		worker.m_Name += nameSeed[i];
		worker.m_salary = rand() % 10000 + 10000;

		//��Ա�����뵽������
		v.push_back(worker);
	}
};
// Ա������
void setGroup(vector<Worker>& v, multimap<int, Worker>& m) {

	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++) {

		//����������ű��
		int deptId = rand() % 3;
		// ��Ա�����뵽������ key ���ű�� value ���ű��
		m.insert(make_pair(deptId, *it));

	}
};
// ������ʾԱ��
void showWorkerByGroup(multimap<int,Worker>&m) {
	//0 abc 1 de 2 fg
	cout << "�߻�����" << endl;
	multimap<int,Worker>::iterator pos = m.find(CEHUA);
	int count = m.count(CEHUA);// ͳ�ƾ�������
	int index = 0;
	for (; pos != m.end()&&index <count;pos++,index++) {
		
		cout << " ����: " << pos->second.m_Name << "  н��  " << pos->second.m_salary << endl;
	}

	cout << "--------------------" << endl;
	cout << "��������" << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU);// ͳ�ƾ�������
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++) {

		cout << " ����: " << pos->second.m_Name << "  н��  " << pos->second.m_salary << endl;
	}


	cout << "--------------------" << endl;
	cout << "�з�����" << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA);// ͳ�ƾ�������
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++) {

		cout << " ����: " << pos->second.m_Name << "  н��  " << pos->second.m_salary << endl;
	}

}
//int main() {
//	// �������
//	srand((unsigned int)time(NULL));
//	//����Ա��
//	vector<Worker>vWorker;
//	createWorker(vWorker);
//
//	//Ա������
//	multimap<int, Worker>mWorker;
//	setGroup(vWorker,mWorker);
//
//	// ������ʾԱ��
//	showWorkerByGroup(mWorker);
//
//	////����
//	//for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end();it++) {
//	//	
//	//	cout << "����  " << it->m_Name << " нˮ  " << it->m_salary <<endl;
//	//}
//	system("pause");
//	return 0;
//}