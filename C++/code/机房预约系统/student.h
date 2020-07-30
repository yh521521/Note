#pragma once
#include <iostream>
#include <fstream>
using namespace std;
#include "identity.h"
#include "computerRoom.h"
#include "globalFile.h"
#include "orderFile.h"
#include <vector>

//ѧ����
class Student :public Identity {
public:
	//Ĭ�Ϲ���
	Student();
	//�вι���
	Student(int id, string name, string pwd);
	// �˵�����
	virtual void operMenu();
	//����ԤԼ
	void applyOrder();
	// �鿴����ԤԼ
	void showOrder();
	//�鿴����ԤԼ
	void showAllOrder();
	// ȡ��ԤԼ
	void cancelOrder();

	//ѧ��ѧ�� 
	int m_Id;

	// �������� 
	vector<ComputerRoom>vCom;


};