package com.soul.recursion;
/**
 * 八皇后问题
 * @author dell
 *
 */
public class Queue8 {
	
	// 定义一个max  表示共有多少个皇后
	int max = 8;
	// 定义数组array  保存皇后 防止位置的结果 
	// 比如 arr[8] = {0,4,7,5,2,6,1,3}
	int[] array = new int[max];
	static int count =0;
	static int judgeCount =0;
	public static void main(String[] args) {
		
		//
		Queue8 queue8 = new Queue8();
		queue8.check(0);
		System.out.println("一共由多少种解法"+count);
		System.out.println("一共判断多少次"+judgeCount);
		
	}
	
	// 将皇后摆放的位置输出 
	private void print() {
		count ++;
		for (int i = 0; i < array.length; i++) {
			System.out.print(array[i]+" ");
		}
		System.out.println();
	}
	
	// 查看当我们防止第n 个皇后时 ,就去检测该皇后是否和前面已经摆放的皇后冲突
	//  n 表示 第 n 个皇后
	
	private boolean judge(int n) {
		judgeCount++;
		for (int i = 0; i < n; i++) {
			//1 array[i] == array[n] 第n 个皇后和前面的n-1 个皇后在同一列
			//2Math.abs(n-i)== Math.abs(array[n]-array[i]) 第n 个皇后和前面的i个皇后在同一斜线
			if(array[i] == array[n] || Math.abs(n-i)== Math.abs(array[n]-array[i])) {
				return false;
			}
		}
		return true;
	}
	// 编写一个方法 放置 n 个皇后
	private void check(int n) {
		if(n == max) {//n = 8 其实8 个皇后 就已经放好了
			print();
			return;
		}
		//如果没有  依次放入皇后  并判断是否冲突
		for (int i = 0; i < max; i++) {
			// 先把 当前这个皇后n 放该行的第一列
			array[n]= i;
			//判断 当前的第n 个皇后 到第 i列 是否冲突
			if(judge(n)) { // 不冲突
				// 接着放n+1 个皇后  ,即 开始递归
				check(n+1);
				
			}
				// 冲突  继续执行 array[n] = i; 将 第n 个皇后  放置到本行的 后移的一个位置
			
			
			
		}
		
	}

}
