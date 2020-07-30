#include <iostream> 
using namespace std;



// 1创建学生数据类型
struct Student {
	// 成员列表
	string name;
	int age;
	int score;
};
// 老师结构体
//struct teacher {
//	int id;// 教师编号
//	string name; // 教师姓名
//	int age;//年岭 
//	struct Student stu;//辅导的学生
//};
//}stu; 
// stu 就是一个结构体变量
//2 通过学生类型 创建具体的学生

//值传递

//将函数中的形参改为指针,可以减少内存空间 而且不会复制出新的副本

void printStudnet1(const Student *stu) {
	//加入const 后一旦有修改 会报错   防止误操作
	//stu->age = 100;
	cout << "子函数姓名:" << stu->name << "年龄:" << stu->age << "分数" << stu->score;

}
// 地址传递
void printStudnet2(struct Student *stu) {
	stu->age = 100;
	cout << "子函数2姓名:" << stu->name << "年龄:" << stu->age << "分数" << stu->score;

}

int main() {

	// 1 
	/*struct Student s1;
	s1.name = "张三";

	s1.age = 19;
	s1.score = 100;

	cout << "姓名:" << s1.name << "年龄:" << s1.age << "分数" << s1.score;*/

	/*struct Student s1 = { "李四",19 ,80 };
	cout << "姓名:" << s1.name << "年龄:" << s1.age << "分数" << s1.score; */

	/*stu.name = "王五";
	stu.age = 22;
	stu.score = 110;

	cout << "姓名:" << stu.name << "年龄:" << stu.age << "分数" << stu.score;*/


	//// 创建结构体数组
	//struct Student stuArray[3] = {
	//	{"张三",19,100},
	//	{"李四", 18, 10},
	//	{"王五",22,60}
	//};
	//stuArray[2].name = "赵六";
	//stuArray[2].age = 66;
	//stuArray[2].score = 33;
	//// 遍历结构体
	//for (int i = 0; i < 3;i++) {

	//	cout << "姓名:" << stuArray[i].name << "年龄:" << stuArray[i].age << "分数" << stuArray[i].score <<endl;
	//}
	//

	//指针结构体 
	//创建学生结构体变量
	//struct Student s = { "李四",19 ,80 }; 定义结构体变量可以省略struct 关键字
	//Student s = { "李四",19 ,80 };
	//2 通过指针指向结构体变量 
	//int* p = &s; 不匹配
	//Student * p = &s; //
	//通过指针访问结构体变量中的数据
	//cout << "姓名" << p->name << "年龄" << p->age << "分数" << p->score<<endl;


	// 嵌套结构体 
	// 老师辅导一个学生 在一个老师的结构体中 记录一个学生的结构体 

	//teacher t;
	//t.id = 10001;
	//t.name = "老王";
	//t.age = 50;
	//t.stu.name = "小学生a";
	//t.stu.age = 18;
	//t.stu.score = 60;
	//cout << "姓名" << t.name << "年龄" << t.age << "学生分数" << t.stu.score << endl;
	// 结构体做函数参数

	//创建结构体变量
	//struct Student stu;
	//stu.name = "张三";
	//stu.age = 20;
	//stu.score = 99;
	//
	////printStudnet1(stu);

	//printStudnet2(&stu);

	//cout << "姓名:" << stu.name << "年龄:" << stu.age << "分数" << stu.score;
 //	
	struct Student stu = { "张三",15,70 };

	printStudnet1(&stu);
	//通过函数打印结构体变量信息
	system("pause");
	return 0;
}