package com.yh.soul.dac;

/**
 * divide - and conquer 分治算法
 * 
 * @author dell
 *
 */
public class Hanoitower {

	public static void main(String[] args) {
		
		hanoiTower(5, 'A', 'B', 'C');
	}

	// 汉诺塔的移动方法
	// 使用分治算法
	/**
	 * 
	 * @param num 盘的数量
	 * @param a   柱子 a
	 * @param b   柱子 b
	 * @param c   柱子c
	 */
	public static void hanoiTower(int num, char a, char b, char c) {

		// 如果只有一个盘
		if (num == 1) {
			System.out.println("第1个盘从   " + a + " -> " + c);

		} else {
			// 如果我们有n >= 2 情况 我们总是可以看作两个盘 1 最下面的盘 2 最上面的盘
			// 1 先把 最上面的所有盘 从 A -> B 移动过程会使用到c
			hanoiTower(num - 1, a, c, b);
			// 2 把 最下面的盘 A -> C
			System.out.println("第 " + num + " 个盘从 " + a + " -> " + c);
			// 3 把B 塔 所有的盘从 B -> C 移动过程使用到 a
			hanoiTower(num - 1, b, a, c);
		}
	}

}// @@@
