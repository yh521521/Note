package com.soul.recursion;

public class MiGong {

	public static void main(String[] args) {
		
		// 先创建一个二维数组 模拟迷宫
		// 地图
		int[][] map = new int[8][7];
		//使用1 表示墙  上下 全部置为1
		for (int i = 0; i < 7; i++) {
			map[0][i]= 1;
			map[7][i] =1 ;
		}
		// 左右全部置为 1 
		for (int i = 0; i < 8; i++) {
			map[i][0]= 1;
			map[i][6] =1 ;
		}
		
		// 设置挡板 1 表示
		map[3][1] = 1;
		map[3][2] = 1;
		
		//输出地图
		System.out.println("地图的情况");
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 7; j++) {
				System.out.print(map[i][j]+ " ");
			}
			System.out.println();
		}
		
		// 使用递归给小球找路
		//setWay(map, 1, 1);
		setWay2(map, 1, 1);
		// 输出新的地图 小球走过 并标识 过的递归
		System.out.println("小球走过 并标识 过的 地图的情况");
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 7; j++) {
				System.out.print(map[i][j]+ " ");
			}
			System.out.println();
		}
	}
	
	// 使用递归回溯 来给小球找路
	/**
	 * 
	 * @param map 表示地图
	 * @param i 从哪个位置开始找
	 * @param j
	 * @return 如果找到通路 ,就返回true ,否则就返回false
	 * 如果 小球能到map[6][5] 位置 ,则说明通路找到
	 * 约定 当map[i][j] = 0 时 表示该店没有走过 当为 1 表示 墙  2 表示通路 可以走 
	 * 3 表示该点 已经走过 但是走不通
	 * 在走迷宫时 需要确定一个策略 (方法) 下->右->上->左
	 */
	public static boolean setWay(int[][] map,int i ,int j) {
		if(map[6][5] == 2) { //通路已经找到
			return true;
		}else {
			if(map[i][j] == 0) {// 如果当前这个点没有走过
				// 按照策略 下->右->上->左
				map[i][j] = 2 ; //假定该点可以走通
				if(setWay(map,i+1,j)) { // 向下走
					return true;
				}else if (setWay(map,i,j+1)) { // 向右走
					return true;
				}else if(setWay(map,i-1,j) ){// 向上走
					return true;
				}else if(setWay(map,i,j-1)) {// 向左走
					return true;
				}else {
					// 说明该点 是走不通 是死路 
					map[i][j]= 3;
					return false;
				}
				
				
			}else {
				// 如果 map[i][j] != 0 可能为1  墙 2  可以走 已经走过了 就不要再走了 3  表示该点 已经走过 但是走不通 死路一条
				return  false ;
			}
		}
	}
	
	/**
	 *  策略2  上- >右- > 下 - > 左
	 * @param map
	 * @param i
	 * @param j
	 * @return
	 */
	
	public static boolean setWay2(int[][] map,int i ,int j) {
		if(map[6][5] == 2) { //通路已经找到
			return true;
		}else {
			if(map[i][j] == 0) {// 如果当前这个点没有走过
				// 按照策略 上- >右- > 下 - > 左
				map[i][j] = 2 ; //假定该点可以走通
				if(setWay2(map,i-1,j)) { // 向上走
					return true;
				}else if (setWay2(map,i,j+1)) { // 向右走
					return true;
				}else if(setWay2(map,i+1,j) ){// 向下走
					return true;
				}else if(setWay2(map,i,j-1)) {// 向左走
					return true;
				}else {
					// 说明该点 是走不通 是死路 
					map[i][j]= 3;
					return false;
				}
				
				
			}else {
				// 如果 map[i][j] != 0 可能为1  墙 2  可以走 已经走过了 就不要再走了 3  表示该点 已经走过 但是走不通 死路一条
				return  false ;
			}
		}
	}

}
