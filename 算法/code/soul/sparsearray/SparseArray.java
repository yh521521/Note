package com.soul.sparsearray;

public class SparseArray {

	public static void main(String[] args) {
		
		//创建原始二维数组 11 * 11
		// 0 表示 没有棋子 1 表示 黑子 2 表示蓝子
		
		int chessArr1[][]= new int[11][11];
		// 赋值 
		chessArr1[1][2] =1;
		chessArr1[2][3]=2;
		chessArr1[4][5]=2;
		///输出原始的二维数组
		for (int[] row : chessArr1) {
			for (int data : row) {
				System.out.printf("%d\t",data);
			}
			System.out.println();
			
		}
		
		// 将二维数组 转为稀疏数组
		// 1 遍历二维数组 得到 非0 数据的个数
		
		int sum = 0;
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				if(chessArr1[i][j]!= 0) {
						sum++;
					
				}
			}
		}
		System.out.println("此时sum = "+sum); 
		// 创建对应的稀疏数组
		int sparseArr[][] = new int[sum+1][3];
		//给稀疏数组复制
		sparseArr[0][0] =11;   // row 
		sparseArr[0][1] =11;  // col 
		sparseArr[0][2] =sum;  // value 
		
		// 遍历二维数组 将非零值 存放到稀疏数组中
		int count = 0; //用于记录第几个非0 数据
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				if(chessArr1[i][j]!= 0) {
					count++;
					sparseArr[count][0] = i;
					sparseArr[count][1] = j;
					sparseArr[count][2] = chessArr1[i][j];
					
				}
			}
		}
		
		// 输出稀疏数组的形式
		System.out.println("---------------------");
//		得到的稀疏数组为
//		11	11	2	
//		1	2	1	
//		2	3	2	
		System.out.println("得到的稀疏数组为");
		for (int i = 0; i < sparseArr.length; i++) {
			System.out.printf("%d\t%d\t%d\t\n",sparseArr[i][0],sparseArr[i][1],sparseArr[i][2]);
		}
		System.out.println();
		
		//将稀疏数组转换为二维数组
		//1 先读取稀疏数组的第一行
		int chessArr2[][] = new int[sparseArr[0][0]][sparseArr[0][1]];
		
		//稀疏数组放的全部为有效数据   不用判断   
		// 因为稀疏数组 第一行 是row col value  所以从i=1 开始遍历
		for(int i =1;i<sparseArr.length;i++) {
			chessArr2[sparseArr[i][0]][sparseArr[i][1]]=sparseArr[i][2];
		}
		
		
		//恢复后的二维数组
		System.out.println("恢复后的二维数组");
		
		for (int[] row : chessArr2) {
			for (int data : row) {
				System.out.printf("%d\t",data);
			}
			System.out.println();
			
		}
		
	}
	
	

}
