#include <iostream>
using namespace std;
#include "workerManager.h"
#include "worker.h"  // ְ��
#include "employee.h"  // ��ͨԱ��
#include "manager.h"  // ����
#include "boss.h"  // �ܲ�
int main() {
	
	////.���Դ���
	//Worker* worker = NULL;
	//worker = new Employee(1, "Զ��", 1);
	//worker->showInfo();
	//delete worker;

	//worker = new Manager(2, "С��", 2);
	//worker->showInfo();
	//delete worker;

	//worker = new Boss(3, "١�ƹ�", 3);
	//worker->showInfo();
	//delete worker;
	//ʵ���������߶���
	WorkerManager wm;

	//�û�ѡ���־
	int choice = 0;
	while (true) {
	//����չʾ�˵���Ա����
		wm.ShowMenu();
		cout << "����������ѡ��:" << endl;
		cin >> choice; //�����û���ѡ��
		switch (choice) {
		case 0: // �˳�ϵͳ
			wm.ExitSystem();
			break;
		case 1: // ����ְ��
			wm.Add_Emp();
			break;
		case 2://��ʾְ��
			wm.show_Emp();
			break;
		case 3:// ɾ��ְ��
			wm.Del_Emp();
			break;
	
		case 4:// �޸�ְ��
			wm.Mod_Emp();
			break;
		case 5://����ְ��
			wm.Find_Emp();
			break;
		case 6://����ְ��
			wm.Sort_Emp();
			break;
		case 7://����ĵ�
			wm.Clean_File();
			break;
		default:
			system("cls"); //���� 
			break;
		}
	}
	
	system("pause");
	return 0;

}