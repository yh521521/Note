#include <iostream>
using namespace std;

struct Hero {

	string name;
	int age;
	string sex;
};
// 案例 设计一个英雄结构体 包括成员姓名年龄性别创建结构体数据 数组中存放五名英雄 
// 冒泡排序 将数组中年龄进行升序排序 打印排序后的结果

void bubbleSort(struct Hero heroArray[], int len) {

	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (heroArray[j].age > heroArray[j + 1].age) {
				struct Hero temp = heroArray[j];
				heroArray[j] = heroArray[j + 1];
				heroArray[j + 1] = temp;

			}

		}
	}
};
void printHero(struct Hero heroArray[], int len) {

	for (int i = 0; i < len; i++) {
		cout << "姓名:" << heroArray[i].name << "  年龄" << heroArray[i].age << " 性别"
			<< heroArray[i].sex << endl;



	}
};

int main() {

	// 设计英雄结构体

	//创建数组存放5名英雄
	struct Hero heroArray[5] = {
		{"刘备",23,"男"},
		{"关羽",22,"男"},
		{"张飞",20,"男"},
		{"赵云",21,"男"},
		{"貂蝉",19,"女"}
		

	};

	int len = sizeof(heroArray) / sizeof(heroArray[0]);
	/*for (int i = 0; i < len;i++) {
		cout << "姓名:" << heroArray[i].name << "  年龄" << heroArray[i].age << " 性别"
			<< heroArray[i].sex << endl;
			


	};*/
	// 对数组进行排序 按照年龄进行升序排序
	bubbleSort(heroArray,len);
	//打印输出
	printHero(heroArray, len);
}