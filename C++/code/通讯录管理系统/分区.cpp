#include <iostream>
using namespace std;
//// 全局变量
//int g_a = 10;
//int g_b = 10;
//
////全局常量
//const int c_g_a = 10;

//栈区
//int*  func() {
//	int a = 10;
//	return &a;
//	
//}

//int * fun() {
//	
//
//	//利用new 关键字 可以将数据开辟到堆区 
//	int* p = new int(10);
//	return p;
//}
//
//int* func() {
//	//堆区创建整型数据
//
//	//new 返回的是该数据类型的指针 你new 的什莫数据类型 
//	//返回的就是该数据类型 的指针
//
//	int* p = new int(10);
//	return p;
//}
//
//void test01() {
//	int* p = func();
//	cout << *p << endl; //解引用
//	cout << *p << endl; //解引用
//	cout << *p << endl; //解引用
//	//堆去的数据 由程序员管理开辟 程序员管理释放
//	//如果想释放堆区的数据 利用关键字  delete 
//	delete p;//内存已经释放 再次访问就是非法访问
//	cout << *p << endl; //解引用
//}
//
////2堆区利用new  开辟数组
//void test02() {
//	
//	//创建 整型数组 在堆区
//	int *arr = new int[10];//10个元素
//	for (int i = 0; i < 10;i++) {
//		arr[i] = i + 100;//
//	}
//	for (int i = 0; i < 10; i++) {
//		cout <<arr[i]<<endl;
//	}
//
//	//释放
//	delete[] arr;
//
//}
////1形参传递
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
////引用传递
//void mySwap03(int& a, int& b) {
//	int temp = a;
//	a = b;
//	b = temp;
//	cout << "swap03 a=" << a << endl;
//	cout << "swap03 b=" << b << endl;
//
//}
//
////不要返回局部变量的引用
//
//int& test001() {
//	
//	int a = 10;//j局部变量存放在栈区
//	return a;
//}
//
//// 2 函数的调用可以作为左值
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

//函数默认参数
//int  func(int a,int b= 3 ,int c=11) {
//
//	return a + b + c;
//}
//// 如果某个位置已经有了默认参数 那麽从这个位置往后 从左往右都必须由默认值 
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


//占位参数   第二个int  就是占位
//void func(int a,int ) {
//	cout << "this is func" << endl;
//}

//函数重载
//可以让函数名相同提高复用性  
//重载条件 
// 1 同一个作用域  函数名称相同 3 函数参数类型不同或者个数不同 或者顺序不同
void func() {
	cout << "func 的调用---- " << endl;
}

void func(int a) {
	cout << "func 的调用! " << endl;
}

void func(int a,double b) {
	cout << "func 的调用~~~~~~~~ " << endl;
}
void func( double b, int a) {
	cout << "func 的调用#####################" << endl;
}

void func1(int &a) {
	cout << "func (int&a)11的调用" << endl;

}
void func1(const int  &a) {
	cout << "func (int&a)22的调用" << endl;

}

void func2( int a,int b = 10) {
	cout << "func2 (int a)的调用" << endl;

}
void func2(int a) {
	cout << "func2 (int a)的调用" << endl;

}
const double PI = 3.14;
//设计一个圆类  求周长
class Circle {
	//访问权限
	public : //公共权限
	//属性
		int m_r;
	//行为

	//获取圆的周长
	double calculateZC() {
		return 2 * PI * m_r;
	}
};
int main() {

	//通过圆类 创建具体的圆 对象
	Circle cl;
	//给院对象的属性进行赋值 
	cl.m_r = 10;
	cout << "圆的周长位" << cl.calculateZC();

	int  a = 10;
	/*func1(a);
	func1(11);*/
	//func2(10);

	////全局区



	////创建普通局部变量
	//int a = 10;
	//int b = 10;

	////创建静态变量
	//static int  s_a = 10;
	//static int  s_b= 10;

	////常量 
	////字符串常量
	//cout << "字符串常量的地址为:" << (int)&"helloworld" << endl;

	////const 修饰的全局变量
	//cout << "全局常量的地址为:" << (int)&c_g_a << endl;


	////const 修饰的局部变量
	//const int c_a = 10;
	//cout << "局部常量的地址为:" << (int)&c_a << endl;

	//cout << "局部变量a 的地址为:" << (int)&a << endl;
	//cout << "局部变量b 的地址为:" << (int)&b << endl;
	//cout << "局部变量g_a 的地址为:" << (int)&g_a << endl;
	//cout << "局部变量g_b 的地址为:" << (int)&g_b << endl;
	//cout << "静态变量s_a 的地址为:" << (int)&s_a << endl;
	//cout << "静态变量s_b 的地址为:" << (int)&s_b << endl;


	/*int* p = func();
	cout << "栈区1 :" << *p << endl;
	cout << "栈区2 :" << *p << endl;*/

	////在堆区开辟数据
	//int* duiqu = fun();
	//cout << "duiqu :" << *duiqu << endl;
	//cout << "duiqu :" << *duiqu << endl;
	//cout << "duiqu :" << *duiqu << endl;

	//new 基本语法  堆区利用new 开辟数组

	//test01();
	//test02();
	 
	//引用的基本语法  本质给变量起一个别名
	//数据类型
	/*int a = 10;
	int& b = a;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	b = 100;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;*/


	//引用必须初始化  引用在初始化后 不可以改变

	//int a = 10;
	////int& b; 报错 必须初始化
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



	//常量引用 
	// 使用场景 用来修饰形参 防止误操作
	//int a = 10;
	 // int& ref = 10; 报错
	//const int& ref = 10; // 等价于   编译器 帮我们做了 
	//int temp = 10; const int &ref  = temp;

	// ref = 22只读 不可以修改
	//showValue(a);

	//cout << func(10, 20, 30) << endl;
	//cout << func(5) << endl;
	//cout << func3() << endl;
	//func(4,12);
	//func(10,3.14);
}