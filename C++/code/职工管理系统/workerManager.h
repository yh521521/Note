#pragma once // ��ֹͷ�ļ��ظ����� 
#include <iostream> // ��������������ռ�
using namespace std; //��׼�����ռ�
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream> # //�ļ�������ͷ�ļ�

#define FILENAME "empFile.txt"

class WorkerManager {
public:
	//���캯��
	WorkerManager();

	//չʾ�˵�
	void ShowMenu();
	// �˳�ϵͳ
	void ExitSystem();
	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker ** m_EmpArray;

	// ���ְ�� 
	void Add_Emp();

	// �����ļ� 
	void save();

	// �ж��ļ��Ƿ�Ϊ�� ��־ 
	bool m_FileIsEmpty;

	// ͳ���ļ������� 
	int get_EmpNum();

	// ��ʼ��Ա��
	void init_Emp();

	// ��ʾְ��
	void show_Emp();

	// ɾ��ְ��
	void Del_Emp();

	// �ж�ְ���Ƿ���� ������ڷ���ְ�����������е�λ�� �����ڷ���-1 
	int  IsExist(int id );

	//�޸�ְ��
	void Mod_Emp();

	//����ְ��
	void Find_Emp();

	//���ձ������
	void Sort_Emp();

	//����ļ� 
	void Clean_File();

	//��������
	~WorkerManager();


	
};