#include <iostream>
using namespace std;

int add(int num1, int num2) {
	int sum = num1 + num2;
	return sum;
}

int main() {
	// do while 循环
	//在屏幕中输出0 到9 这10 个数字
	/*int num = 0;
	do {
		cout << num << endl;
		num++;
	} while (num < 10);*/

	// 水仙花数 指 一个三位数 它的每个位上的数字三次幂 之和等于它本身

	//1 先打印所有三位数字
	//int num = 100;

	////2 从所有三位数字选出水仙花数 
	//do {
	//	int a = 0; // 个位 
	//	int b = 0;// 十位
	//	int c = 0; //百位

	//	a = num % 10; //获取数字的个位
	//	b = num / 10 % 10; // 获取十位
	//	c = num / 100;// 获取数字的百位

	//	if ((a*a*a + b* b* b+ c*c*c) ==num) {
	//		cout << "输出水仙花数" << num << endl;
	//	}
	//	
	//	num++;
	//} while (num < 1000);

	//for 循环


	//for (int i = 0; i < 10; i++) {
	//	cout << "for 循环输出" << i << endl;
	//}

	// 敲桌子案例
	// 游戏规则 7 的倍数 个位 有 7  十位有7  打印敲桌子
	// 1 先输出 1 - 100 数字
	//for (int i = 1; i <= 100; i++) {

	//	//2 从100个数字中找到特殊数字 打印敲桌子
	//	// 
	//	if (i %7 == 0 || i %10  == 7|| i/10 ==7) {
	//		cout << "敲桌子" << endl;
	//	}
	//	else {
	//		cout << i << endl;
	//	}
	//	


	//}
	// 嵌套循环 
	// 利用嵌套循环实现星图
	/*for (int i = 0; i < 10; i++) {

		for (int i = 0; i < 10; i++) {
			cout << "*";
		}
		cout << endl;
	}
	*/


	// 乘法口诀表
	// 列数 * 行数 = 计算结果  
	//for(int i= 1;i< 10; i++) {
	//	//cout << i << endl;
	//	for (int j = 1; j <= i; j++)
	//	{
	//		//cout << j ;
	//		cout << j << "*" << i << "=" << j * i<<"     ";
	//	}
	//	cout <<  endl;
	//}
	//break 使用时机 

	//1 出现在switch 语句
	//cout << " 请选择副本难度" << endl;
	//cout << " 1 普通" << endl;
	//cout << " 2 中等" << endl;
	//cout << " 3 困难" << endl;
	//int select = 0;
	//cin >> select; // 等待用户输入
	//switch (select) {
	//
	//	case 1 :
	//		cout << "你选择是普通难度" << endl;
	//		break;
	//	case 2:
	//		cout << "你选择是中等难度" << endl;
	//		break;
	//	case 3:
	//		cout << "你选择是困难难度" << endl;
	//		break;
	//	default:// 走默认情况
	//		break;
	//}

	// 出现在循环语句中

	//for (int i= 0;i< 10;i++ ) {
	//	if (i== 5) {
	//		break; // 退出循环
	//	}
	//	cout << i << endl;
	//}

	// 嵌套循环语句中

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
//		//奇数输出 偶数 不输出
//		if (i % 2 == 0) {
//			continue;
//		}
//		cout << i << endl;
//	}

// goto 语句
	//
	//cout << "1 XXXX" << endl;
	//goto FLAG;
	//cout << "2 XXXX" << endl;
	//cout << "3 XXXX" << endl;
	//FLAG:
	//cout << "5 XXXX" << endl;


	
	// 数组 // 一个集合  放同种数据类型
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

	// 利用循环输出数组中的元素
	/*for (int i = 0; i < 5;i++) {
		cout << arr[i] <<endl ;
	}*/
	// 定义数组的时候 必须有初始长度
	/*int arr[] = { 11,2,223,44,55 ,66,77};

	for (int i = 0; i < 7; i++) {
		cout << arr[i] << endl;
	}
*/

	////数组的用途
	//int arr[10] = { 1,2,3,4,5,6,7,8,9 ,10};
	//cout << "整个数组占用内存空间为" << sizeof(arr) << endl;
	//cout << "统计 每个元素占用的空间"<< sizeof(arr[0])<<endl;
	////通过数组名查看数组首地址  00D3FC08 首地址为16进制 可转为int 类型

	//cout << "数组地址为" << arr << endl; 
	////13631112
	//cout << "数组地址为" << (int)arr << endl;
	//cout << "数组中第一个元素地址为" << &arr[0];//00D3FC08

	////数组名是常量 不可以进行赋值操作
	
	//	 5 个小猪称体重
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
	

	 // 数组逆序排序
	
	//创建数组

	//int arr[5] = { 1,3,2,5,4 };
	//for (int i = 0; i < 5; i++)
	//{
	//	cout << "原来的数组为:"<<arr[i] << endl;
	//}

	//// 实现逆置
	//int start = 0;// 起始下标
	//int end = sizeof(arr)/sizeof(arr[0]) - 1;// 结束下标
	//

	//while (start < end)
	//{
	//	//实现元素互换
	//	int temp = arr[start];
	//	arr[start] = arr[end];
	//	arr[end] = temp;

	//	//下标更新
	//	start++;
	//	end--;
	//	

	//}

	////打印逆置后的数组

	//cout << "数组元素逆置后" << endl;
	//for (int i = 0; i < 5; i++)
	//{
	//	cout << "逆置后的数组为:" << arr[i] << endl;
	//	
	//}
	

	//// 冒泡排序
	//int arr[9] = { 4,2,8,0,5,7,1,3,9 };
	//cout << "排序前" << endl;
	//for (int i = 0; i < 9; i++)
	//	{
	//		cout << "    "<<  arr[i];
	//
	//	}

	//// 排序轮数 9-1
	//for (int i = 0; i < 9 - 1;i++ ) {
	//		// 内层循环对比 次数 = 元素个数- 当前轮数-1 
	//	for (int j = 0; j < 9 - i - 1;j++) {
	//		// 如果第一个数字,比第二个数字大 ,交换两个数字
	//		if (arr[j] > arr[j+1]) {
	//			int temp = arr[j];
	//			arr[j] = arr[j + 1];
	//			arr[j + 1] = temp;
	//		}
	//		
	//	}
	//}

	//// 排序后的结果
	//cout << "排序后的数组为:" <<endl;
	//for (int i = 0; i < 9; i++)
	//{
	//	cout << "   "<< arr[i] ;

	//}


	// 二维数组 
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
	//		// 按照矩阵方式打印
	//		cout << arr[i][j] <<"  ";
	//	}
	//	cout << endl;
	//}
	//// 可以省略行数 不能省略列数 
	//int arr2[][3] = { 1,2,3,4,5,6 };

	// 二维数组名称用途  查看占用内存空间大小

	//int arr[2][3] =
	//{
	//	{1,2,3},
	//	{4,5,6}
	//};
	//cout << "二维数组占用内存空间为" << sizeof(arr) << endl; //int 4 * 6 = 24
	//cout << "二维数组第一行占用内存空间为" <<  sizeof(arr[0]) << endl; //int 4 * 6 = 24
	//cout << "二维数组第一个元素占用内存空间为" <<  sizeof(arr[0][0]) << endl; //int 4 * 6 = 24
	//// 查看首地址
	

	// 二维数组应用案例--考试成绩统计
	// 1 创建二维数组 
	//int scores[3][3] =
	//{
	//	{100,100,100},
	//	{90,50,100},
	//	{60,70,80}
	//};
	//string names[3] = { "张三","李四","王五" };
	////统计每个人的总和分数
	//for (int i = 0; i < 3;i++) {
	//	int sum = 0; //统计分数总和变量
	//	for (int j = 0; j < 3;j++) {
	//		sum += scores[i][j];
	//		//cout << scores[i][j] << "   ";
	//	}
	//	//cout << endl;
	//	cout <<names[i]<< "个人的总分为" <<sum <<endl;
	//}
	

	//函数 作用将一段经常使用的代码封装起来 减少重复代码
	
	// 加法函数 实现两个整型相加
	
	

// 调用函数
	int a = 10;
	int b = 22;
	int result = add(a, b);
	cout << "result" << result << endl;

	system("pause");
	return 0;
}
// 定义一个加法函数
