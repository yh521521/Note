package com.soul.search;
/**
 * 斐波那契额查找算法 
 * （1）如果与给定关键字相同，则查找成功，返回在表中的位置；

（2）如果给定关键字大，向右查找并减小2个斐波那契区间；

（3）如果给定关键字小，向左查找并减小1个斐波那契区间；

（4）重复过程，直到找到关键字（成功）或区间为空集（失败）。
 */
import java.util.Arrays;

public class FibonacciSearch {
	
	public static int maxSize = 20;
	public static void main(String[] args) {
		
		int[] arr = {1,8,10,89,1000,1234};
		System.out.println("index::"+fibSearch(arr, 1234));
		//int[] fib = fib();
		//index::[1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765]
		//System.out.println("index::"+Arrays.toString(fib));
		
	}
	
	// 要用到斐波那契数列 因此我们需要获取到一个斐波那契数列
	
	// 非递归 和递归两种方式  此处为 非递归产生一个斐波那契额数列
	public static int[] fib() {
		int[] f = new int[maxSize];
		f[0] = 1;
		f[1] = 1;
		for (int i = 2; i < maxSize; i++) {
			f[i] = f[i-1]+f[i-2];
		}
		return f;
	}
	
	// 编写斐波那契查找算法
	/**
	 * 
	 * @param a 数组
	 * @param key 需要查找的关键值
	 * @return 返回对应的下标  没有则返回-1 
	 */
	public static int fibSearch(int[] a,int key) {
		int low = 0;
		int high = a.length-1;
		int k = 0; //表示斐波那契分割数值的下标
		int mid = 0;//存放mid 的值 
		int[] f= fib();// 调用方法 得到一个斐波那契数列
		// 获取斐波那契分割数的下标
		while(high > f[k] -1) {
			k++;
		}
		// 因为f[k] 值 可能大于a 的长度 ,因此我们需要使用Arrays  类 构造一个新的数组 并指向a[]
		// 不足的部分会使用0 填充
		int[] temp = Arrays.copyOf(a, f[k]);
		// 实际上需要使用a 数组最后的数据填充temp 
		for (int i = high+1; i < temp.length; i++) {
			temp[i] = a[high];
		}
		//使用while 循环处理,找到我们的数 key 
		while(low <= high) { // 只要这个条件满足 就可以找
			mid = low+f[k-1]-1;
			if(key < temp[mid]) { // 我们应该向数组的前面查找(左边)
				high = mid -1;
				// 全部元素 = 前面的元素 + 后面元素
				// f[k] = f[k-1]+f[k-2]
				// 因为 前面有k[k-1] 个元素 所以可以继续拆分 f[k-1] = f[k-2]+f[k-3]
				// 即 在f[k-1] 的前面 继续查找k--
				// 下次循环mid = f[k-1-1] -1
				k--;
			}else if(key > temp[mid]){//我们应该 继续向数组的后面查找 (右边)
				low = mid +1 ;
				//全部元素 = 前面的元素 + 后面元素  f[k] = f[k-1]+f[k-2]
				// 后面我们有f[k-2] 所以我们继续拆分f[k-1] = f[k-3]+f[k-4]
				// 即 在 f[ k-2] 的前面进行查找k -=2
				// 即 下次循环mid = f[k-1-2] -1;
				k -= 2;
				//key -= 2;
			}else{ // 找到
				//需要确定 返回的是哪个下标
				if(mid <= high) {
					return mid;
					
				}else {
					return high;
				}
			}
			
		}
		return -1;
	}
	
}//@@@@@@@@
