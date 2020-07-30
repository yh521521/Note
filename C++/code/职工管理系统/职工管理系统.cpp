#include <iostream>
using namespace std;
#include "workerManager.h"
#include "worker.h"  // 职工
#include "employee.h"  // 普通员工
#include "manager.h"  // 经理
#include "boss.h"  // 总裁
int main() {
	
	////.测试代码
	//Worker* worker = NULL;
	//worker = new Employee(1, "远方", 1);
	//worker->showInfo();
	//delete worker;

	//worker = new Manager(2, "小王", 2);
	//worker->showInfo();
	//delete worker;

	//worker = new Boss(3, "佟掌柜", 3);
	//worker->showInfo();
	//delete worker;
	//实例化管理者对象
	WorkerManager wm;

	//用户选择标志
	int choice = 0;
	while (true) {
	//调用展示菜单成员函数
		wm.ShowMenu();
		cout << "请输入您的选择:" << endl;
		cin >> choice; //接收用户的选项
		switch (choice) {
		case 0: // 退出系统
			wm.ExitSystem();
			break;
		case 1: // 增加职工
			wm.Add_Emp();
			break;
		case 2://显示职工
			wm.show_Emp();
			break;
		case 3:// 删除职工
			wm.Del_Emp();
			break;
	
		case 4:// 修改职工
			wm.Mod_Emp();
			break;
		case 5://查找职工
			wm.Find_Emp();
			break;
		case 6://排序职工
			wm.Sort_Emp();
			break;
		case 7://清空文档
			wm.Clean_File();
			break;
		default:
			system("cls"); //清屏 
			break;
		}
	}
	
	system("pause");
	return 0;

}