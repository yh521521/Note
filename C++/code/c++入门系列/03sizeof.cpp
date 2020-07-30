#include <iostream>
using namespace std;
//全局变量生命
int g;
//int11 main() {
	//sizeof 关键字 数据类型所占内存大小
	short num1 = 199;
	cout << "short 所占用内存空间为:" << sizeof(short) << "\n";
	int num2 = 199;
	cout << "num2 所占用内存空间为:" << sizeof(num2) << endl;
	long num3 = 199;
	cout << "num3 所占用内存空间为:" << sizeof(num3) << endl;
	long long  num4 = 199;
	cout << "num4 所占用内存空间为:" << sizeof(num4) << endl;

	cout << "string:\t" << "所占字节数:" << sizeof(string) << endl;
	cout << "size_t: \t" << "所占字节数" << sizeof(size_t);
	cout << "\t最大值:" << (numeric_limits<size_t>::max)();
	cout << "\t最小值:" << (numeric_limits<size_t>::min)()<<endl;

	typedef short duan;
	cout << "duan 所占用内存空间为:" << sizeof(duan) << endl;
	duan num_duan = 20;
	
	//局部变量声明 
	int a, b;
	int c;

	//实际初始化
	a = 10;
	b = 20;
	c = a + b;

	g = a + b;
	cout << "打印c的结果:" << c<<endl;
	cout << "打印g的结果:" << g<<endl;
	

	short int i; // 有符号短整数 
	short unsigned int j;
	short signed int z;

	j = 5000;
	i = 4444444;
	z = 33;
	cout << i << endl;
	cout << j << endl;
	cout << z << endl;



	// 运算符 
	int e = 22;
	int f = 11;
	

	if (e == f) {
		cout << "line 1  e 等于f" << endl;

	}
	else {
		cout << "line 1  e 不等于f" << endl;
	}

	//逻辑运算符
	if (e&&f) {
		cout << "line 1  e f为真" << endl;
	}
	else {
		cout << "line 1  e f不为真" << endl;
	}
	if (!(e &&f)) {
		cout << "条件为真" << endl;
	}
	else {
		cout << "条件为假 " << endl;

	}

	//位运算 
	unsigned int g1 = 60;
	unsigned int h1 = 13;
	int i1 = 0;
	int j1 = 0;
	i1 = g1 & h1;
	cout << "位运算 & 结果为" << i1 << endl;

	j1 = g1 | h1;
	cout << "位运算 | 的操作时" << j1<< endl;


	for (;;) {
		printf("This loop will run forever \n");
	}
	
	system("pause");
	return 0;



}
