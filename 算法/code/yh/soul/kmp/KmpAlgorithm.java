package com.yh.soul.kmp;

import java.util.Arrays;

/**
 * kmp  算法
 * @author dell
 *
 */
public class KmpAlgorithm {

	public static void main(String[] args) {
		
		String str1 = "BBC ABCDAB ABCDABCDABDE";
		//String str2 = "ABCDABD";
		String str2 = "ABCDABD";
		int[] next = kmpNext("ABCDABD");//
		System.out.println("next: "+Arrays.toString(next));
		
		int index = kmpSearch(str1, str2, next);
		System.out.println("index::::"+index);
	}
	//kmp 搜索算法
	/**
	 * 
	 * @param str1    源字符串
	 * @param str2    字串
	 * @param next  部分匹配表 ,是字串对应的部分匹配表
	 * @return -1 就是没有匹配到  否则返回第一个匹配的位置
	 */
	public static int kmpSearch(String str1,String str2 ,int[] next) {
		
		//遍历 
		for (int i = 0,j = 0; i < str1.length(); i++) {
			//需要考虑str1.charAt(i) != str2.charAt(j) 调整j 的大小
			//kmp算法核心点
			while(j > 0  && str1.charAt(i) != str2.charAt(j) ) {
				j = next[j-1];
			}
			if(str1.charAt(i) == str2.charAt(j)) {
				j++;
			}
			if(j == str2.length()) {// 找到了
				return i- j + 1;
			}
		}
		return -1;
	}
	
	
	// 获取到一个字符串(字串)的部分匹配值 表
	public static  int[] kmpNext(String dest) {
		// 创建一个next 数组保存部分匹配值 
		int[] next = new int[dest.length()]; 
		next[0] = 0;// 如果字符串是长度为1 ,它的部分匹配值就是0
		for (int i = 1,j = 0; i < dest.length(); i++) {
			//当dest.charAt(i) != dest.charAt(j) 需要从next[j-1]获取新的j 
			//直到我们发现有dest.charAt(i) == dest.charAt(j)成立时才退出
			// 这是kmp算法的核心点
			while (j > 0 && dest.charAt(i) != dest.charAt(j)) {
				j = next[j-1];
			}
			
			
			//dest.charAt(i) == dest.charAt(j) 成立是 部分匹配值就需要+1
			if(dest.charAt(i) == dest.charAt(j)) {
				j++;
			}
			next[i] = j;
		}
		return next;
	}
	
	
	

}//@@@

