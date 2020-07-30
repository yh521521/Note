#pragma once
#include <iostream>
using namespace std;
#include "identity.h"
#include "globalFile.h"
#include <fstream>
#include <vector>
#include "teacher.h"
#include "student.h"
#include "computerRoom.h"
#include<algorithm>


//����Ԫ����� 
class Manager :public Identity {
public:
	//Ĭ�Ϲ���
	Manager();

	//�вι���
	Manager(string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void cleanFile();

	//��ʼ������
	void initVector();

	// ���ȥ�� ����1 ���ѧ�� / ְ����  ����2  ������� 
	bool checkRepeat(int id ,int type);

	//ѧ������
	vector<Student>vStu;
	//��ʦ����
	vector<Teacher>vTea;

	//������Ϣ
	vector<ComputerRoom>vCom;
	
};