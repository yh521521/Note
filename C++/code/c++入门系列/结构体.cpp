#include <iostream> 
using namespace std;



// 1����ѧ����������
struct Student {
	// ��Ա�б�
	string name;
	int age;
	int score;
};
// ��ʦ�ṹ��
//struct teacher {
//	int id;// ��ʦ���
//	string name; // ��ʦ����
//	int age;//���� 
//	struct Student stu;//������ѧ��
//};
//}stu; 
// stu ����һ���ṹ�����
//2 ͨ��ѧ������ ���������ѧ��

//ֵ����

//�������е��βθ�Ϊָ��,���Լ����ڴ�ռ� ���Ҳ��Ḵ�Ƴ��µĸ���

void printStudnet1(const Student *stu) {
	//����const ��һ�����޸� �ᱨ��   ��ֹ�����
	//stu->age = 100;
	cout << "�Ӻ�������:" << stu->name << "����:" << stu->age << "����" << stu->score;

}
// ��ַ����
void printStudnet2(struct Student *stu) {
	stu->age = 100;
	cout << "�Ӻ���2����:" << stu->name << "����:" << stu->age << "����" << stu->score;

}

int main() {

	// 1 
	/*struct Student s1;
	s1.name = "����";

	s1.age = 19;
	s1.score = 100;

	cout << "����:" << s1.name << "����:" << s1.age << "����" << s1.score;*/

	/*struct Student s1 = { "����",19 ,80 };
	cout << "����:" << s1.name << "����:" << s1.age << "����" << s1.score; */

	/*stu.name = "����";
	stu.age = 22;
	stu.score = 110;

	cout << "����:" << stu.name << "����:" << stu.age << "����" << stu.score;*/


	//// �����ṹ������
	//struct Student stuArray[3] = {
	//	{"����",19,100},
	//	{"����", 18, 10},
	//	{"����",22,60}
	//};
	//stuArray[2].name = "����";
	//stuArray[2].age = 66;
	//stuArray[2].score = 33;
	//// �����ṹ��
	//for (int i = 0; i < 3;i++) {

	//	cout << "����:" << stuArray[i].name << "����:" << stuArray[i].age << "����" << stuArray[i].score <<endl;
	//}
	//

	//ָ��ṹ�� 
	//����ѧ���ṹ�����
	//struct Student s = { "����",19 ,80 }; ����ṹ���������ʡ��struct �ؼ���
	//Student s = { "����",19 ,80 };
	//2 ͨ��ָ��ָ��ṹ����� 
	//int* p = &s; ��ƥ��
	//Student * p = &s; //
	//ͨ��ָ����ʽṹ������е�����
	//cout << "����" << p->name << "����" << p->age << "����" << p->score<<endl;


	// Ƕ�׽ṹ�� 
	// ��ʦ����һ��ѧ�� ��һ����ʦ�Ľṹ���� ��¼һ��ѧ���Ľṹ�� 

	//teacher t;
	//t.id = 10001;
	//t.name = "����";
	//t.age = 50;
	//t.stu.name = "Сѧ��a";
	//t.stu.age = 18;
	//t.stu.score = 60;
	//cout << "����" << t.name << "����" << t.age << "ѧ������" << t.stu.score << endl;
	// �ṹ������������

	//�����ṹ�����
	//struct Student stu;
	//stu.name = "����";
	//stu.age = 20;
	//stu.score = 99;
	//
	////printStudnet1(stu);

	//printStudnet2(&stu);

	//cout << "����:" << stu.name << "����:" << stu.age << "����" << stu.score;
 //	
	struct Student stu = { "����",15,70 };

	printStudnet1(&stu);
	//ͨ��������ӡ�ṹ�������Ϣ
	system("pause");
	return 0;
}