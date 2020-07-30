//自己的通用数组类 
#pragma once
#include <iostream>
using namespace std;

template <class T>
class MyArray {
public:
	MyArray(int capacity) {
		cout << "MyArray 有参构造" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}
	//拷贝构造
	MyArray(const MyArray& arr) {
		cout << "MyArray 拷贝构造" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		// 深拷贝
		this->pAddress = new T[arr.m_Capacity];
		// 将arr 中的数据都拷贝过来
		for (int  i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}
	//operator  防止浅拷贝问题
	MyArray& operator = (const MyArray& arr) {
		cout << "MyArray operator  防止浅拷贝构造" << endl;
		// 先判断原来堆区是否有数据 有显示放
		if (this->pAddress != NULL) {
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		//深拷贝
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];

		for (int  i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}

	// 尾插法
	void Push_Back(const T& val ) {
		//判断容量
		if (this->m_Capacity ==this->m_Size) {
			return;
		}
		this->pAddress[this->m_Size] = val; //在数组末尾插入数据
		this->m_Size++; //更新数组大小
	}
	// 尾删法
	void Pop_Back() {
		//让用户访问不到最后一个元素 即为尾删 逻辑删除
		if (this->m_Size == 0) {
			return;
		}
		this->m_Size--;
	}

	// 通过下标方式访问数组元素
	T&  operator[](int index) {
		return this->pAddress[index];
	}
	// 返回数组容量
	int getCapacity() {
		return this->m_Capacity;
	}

	// 返回数组大小
	int  getSize() {
		return this->m_Size;
	}

	//析构函数
	~MyArray() {
		cout << "MyArray 析构构造" << endl;
		if (this->pAddress != NULL) {
			delete[] this->pAddress;	
			this->pAddress = NULL;
		}
	}
private:

	T* pAddress; //指针指向堆区开辟的真实数组
	int m_Capacity; //数组容量
	int m_Size; // 数组大小
};