#include <iostream>
using namespace std;
//ȫ�ֱ�������
int g;
//int11 main() {
	//sizeof �ؼ��� ����������ռ�ڴ��С
	short num1 = 199;
	cout << "short ��ռ���ڴ�ռ�Ϊ:" << sizeof(short) << "\n";
	int num2 = 199;
	cout << "num2 ��ռ���ڴ�ռ�Ϊ:" << sizeof(num2) << endl;
	long num3 = 199;
	cout << "num3 ��ռ���ڴ�ռ�Ϊ:" << sizeof(num3) << endl;
	long long  num4 = 199;
	cout << "num4 ��ռ���ڴ�ռ�Ϊ:" << sizeof(num4) << endl;

	cout << "string:\t" << "��ռ�ֽ���:" << sizeof(string) << endl;
	cout << "size_t: \t" << "��ռ�ֽ���" << sizeof(size_t);
	cout << "\t���ֵ:" << (numeric_limits<size_t>::max)();
	cout << "\t��Сֵ:" << (numeric_limits<size_t>::min)()<<endl;

	typedef short duan;
	cout << "duan ��ռ���ڴ�ռ�Ϊ:" << sizeof(duan) << endl;
	duan num_duan = 20;
	
	//�ֲ��������� 
	int a, b;
	int c;

	//ʵ�ʳ�ʼ��
	a = 10;
	b = 20;
	c = a + b;

	g = a + b;
	cout << "��ӡc�Ľ��:" << c<<endl;
	cout << "��ӡg�Ľ��:" << g<<endl;
	

	short int i; // �з��Ŷ����� 
	short unsigned int j;
	short signed int z;

	j = 5000;
	i = 4444444;
	z = 33;
	cout << i << endl;
	cout << j << endl;
	cout << z << endl;



	// ����� 
	int e = 22;
	int f = 11;
	

	if (e == f) {
		cout << "line 1  e ����f" << endl;

	}
	else {
		cout << "line 1  e ������f" << endl;
	}

	//�߼������
	if (e&&f) {
		cout << "line 1  e fΪ��" << endl;
	}
	else {
		cout << "line 1  e f��Ϊ��" << endl;
	}
	if (!(e &&f)) {
		cout << "����Ϊ��" << endl;
	}
	else {
		cout << "����Ϊ�� " << endl;

	}

	//λ���� 
	unsigned int g1 = 60;
	unsigned int h1 = 13;
	int i1 = 0;
	int j1 = 0;
	i1 = g1 & h1;
	cout << "λ���� & ���Ϊ" << i1 << endl;

	j1 = g1 | h1;
	cout << "λ���� | �Ĳ���ʱ" << j1<< endl;


	for (;;) {
		printf("This loop will run forever \n");
	}
	
	system("pause");
	return 0;



}
