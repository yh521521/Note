#include <iostream>
// Ϊ��ʹ����ѧ����ĺ������� <cmath>
#include<cmath>
//ϵͳʱ�� 
#include <ctime> 
#include <iomanip>
#include <cstdlib>
using namespace std;
//using std::setw;

////��������
//int max(int num1, int num2);
//
int  main() {
//	//�ֲ���������
//	int a = 100;
//	int b = 200;
//	int ret;
//	//���ú�������ȡ���ֵ
//	ret = max(a, b);
//	cout << "Max value is:" << ret << endl;
//	return 0;
//}
//
////���������������нϴ���Ǹ���
//int max(int num1, int num2) {
//	//�ֲ���������
//	int result;
//	if (num1 > num2) {
//		result = num1;
//	}
//	else {
//		result = num2;
//	}
//
//	return result;
//}

////��������  �൱�ڸ�һ��Ĭ��ֵ  û��b ��ֵ ����Ĭ��
//int sum(int a, int  b = 20) {
//	int result;
//	result = a + b;
//	return result;
//}
//int main() {
//	//�ֲ���������
//	int a = 100;
//	int b = 200;
//	int result;
//
//	//���� ������ b ��ֵ
//	result = sum(a, b);
//	cout << "total value is :" << result << endl;
//
//	//���ú��� ����b ��ֵ   ʹ��Ĭ�� 
//	result = sum(a);
//	cout << "total value is :" << result << endl;
//	//���ֶ���
//	short s;
//	int i;
//	long l;
//	float f;
//	double d;
//	//���ָ�ֵ
//	s = 10;
//	i = 1000;
//	l = 1000000;
//	f = 230.44;
//	d = 3333.1234;
//
//	//�������
//	cout << "short s is :" << s << endl;
//	cout << "int i is :" << i << endl;
//	cout << "long l is :" << l << endl;
//	cout << "float f is :" << f << endl;
//	cout << "double d is :" << d << endl;
//
//
//	//��ѧ����
//	cout << "sin(d)" << sin(d) << endl;
//	cout << "abs(i)" << abs(i) << endl;
//	cout << "sqrt(f)" << sqrt(f) << endl;
//	cout << "pow(d,2)" << pow(d, 2) << endl;
//
//	int y, z;
//	//��������
//	//srand((unsigned)time(NULL));
//	//����10 �������
//	for (y = 0; y < 10; y++) {
//		//����ʵ�ʵ������
//		z = rand();
//		cout << "�����" << z << endl;
//
//	}
//	//����һ������
//	int n[10];
//	//��ʼ������Ԫ��
//	for (int i = 0; i < 10;i++ ) {
//		//�޸����е�Ԫ��
//		n[i] = i + 100;
//
//	}
//	cout << "Element" << setw(13) << "Value" << endl;
//
//	//�������ÿ��Ԫ�ص�ֵ
//	for (int j = 0; j < 10; j++) {
//		cout << setw(7) << j << setw(13) << n[j] << endl;
//	}
//	//����ַ��� 
//	char greeting[6] = { 'h','e','l','l','o','\0' };
//	cout << "Greeting message : ";
//	cout <<greeting << endl;

	//�ַ����Ļ�������
	char str1[11] = "Hello";
	char str2[11] = "World";
	char str3[11];
	int len;

	//���� str1 ��str3 
	strcpy(str3, str1);
	cout << "�ַ�����copy ���� " << str3 << endl;
	//cat ���Ӳ���
	strcat(str1, str2);
	cout << "�ַ�����cat ���� " << str1 << endl;
	//���Ӻ� str1 ���ܳ���
	len = strlen(str1);
	cout << "�ַ�������Ϊ " << len << endl;

	int var1;
	char var2[10];
	cout << "var1 �ı�����ַ " << &var1 << endl;
	cout << "var2 �ı�����ַ " << &var2 << endl;

	//int *ip;// һ������ ��ָ��
	//double *dp; //һ��double��ָ��
	//float *fp;//һ�������͵�ָ��
	//char *ch; // һ���ַ��͵�ָ��

	int var = 20;
	int *ip;
	ip = &var;//��ָ������д洢var �� ��ַ
	//�����ָ������д洢�ĵ�ַ
	cout << "address in ip variable:  " << ip << endl;
		//����ָ���е�ַ��ֵ 

	cout << "address in ip variable:   " << *ip << endl;

	//�����򵥵ı���
	int i;
	double d;

	//�������ñ���

	int& r = i;
	double& s = d;
	i = 5;
	cout << "value of i " << i << endl;

	cout << "value of i reference " << r << endl;
	d = 11.7;
	cout << "value of d " << d << endl;
	 
	cout << "value of d reference " << s << endl;
	// ���� <ctime>

	////���ڵ�ǰϵͳ�ĵ�ǰ���� ʱ��
	//time_t now = time(0);

	//	// �� now ת��Ϊ�ַ�����ʽ
	//char* dt = ctime(&now);
	//cout << "����ʱ�������" << dt << endl;

	////�� now תΪtm �ṹ
	//tm* gmtm = gmtime(&now);
	//dt = asctime(gmtm);

	//cout << "UTC����ʱ�������" << dt << endl;
	//
	// ����Ŀǰϵͳ�ĵ�ǰ���� /ʱ��

	time_t now = time(0);
	cout << "1970 ��Ŀǰ��������" << now << endl;
	tm* ltm = localtime(&now);

	//���tm �ṹ�ĸ�����ɲ���

	cout << "��" << 1900 + ltm->tm_year << endl;
	cout << "��" << 1 + ltm->tm_mon << endl;
	cout << "��" << ltm->tm_mday << endl;
	cout << "ʱ��" <<ltm->tm_hour << endl;
	cout  << ltm->tm_min << ":";

	cout <<  ltm->tm_sec << endl;


	//c++ �Ļ����������
	//��׼�����
	char str[] = " Hello C++";
	cout << "Value of str is :" << str << endl;
	//��׼������

	char name[50];

	cout <<"�������������";
	cin >> name;

	cout << "����������:" << name << endl;

	// ��׼������
	char str22[] = "Unable to read ....";
	cerr << "Error message :" << str22 << endl;
	//��׼��־�� 
	char str33[] = "Unable to read....";
	clog << "Error message:" << str33 << endl;
	return 0;
}
