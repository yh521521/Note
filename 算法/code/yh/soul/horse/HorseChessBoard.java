package com.yh.soul.horse;

import java.awt.Point;
import java.util.ArrayList;

public class HorseChessBoard {
	
	private static int X;// 棋盘的列数
	private static int Y;// 棋盘的行数
	//创建一个数组 标记棋盘的各个位置是否被访问过
	private static boolean visited[];
	//是使用一个属性 标记是否棋盘的所有位置 都被访问过
	private static boolean finished; // 如果为true 表示成功
	
	
	public static void main(String[] args) {
		// 测试骑士 周游算法是否正确
		X = 8;
		Y = 8;
		int row = 1 ; // 马儿初始位置行   从1 开始编号 
		int column = 1;// 马儿初始位置列    从1 开始编号
		// 创建棋盘 
		int[][] chessboard = new int[X][Y];
		visited = new boolean[X * Y];// 初始值都是false;
		
		// 测试 一下耗时 
		long start = System.currentTimeMillis();
		traversalChessboard(chessboard, row -1 , column -1 , 1);
		long end = System.currentTimeMillis();
		System.out.println("共耗时 "+ (end-start) + "毫秒 ");
		//输出期盼的最后情况
		for (int[] rows : chessboard) {
			for (int step : rows) {
				System.out.print(step +"\t");
			}
			System.out.println();
		}
		
	}
	/**
	 * 功能  完成其实周游棋盘问题的算法
	 * @param chessboard 棋盘
	 * @param row 马儿当前位置的行  从 0 开始
	 * @param column 马儿当前位置的列  从 0 开始
	 * @param step 是第几步    初始位置就是第 1 步 
	 */
	public static void traversalChessboard(int[][] chessboard,int row ,int column,int step ) {
			
		chessboard[row][column] = step;
		// row = 4 x = 8 column = 4 4 *8 +4 = 36
		visited[row * X +column]  = true; // 标记为已经访问
		// 获取当前位置可以走的下一个位置的集合 
		ArrayList<Point> ps = next(new Point(column,row));
		//遍历ps 
		while (!ps.isEmpty()) {
			Point p = ps.remove(0); // 取出一个可以走的位置
			// 判断该点是否已经访问过 
			if(!visited[p.y * X+p.x]) { // 说明还没有访问过
				traversalChessboard(chessboard, p.y, p.x, step + 1);
			}
		}
		// 判断马儿是否完成了任务 使用step 和应该走的步数比较
		// 如果没有达到数量 则表示 没有完成任务 将整个棋盘置0
		// 说明下面 step < x * y 成立条件有两种 
		// 1 棋盘到目前位置 仍然没有走完
		//2 棋盘处于 一个回溯过程
		if(step < X * Y && !finished) {
			chessboard[row][column] = 0;
			visited[row * X + column] = false;
		}else {
			finished = true;
		}
		
	}
	
	
	/**
	 * 功能  根据当前位置(point对象) 计算马儿还能走哪些位置(point) 
	 * 并放入到集合中(ArrayList) 最多有8 个位置 
	 * @param curPoint
	 * @return
	 */
	public static ArrayList<Point> next(Point curPoint) {
		//创建一个ArrayList 
		ArrayList<Point> ps = new ArrayList<Point>();
		//创建一个point 
		Point p1 = new Point();
		// 表示马儿可以走5 这个位置
		if((p1.x = curPoint.x -2) >= 0 && (p1.y = curPoint.y- 1) >= 0) {
			ps.add(new Point(p1));
		}
		//判断 马儿是否可以走6 个位置
		if((p1.x = curPoint.x -1) >= 0 && (p1.y = curPoint.y- 2) >= 0) {
			ps.add(new Point(p1));
		}
		//判断 马儿是否可以走7个位置
		if((p1.x = curPoint.x +1) < X && (p1.y = curPoint.y- 2) >= 0) {
			ps.add(new Point(p1));
		}
		//判断 马儿是否可以走0个位置
		if((p1.x = curPoint.x + 2) < X && (p1.y = curPoint.y- 1) >= 0) {
			ps.add(new Point(p1));
		}
		//判断 马儿是否可以走1 个位置
		if((p1.x = curPoint.x + 2) < X && (p1.y = curPoint.y + 1) < Y) {
			ps.add(new Point(p1));
		}
		//判断 马儿是否可以走2个位置
		if((p1.x = curPoint.x + 1) < X && (p1.y = curPoint.y + 2) < Y) {
			ps.add(new Point(p1));
		}
		//判断 马儿是否可以走3 个位置
		if((p1.x = curPoint.x - 1) >= 0 && (p1.y = curPoint.y + 2) < Y) {
			ps.add(new Point(p1));
		}
		//判断 马儿是否可以走4 个位置
		if((p1.x = curPoint.x - 2) >= 0 && (p1.y = curPoint.y + 1) < Y) {
			ps.add(new Point(p1));
		}
		return ps;
	}

}
