package com.soul.sort;

import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Date;

/**
 * 插入排序
 * @author dell
 *
 */
public class InsertSort {

	public static void main(String[] args) {
		//int[] arr = {101,34,119,1};
		int[] arr = {101,34,119,1,33,666,44,77,0};
		
	
		insertsort(arr);
		
		
		
	}
	
	public static void insertsort(int[] arr) {
		int insertVal = 0;
		int insertIndex = 0;
		
		// 使用for 循环来简化代码
		
		for (int i = 1; i < arr.length; i++) {
			 insertVal = arr[i];
			 insertIndex = i-1;//即 arr[1]的前面这个数的下标
			//给insertVal 找到插入的位置
			//1. insertIndex >= 0) 保证在给insertVal 找插入位置  不越界 
			// 2. insertVal<arr[insertIndex]  待插入的数 还没找到插入位置
			//3 就需要将arr[insertIndex]后移
			while(insertIndex >= 0 && insertVal<arr[insertIndex]) {
				arr[insertIndex+1] = arr[insertIndex];
				insertIndex--;
			}
			// 退出while 时 说明插入的位置找到 insertIndex +1 
			// 判断是否需要赋值
			if(insertIndex+1 != i) {
				arr[insertIndex+1] = insertVal;
			}
			
			//System.out.println("第"+i+"轮插入");
			//System.out.println(Arrays.toString(arr));
		}
		
		
		
		
		
		// 逐步推导
		// 分为一个有序表 和一个无序表
		// 定义待插入的数
		
//		// 定义待插入的数
//		int insertVal = arr[1];
//		int insertIndex = 1-1;//即 arr[1]的前面这个数的下标
//		//给insertVal 找到插入的位置
//		//1. insertIndex >= 0) 保证在给insertVal 找插入位置  不越界 
//		// 2. insertVal<arr[insertIndex]  待插入的数 还没找到插入位置
//		//3 就需要将arr[insertIndex]后移
//		while(insertIndex >= 0 && insertVal<arr[insertIndex]) {
//			arr[insertIndex+1] = arr[insertIndex];
//			insertIndex--;
//		}
//		// 退出while 时 说明插入的位置找到 insertIndex +1 
//		arr[insertIndex+1] = insertVal;
//		System.out.println("第一轮插入后");
//		System.out.println(Arrays.toString(arr));
//		
//		//第2轮
//		 insertVal = arr[2];
//		 insertIndex = 2-1;//即 arr[1]的前面这个数的下标
//		 while(insertIndex >= 0 && insertVal<arr[insertIndex]) {
//				arr[insertIndex+1] = arr[insertIndex];
//				insertIndex--;
//			}
//		arr[insertIndex+1] = insertVal;
//		System.out.println("第二轮插入后");
//		System.out.println(Arrays.toString(arr));
//		//第3轮
//		 insertVal = arr[3];
//		 insertIndex = 3-1;//即 arr[1]的前面这个数的下标
//		 while(insertIndex >= 0 && insertVal<arr[insertIndex]) {
//				arr[insertIndex+1] = arr[insertIndex];
//				insertIndex--;
//			}
//		arr[insertIndex+1] = insertVal;
//		System.out.println("第三轮插入后");
//		System.out.println(Arrays.toString(arr));
	}

}
