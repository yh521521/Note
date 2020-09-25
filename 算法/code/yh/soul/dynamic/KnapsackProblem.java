package com.yh.soul.dynamic;
/**
 *动态问题 --- 背包问题
 * @author dell
 *
 */
public class KnapsackProblem {

	public static void main(String[] args) {
		
		// 放的物品 不能重复  所有三种商品 最多三个
		int[] w = {1,4,3};// 物品的重量
		int[] val = {1500,3000,2000};//物品的价值 
		
		int m = 4;// 背包的容量
		int n = val.length; //物品的个数
		
		// 为了记录放入商品的情况 我们定一个二维数组
		int[][] path = new int[n+1][m+1];
		//创建二维数组  表示 在前i 个物品中能够装入容量为j 的背包的最大价值 
		int[][] v = new int[n+1][m+1];
		// 初始化第一行和第一列   ,这里程序中  不去处理 因为默认就是 0 
		for (int i = 0; i < v.length; i++) {
			v[i][0] = 0;// 将第一列设置为 0
		}
		for (int i = 0; i < v[0].length; i++) {
			v[0][i] = 0 ;// 将第一行设置为0 
		}
		
		// 根据得到的公式来动态规划处理
		for (int i = 1; i < v.length; i++) {// 不处理第一行  i 从1 开始
			for (int j = 1; j < v[0].length; j++) {// 不处理第一列 j 从 1 开始
				// 公式 w[i-1] >j  新增物品的重量 大于 背包的容量 j (j 0 1 2 3 4 )   就是不能新增物品
				if(w[i-1] >j) {// 因为我们程序i 是从1 开始的  因此 公式中的w[i] 改为 w[i-1]
					v[i][j] = v[i-1][j]; // 用上一个单元格的装入策略
				}else {
					// 新增的物品 <= 当前背包的容量  说明可以继续添加 物品  那么就给它预留空间 
					// 因为我们的i 从1 开始的 因此公式需要调整成 
					//v[i][j] = Math.max(v[i-1][j],val[i-1]+v[i-1][j-w[i-1]]);
					// 为了记录商品存放到背包的情况 不能简单的使用 上面的公式 需要使用if else 体现公式 
					if(v[i-1][j] < val[i-1]+v[i-1][j-w[i-1]]) {
						v[i][j] = val[i-1]+v[i-1][j-w[i-1]];
						//把当前的情况记录到path
						path[i][j] = 1;
					}else {
						v[i][j] = v[i-1][j];
					}
				}
			}
			
		}
		
		
		//输出一下v 看看目前的情况
		for (int i = 0; i < v.length; i++) {
			for (int j = 0; j < v[i].length; j++) {
				System.out.print(v[i][j]+" ");
			}
			System.out.println();
		}
		
		System.out.println("=====================");
		
		//输出最后是放入的哪些商品 
		//遍历 path
//		for (int i = 0; i < path.length; i++) {
//			for (int j = 0; j < path[i].length; j++) {
//				
//				if(path[i][j] == 1) {
//					System.out.printf("第%d个商品放入了背包\n",i);
//				}
//				
//			}
//		}
		
		int i = path.length -1; // 行的最大下标
		int j = path[0].length -1 ; // 列的最大下标
		while( i > 0 && j > 0 ) { // 从path 的最后开始找
			if(path[i][j] == 1) {
				System.out.printf("第%d个商品放入了背包\n",i);
				j -=w[i-1];
			}
			i --;
			
			
		}
		
	}

}
