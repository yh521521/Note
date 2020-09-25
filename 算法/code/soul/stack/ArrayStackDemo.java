package com.soul.stack;

import java.util.Scanner;

public class ArrayStackDemo {

	public static void main(String[] args) {
		//创建长度为4 的栈 
		ArrayStack stack = new ArrayStack(4);
		String key = "";
		boolean loop = true;// 控制是否退出菜单
		Scanner sc = new Scanner(System.in);
		while(loop) {
			System.out.println("show  表示显示栈 ");
			System.out.println("exit  表示退出栈 ");
			System.out.println("push  表示添加数据到栈 ");
			System.out.println("pop   表示从栈 取出数据 ");
			System.out.println("请输入你的选择");
			key = sc.next();
			switch (key) {
			case "show":
				stack.list();
				break;
			case "push":
				System.out.println("请输入一个数");
				int value = sc.nextInt();
				stack.push(value);
				break;
			case "pop":
				try {
					int res = stack.pop();
					System.out.println("出栈的数据是"+res);
				} catch (Exception e) {
					e.printStackTrace();
				}
				break;
			case "exit":
				//关闭键入 流
				sc.close();
				// 终止 循环
				loop = false;
				break;
			default:
				break;
			}
		}
		System.out.println("程序退出while 循环");
	}

}

//栈 
class ArrayStack{
	
	private int maxSize ; // 栈的大小
	private int[] stack;// 数组 数组模拟栈 数据就放在该数组中
	private int top= -1; //栈 顶
	//private int top= -1; //栈 顶
	public ArrayStack(int maxSize) {
		this.maxSize = maxSize;
		stack = new int[this.maxSize];
		
	}
	// 栈 满 
	public boolean isFull() {
		return top == maxSize-1;
	}
	// 栈 是否为空
	public boolean isEmpty() {
		return top == -1;
	}
	//入栈
	public void push(int value) {
		// 判断栈 是否满 
		if(isFull()) {
			System.out.println("栈满 了");
			return;
		}
		top++;
		stack[top] = value;
	}
	//出栈 
	public int pop() {
		// 判断栈 是否为空
		if(isEmpty()) {
			// 抛出异常
			throw new RuntimeException("栈空 ,没有数据");
		}
		int value = stack[top];
		top--;
		return value;
		
		// 遍历栈  从栈 顶 开始显示数据
		
	}
	public void list() {
		if(isEmpty()) {
			System.out.println("栈空 没有数据");
			return;
		}
		for (int i = top; i>=0; i--) {
			System.out.printf("stack[%d]=%d\n",i,stack[i]);
			
		}
	}
	
}
