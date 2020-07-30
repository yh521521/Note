#include<iostream>
using namespace std;
#include <vector> //容器
#include <deque>// 容器
#include <algorithm>
#include<ctime> // 随机数种子要加桑
/*
	5名选手 选手abcde 10 个评委打分对每一名选手打分 去除最高分 
	去除最低分 取其平均分
*/

class Person {


public:
	Person(string name,int score){
	
		this->m_Name = name;
		this->m_Score = score;
	}
	
	
	
	string m_Name;//姓名
	  int m_Score;// 平均分

};
void createPerson(vector<Person>&v) {

	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{	

		string name = "选手";
		name += nameSeed[i];

		int score = 0;
		Person p(name,score);
		// 将创建的person 对象放入到容器中
		v.push_back(p);
	}

}


//打分
void getScore(vector<Person>&v) {
	
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//将评委的分数放入到deque 容器中
		deque<int>d;
		for (int  i = 0; i < 10; i++)
		{
			int score = rand()%41+60;// 60 -100 随机数
			d.push_back(score);
		}

		// 看下评委给打的分数
		cout << "选手  " << it->m_Name << "  分数   " << it->m_Score<<endl;
		/*for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++) {


			cout << (*dit) << "    ";
		}
		cout << endl;*/


		// 排序 引入算法排序  默认升序
		sort(d.begin(), d.end());
		// 去除最高分 去除最低分
		d.pop_back(); //去掉最后一个元素
		d.pop_front();//去掉第一个元素
		

		// 取平均分
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++) {
			

			sum += *dit;// 累加每个评委的分数
		}
		int avg = sum / d.size();
		//将平均分 赋值给选手身上
		it->m_Score = avg;
	}
}

void showScore(vector<Person>& v) {
	
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名:   " << it->m_Name << "  平均分:  " << it->m_Score << endl;
	}

}
int main() {
	
	// 随机数种子
	srand((unsigned int)time(NULL));

	// 创建5名选手 
	vector<Person>v; // 存放选手的容器
	createPerson(v);
	/*for (vector<Person>::iterator it = v.begin();it!= v.end(); it++)
	{
		cout << "打印姓名  " << (*it).m_Name << "  分数   " << (*it).m_Score<<endl;
	}*/

	//2 给5名选手打分
	getScore(v);

	//3 显示最后得分
	showScore(v);
}