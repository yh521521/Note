#include <iostream>
using namespace std;
#include <ctime>
int main() {
	////c ����ַ���
	//cout << "hello world" << endl;

	//char str[] = "my self";
	//cout << str << endl;
	//string str2 = " asdas da";
	//cout << str2 << endl;
	////bool ���� true 1 false 0  һ���ֽ�

	////����bool ����
	//bool flag = true;
	//cout << flag << endl;
	//cout << "��ռ�ֽ�" << sizeof(flag) << endl;


	////���� ���� cin 
	////����
	//int a = 0;
	//cout << "������ͱ���a ��ֵ" << endl;
	//cin >> a;
	//cout << "������ͱ���a :" <<a<< endl;

	////������
	//float f = 3.14f;
	//cout << "��������ͱ���f ��ֵ" << endl;
	//cin >>f;
	//cout << "������ͱ���f :" << f << endl;

	////�ַ���
	//char c = 'y';
	//cout << "��������ͱ���c ��ֵ" << endl;
	//cin >>c;
	//cout << "������ͱ���c :" << c << endl;

	////�ַ�����
	//string c = "asdasdas";
	//cout << "����ַ����ͱ���c ��ֵ" <<c<< endl;
	//cin >> c;
	//cout << "����ַ����ͱ���c :" << c << endl;
	//bool ��
	/*bool flag = true;
	cout << "���bool�ͱ��� ��ֵ" << endl;
	cin >> flag;
	cout << "���bool�ͱ���flag :"<<flag << endl;*/

	//����� �Ӽ��˳�

	//int a = 10;
	//int b = 3;
	//cout << a + b << endl;
	//cout << a - b << endl;
	//cout << a * b << endl;
	//cout << a / b << endl;

	//int a1 = 10;
	//int b1 = 0;
	//cout << a1 / b1 << endl;
	//���������  ����
	/*cout << a % b << endl;*/

	/*double d1 = 3.14;
	double d2 = 1.1;*/
	//cout << d1 % d2;<<endl; ����
	// ǰ�� ���� ���� �ݼ�
	//++a;
	//cout << "��ӡaΪ :" << a << endl; //11
	////a++;
	//cout << "�ٴ����aΪ :" << a << endl; //11 

	// ǰ�úͺ��õ�����
	
	//cout << "�ٴ����a++ *10 Ϊ :" << a++ * 10 << endl; //100 
	//cout << "�ٴ����++a1 *10 Ϊ :" << ++a1 * 10 << endl; //110
	//cout << "�ٴ����a-- *10 Ϊ :" << a-- * 10 << endl; //100 
	//cout << "�ٴ����--a1 *10 Ϊ :" << --a1 * 10 << endl; //90

	//��ֵ����
	//
	//a = 100;
	//cout << "�ٴ����aΪ :" << a << endl; //11 
	//a = 11;
	//a += 2;
	//cout << "�ٴ����aΪ :" << a << endl; //11 


	// �Ƚ������

	//int a = 10;
	//int b = 20;
	//cout << (a == b) << endl;  //false 0 

	//cout << (a != b) << endl;  //true 1 

	//cout << (a >= b) << endl;  //false 0 

	//cout << (a <= b) << endl;  //true 1 


	//// �߼������ 
	//cout << !a << endl;  //false 0 

	//cout << !!a << endl;  //true 1 
	//cout << ( a &&b) << endl;  //true 1 
	//a = 0;
	//cout << (a && b) << endl;  //false 0 

	//a = 0;
	//b = 0;
	//cout << (a && b) << endl;  //false 0 

	//int a = 10;
	//int b = 20;
	//cout << (a || b) << endl;  //1

	// b = 0;
	//cout << (a || b) << endl;  // 1
	//a = 0;
	//cout << (a || b) << endl;  //0

	//ѡ��ṹ ��if ���
	// �û�������� ����> 600  ����һ����ѧ����Ļ�����
	
	//int score = 0;
	//cout << " ������һ������:" <<endl;
	//cin >> score;
	////��ӡ����ķ���
	//cout << "������ķ���Ϊ" << score << endl;
	//// �жϷ����Ƿ�> 600 ������� ��ħ���һ����ѧ
	//if (score > 600) {
	//	cout << "��ϲ������һ����ѧ"<< endl;

	// > 600 ����һ�� < 600δ ����һ����ѧ
	
	/*int score = 0;
	cout << "������һ�����Է���" << score << endl;
	cin >> score;
	if (score > 600) {
		cout << "��ϲ�㿼����һ����ѧ";
	}else {
		cout << "��δ����һ����ѧ";
	}*/
	
	//������ѡ��ṹ
	//
	//int score = 0;
	//cout << "�����뿼�Է���" << endl;
	//cin >> score;

	//if (score > 600) {
	//	cout << "��ϲ�� ����һ����ѧ"<< endl;
	//}
	//else  if (score > 500 ) {
	//	cout << "��ϲ�� ���϶�����ѧ" << endl;
	//}
	//else if (score > 400) {
	//	cout << "��ϲ�� ����������ѧ" << endl;
	//}
	//else {
	//	cout << "δ���� ���ƴ�ѧ" << endl;
	//}
	//int score = 0;
	//cout << "������߿�����;" << endl;
	//cin >> score;
	//cout << "������ķ���Ϊ'" <<score << endl;

	//// �������ж�
	//if (score > 600) {
	//	cout << "��ϲ �㿼��һ����ѧ" << endl;
	//	if (score > 700) {
	//		cout << " ���ܿ��ϱ�����ѧ" << endl;
	//	}
	//	else if(score > 650) {
	//		cout << "���ܿ����廪��ѧ" << endl;
	//	}
	//	else {
	//		cout << "���ܿ��������ѧ" << endl;
	//	}
	//}
	//else if (score >500) {

	//	cout << "��ϲ �㿼�϶�����ѧ" << endl;
	//}
	//else if (score > 400) {

	//	cout << "��ϲ �㿼��������ѧ" << endl;
	//}
	//else {
	//	cout << "δ���ϴ�ѧ ���ڽ�����" << endl;
	//}

	// ��ֻС�������
	//
	//int num1 = 0;
	//int num2 = 0;
	//int num3 = 0;
	//
	////���û���������ֻС�������

	//cout << " ������С��a ������" << endl;
	//cin >> num1;

	//cout << " ������С��b������" << endl;
	//cin >> num2;

	//cout << " ������С��c ������" << endl;
	//cin >> num3;

	//cout << " С��a ������" <<num1 << endl;
	//cout << " С��b ������" <<num2 << endl;
	//cout << " С��c ������" <<num3 << endl;
	//
	//// �ж���ֻ ���� 
	//if (num1 > num2 ) {
	//	if (num1 >num3) {
	//		cout << "С��a ���� " << endl;
	//	}
	//	else {
	//		cout << "С��c ���� " << endl;
	//	}
	//}
	//else {
	//	if (num2 > num3) {
	//		cout << "С��b ���� " << endl;
	//	}
	//	else {
	//		cout << "С��c ���� " << endl;
	//	}

	//}


	//��Ŀ�����
	 //������������a b c 
	// �� a  b ���Ƚ� ����������ֵ ��ֵ��c 
	/*int a = 10;
	int b = 12;
	int c = 0;
	c = (a > b ? a : b);
	cout << "��Ŀ����� " << c<<endl;*/

	//switch ���
	// ����Ӱ���д��
	// 10  �־���
	// 8 �ַǳ���
	//6 һ��
	//5 ������ ��Ƭ
	// ��ʾ�û�����Ӱ����
	//cout << "�����Ӱ���д��" << endl;
	//int score = 0;
	//cin >> score;
	//cout << "���ķ���Ϊ" << score << endl;

	//// �����û�����ķ�������ʾ�û����Ľ��
	//switch (score) {
	//	case 10:
	//		cout << "����Ϊ�Ǿ����Ӱ" << endl;
	//		break; // �˳���ǰ�ķ�֧
	//	case 9:
	//		cout << "����Ϊ�Ǿ����Ӱ" << endl;
	//		break;
	//	case 8:
	//		cout << "����Ϊ�ǵ�Ӱ�ǳ���" << endl;
	//		break;
	//	case 7:
	//		cout << "����Ϊ�ǵ�Ӱ�ǳ���" << endl;
	//		break;
	//	default:
	//		cout << "����Ϊ��Ӱһ���" << endl;
	//}
	// if switch ����
	//switch ȱ�� �ж�֮�������ͻ����ַ��� ��������һ������
	//�ŵ� �ṹ����ִ��Ч�ʸ� 

	// while ѭ��
	// ����Ļ�д�ӡ0 - 9 ��10 ������
	//int num = 0;
	//cout << num << endl;
	//// while ѭ��
	//num++;
	//cout << num << endl;
	// ����������ѭ��
	/*while (num < 10)
	{
		cout << num << endl;
		++num;
		
	}*/

	 // ��������Ϸ
	
	// ������������ ���� ���õ�ǰϵͳʱ�������������ֹÿ���������һ��

	srand((unsigned int)time(NULL));
	// 1 ϵͳ��������� 
	int num = rand() % 100+1; // 1 - 100 ������ 
	//cout << num << endl;
	
	//2 ��ҽ��в²�
	int val = 0;  //��� ���������

	while (1) {
		cin >> val;

		// 3 �ж���ҵĲ²�
		if (val > num) {
			cout << "�²����";
		}
		else if (val < num) {
			cout << "��С��" << endl;
		}
		else {
			cout << "��ϲ��¶���" << endl;
			break; //����ѭ��
		}
		// �¶� �˳���Ϸ
		// �´� ��ʾ�µĽ�� ���� ��С ���½��еڶ��� 

	}
	





	system("pause");
	return 0;




}




