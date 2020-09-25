package com.soul.sort;

import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Date;

public class BubbleSort {

	public static void main(String[] args) {
		//int arr[] = {3,9,-1,10,20}; 
		//int arr[] = {1,2,3,4,5}; 
		
		int[] arr = new int[80000];
		for (int i = 0; i < 80000; i++) {
			arr[i] = (int) (Math.random()*80000);
		}
		Date date1 = new Date();
		SimpleDateFormat format = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		String date1Str = format.format(date1);
		System.out.println("排序前的时间为"+date1Str);
		bubbleSort(arr);
		
		Date date2 = new Date();
		SimpleDateFormat format2 = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		String date21Str = format2.format(date2);
		System.out.println("排序后的时间为"+date21Str);
		System.out.println("排序后");
		System.out.println(Arrays.toString(arr));
		
		// 时间复杂度  o(n^2)
		// 第二种
//		boolean flag = false;
//		for (int j = 0; j < arr.length-1; j++) {
//			for (int i = 0; i < arr.length-j-1; i++) {
//				if(arr[i]>arr[i+1]) {
//					flag = true;
//					int temp= arr[i];
//					arr[i]= arr[i+1];
//					arr[i+1] = temp;
//				}
//			}
//			System.out.println("第"+(j+1)+"趟排序后的数据");
//			System.out.println(Arrays.toString(arr));
//			if(flag == false) { // 没有发生交换
//				break;
//			}else {
//				flag = false;// 重置flag  进行下次判断
//			}
//		}
		
		//第一种
//		for (int j = 0; j < arr.length-1; j++) {
//			for (int i = 0; i < arr.length-j-1; i++) {
//				if(arr[i]>arr[i+1]) {
//					int temp= arr[i];
//					arr[i]= arr[i+1];
//					arr[i+1] = temp;
//				}
//			}
//		}
		
		
		
		
//		for (int i = 0; i < arr.length-1-1; i++) {
//			if(arr[i]>arr[i+1]) {
//				int temp= arr[i];
//				arr[i]= arr[i+1];
//				arr[i+1] = temp;
//			}
//		}
//		
//		System.out.println("第二趟排序后的数据");
//		System.out.println(Arrays.toString(arr));
//		for (int i = 0; i < arr.length-1-1-1; i++) {
//			if(arr[i]>arr[i+1]) {
//				int temp= arr[i];
//				arr[i]= arr[i+1];
//				arr[i+1] = temp;
//			}
//		}
//		
//		System.out.println("第三趟排序后的数据");
//		System.out.println(Arrays.toString(arr));
//		for (int i = 0; i < arr.length-1-1-1-1; i++) {
//			if(arr[i]>arr[i+1]) {
//				int temp= arr[i];
//				arr[i]= arr[i+1];
//				arr[i+1] = temp;
//			}
//		}
//		
//		System.out.println("第四趟排序后的数据");
//		System.out.println(Arrays.toString(arr));
	}
	
	public static void bubbleSort(int[] arr) {
		boolean flag = false;
		for (int j = 0; j < arr.length-1; j++) {
			for (int i = 0; i < arr.length-j-1; i++) {
				if(arr[i]>arr[i+1]) {
					flag = true;
					int temp= arr[i];
					arr[i]= arr[i+1];
					arr[i+1] = temp;
				}
			}
			//System.out.println("第"+(j+1)+"趟排序后的数据");
			//System.out.println(Arrays.toString(arr));
			if(flag == false) { // 没有发生交换
				break;
			}else {
				flag = false;// 重置flag  进行下次判断
			}
		}
		
	}

}
