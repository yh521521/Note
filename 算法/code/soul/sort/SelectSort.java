package com.soul.sort;

import java.util.Arrays;

public class SelectSort {

	public static void main(String[] args) {
		int[] arr = {101,34,119,1};
		System.out.println("排序前");
		System.out.println(Arrays.toString(arr));
		selectSort(arr);
		System.out.println("排序后");
		System.out.println(Arrays.toString(arr));
	}
	// 选择排序
	public static void selectSort(int[] arr) {
		//使用逐步推导的方式 实现选择排序
		// 数组 1 34 119 101
		//第一轮 1 34 119 101
		
		for (int i = 0; i < arr.length-1; i++) {
			int minIndex = i;
		    int min = arr[i];
		    for (int j = i+1; j < arr.length; j++) {
		    	if(min >arr[j]) {
					//重置最小值
					min = arr[j];
					//重置最小值的索引
					minIndex= j;
				}
			}
		    if(minIndex != i) {
				arr[minIndex] = arr[i];
				arr[i] = min;
			}
			
			System.out.println("第"+(i+1)+"轮后");
			System.out.println(Arrays.toString(arr));
			
		    
		}
		
//		int minIndex = 0;
//		int min = arr[0];
//		for (int i = 1; i < arr.length; i++) {
//			if(min >arr[i]) {
//				//重置最小值
//				min = arr[i];
//				//重置最小值的索引
//				minIndex= i;
//			}
//		}
//		// 将最小值 放到arr[0] 即交换 
//		if(minIndex != 0) {
//			arr[minIndex] = arr[0];
//			arr[0] = min;
//		}
//		
//		System.out.println("第一轮后");
//		System.out.println(Arrays.toString(arr));
//		
//		// 第二轮
//		 minIndex = 1;
//		 min = arr[1];
//		for (int i = 1+1; i < arr.length; i++) {
//			if(min >arr[i]) {
//				//重置最小值
//				min = arr[i];
//				//重置最小值的索引
//				minIndex= i;
//			}
//		}
//		// 将最小值 放到arr[0] 即交换 
//		if(minIndex != 1) {
//			arr[minIndex] = arr[1];
//			arr[1] = min;
//		}
//		
//		System.out.println("第二轮后");
//		System.out.println(Arrays.toString(arr));
//		
//		
//		// 第三轮
//		 minIndex = 2;
//		 min = arr[2];
//		for (int i = 3; i < arr.length; i++) {
//			if(min >arr[i]) {
//				//重置最小值
//				min = arr[i];
//				//重置最小值的索引
//				minIndex= i;
//			}
//		}
//		// 将最小值 放到arr[0] 即交换 
//		if(minIndex != 2) {
//			arr[minIndex] = arr[2];
//			arr[2] = min;
//		}
//		
//		System.out.println("第三轮后");
//		System.out.println(Arrays.toString(arr));
//				
	}

}
