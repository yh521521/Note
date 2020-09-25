package com.soul.tree;

import java.util.Arrays;

public class HeapSort {

	public static void main(String[] args) {
		// 升序 用大顶堆 降序 小顶堆 
		//int[] arr = {4,6,8,5,9};
		int[] arr = {4,6,8,5,9,-1,90,89,56,-999};
		heapSort(arr);
	}
	
	// 编写一个堆排序的方法
	public static void heapSort(int[] arr) {
		int temp = 0;
		System.out.println("堆排序");
		//分布完成
//		adjustHeap(arr, 1, arr.length);
//		System.out.println("第一次"+ Arrays.toString(arr));
//		adjustHeap(arr, 0, arr.length);
//		System.out.println("第二次"+ Arrays.toString(arr));
		
		for (int i = arr.length / 2  -1; i >= 0; i--) {
			adjustHeap(arr, i, arr.length);
		}
		/**
		 * 2) 将堆顶元素 鱼末尾元素 交换 将 最大元素 沉到 数组末端 
		 * 3) 重新调整结构 使其满足堆定义 然后继续交换堆顶元素鱼当前末尾元素  反复执行调整 
		 * +交换步骤 直到 整个序列有序
		 */
		for (int j = arr.length -1 ; j >0  ; j--) {
			//交换
			temp = arr[j];
			arr[j] = arr[0];
			arr[0] = temp;
			adjustHeap(arr, 0, j);
		}
		System.out.println("第一次"+ Arrays.toString(arr));
	}
	// 将一个数组 (二叉树 ) 调整成 一个大顶堆 
	/**
	 *  功能 完成将 以i 对应的非叶子节点 的数调整大顶堆 
	 *  example int[] arr = {4,6,8,5,9}; =>i =1 =>{4,9,8,5,6}
	 *  再次调整 i = 0 => {9,6,8,5,4}
	 * @param arr 待调整的数组
	 * @param i 表示 非叶子节点在数组中的索引 
	 * @param length 表示堆多少个元素继续调整 length 在逐渐减少 
	 */
	public static void adjustHeap(int[] arr,int i,int length) {
		
		int temp = arr[i]; // 先取出当前元素的值 保存在临时变量
		//开始调整 
		//  k = i*2+1  k 是i 节点的左子节点 
		for (int k = i*2+1; k < length; k= k*2+1) {
			if(k+ 1 <length && arr[k] < arr[k+1]) {// 说明左子节点的值 小于右子节点的值 
				k++; // k 指向右子节点
			}
			if(arr[k]  >temp) {// 如果子节点 大于父节点 
				arr[i] = arr[k];//把 较大的值赋给 当前节点
				i =k;// i 指向k 继续循环比较 
			}else {
				break;//
			}
		}
		// for 循环结束后 我们已经将以 i  为父节点 的树的最大值  放在了最顶(局部 )
		arr[i] = temp; //将temp 的值 放到调整后的位置 
	}
	
	

}//@@@@@@@@@@@@
