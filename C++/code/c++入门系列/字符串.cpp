#include <iostream>
using namespace std;
#include <ctime>
int main() {
	////c 风格字符串
	//cout << "hello world" << endl;

	//char str[] = "my self";
	//cout << str << endl;
	//string str2 = " asdas da";
	//cout << str2 << endl;
	////bool 类型 true 1 false 0  一个字节

	////创建bool 类型
	//bool flag = true;
	//cout << flag << endl;
	//cout << "所占字节" << sizeof(flag) << endl;


	////数据 输入 cin 
	////整型
	//int a = 0;
	//cout << "请给整型变量a 赋值" << endl;
	//cin >> a;
	//cout << "输出整型变量a :" <<a<< endl;

	////浮点型
	//float f = 3.14f;
	//cout << "请给浮点型变量f 赋值" << endl;
	//cin >>f;
	//cout << "输出整型变量f :" << f << endl;

	////字符型
	//char c = 'y';
	//cout << "请给浮点型变量c 赋值" << endl;
	//cin >>c;
	//cout << "输出整型变量c :" << c << endl;

	////字符串型
	//string c = "asdasdas";
	//cout << "请给字符串型变量c 赋值" <<c<< endl;
	//cin >> c;
	//cout << "输出字符串型变量c :" << c << endl;
	//bool 型
	/*bool flag = true;
	cout << "请给bool型变量 赋值" << endl;
	cin >> flag;
	cout << "输出bool型变量flag :"<<flag << endl;*/

	//运算符 加减乘除

	//int a = 10;
	//int b = 3;
	//cout << a + b << endl;
	//cout << a - b << endl;
	//cout << a * b << endl;
	//cout << a / b << endl;

	//int a1 = 10;
	//int b1 = 0;
	//cout << a1 / b1 << endl;
	//算数运算符  求余
	/*cout << a % b << endl;*/

	/*double d1 = 3.14;
	double d2 = 1.1;*/
	//cout << d1 % d2;<<endl; 报错
	// 前置 后置 递增 递减
	//++a;
	//cout << "打印a为 :" << a << endl; //11
	////a++;
	//cout << "再次输出a为 :" << a << endl; //11 

	// 前置和后置的区别
	
	//cout << "再次输出a++ *10 为 :" << a++ * 10 << endl; //100 
	//cout << "再次输出++a1 *10 为 :" << ++a1 * 10 << endl; //110
	//cout << "再次输出a-- *10 为 :" << a-- * 10 << endl; //100 
	//cout << "再次输出--a1 *10 为 :" << --a1 * 10 << endl; //90

	//赋值运算
	//
	//a = 100;
	//cout << "再次输出a为 :" << a << endl; //11 
	//a = 11;
	//a += 2;
	//cout << "再次输出a为 :" << a << endl; //11 


	// 比较运算符

	//int a = 10;
	//int b = 20;
	//cout << (a == b) << endl;  //false 0 

	//cout << (a != b) << endl;  //true 1 

	//cout << (a >= b) << endl;  //false 0 

	//cout << (a <= b) << endl;  //true 1 


	//// 逻辑运算符 
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

	//选择结构 单if 语句
	// 用户输入分数 分数> 600  考上一本大学在屏幕上输出
	
	//int score = 0;
	//cout << " 请输入一个分数:" <<endl;
	//cin >> score;
	////打印输入的分数
	//cout << "你输入的分数为" << score << endl;
	//// 判断分数是否> 600 如果大于 那魔输出一本大学
	//if (score > 600) {
	//	cout << "恭喜考上了一本大学"<< endl;

	// > 600 考上一本 < 600未 考上一本大学
	
	/*int score = 0;
	cout << "请输入一个考试分数" << score << endl;
	cin >> score;
	if (score > 600) {
		cout << "恭喜你考上了一本大学";
	}else {
		cout << "你未考上一本大学";
	}*/
	
	//多条件选择结构
	//
	//int score = 0;
	//cout << "请输入考试分数" << endl;
	//cin >> score;

	//if (score > 600) {
	//	cout << "恭喜你 考上一本大学"<< endl;
	//}
	//else  if (score > 500 ) {
	//	cout << "恭喜你 考上二本大学" << endl;
	//}
	//else if (score > 400) {
	//	cout << "恭喜你 考上三本大学" << endl;
	//}
	//else {
	//	cout << "未考上 本科大学" << endl;
	//}
	//int score = 0;
	//cout << "请输入高考分数;" << endl;
	//cin >> score;
	//cout << "你输入的分数为'" <<score << endl;

	//// 多条件判断
	//if (score > 600) {
	//	cout << "恭喜 你考上一本大学" << endl;
	//	if (score > 700) {
	//		cout << " 你能考上北京大学" << endl;
	//	}
	//	else if(score > 650) {
	//		cout << "你能考上清华大学" << endl;
	//	}
	//	else {
	//		cout << "你能考上人民大学" << endl;
	//	}
	//}
	//else if (score >500) {

	//	cout << "恭喜 你考上二本大学" << endl;
	//}
	//else if (score > 400) {

	//	cout << "恭喜 你考上三本大学" << endl;
	//}
	//else {
	//	cout << "未考上大学 请在接再励" << endl;
	//}

	// 三只小猪称体重
	//
	//int num1 = 0;
	//int num2 = 0;
	//int num3 = 0;
	//
	////让用户来输入三只小猪的重量

	//cout << " 请输入小猪a 的体重" << endl;
	//cin >> num1;

	//cout << " 请输入小猪b的体重" << endl;
	//cin >> num2;

	//cout << " 请输入小猪c 的体重" << endl;
	//cin >> num3;

	//cout << " 小猪a 的体重" <<num1 << endl;
	//cout << " 小猪b 的体重" <<num2 << endl;
	//cout << " 小猪c 的体重" <<num3 << endl;
	//
	//// 判断哪只 最重 
	//if (num1 > num2 ) {
	//	if (num1 >num3) {
	//		cout << "小猪a 最重 " << endl;
	//	}
	//	else {
	//		cout << "小猪c 最重 " << endl;
	//	}
	//}
	//else {
	//	if (num2 > num3) {
	//		cout << "小猪b 最重 " << endl;
	//	}
	//	else {
	//		cout << "小猪c 最重 " << endl;
	//	}

	//}


	//三目运算符
	 //创建三个变量a b c 
	// 将 a  b 作比较 将变量最大的值 赋值给c 
	/*int a = 10;
	int b = 12;
	int c = 0;
	c = (a > b ? a : b);
	cout << "三目运算符 " << c<<endl;*/

	//switch 语句
	// 给电影进行打分
	// 10  分经典
	// 8 分非常好
	//6 一般
	//5 分以下 烂片
	// 提示用户给电影评分
	//cout << "请给电影进行打分" << endl;
	//int score = 0;
	//cin >> score;
	//cout << "你打的分数为" << score << endl;

	//// 根据用户输入的分数来提示用户最后的结果
	//switch (score) {
	//	case 10:
	//		cout << "您认为是经典电影" << endl;
	//		break; // 退出当前的分支
	//	case 9:
	//		cout << "您认为是经典电影" << endl;
	//		break;
	//	case 8:
	//		cout << "您认为是电影非常好" << endl;
	//		break;
	//	case 7:
	//		cout << "您认为是电影非常好" << endl;
	//		break;
	//	default:
	//		cout << "你认为电影一般般" << endl;
	//}
	// if switch 区别
	//switch 缺点 判断之能是整型或者字符型 不可以是一个区间
	//优点 结构秦星执行效率高 

	// while 循环
	// 在屏幕中打印0 - 9 这10 个数字
	//int num = 0;
	//cout << num << endl;
	//// while 循环
	//num++;
	//cout << num << endl;
	// 尽量避免死循环
	/*while (num < 10)
	{
		cout << num << endl;
		++num;
		
	}*/

	 // 猜数字游戏
	
	// 添加随机数种子 作用 利用当前系统时间生成随机数防止每次随机数都一样

	srand((unsigned int)time(NULL));
	// 1 系统生成随机数 
	int num = rand() % 100+1; // 1 - 100 的区间 
	//cout << num << endl;
	
	//2 玩家进行猜测
	int val = 0;  //玩家 输入的数据

	while (1) {
		cin >> val;

		// 3 判断玩家的猜测
		if (val > num) {
			cout << "猜测过大";
		}
		else if (val < num) {
			cout << "猜小了" << endl;
		}
		else {
			cout << "恭喜你猜对了" << endl;
			break; //结束循环
		}
		// 猜对 退出游戏
		// 猜错 提示猜的结果 过大 过小 重新进行第二部 

	}
	





	system("pause");
	return 0;




}




