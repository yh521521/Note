#include <iostream>
using namespace std;
#include "swap.h"

// ֵ����
// ���庯�� ʵ���������ֽ��н���
// ����Ҫ ����ֵ ����Ϊvoid 

	//void swap(int num1, int num2) {
	//	cout << "����ǰ:" << endl;
	//	cout << "num1=:" <<num1 << endl;
	//	cout << "num2 = :"<<num2 << endl;


	//	int temp = num1;
	//	num1 = num2;
	//	num2 = temp;
	//	cout << "������:" << endl;
	//	cout << "num1=:" << num1 << endl;
	//	cout << "num2 = :" << num2 << endl;
	//}

	// �޲� �޷�
	//void test01() {
	//	cout << "this is test01" << endl;
	//}
	////�в� �޷�
	//void test02(int a) {
	//	cout << "this is test02   a = " <<a<< endl;
	//}
	////�в��޷�
	//int test03() {
	//	cout << "this is test03" << endl;
	//	return 100;
	//}
	////�в��з�
	//int test04(int a) {
	//	cout << "this is test04" << endl;
	//	return a;
	//}

	//����������
	//�ȽϺ��� ʵ���������ֽ��бȽ� ���ؽϴ��ָ 
//int max(int a, int b);


// �����ķ��ļ���д
// ʵ���������ֽ��нл��ĺ��� 
// ����������
//void swap(int a, int b);
//// �����Ķ���
//void swap(int a, int b) {
//	int temp = a;
//	a = b;
//	b = temp;
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//}

//void swap(int* p1, int* p2) {
//	int temp = *p1;
//	*p1 = *p2;
//	*p2 = temp;
//
//}

// ð�������� ����1 ������׵�ַ ����2 ���鳤��
void bubbleSort(int* arr, int len) {
	for (int i= 0;i < len -1;i++) {
		for (int j = 0; j < len - i - 1;j++) {
			if (arr[j] >arr[j+1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

}

// ��ӡ����
void printArray(int * arr,int len) {
	for (int i = 0; i < len ; i++) {
		cout << arr[i] << endl;
	}
}
int main() {
	
	//int a = 10;
	//int b = 22;
	//swap(a, b);
	//// ab δ�����ı� ֵ���ݵ�ʱ�� �βη����κθı�  ʵ�ζ�����ı�
	//test01();
	//int a = 122323;
	//test02(100);
	//int num1 = test03();
	//cout << "this is num1" <<num1 << endl;

	//int num2 = test04(a);
	//cout << "this is num2---" << num2 << endl;

	//int a = 10;
	//int b = 22;
	//int c = max(a, b);
	//cout << c;

	//int a = 10;
	//int b = 22;
	//swap(a,b);

	// ����ָ��
	//int a = 10;
	////ָ�붨����﷨
	//int  * p;
	//// ��ָ���¼����a �ĵ�ַ
	//p = &a;
	//cout << "a�ĵ�ַΪ" << &a << endl;

	//cout << "ָ��p Ϊ:" << p << endl;

	//// ʹ��ָ��
	//// ����ͨ�����õķ�ʽ���ҵ�ָ��ָ����ڴ�
	//// ָ��ǰ �� һ�� * �������� �ҵ�ָ��ָ����ڴ��е�����
	//*p = 1000;  // ��ԭ����10 �޸�Ϊ1000 

	//cout << "a" <<&a << endl;
	//cout << "ָ��p Ϊ:" << *p << endl;

	//// ָ����ռ���ڴ�ռ�
	//int a = 10;
	///*int   *    p;
	//p = &a;*/
	//// �ȼ���
	//int  *   p = &a;
	////�� 32 λ����ϵͳ��ָ��ռ��4���ֽڿռ��С ����ʲĪ��������
	////64 λ����ϵͳ��ָ������8 ���ֽڿռ��С ����ʲĪ��������
	//cout << "sizeof (int  *)" << sizeof(int    *) << endl;

	// ��ָ�� ���ڸ�ָ��������г�ʼ�� 
	//int  *  p = NULL;
	// ��ָ���ǲ����Խ��з��ʵ�
	//*p = 100; // ���쳣 

	// Ұָ��
	//int* p = (int *)0x1100; // ������ �����������Ұָ��  

	//cout << *p << endl; �ᱨ��

	//1 const ����ָ�� ����ָ�� ָ��ָ���ֵ
	//�� ���Ը�      ָ���ָ����Ը�
	//int a = 10;
	//int b = 10;
	//const int* p = &a;
	//// *p = 20; ����
	//p = &b; // ��ȷ
	////2 const ���γ���

	//int*  const p2 = &a;  //ָ���ָ�򲻿��Ը�    ֵ ���Ը�
	//*p2 = 100;
	////p2 = &b; ����
	//// 3 const ����ָ��ͳ���
	//const int* const  p3 = &a;
	//// ��Ϊ��
	///**p3 = 100;
	//p3 = &b;*/

	//ָ�������
	// ����ָ����������е�Ԫ��
	//int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//cout << "�����еĵ�һԪ��" << arr[0]<<endl;
	//int* p = arr;// arr ���������׵�ַ
	//cout << "ָ���ȡ�����е�һ����Ԫ��" << *p << endl;
	//p++;
	//cout << "ָ���ȡ�����еڶ�����Ԫ��" << *p << endl;

	//int* p2 = arr;
	//for (int i = 0; i < 10;i++) {
	//	//cout << arr[i] <<endl;
	//	//��ָ��ȡ��Ԫ��
	//	cout << *p2 << endl;
	//	p2++;
	//}
	// ָ��ͺ���
	// ����ָ�� 
	// ��ַ���ݿ����޸�ʵ�ε�ֵ --

	//int a = 10;
	//int b = 20;
	////2��ַ����
	//swap(&a,&b);
	//cout << "a= " << a << endl;
	//cout << "b = " << b << endl;
	//��װһ����������ð������,ʵ�ֶ������������������

	
	//��������
	int arr[10] = { 4,3,5,8,10,1,6,2,9,7 };
	// �������� ʵ��ð�ݺ���
	int len = sizeof(arr) / sizeof(arr[0]);

	//�������� ʵ��ð������
	bubbleSort(arr, len);
	//��ӡ��Ѱ�������
	printArray(arr, len);
	system("pause");
	return 0;
}

//int max(int a, int b) {
//	return a > b ? a : b;
//}