#include "manager.h"



Manager::Manager(int id, string name, int dId) {
	
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
//��ʾ������Ϣ
void Manager::showInfo() {
	cout << "ְ�����: " << this->m_Id
		<< "\tְ������: " << this->m_Name
		<< "\t����: " << this->getDeptName()
		<< "\t ��λְ�� : ��ɾ�����������" << endl;
}
//��ȡ��λ����
string Manager::getDeptName() {
	
	return string("����");
}