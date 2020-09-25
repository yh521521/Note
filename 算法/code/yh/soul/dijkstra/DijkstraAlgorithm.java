package com.yh.soul.dijkstra;

import java.util.Arrays;
/**
 * 迪杰斯特拉算法     最短路径问题
 * @author dell
 *
 */
public class DijkstraAlgorithm {

	public static void main(String[] args) {
		char[] vertex = {'A','B','C','D','E','F','G'};
		//邻接矩阵
		int[][] matrix = new int[vertex.length][vertex.length];
		final int N = 65535; // 表示不可以连接
		 matrix[0]=new int[]{N,5,7,N,N,N,2};  
         matrix[1]=new int[]{5,N,N,9,N,N,3};  
         matrix[2]=new int[]{7,N,N,N,8,N,N};  
         matrix[3]=new int[]{N,9,N,N,N,4,N};  
         matrix[4]=new int[]{N,N,8,N,N,5,4};  
         matrix[5]=new int[]{N,N,N,4,5,N,6};  
         matrix[6]=new int[]{2,3,N,N,4,6,N};
         
         //创建graph 对象
         Graph graph = new Graph(vertex, matrix);
         //测试 查看图的邻接矩阵是否ok
         graph.showGraph();
         //测试迪杰斯特拉算法
         graph.dsj(2);
         graph.showDijkstra();
      //   A(2)B(3)C(9)D(10)E(4)F(6)G(0) g 
       //  A(7)B(12)C(0)D(17)E(8)F(13)G(9)c 
	}

}//@@@@@

class Graph{
	private char[] vertex;//顶点数组
	private int[][] matrix;//邻接矩阵
	private VisitedVertex vv;// 已经访问的顶点的集合
	
	//构造器
	public Graph(char[] vertex,int[][] matrix) {
		this.vertex = vertex;
		this.matrix = matrix;
	}
	
	// 显示结果 
	public void  showDijkstra() {
		vv.show();
	}
	
	
	
	//显示图 
	public void showGraph() {
		for (int[] link : matrix) {
			System.out.println(Arrays.toString(link));
		}
	}
	
	//显示迪杰斯特拉算法
	/**20033184 400684  15600030063
	 * 
	 * @param index 表示出发顶点对应的下标 
	 */
	public void dsj(int index) {
		 vv = new VisitedVertex(vertex.length, index);
		 update(index);// 更新index 顶点到周围顶点的距离和前驱顶点
		 
		 //先走你传的顶点  然后再走其它顶点 
		 
		 for (int i = 1; i < vertex.length; i++) {
			 index = vv.updateArr();// 选择并返回新的访问顶点
			 update(index);// 更新index 顶点到周围顶点的距离和前驱顶点
			
		}
	}
	//更新index 下标顶点到周围顶点的距离和周围顶点的前驱顶点 
	private void update(int index) {
		int len = 0;
		// 根据遍历我们的邻接矩阵的matrix[index] 行
		for (int i = 0; i < matrix[index].length; i++) {
			//len 的含义是 出发顶点  到 index 顶点的距离 + 从index 顶点 到顶带你的距离
			len = vv.getDis(index) + matrix[index][i];
			if(!vv.in(i) && len < vv.getDis(i)) {
				//如果j 顶点没有被访问过 并且len 小于出发顶点的到j 顶点的距离  就需要更新
				//更新 j 顶点 的前驱为index 的顶点
				vv.updatePre(i, index);
				// 更新出发顶点到j 顶点的距离
				vv.updateDis(i, len);
			}
		}
		
	}
}

//已访问顶点集合 
class VisitedVertex{
	//记录各个顶点是否访问过 1 表示访问过  0 表示未访问  会动态更新
	public int[] already_arr;
	//每个下标对应的值前一个顶点下标 ,会动态更新  前驱 
	public int[] pre_visited;
	//记录出发顶点到其它所有顶点的距离 比如g为出发顶点 就会记录g 到其它顶点的距离
	// 会动态更新 得到最短距离就会存放到dis 中 
	public int[] dis;
	
	//构造器
	/**
	 * 
	 * @param length 表示顶点的个数
	 * @param index 出发顶点 对应的下标 比如g 顶点 下标 6 
	 */
	public VisitedVertex(int length,int index) {
		this.already_arr = new int[length];
		this.pre_visited = new int[length];
		this.dis = new int[length];
		//初始化 dis 数组
		Arrays.fill(dis, 65535);
		this.already_arr[index] = 1;//设置出发顶点被访问过
		this.dis[index] = 0;  // 设置出发顶点的访问距离 为 0
	}
	/**
	 * 
	 * @param index 判断index 顶点是否被访问过
	 * @return 如果访问过  就返回true 否则返回 false 
	 */
	public boolean in(int index) {
		return already_arr[index] == 1; //1 访问过   0 没访问过
	}
	/**
	 * 功能  更新 出发顶点  到 index 顶点的距离
	 * @param index
	 * @param len
	 */
	public void updateDis(int index ,int len) {
		dis[index] = len;
	}
	/**
	 * 功能 更新pre 这个顶点的前驱顶点为index 节点
	 * @param pre
	 * @param pre
	 */
	public void updatePre(int pre ,int index) {
		pre_visited[pre] = index;
	}
	/**
	 *  功能 返回出发顶点到 index 顶点的距离
	 * @param index
	 */
	public int getDis(int index) {
		return dis[index];
	}
	//继续选择并返回新的访问节点 比如这里的G 完后  就是A点作为新的访问顶点(   不是出发顶点)
	public int updateArr() {
		int min = 65535;
		int index = 0;
		for (int i = 0; i < already_arr.length; i++) {
			//already_arr[i] == 0 i  未被访问  
			if(already_arr[i] == 0 && dis[i] < min) {
				min= dis[i];
				index = i;
			}
		}
		//更新index 顶点 被访问过
		already_arr[index] = 1;
		return index;
	}
	
	//显示最后的结果
	//就是将三个数组的情况输出一下 
	public void show() {
		System.out.println("=============");
		//输出already_arr
		for (int i : already_arr) {
			System.out.print(i+" ");
		}
		System.out.println();
		//输出pre_visited
		for (int i : pre_visited) {
			System.out.print(i+" ");
		}
		System.out.println();
		//输出dis
		for (int i : dis) {
			System.out.print(i+" ");
		}
		System.out.println();
		//处理这个dis 
		char[] vertex = {'A','B','C','D','E','F','G'};
		int count = 0;
		for (int  i : dis) {
			if( i != 65535) {
				System.out.print(vertex[count]+"("+i+")");
			}else {
				System.out.print("N");
			}
			count ++;
		}
		System.out.println();
	}
	
}
