package com.soul.search;

import java.util.ArrayList;
import java.util.List;

/**
 * 二分查找的前提  是该数组 有序  从大到小 或者从小到大
 * @author dell
 *
 */
public class BinarySearch {

	public static void main(String[] args) {
		
		//int arr[] = {1,8,10,89,1234,2222};
		int[] arr = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
		// 如果查找不存在的就会栈溢出
//		int resIndex = binarySearch(arr, 0, arr.length-1, 1000); 
//		if(resIndex == -1) {
//			System.out.println("未找到");
//			return;
//		}
//		System.out.println("找到了下标为:  "+ resIndex);
		
		
		List<Integer> resIndexList = binarySearch2(arr, 0, arr.length -1, 1);
		System.out.println("resIndexList >>"+resIndexList);
	}
	// 二分查找法 
	/**
	 * 
	 * @param arr 数组
	 * @param left  左边的索引
	 * @param right 右边的索引
	 * @param findVal要查找的值 
	 * return 如果找到就返回下标 没找到返回 -1 
	 */
	public static int  binarySearch(int[] arr,int left,int right,int findVal) {
		// 当left > right 时候  说明递归整个数组 但是没有找到
		if(left > right) {
			return -1;
		}
		
		
		int mid = (left + right) / 2;
		int midVal = arr[mid];
		if(findVal >midVal) { // 向右递归
			return binarySearch(arr, mid+1, right, findVal);
			
		}else if(findVal < midVal) { // 向左递归
			return binarySearch(arr, left, mid-1, findVal);
		}else {
			return mid;
		}
	}
	/**
	 * int arr[] = {1,8,10,89,1000,1000,1234,2222}; 
	 * 如果有多个相同的值,如何将所有的值 都查到 比如这里的 1000 
	 * 找到mid 索引值 时 不要马上返回 
	 * 向mid 索引值的左边扫描  将所有满足1000 的元素下标 加入到集合ArrayList  
	 * 向mid 索引值的右边扫描  将所有满足1000 的元素下标 加入到集合ArrayList  
	 * 返回一个list 就行
	 * @param arr
	 * @param left
	 * @param right
	 * @param findVal
	 * @return
	 */
	public static List<Integer>  binarySearch2(int[] arr,int left,int right,int findVal) {
		System.out.println("hello world");
		// 当left > right 时候  说明递归整个数组 但是没有找到
		if(left > right) {
			return new ArrayList<Integer>();
		}
		
		
		int mid = (left + right) / 2;
		int midVal = arr[mid];
		if(findVal >midVal) { // 向右递归
			return binarySearch2(arr, mid+1, right, findVal);
			
		}else if(findVal < midVal) { // 向左递归
			return binarySearch2(arr, left, mid-1, findVal);
		}else {
//			找到mid 索引值 时 不要马上返回 
//			 * 向mid 索引值的左边扫描  将所有满足1000 的元素下标 加入到集合ArrayList  
//			 * 向mid 索引值的右边扫描  将所有满足1000 的元素下标 加入到集合ArrayList  
//			 * 返回一个list 就行
			List<Integer> resIndexList = new ArrayList<Integer>();
			//向mid 索引值的左边扫描  将所有满足1000 的元素下标 加入到集合ArrayList  
			int temp = mid -1;
			while(true) {
				if(temp < 0 || arr[temp] != findVal) {//退出
					break;
					
				}
				//否则 就temp   放入到resIndexList 
				resIndexList.add(temp);
				temp -= 1; //temp 左移
			}
			resIndexList.add(mid);
			
			
			//向mid 索引值的右边扫描  将所有满足1000 的元素下标 加入到集合ArrayList  
			temp = mid +1;	
			while(true) {
				if(temp > arr.length -1 || arr[temp] != findVal) {//退出
					break;
					
				}
				//否则 就temp   放入到resIndexList 
				resIndexList.add(temp);
				temp += 1; //temp 右移
			}
			//resIndexList.add(mid);
			return resIndexList;
		}
	}
	
}//@@@@@@@@
