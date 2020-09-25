package com.yh.soul.binarysearchnorecursion;

/**
 * 二分查找非递归实现
 * @author dell
 *
 */
public class BinarySearchNoRecur {

	public static void main(String[] args) {
		int[] arr = {1,3,8,10,11,67,100};
		int index = binarySearch(arr, 8);
		System.out.println("index:::"+index);
	}
	
	// 二分查找的非递归实现  非递归 好处可以 减轻 递归带来的栈空间 开销
	/**
	 * 
	 * @param arr 待查找的数组   有序 默认是升序排列 
	 * @param traget 需要查找的值  
	 * @return 返回的对应的下标 -1 没找到
	 */
	public static int binarySearch(int[] arr,int traget) {
		
		int left = 0;
		int right = arr.length -1;
		while(left <= right) { // 说明继续查找
			int mid = (left+right) / 2 ;
			if(arr[mid] == traget) {
				return mid;
			}else if(arr[mid]  > traget) {
				right = mid -1;// 需要向左边查找
			}else {
				left = mid + 1;// 需要向右边查找
			}
		}
		return -1;
	}

}//@@@@
