#include <iostream>
using namespace std;

int add(int num1, int num2) {
	int sum = num1 + num2;
	return sum;
}

int main() {
	// do while ѭ��
	//����Ļ�����0 ��9 ��10 ������
	/*int num = 0;
	do {
		cout << num << endl;
		num++;
	} while (num < 10);*/

	// ˮ�ɻ��� ָ һ����λ�� ����ÿ��λ�ϵ����������� ֮�͵���������

	//1 �ȴ�ӡ������λ����
	//int num = 100;

	////2 ��������λ����ѡ��ˮ�ɻ��� 
	//do {
	//	int a = 0; // ��λ 
	//	int b = 0;// ʮλ
	//	int c = 0; //��λ

	//	a = num % 10; //��ȡ���ֵĸ�λ
	//	b = num / 10 % 10; // ��ȡʮλ
	//	c = num / 100;// ��ȡ���ֵİ�λ

	//	if ((a*a*a + b* b* b+ c*c*c) ==num) {
	//		cout << "���ˮ�ɻ���" << num << endl;
	//	}
	//	
	//	num++;
	//} while (num < 1000);

	//for ѭ��


	//for (int i = 0; i < 10; i++) {
	//	cout << "for ѭ�����" << i << endl;
	//}

	// �����Ӱ���
	// ��Ϸ���� 7 �ı��� ��λ �� 7  ʮλ��7  ��ӡ������
	// 1 ����� 1 - 100 ����
	//for (int i = 1; i <= 100; i++) {

	//	//2 ��100���������ҵ��������� ��ӡ������
	//	// 
	//	if (i %7 == 0 || i %10  == 7|| i/10 ==7) {
	//		cout << "������" << endl;
	//	}
	//	else {
	//		cout << i << endl;
	//	}
	//	


	//}
	// Ƕ��ѭ�� 
	// ����Ƕ��ѭ��ʵ����ͼ
	/*for (int i = 0; i < 10; i++) {

		for (int i = 0; i < 10; i++) {
			cout << "*";
		}
		cout << endl;
	}
	*/


	// �˷��ھ���
	// ���� * ���� = ������  
	//for(int i= 1;i< 10; i++) {
	//	//cout << i << endl;
	//	for (int j = 1; j <= i; j++)
	//	{
	//		//cout << j ;
	//		cout << j << "*" << i << "=" << j * i<<"     ";
	//	}
	//	cout <<  endl;
	//}
	//break ʹ��ʱ�� 

	//1 ������switch ���
	//cout << " ��ѡ�񸱱��Ѷ�" << endl;
	//cout << " 1 ��ͨ" << endl;
	//cout << " 2 �е�" << endl;
	//cout << " 3 ����" << endl;
	//int select = 0;
	//cin >> select; // �ȴ��û�����
	//switch (select) {
	//
	//	case 1 :
	//		cout << "��ѡ������ͨ�Ѷ�" << endl;
	//		break;
	//	case 2:
	//		cout << "��ѡ�����е��Ѷ�" << endl;
	//		break;
	//	case 3:
	//		cout << "��ѡ���������Ѷ�" << endl;
	//		break;
	//	default:// ��Ĭ�����
	//		break;
	//}

	// ������ѭ�������

	//for (int i= 0;i< 10;i++ ) {
	//	if (i== 5) {
	//		break; // �˳�ѭ��
	//	}
	//	cout << i << endl;
	//}

	// Ƕ��ѭ�������

	//for (int i = 0; i < 10; i++) {
	//	for (int j = 0; j < 10;j++) {

	//		if (j == 5 || j == 6 || j==7) {
	//			//break;
	//			continue;
	//		}
	//		cout << "*";
	//		}
	//	cout << endl;
	//}
//for (int i= 0; i< 100;i++) {
//		//������� ż�� �����
//		if (i % 2 == 0) {
//			continue;
//		}
//		cout << i << endl;
//	}

// goto ���
	//
	//cout << "1 XXXX" << endl;
	//goto FLAG;
	//cout << "2 XXXX" << endl;
	//cout << "3 XXXX" << endl;
	//FLAG:
	//cout << "5 XXXX" << endl;


	
	// ���� // һ������  ��ͬ����������
	/*int arr[5];
	arr[0] = 10;
	arr[1] = 20;
	arr[3] =30 ;
	arr[4] = 40;
	cout << arr[0] << endl;
	cout << arr[1] << endl;
	cout << arr[3] << endl;
	cout << arr[4] << endl;*/
	

	//int arr[5] = { 10,20,30,40,50 };
	/*cout << arr[0] << endl;
	cout << arr[1] << endl;
	cout << arr[3] << endl;
	cout << arr[4] << endl;*/

	// ����ѭ����������е�Ԫ��
	/*for (int i = 0; i < 5;i++) {
		cout << arr[i] <<endl ;
	}*/
	// ���������ʱ�� �����г�ʼ����
	/*int arr[] = { 11,2,223,44,55 ,66,77};

	for (int i = 0; i < 7; i++) {
		cout << arr[i] << endl;
	}
*/

	////�������;
	//int arr[10] = { 1,2,3,4,5,6,7,8,9 ,10};
	//cout << "��������ռ���ڴ�ռ�Ϊ" << sizeof(arr) << endl;
	//cout << "ͳ�� ÿ��Ԫ��ռ�õĿռ�"<< sizeof(arr[0])<<endl;
	////ͨ���������鿴�����׵�ַ  00D3FC08 �׵�ַΪ16���� ��תΪint ����

	//cout << "�����ַΪ" << arr << endl; 
	////13631112
	//cout << "�����ַΪ" << (int)arr << endl;
	//cout << "�����е�һ��Ԫ�ص�ַΪ" << &arr[0];//00D3FC08

	////�������ǳ��� �����Խ��и�ֵ����
	
	//	 5 ��С�������
	//int arr[5] = { 300,350,200,400,250 };
	
	/*int max = arr[0];
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << endl;
		if (arr[i] >max) 
		{
			max = arr[i];
		}
	}
	cout << max << endl;*/
	

	 // ������������
	
	//��������

	//int arr[5] = { 1,3,2,5,4 };
	//for (int i = 0; i < 5; i++)
	//{
	//	cout << "ԭ��������Ϊ:"<<arr[i] << endl;
	//}

	//// ʵ������
	//int start = 0;// ��ʼ�±�
	//int end = sizeof(arr)/sizeof(arr[0]) - 1;// �����±�
	//

	//while (start < end)
	//{
	//	//ʵ��Ԫ�ػ���
	//	int temp = arr[start];
	//	arr[start] = arr[end];
	//	arr[end] = temp;

	//	//�±����
	//	start++;
	//	end--;
	//	

	//}

	////��ӡ���ú������

	//cout << "����Ԫ�����ú�" << endl;
	//for (int i = 0; i < 5; i++)
	//{
	//	cout << "���ú������Ϊ:" << arr[i] << endl;
	//	
	//}
	

	//// ð������
	//int arr[9] = { 4,2,8,0,5,7,1,3,9 };
	//cout << "����ǰ" << endl;
	//for (int i = 0; i < 9; i++)
	//	{
	//		cout << "    "<<  arr[i];
	//
	//	}

	//// �������� 9-1
	//for (int i = 0; i < 9 - 1;i++ ) {
	//		// �ڲ�ѭ���Ա� ���� = Ԫ�ظ���- ��ǰ����-1 
	//	for (int j = 0; j < 9 - i - 1;j++) {
	//		// �����һ������,�ȵڶ������ִ� ,������������
	//		if (arr[j] > arr[j+1]) {
	//			int temp = arr[j];
	//			arr[j] = arr[j + 1];
	//			arr[j + 1] = temp;
	//		}
	//		
	//	}
	//}

	//// �����Ľ��
	//cout << "����������Ϊ:" <<endl;
	//for (int i = 0; i < 9; i++)
	//{
	//	cout << "   "<< arr[i] ;

	//}


	// ��ά���� 
	//int arr[2][3];
	//arr[0][0] = 1;
	//arr[0][1] = 2;
	//arr[0][2] =3 ;
	//arr[1][0] =4 ;
	//arr[1][1] =5 ;
	//arr[1][2] =6 ;
	//
	////cout << arr[0][0] << endl;
	//for (int i = 0; i < 2;i++) {
	//	for (int j = 0; j < 3;j++) {
	//		//cout << arr[i][j] << endl;
	//		// ���վ���ʽ��ӡ
	//		cout << arr[i][j] <<"  ";
	//	}
	//	cout << endl;
	//}
	//// ����ʡ������ ����ʡ������ 
	//int arr2[][3] = { 1,2,3,4,5,6 };

	// ��ά����������;  �鿴ռ���ڴ�ռ��С

	//int arr[2][3] =
	//{
	//	{1,2,3},
	//	{4,5,6}
	//};
	//cout << "��ά����ռ���ڴ�ռ�Ϊ" << sizeof(arr) << endl; //int 4 * 6 = 24
	//cout << "��ά�����һ��ռ���ڴ�ռ�Ϊ" <<  sizeof(arr[0]) << endl; //int 4 * 6 = 24
	//cout << "��ά�����һ��Ԫ��ռ���ڴ�ռ�Ϊ" <<  sizeof(arr[0][0]) << endl; //int 4 * 6 = 24
	//// �鿴�׵�ַ
	

	// ��ά����Ӧ�ð���--���Գɼ�ͳ��
	// 1 ������ά���� 
	//int scores[3][3] =
	//{
	//	{100,100,100},
	//	{90,50,100},
	//	{60,70,80}
	//};
	//string names[3] = { "����","����","����" };
	////ͳ��ÿ���˵��ܺͷ���
	//for (int i = 0; i < 3;i++) {
	//	int sum = 0; //ͳ�Ʒ����ܺͱ���
	//	for (int j = 0; j < 3;j++) {
	//		sum += scores[i][j];
	//		//cout << scores[i][j] << "   ";
	//	}
	//	//cout << endl;
	//	cout <<names[i]<< "���˵��ܷ�Ϊ" <<sum <<endl;
	//}
	

	//���� ���ý�һ�ξ���ʹ�õĴ����װ���� �����ظ�����
	
	// �ӷ����� ʵ�������������
	
	

// ���ú���
	int a = 10;
	int b = 22;
	int result = add(a, b);
	cout << "result" << result << endl;

	system("pause");
	return 0;
}
// ����һ���ӷ�����
