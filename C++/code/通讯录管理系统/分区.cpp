#include <iostream>
using namespace std;
//// ȫ�ֱ���
//int g_a = 10;
//int g_b = 10;
//
////ȫ�ֳ���
//const int c_g_a = 10;

//ջ��
//int*  func() {
//	int a = 10;
//	return &a;
//	
//}

//int * fun() {
//	
//
//	//����new �ؼ��� ���Խ����ݿ��ٵ����� 
//	int* p = new int(10);
//	return p;
//}
//
//int* func() {
//	//����������������
//
//	//new ���ص��Ǹ��������͵�ָ�� ��new ��ʲĪ�������� 
//	//���صľ��Ǹ��������� ��ָ��
//
//	int* p = new int(10);
//	return p;
//}
//
//void test01() {
//	int* p = func();
//	cout << *p << endl; //������
//	cout << *p << endl; //������
//	cout << *p << endl; //������
//	//��ȥ������ �ɳ���Ա������ ����Ա�����ͷ�
//	//������ͷŶ��������� ���ùؼ���  delete 
//	delete p;//�ڴ��Ѿ��ͷ� �ٴη��ʾ��ǷǷ�����
//	cout << *p << endl; //������
//}
//
////2��������new  ��������
//void test02() {
//	
//	//���� �������� �ڶ���
//	int *arr = new int[10];//10��Ԫ��
//	for (int i = 0; i < 10;i++) {
//		arr[i] = i + 100;//
//	}
//	for (int i = 0; i < 10; i++) {
//		cout <<arr[i]<<endl;
//	}
//
//	//�ͷ�
//	delete[] arr;
//
//}
////1�βδ���
//void mySwap01(int a ,int b) {
//	int temp = a;
//	a = b;
//	b = temp;
//	cout << "swap01 a=" << a << endl;
//	cout << "swap01 b=" << b << endl;
//
//}
//
//void mySwap02(int *a, int * b) {
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//	cout << "swap01 a=" << a << endl;
//	cout << "swap01 b=" << b << endl;
//
//}
////���ô���
//void mySwap03(int& a, int& b) {
//	int temp = a;
//	a = b;
//	b = temp;
//	cout << "swap03 a=" << a << endl;
//	cout << "swap03 b=" << b << endl;
//
//}
//
////��Ҫ���ؾֲ�����������
//
//int& test001() {
//	
//	int a = 10;//j�ֲ����������ջ��
//	return a;
//}
//
//// 2 �����ĵ��ÿ�����Ϊ��ֵ
//int& test002() {
//
//	static int a = 10;
//	return a;
//}
//// 
//void showValue(int &val){
//	
//	cout << "val = "<<val <<endl;
//}

//����Ĭ�ϲ���
//int  func(int a,int b= 3 ,int c=11) {
//
//	return a + b + c;
//}
//// ���ĳ��λ���Ѿ�����Ĭ�ϲ��� ��������λ������ �������Ҷ�������Ĭ��ֵ 
//int  func2(int a, int b , int c = 3) {
//
//	return a + b + c;
//}





//int func3(int a = 10, int b= 1);
//int func3(int a ,int b ) {
//
//	return a + b ;
//
//}


//ռλ����   �ڶ���int  ����ռλ
//void func(int a,int ) {
//	cout << "this is func" << endl;
//}

//��������
//�����ú�������ͬ��߸�����  
//�������� 
// 1 ͬһ��������  ����������ͬ 3 �����������Ͳ�ͬ���߸�����ͬ ����˳��ͬ
void func() {
	cout << "func �ĵ���---- " << endl;
}

void func(int a) {
	cout << "func �ĵ���! " << endl;
}

void func(int a,double b) {
	cout << "func �ĵ���~~~~~~~~ " << endl;
}
void func( double b, int a) {
	cout << "func �ĵ���#####################" << endl;
}

void func1(int &a) {
	cout << "func (int&a)11�ĵ���" << endl;

}
void func1(const int  &a) {
	cout << "func (int&a)22�ĵ���" << endl;

}

void func2( int a,int b = 10) {
	cout << "func2 (int a)�ĵ���" << endl;

}
void func2(int a) {
	cout << "func2 (int a)�ĵ���" << endl;

}
const double PI = 3.14;
//���һ��Բ��  ���ܳ�
class Circle {
	//����Ȩ��
	public : //����Ȩ��
	//����
		int m_r;
	//��Ϊ

	//��ȡԲ���ܳ�
	double calculateZC() {
		return 2 * PI * m_r;
	}
};
int main() {

	//ͨ��Բ�� ���������Բ ����
	Circle cl;
	//��Ժ��������Խ��и�ֵ 
	cl.m_r = 10;
	cout << "Բ���ܳ�λ" << cl.calculateZC();

	int  a = 10;
	/*func1(a);
	func1(11);*/
	//func2(10);

	////ȫ����



	////������ͨ�ֲ�����
	//int a = 10;
	//int b = 10;

	////������̬����
	//static int  s_a = 10;
	//static int  s_b= 10;

	////���� 
	////�ַ�������
	//cout << "�ַ��������ĵ�ַΪ:" << (int)&"helloworld" << endl;

	////const ���ε�ȫ�ֱ���
	//cout << "ȫ�ֳ����ĵ�ַΪ:" << (int)&c_g_a << endl;


	////const ���εľֲ�����
	//const int c_a = 10;
	//cout << "�ֲ������ĵ�ַΪ:" << (int)&c_a << endl;

	//cout << "�ֲ�����a �ĵ�ַΪ:" << (int)&a << endl;
	//cout << "�ֲ�����b �ĵ�ַΪ:" << (int)&b << endl;
	//cout << "�ֲ�����g_a �ĵ�ַΪ:" << (int)&g_a << endl;
	//cout << "�ֲ�����g_b �ĵ�ַΪ:" << (int)&g_b << endl;
	//cout << "��̬����s_a �ĵ�ַΪ:" << (int)&s_a << endl;
	//cout << "��̬����s_b �ĵ�ַΪ:" << (int)&s_b << endl;


	/*int* p = func();
	cout << "ջ��1 :" << *p << endl;
	cout << "ջ��2 :" << *p << endl;*/

	////�ڶ�����������
	//int* duiqu = fun();
	//cout << "duiqu :" << *duiqu << endl;
	//cout << "duiqu :" << *duiqu << endl;
	//cout << "duiqu :" << *duiqu << endl;

	//new �����﷨  ��������new ��������

	//test01();
	//test02();
	 
	//���õĻ����﷨  ���ʸ�������һ������
	//��������
	/*int a = 10;
	int& b = a;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	b = 100;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;*/


	//���ñ����ʼ��  �����ڳ�ʼ���� �����Ըı�

	//int a = 10;
	////int& b; ���� �����ʼ��
	//int& b = a;
	//int c = 20;
	//int& b = c;

	/*int a = 10;
	int b = 20;
	mySwap03(a,b);

	cout << "a=" << a << endl;
	cout << "b=" << b << endl;*/

	//int& ref = test001();
	/*int& ref = test002();
	cout << "ref=" << ref << endl;
	cout << "ref=" << ref << endl;*/



	//�������� 
	// ʹ�ó��� ���������β� ��ֹ�����
	//int a = 10;
	 // int& ref = 10; ����
	//const int& ref = 10; // �ȼ���   ������ ���������� 
	//int temp = 10; const int &ref  = temp;

	// ref = 22ֻ�� �������޸�
	//showValue(a);

	//cout << func(10, 20, 30) << endl;
	//cout << func(5) << endl;
	//cout << func3() << endl;
	//func(4,12);
	//func(10,3.14);
}