//#include <iostream>
//using namespace std;
//#define PI 3.14
//
//int main() {
//	cout << "Value of PI :" << PI << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//#define MIN(a,b) (a<b ? a:b)
//
//int main() {
//	int i, j;
//	i = 300;
//	j = 22;
//	cout << "��С��ֵ Ϊ:" << MIN(i, j) << endl;
//
//	return 0;
//}
//#include <iostream>
//using namespace std;
//
//#define DEBUG
//
//#define MIN(a,b) (((a) < (b)) ? a:b)
//
//int main() {
//	int i, j;
//	i = 100;
//	j = 30;
//#ifdef DEBUG
//	cerr << "Inside main function" << endl;
//
//#endif // DEBUG
//
//#if 0
//	cout << MKSTR(HELLO C++) << endl;
//#endif // 0
//	cout << "the minimum is " << MIN(i, j) << endl;
//
//#ifdef DEBUG
//	cerr << "coming out of main function" << endl;
//
//#endif // DEBUG
//	return 0;
//}

//#include <iostream>
//using namespace std;
//#define MKSTR( x ) #x 
//��# �������� replacement-text ����ת��Ϊ��������
//�������ַ�����
//int main() {
//	cout << MKSTR(HELLO C++) << endl;
//	return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//#define concat(a,b) a ## b;
//
//int main() {
//	int xy = 100;
//	cout << concat(x, y);
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main() {
//	// c++  Ԥ���� ��
//
//	cout << "Vlaue of __Line__:" << __LINE__ << endl;
//	cout << "Vlaue of __ file__:" << __FILE__ << endl;
//	cout << "Vlaue of __date__:" << __DATE__ << endl;
//	cout << "Vlaue of __Time__:" << __TIME__ << endl;
//	return 0;
//}

//#include <iostream>
//#include <csignal>
//#include <windows.h>
//
//using namespace std;
//void signalHandler(int signum) {
//	cout << "Interrupt signal(" << signal << ")received.\n";
//
//	//�����ر�
//	//��ֹ����;
//	exit(signum);
//
//	
//}
//int main() {
//	// ע���ź� sigint ���źŴ������ 
//	signal(SIGINT, signalHandler);
//
//	while (1) {
//		cout << "going to sleep ..." << endl;
//		Sleep(1);
//	}
//	return 0;
//}


//#include <iostream>
//#include <Windows.h>
//using namespace std;
//
//int main() {
//	
//	int a = 1;
//	while (a) {
//		
//		cout << "�ܸ�����ʶ��" << endl;
//		Sleep(100);
//	}
//	system("pause");
//	return 0;
//}

#include <iostream>
using namespace std;

//int main()
//{
//
//    cout << "Content-type:text/html\r\n\r\n";
//    cout << "<html>\n";
//    cout << "<head>\n";
//    cout << "<title>Hello World - ��һ�� CGI ����</title>\n";
//    cout << "</head>\n";
//    cout << "<body>\n";
//    cout << "<h2>Hello World! �����ҵĵ�һ�� CGI ����</h2>\n";
//    cout << "</body>\n";
//    cout << "</html>\n";
//
//    return 0;
//}
//int main() {
//	//1�ַ��ͱ���������ʽ
//	char ch = 'a';
//	cout << ch << endl;
//	//2 ��ռ�ڴ��С
//
//	cout << sizeof(ch) << endl;
//
//	// 3 �������� 
//
//	//char ch2 = "b"; ���� Ҫ�õ�����
//	//a -- 97
//	char ch2 = 'A';
//	cout << (int)ch << endl;
//	cout << (int)ch2 << endl;
//	//4 �ַ��ͱ�����Ӧ��ASCII ���� 
//	system("pause");
//	return 0;

int main() {

	//ת���ַ� 

	//���з� 
	cout << "hello world\n";
 
	//��б��
	cout << "\\"<<endl;
	//ˮƽ�Ʊ��  \t 8 ��λ�� 
	cout << "aaa\tbbb";
}
