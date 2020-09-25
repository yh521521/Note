package com.soul.sort;

import java.util.Arrays;

/**
 * 基数排序
 * @author dell
 *
 */
//第一次 bucket
//[[0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [542, 0, 0, 0, 0, 0], [53, 3, 0, 0, 0, 0], [542, 214, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], 
//[0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [748, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0]]

//第二次 bucket 
//[[3, 0, 0, 0, 0, 0], [14, 214, 0, 0, 0, 0], [542, 0, 0, 0, 0, 0], [53, 3, 0, 0, 0, 0], [542, 748, 0, 0, 0, 0], 
 //[53, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0],[0, 0, 0, 0, 0, 0], [748, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0]]
//第三次 bucket
// 有些数据被覆盖了 比如 53  十位  是在 第五个桶中  542 百位 也在第五个桶中都是第一位  542 覆盖了 53 
//[[3, 14, 53, 0, 0, 0], [14, 214, 0, 0, 0, 0], [214, 0, 0, 0, 0, 0], [53, 3, 0, 0, 0, 0], [542, 748, 0, 0, 0, 0],
// [542, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [748, 0, 0, 0, 0, 0], [748, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0]]
public class RadixSort {

	public static void main(String[] args) {
		int[] arr = {53,3,542,748,14,214};
		
		radixSort1(arr);
	}
	
	
	public static void radixSort1(int[] arr) {
		//得到数组中最大数 
		int max = arr[0]; // 将设 第一个数就是最大数
		for (int i = 1; i < arr.length; i++) {
			if(arr[i] >max) {
				max = arr[i];
			}
		}
		// 得到数组中最大数 是几位数 
		int maxLength = (max +"").length(); 
		
		// 第一轮  (针对每个元素的个位进行排序处理)
		
		// 定义一个二维数组 表示10 个桶 每个桶就是一个二维数组
		// 二维数组 包含10 个一维数组 
		// 为了防止再放入数据的时候 数据溢出 每个一维数组 大小定为 arr.length
		// 基数排序是使用空间换时间的经典算法
		int[][] bucket = new int[10][arr.length];
		//为了记录每个桶中 实际存放了多少个数据,我们定义一个
		//一维数组来记录各个桶的每次放入的数据个数
		//bucketElementCounts[0] 记录的是bucket[0]桶 放入数据个数
		int[] bucketElementCounts = new int[10];
		
		for (int i = 0,n =1 ; i < maxLength; i++,n *= 10) {
			
			// 针对每个元素的对应的 位进行排序处理  第一次是个位  第二次是十位 第三次是百位
			for (int j = 0; j < arr.length; j++) {
				// 取出每个元素的对应位的值  arr 数组都是会变得  第一次拿的是元数据 第二次 拿的是 个位排序得到桶 刷新到数组的arr 
				int  digitOfElement = arr[j]/n  %10;
				//放入到对应的桶中 
				bucket[digitOfElement][bucketElementCounts[digitOfElement]] = arr[j];
				bucketElementCounts[digitOfElement]++;
			}
			//按照这个桶的顺序 (一维数组的下标依次取出数据 放入原来数组)
			int index = 0;
			
			//遍历每一个桶 并将桶中数据 放入到原数组 
			for(int k = 0;k<bucketElementCounts.length;k++) {
				//如果桶中有数据 我们才放入到原数组
				if(bucketElementCounts[k] != 0) {
					//循环该桶即第k 个桶 (即第k 个一维数组 ,放入)
					for (int l = 0; l < bucketElementCounts[k]; l++) {
						//取出元素放到arr  原来的数组为 {53,3,542,748,14,214}; 
						//[542, 3, 542, 748, 14, 214]  从桶中 取出数据 放到 并发重新放到原数组中
						arr[index++] = bucket[k][l];
					
					}
				}
				// 第i+1轮处理后 需要将bucketElementCounts[k] =0  桶中的数据 取出来后  一定要记得去清除
				bucketElementCounts[k] =0 ;
			}
			System.out.println("第"+(i+1)+"轮,对个位的排序处理 arr = "+Arrays.toString(arr));
			
		}
	
	}
	// 基数排序方法  
	public static void radixSort(int[] arr) {
		
		// 第一轮  (针对每个元素的个位进行排序处理)
		
		// 定义一个二维数组 表示10 个桶 每个桶就是一个二维数组
		// 二维数组 包含10 个一维数组 
		// 为了防止再放入数据的时候 数据溢出 每个一维数组 大小定为 arr.length
		// 基数排序是使用空间换时间的经典算法
		int[][] bucket = new int[10][arr.length];
		//为了记录每个桶中 实际存放了多少个数据,我们定义一个
		//一维数组来记录各个桶的每次放入的数据个数
		//bucketElementCounts[0] 记录的是bucket[0]桶 放入数据个数
		int[] bucketElementCounts = new int[10];
		// 第一轮 针对每个元素的个位进行排序处理 
		for (int j = 0; j < arr.length; j++) {
			// 取出每个元素的个位的值
			int  digitOfElement = arr[j] %10;
			//放入到对应的桶中 
			bucket[digitOfElement][bucketElementCounts[digitOfElement]] = arr[j];
			bucketElementCounts[digitOfElement]++;
		}
		//按照这个桶的顺序 (一维数组的下标依次取出数据 放入原来数组)
		int index = 0;
		
		//遍历每一个桶 并将桶中数据 放入到原数组 
		for(int k = 0;k<bucketElementCounts.length;k++) {
			//如果桶中有数据 我们才放入到原数组
			if(bucketElementCounts[k] != 0) {
				//循环该桶即第k 个桶 (即第k 个一维数组 ,放入)
				for (int i = 0; i < bucketElementCounts[k]; i++) {
					//取出元素放到arr
					arr[index++] = bucket[k][i];
				
				}
			}
			// 第一轮处理后 需要将bucketElementCounts[k] =0 
			bucketElementCounts[k] =0 ;
		}
		System.out.println("第一轮,对个位的排序处理 arr = "+Arrays.toString(arr));
		
		//第二轮
		for (int j = 0; j < arr.length; j++) {
			// 取出每个元素的个位的值
			int  digitOfElement = arr[j] / 10 %10;
			//放入到对应的桶中 
			bucket[digitOfElement][bucketElementCounts[digitOfElement]] = arr[j];
			bucketElementCounts[digitOfElement]++;
		}
		//按照这个桶的顺序 (一维数组的下标依次取出数据 放入原来数组)
		 index = 0;
		//遍历每一个桶 并将桶中数据 放入到原数组 
		for(int k = 0;k<bucketElementCounts.length;k++) {
			//如果桶中有数据 我们才放入到原数组
			if(bucketElementCounts[k] != 0) {
				//循环该桶即第k 个桶 (即第k 个一维数组 ,放入)
				for (int i = 0; i < bucketElementCounts[k]; i++) {
					//取出元素放到arr
					arr[index++] = bucket[k][i];
				
				}
			}
			bucketElementCounts[k] =0 ;
		}
		System.out.println("第二轮,对十位的排序处理 arr = "+Arrays.toString(arr));
		//第三轮
		for (int j = 0; j < arr.length; j++) {
			// 取出每个元素的百位的值
			int  digitOfElement = arr[j] / 100 %10;
			//放入到对应的桶中 
			bucket[digitOfElement][bucketElementCounts[digitOfElement]] = arr[j];
			bucketElementCounts[digitOfElement]++;
		}
		//按照这个桶的顺序 (一维数组的下标依次取出数据 放入原来数组)
		 index = 0;
		//遍历每一个桶 并将桶中数据 放入到原数组 
		for(int k = 0;k<bucketElementCounts.length;k++) {
			//如果桶中有数据 我们才放入到原数组
			if(bucketElementCounts[k] != 0) {
				//循环该桶即第k 个桶 (即第k 个一维数组 ,放入)
				for (int i = 0; i < bucketElementCounts[k]; i++) {
					//取出元素放到arr
					arr[index++] = bucket[k][i];
				
				}
			}
		}
		System.out.println("第三轮,对十位的排序处理 arr = "+Arrays.toString(arr));
		
	}

}//@@@@@
