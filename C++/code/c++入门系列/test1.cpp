#include<iostream>
#include <ctime>;
using namespace std;



//����ѧ���Ľṹ��
struct Student {
	//����
	string sName;
	//����
	int score;
};

//��ʦ�ṹ��Ķ���
struct Teacher {
	//����
	string tName;
	//ѧ������
	struct Student sArray[5];
};
//����ʦ��ѧ����ֵ�ĺ���
void allocateSpace(struct Teacher tArray[], int len) {

	string nameSeed = "ABCDE";
	//����ʦ��ֵ
	for (int i = 0; i < len; i++) {
		tArray[i].tName = "Teacher_";
		tArray[i].tName += nameSeed[i];
		//ͨ��ѭ����ÿ����ʦ������ѧ����ֵ
		for (int j = 0; j < 5; j++) {
			tArray[i].sArray[j].sName = "Student_";
			tArray[i].sArray[j].sName += nameSeed[j];
			int random = rand() % 60 + 40;
			tArray[i].sArray[j].score = random;
			//��ӡ������ʦ������ѧ����Ϣ	}


		}
	}

};
//��ӡ������Ϣ
void printInfo(struct Teacher tArray[], int len) {

	for (int i = 0; i < len; i++) {
		cout << "��ʦ����" << tArray[i].tName << endl;
		for (int j = 0; j < 5; j++) {
			
			cout << "\tѧ������" << tArray[i].sArray[j].sName << " ���Է���: " << tArray[i].sArray[j].score << endl;
		}
	}
};


int main() {
	//�������
	srand((unsigned int)time(NULL));


	//����������ʦ������
	struct Teacher tArray[3];
	int len = sizeof(tArray) / sizeof(tArray[0]);
	allocateSpace(tArray, len);

	//ͨ��������3����ʦ����Ϣ��ֵ  ,��������ѧ����Ϣ��ֵ
	printInfo(tArray, len);
}