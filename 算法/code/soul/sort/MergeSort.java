package com.soul.sort;

import java.util.Arrays;

/**
 * 归并排序
 * @author dell
 *
 */
public class MergeSort {

	public static void main(String[] args) {
		
		int[] arr = {8,4,5,7,1,3,6,2};
		int[] temp = new int[arr.length];// 归并排序需要额外的空间开销 
		mergeSort(arr, 0, arr.length-1, temp);
		System.out.println("归并排序后:"+Arrays.toString(arr));
	}
	
	
	// 分 + 合 的方法
	public static void mergeSort(int[] arr,int left ,int right,int[] temp) {
		if(left <right) {
			int mid = (left+right) /2; // 中间索引
			// 向左递归进行分解
			mergeSort(arr, left, mid, temp);
			// 向右递归进行分解
			mergeSort(arr, mid+1, right, temp);
			// 合并
			merge(arr, left, mid, right, temp);
			
		}
	}
	
	//  合并的方法
	/**
	 * 
	 * @param arr 排序的原始数组
	 * @param left 左边有序序列的初始索引
	 * @param mid中间索引
	 * @param right右边的索引
	 * @param temp 做中专的数组
	 */
	public static void merge(int[] arr,int left,int mid ,int right,int[] temp) {
		
		int i = left;// 初始化 i 左边有序列初始化索引
		int j = mid +1; //初始化j  右边有序列的初始化索引
		int t = 0; // 指向temp 数组的当前索引
		
		//   (一)
		// 先把 左右两边的(有序)的数据按照规则填充到temp 数组
		//直到左右两边的有序序列 ,有一边 处理完 为止
		while(i <=mid &&j <= right) {//继续
			// 如果左边的有序序列的当前元素 <= 右边有序序列的当前元素
			// 即 将左边的当前元素  填充到temp 数组
			// 然后t++ ,i++
			if(arr[i]<= arr[j]) {
				temp[t] = arr[i];
				t+=1;
				i+=1;
			}else { //  将右边有序序列的当前元素,填充到temp 数组
				temp[t]= arr[j];
				t+=1;
				j+=1;
			}
		}
		
		//   (二)
		// 把所有剩余数据的一边的数据依次全部填充到temp 
		while(i<= mid) { // 左边的有序序列 还有剩余的元素 就全部填充到temp 
			temp[t] = arr[i];
			t+=1;
			i+=1;
			
		}
		
		while(j<= right) { // 右边的有序序列 还有剩余的元素 就全部填充到temp 
			temp[t] = arr[j];
			t+=1;
			j+=1;
			
		}
		//   (三)
		//将temp 数组的元素拷贝到arr 
		// 并不是每次拷贝所有
		t = 0;
		int tempLeft = left;
		// 第一次合并 tempLeft = 0 ,right =1  第二次合并tempLeft = 2 ,right  = 3 第三次合并 tempLeft = 0 ,right  = 3
		// 最后一次合并 tempLeft = 0 ,right =7 
		//System.out.println("tempLeft:"+tempLeft +"right:"+right);
		
//		tempLeft:0   right:1
//		tempLeft:2   right:3
//		tempLeft:0   right:3
//		tempLeft:4   right:5
//		tempLeft:6   right:7
//		tempLeft:4   right:7
//		tempLeft:0   right:7
		while(tempLeft <= right) {
			arr[tempLeft] = temp[t];
			t+=1;
			tempLeft +=1;
			
		}
		
	}

}//@@@@@
