package com.soul.sort;

import java.util.Arrays;

/**
 * 希尔排序
 * @author dell
 *
 */
public class ShellSort {

	public static void main(String[] args) {
		
		int[] arr = {8,9,1,7,2,3,5,4,6,0};
		//shellSort(arr);
		shellSort2(arr);
	}
	
	// 希尔排序移位法
	public static void shellSort2(int[] arr) {
		
		int count = 0;
		//增量gap  并逐步缩小增量
		for (int gap = arr.length / 2; gap>0; gap /= 2) {
			// 从第gap 个元素 ,诸葛对其所在的组进行直接插入排序
			for (int i = gap; i < arr.length; i++) {
				int j = i;
				int temp = arr[j];
				if(arr[j]<arr[j-gap]) {
					while(j-gap >= 0 && temp <arr[j-gap]) {
						//移动
						arr[j] = arr[j-gap];
						j -= gap;
					}
					// 退出while 循环后 就给temp 找到 插入的位置了
					arr[j] = temp;
				}
			}
			
			System.out.println("希尔排序第"+(count++)+"轮后"+Arrays.toString(arr));
		}
	}
	
	//使用逐步推导的方式来编写希尔排序
	// 希尔排序交换法 
	public static void shellSort(int[] arr) {
		int temp = 0;
		int count = 0;
		for (int gap = arr.length / 2; gap>0; gap /= 2) {
			for (int i = gap; i < arr.length; i++) {
				//遍历各组所有的元素(共gap组 ,每组有两个元素,    步长gap)
				for (int j = i-gap; j >=0; j-=gap) {
					//如果当前的元素大于加上步长后的那个元素 说明要交换位置
					if(arr[j]>arr[j+gap]) {
						temp= arr[j];
						arr[j]= arr[j+gap];
						arr[j+gap]= temp;
					}
				}
			}
			
			System.out.println("希尔排序第"+(count++)+"轮后"+Arrays.toString(arr));
		}
		
		
		// 希尔排序移位法
		
		
		
		// 希尔排序第一轮排序
		//因为第一轮排序 是将10 个数据分成了5组
//		for (int i = 5; i < arr.length; i++) {
//			//遍历各组所有的元素(共5组 ,每组有两个元素,    步长5)
//			for (int j = i-5; j >=0; j-=5) {
//				//如果当前的元素大于加上步长后的那个元素 说明要交换位置
//				if(arr[j]>arr[j+5]) {
//					temp= arr[j];
//					arr[j]= arr[j+5];
//					arr[j+5]= temp;
//				}
//			}
//		}
//		System.out.println("希尔排序第一轮后="+Arrays.toString(arr));
//		// 希尔排序第二轮排序
//		for (int i = 2; i < arr.length; i++) {
//			//遍历各组所有的元素(共2组 ,每组有两个元素,步长2)
//			for (int j = i-2; j >=0; j-=2) {
//				//如果当前的元素大于加上步长后的那个元素 说明要交换位置
//				if(arr[j]>arr[j+2]) {
//					temp= arr[j];
//					arr[j]= arr[j+2];
//					arr[j+2]= temp;
//				}
//			}
//		}
//		System.out.println("希尔排序第三轮后="+Arrays.toString(arr));
//		for (int i = 1; i < arr.length; i++) {
//			//遍历各组所有的元素(共5组 ,每组有两个元素,步长5)
//			for (int j = i-1; j >=0; j-=1) {
//				//如果当前的元素大于加上步长后的那个元素 说明要交换位置
//				if(arr[j]>arr[j+1]) {
//					temp= arr[j];
//					arr[j]= arr[j+1];
//					arr[j+1]= temp;
//				}
//			}
//		}
//		System.out.println("希尔排序第三轮后="+Arrays.toString(arr));
//	
	}
}
