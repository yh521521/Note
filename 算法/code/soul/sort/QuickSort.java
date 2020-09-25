package com.soul.sort;

import java.util.Arrays;

public class QuickSort {

	public static void main(String[] args) {
		
		int[] arr = {-9,78,0,23,-567,70};
		quickSort(arr,0,arr.length -1);
		System.out.println("quickSort"+Arrays.toString(arr));
	}
	
	public static void quickSort(int[] arr,int left,int right) {
		int L = left;//左下标
		int r = right;//右下标
		// pivot 中轴 中心点 
		int pivot = arr[(left+right)/2];
		int temp = 0;// 临时变量 作为交换 时 使用
		//while 循环的目的是让pivot 值 小的放到左边 
		// 比pivot  值大的放到右边
		while(L < r) {
			// 在pivot 的左边一直找 找到大于等于pivot 值  才退出
			while(arr[L] <pivot) {
				L+=1;
			}
			// 在pivot 的左边一直找 找到小于等于pivot 值  才退出
			while(arr[r]>pivot) {
				r-=1;
			}
			// 说明L > r 说明pivot 的左右两边的值  已经按照pivot 左边<= pivot    右边  >= pivot 
			if(L >= r) {
				break;
			}
			// 交换
			temp = arr[L];
			arr[L] = arr[r];
			arr[r] = temp;
			// 如果交换完后  发现arr[L] == pivot 值 前移
			if(arr[L] == pivot) {
				r-= 1;
			}
			// 如果交换完后  发现arr[r] == pivot 值 后移
			if(arr[r] == pivot) {
				L+=1;
			}
		}
		// 如果L== r  必须 L++ ,r--,否则出现栈 溢出 
		if(L==r) {
			L +=1;
			r -=1;
		}
		//向左递归 
		if(left <r) {
			quickSort(arr,left,r);
		}
		//向右递归 
		if(right >L) {
			quickSort(arr,L,right);
		}
	}

}//@@@@@@@@@@@@@@@
