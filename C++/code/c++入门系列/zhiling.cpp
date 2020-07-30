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
//	cout << "较小的值 为:" << MIN(i, j) << endl;
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
//。# 运算符会把 replacement-text 令牌转换为用引号引
//起来的字符串。
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
//	// c++  预定义 宏
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
//	//清理并关闭
//	//终止程序;
//	exit(signum);
//
//	
//}
//int main() {
//	// 注册信号 sigint 和信号处理程序 
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
//		cout << "很高兴认识你" << endl;
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
//    cout << "<title>Hello World - 第一个 CGI 程序</title>\n";
//    cout << "</head>\n";
//    cout << "<body>\n";
//    cout << "<h2>Hello World! 这是我的第一个 CGI 程序</h2>\n";
//    cout << "</body>\n";
//    cout << "</html>\n";
//
//    return 0;
//}
//int main() {
//	//1字符型变量创建方式
//	char ch = 'a';
//	cout << ch << endl;
//	//2 所占内存大小
//
//	cout << sizeof(ch) << endl;
//
//	// 3 常见错误 
//
//	//char ch2 = "b"; 错误 要用单引号
//	//a -- 97
//	char ch2 = 'A';
//	cout << (int)ch << endl;
//	cout << (int)ch2 << endl;
//	//4 字符型变量对应的ASCII 编码 
//	system("pause");
//	return 0;

int main() {

	//转义字符 

	//换行符 
	cout << "hello world\n";
 
	//反斜杠
	cout << "\\"<<endl;
	//水平制表符  \t 8 个位置 
	cout << "aaa\tbbb";
}
