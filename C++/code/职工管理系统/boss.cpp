#include "boss.h"



Boss::Boss(int id, string name, int dId) {

	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
//��ʾ������Ϣ
void Boss::showInfo() {
	cout << "ְ�����: " << this->m_Id
		<< "\tְ������: " << this->m_Name
		<< "\t����: " << this->getDeptName()
		<< "\t ��λְ�� : ��ɾ�����������" << endl;


}
//��ȡ��λ����
string Boss::getDeptName() {

	return string("�ܲ�");
}