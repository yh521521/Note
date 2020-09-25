package com.soul.queue;

import java.util.Scanner;

public class CircleArrayQueueDemo {

	public static void main(String[] args) {
		
		System.out.println("测试数组模拟环形队列的案例");

		
		//测试 创建一个队列  设置为4 其队列的有效数据最大为3 
		CircleArray queue = new CircleArray(4);
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

class CircleArray{
	// 数组的最大容器
	private int maxSize ;
	// 队列头  初始值 = 0  指向队列的第一个元素 也就是arr[front]
	private int front ;
	// 队列尾  初始值 0   指向队列的最后一个元素的后一个位置  .因为希望能空出一段空间  
	private int rear ;
	// 数组存放数据
	private int[] arr ;
	
	//创建队列的构造器
	public CircleArray(int arrMaxSize) {
		maxSize =arrMaxSize;
		arr = new int[maxSize];
		//队列头 指向队列头的前一个位置
//		front = 0;
		//队列尾 指向队列尾的数据  也就是最后一个数据
//		rear = 0;
	}
	//判断队列是否满
	public boolean isFull() {
		
		return (rear+1)% maxSize ==front;
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
		
		arr[rear]=n;
		//尾指针 后移
		rear= (rear+1)%maxSize;
	}
	//获取队列数据 出队列
	public int getQueue() {
		//判断队列是否为空
		if(isEmpty()) {
			//抛出异常
			throw new RuntimeException("队列空 不能获取数据");
			
		}
		// 这里需要分析front 指向队列的第一个元素
		// 1 先把 front 的对应的值 保存到一个临时变量
		//2 将 front 后移  考虑取模
		// 将 链式保存的变量返回 
		int value = arr[front];
		front = (front +1)%maxSize;
		return value;
	}
	
	// 显示队列的所有数据
	public void showQueue() {
		
		//遍历
		if(isEmpty()) {
			System.out.println("队列为空 没数据");
			return;
		}
		// 思路  从front  开始遍历  遍历多少个元素
		
		for (int i = front; i < front+size(); i++) {
			System.out.printf("arr[%d]=%d\n",i%maxSize,arr[i%maxSize]);
		}
	}
	
	// 求出当前队列有效数据的个数
	public int size() {
		
		return (rear+maxSize-front)%maxSize;
		
	}
	
	//显示队列的头数据  不是取数据
	public int headQueue() {
		
		if(isEmpty()) {
			//抛出异常
			throw new RuntimeException("队列空 不能获取数据");
			
		}
		return arr[front];
	}
	
}

