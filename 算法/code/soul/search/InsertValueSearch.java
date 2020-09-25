package com.soul.search;

import java.util.Arrays;

/**
 * 插值查找算法   自适应  
 * 数据量较大关键字分布均匀的查找来说 采用插值查找速度较快 
 * 关键字分布不均匀的情况下 不一定比二分查找方法好
 * @author dell
 *
 */
public class InsertValueSearch {

	public static void main(String[] args) {
		
		int[] arr = new int[100];
		for (int i = 0; i < arr.length; i++) {
			arr[i] = i+1;
		}
		int index = insertValueSearch(arr, 0, arr.length-1, 22);
		System.out.println("index::::::"+ index);
		//System.out.println(Arrays.toString(arr));
	}
	
	//插值查找算法
	/** 插值查找算法 也需要是有序的
	 * 
	 * @param arr 传入的数组
	 * @param left 左左边索引
	 * @param right 右边索引
	 * @param findVal 查找的值 
	 * @return  找到 就返回对应的下标  如果没找到 返回-1
	 */
	public static int insertValueSearch(int[] arr,int left,int right,int findVal) {
		System.out.println("查找次数");
		// findVal <arr[0]   findVal>arr[arr.length -1] 需要
		// 否则会越界  因为findVal 是参与到mid的计算
		if(left > right || findVal <arr[0] || findVal>arr[arr.length -1]) {
			return -1;
		}
		
		
		// 求出mid  自适应
		int mid = left+ (right-left)*(findVal-arr[left]) /(arr[right] - arr[left]);
		int midVal = arr[mid];
		if(findVal > midVal) { //向右查找
			return insertValueSearch(arr, mid+1, right, findVal);
			
		}else if(findVal < midVal) {//向左查找
			return insertValueSearch(arr, left, right-1, findVal);
		}else {
			return mid;
		}
	}

}//@@@@ 
