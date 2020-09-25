package com.soul.queue;

import java.util.Scanner;

public class ArrayQueueDemo {
//	 1 目前数据使用一次就不能复用  没有达到服用的效果
//
//	 2 将这个数组使用算法  ,该近成 一个环形数组

	

	public static void main(String[] args) {
		
		//测试 创建一个队列
		ArrayQueue queue = new ArrayQueue(3);
		char key = ' '; // 接收用户输入
		Scanner scanner = new Scanner(System.in);//
		boolean loop = true;
		//输出一个菜单
		while(loop) {
			System.out.println(" s(show): 显示队列");
			System.out.println(" e(exit): 退出程序");
			System.out.println(" a(add): 添加数据到队列");
			System.out.println(" g(get): 从队列取出数据");
			System.out.println(" h(head): 查看队列头的数据");
			
			key = scanner.next().charAt(0);
			switch (key) {
			case 's':
				queue.showQueue();
				break;
			case 'a':
				System.out.println("请输入一个数");
				int value = scanner.nextInt();
				queue.addQueue(value);
				break;
			case 'g':// 取出数据
				try {
				int res = queue.getQueue();
				System.out.printf("取出的数据%d\n",res);
				}catch(Exception e){
					System.out.println(e.getMessage());
				}
				break;
			case 'h': // 查看队列头的数据
				try {
					int res = queue.headQueue();
					System.out.printf("队列头的数据是%d\n",res);
				} catch (Exception e) {
					System.out.println(e.getMessage());
				}
				break;
			case 'e': // 退出
				scanner.close();
				loop = false;
				break;
			default:
				break;
			}
		}
		
		System.out.println("程序退出");
	}

}
//使用数组模拟队列 编写一个ArrayQueue类

class ArrayQueue{
	
	// 数组的最大容器
	private int maxSize ;
	// 队列头
	private int front ;
	// 队列尾
	private int rear ;
	// 数组存放数据
	private int[] arr ;
	
	//创建队列的构造器
	public ArrayQueue(int arrMaxSize) {
		maxSize =arrMaxSize;
		arr = new int[maxSize];
		//队列头 指向队列头的前一个位置
		front = -1;
		//队列尾 指向队列尾的数据  也就是最后一个数据
		rear = -1;
	}
	//判断队列是否满
	public boolean isFull() {
		
		return rear == maxSize -1;
	}
	//判断队列是否为空
	public boolean isEmpty() {
		
		return rear == front;
	}
	//添加数据到队列
	public void addQueue(int n) {
			
		//判断队列受否满
		if(isFull()) {
			
			System.err.println("队列满 , 不能加入数据");
			return;
		}
		//尾指针 后移
		rear++;
		arr[rear]=n;
	}
	//获取队列数据 出队列
	public int getQueue() {
		//判断队列是否为空
		if(isEmpty()) {
			//抛出异常
			throw new RuntimeException("队列空 不能获取数据");
			
		}
		front++;// front 后移
		return  arr[front];
	}
	// 显示队列的所有数据
	public void showQueue() {
		
		//遍历
		if(isEmpty()) {
			System.out.println("队列为空 没数据");
			return;
		}
		for (int i = 0; i < arr.length; i++) {
			System.out.printf("arr[%d]=%d\n",i,arr[i]);
		}
	}
	//显示队列的头数据  不是取数据
	public int headQueue() {
		
		if(isEmpty()) {
			//抛出异常
			throw new RuntimeException("队列空 不能获取数据");
			
		}
		return arr[front+1];
	}
}
