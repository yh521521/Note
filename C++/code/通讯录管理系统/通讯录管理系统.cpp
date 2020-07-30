//��װ������ʾ�ý���
//��main �����е��÷�װ�õĺ���
#include <iostream>
using namespace std;
#define MAX 1000

//�����ϵ�˽ṹ��
struct Person {
	//����
	string m_Name;
	//�Ա� 1 �� 2 Ů 
	int m_Sex;
	//����
	int m_Age;
	//�绰
	string m_Phone;
	//סַ 
	string m_Addr;

};

//���ͨѶ¼�ṹ��
struct Addressbooks {

	//ͨѶ¼�б������ϵ������
	struct Person personArray[MAX];
	//ͨѶ¼�е�ǰ��¼��ϵ�˸���
	int m_Size;
};
//��1 ����ϵ��

void addPerson(Addressbooks * abs) {
	
	//�ж�ͨѶ¼�Ƿ����� ������˾Ͳ����

	if (abs ->m_Size == MAX) {
		
		cout << "ͨѶ¼����,�޷����!";
			return;
	}
	else {
		//��Ӿ�����ϵ��
		//����
		string name;
		cout << "����������:   " << endl;
		cin >> name;
		abs ->personArray[abs->m_Size].m_Name = name;
		//�Ա�
		cout << "�������Ա�:" << endl;
		cout << "1-----��" << endl;
		cout << "2-----Ů" << endl;
		int sex = 0;
		while(true){
			//����������1 ��2 �����˳�ѭ�� ���������ȷֵ
			// ����������� ��������
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "�������� ����������" << endl;
		}
		
		//����
		cout << "����������:" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		//�绰
		cout << "��������ϵ�绰:" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//סַ
		cout << "�������ͥסַ:" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//���� ͨѶ¼����
		abs->m_Size++;
		cout << "��ӳɹ�" << endl;
		system("pause");// �밴���������
		//��������
		system("cls");

	}
}
//2 ��ʾ��ϵ��
void showPerson(Addressbooks *abs) {
	//�ж�ͨѶ¼�������Ƿ�Ϊ0 ���Ϊ0��ʾ��¼Ϊ��
	//��Ϊ0 ��ʾ��¼����ϵ����Ϣ
	if (abs->m_Size ==0) {
		cout << "��ǰ��¼Ϊ�� " << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size;i++) {
			cout << "���� "<<abs->personArray[i].m_Name << "\t";
			cout << "�Ա� "<<(abs->personArray[i].m_Sex ==  1 ? "��":"Ů"  )<< "\t";
			cout << "���� "<<abs->personArray[i].m_Age << "\t";
			cout << "�绰 "<<abs->personArray[i].m_Phone << "\t";
			cout << "סַ "<<abs->personArray[i].m_Addr << endl;
		}
	}
	// �밴���������
	system("pause");
	//��������
	system("cls");

}
//�����ϵ���Ƿ���� ������� ������ϵ�����������о���λ��,�����ڷ���-1 
//����1 ͨѶ¼ ����2 �Աȵ����� 
int isExist(Addressbooks* abs,string name) {

	for (int i = 0; i < abs->m_Size;i++) {
		//�ҵ��û����������
		if (abs->personArray[i].m_Name == name) {
			return i;
		}
	}
	//����������û���ҵ� ���� -1 
	return  -1;
}

//3 ɾ����ϵ��
void deletePerson(Addressbooks* abs) {

	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name); //���÷���  -1 δ�鵽 
	if (ret  != -1) {
		//���ҵ��˽���ɾ��
		for (int i = 0; i < abs->m_Size; i++)
		{
			// ����ǰ��  
			abs->personArray[i] = abs->personArray[i + 1];
		}
		//����ͨѶ¼�е������� 
		abs->m_Size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else {
		cout << "���޴���" << endl;
	}
	// �밴���������
	system("pause");
	//��������
	system("cls");

}

// 4 ����ָ����ϵ����Ϣ 
void findPerson(Addressbooks* abs) {
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	//�ж�ָ������ϵ���Ƿ����ͨѶ¼�� 
	int ret = isExist(abs, name);
	if (ret !=-1){
		cout << "����:" << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�:" << abs->personArray[ret].m_Sex << "\t";
		cout << "����:" << abs->personArray[ret].m_Age << "\t";
		cout << "�绰:" << abs->personArray[ret].m_Phone << "\t";
			cout << "סַ:" << abs->personArray[ret].m_Addr << endl;
		
	}
	else {
		cout << "���޴���" << endl;
	}
	// �밴���������
	system("pause");
	//��������
	system("cls");

}

//5 �޸�ָ����ϵ��
void modifyPerson(Addressbooks* abs) {

	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);

	if (ret != -1) {
		//����
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1 -- �� " << endl;
		cout << "2 -- Ů " << endl;
		
		int sex = 0;
		while (true) {
			
			cin >> sex;
			if (sex ==1 || sex ==2) {
				//������ȷ �˳�ѭ������
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "�������� ���������� " << endl;

		}
		
		//����
		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		//�绰 
		cout << "��������ϵ�绰:" << endl;
		string  phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//סַ
		cout << "��������ϵ��ͥסַ:" << endl;
		string  address ;
		cin >> address;
		abs->personArray[ret].m_Addr= address;
		

		cout << "�޸ĳɹ� !:" << endl;
	}
	else {
		cout << "���޴���" << endl;
	}
	// �밴���������
	system("pause");
	//��������
	system("cls");


}
//6 ���������ϵ��  
void cleanPerson(Addressbooks* abs) {

	abs->m_Size = 0;//��ͨѶ¼�е���������Ϊ0  ���߼�ɾ��
	cout << "ͨѶ¼�����" << endl;
	// �밴���������
	system("pause");
	//��������
	system("cls");
}


//1 �˵�����
void showMenu() {
	cout << "***********************" << endl;
	cout << "*****1. �����ϵ��*****" << endl;
	cout << "*****2. ��ʾ��ϵ��*****" << endl;
	cout << "*****3. ɾ����ϵ��*****" << endl;
	cout << "*****4. ������ϵ��*****" << endl;
	cout << "*****5. �޸���ϵ��*****" << endl;
	cout << "*****6. �����ϵ��*****" << endl;
	cout << "*****0. �˳�ͨѶ¼*****" << endl;
	cout << "***********************" << endl;
} 
int main() {

	//����ͨѶ¼�Ľṹ�����
	Addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.m_Size = 0;

	int select = 0;//�����û�ѡ������ı���

	while (true) {
		//�˵�����
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:  // �����ϵ��
			addPerson(&abs);
			break;
		case 2:  // 2 ��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3:
		/*{
			cout << "������ɾ����ϵ������" << endl;
			string name;
			cin >> name;
			if (isExist(&abs, name) == -1) {
				cout << "���޴���" << endl;
			}
			else {
				cout << "�ҵ�����" << endl;
			}


		}*/
		deletePerson(&abs);
			break;
		case 4:
			findPerson(&abs);
			break;
		case 5:
			modifyPerson(&abs);
			break;
		case 6:
			cleanPerson(&abs);
			break;
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}