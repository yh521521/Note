package com.soul.graph;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;

/**
 * 图
 * @author dell
 *
 */
public class GraphDemo {
	
	private	ArrayList<String> vertexList;// 存储顶点集合
	private int[][] edges ; /// 存储 图 对应的邻结矩阵
	private int numOfEdges;// 表示边的数目 
	
	
	// 定义给数组Boolean[] 记录某个系欸但是否被访问 
	private boolean[] isVisited ;
	
	public static void main(String[] args) {
		//测试图是否创建成功
		int n = 8;//节点的个数 
		//String[] vertexs = {"A","B","C","D","E"};
		String[] vertexs = {"1","2","3","4","5","6","7","8"};
		//创建图对象 
		GraphDemo graph = new GraphDemo(n);
		//循环添加点 
		for (String vertex : vertexs) {
			graph.insertVertex(vertex);
		}
		// 添加边 
		// A-B, A-C , B-C,B-D,B-E  
		// 0 代表第一个节点下标 A  1 代表第二个节点的下标 1 代表连通
//		graph.insertEdge(0, 1, 1);//A-B
//		graph.insertEdge(0, 2, 1);//A-C
//		graph.insertEdge(1, 2, 1);//B-C
//		graph.insertEdge(1, 3, 1);//B-D
//		graph.insertEdge(1, 4, 1);//B-E
		
		//更新边的关系
		graph.insertEdge(0, 1, 1);
		graph.insertEdge(0, 2, 1);
		graph.insertEdge(1, 3, 1);
		graph.insertEdge(1, 4, 1);
		graph.insertEdge(3, 7, 1);
		graph.insertEdge(4, 7, 1);
		graph.insertEdge(2, 5, 1);
		graph.insertEdge(2, 6, 1);
		graph.insertEdge(5, 6, 1);
		
		
		
		// 显示一把邻节矩阵
		graph.showGraph();
		
		//测试 我们的dfs 遍历是否ok
		System.out.println("深度遍历");
		graph.dfs(); // A->B->C->D->E
		
		System.out.println();
		// 广度优先
		System.out.println("广度优先");
		graph.bfs(); // A->B->C->D->E
		
		// 广度优先 和深度优先的区别
//		深度遍历
//		1->2->4->8->5->3->6->7->
//		广度优先
//		1=>2=>3=>4=>5=>6=>7=>8=>
	}
	
	// 构造器 
	public GraphDemo(int n) {
		//初始化矩阵和vertexList
		edges = new int[n][n];
		vertexList = new ArrayList<String>(n);
		numOfEdges = 0; // 默认为0 
		//isVisited = new boolean[5];
	}
	
	
	//得到第一个邻接节点的下标 w
	/**
	 *
	 * @param index
	 * @return 如果存在 就返回对应的下标  否则返回-1 
	 */
	public int getFirstNeighbor(int index ) {
		for (int i = 0; i < vertexList.size(); i++) {
			if(edges[index][i] > 0) {
				return i;
			}
		}
		return -1;
		
	}
	// 根绝前一个邻接节点的下标  来获取下一个邻接节点
	public int getNextNeighbor(int v1,int v2) {
		for (int i = v2 + 1; i < vertexList.size(); i++) {
			if(edges[v1][i]> 0) {
				return i;
			}
		}
		return -1;
	}
	
	//深度优先遍历算法  
	//i 第一次就是0 
	public void dfs(boolean[] isVisited ,int i) {
		
		//首先我们访问该节点 输出
		System.out.print(getValueByIndex(i)+"->");
		//将节点设置为已经访问
		isVisited[i] = true;
		//查找节点i 的第一个邻接节点w 
		int w = getFirstNeighbor(i);
		while(w != -1) {// 说明有邻接点
			if(!isVisited[w]) {
				dfs(isVisited, w);
			}
			//如果w 节点已经被访问过 
			w = getNextNeighbor(i, w);
		}
	}
	
	//对 dfs 进行重载  遍历我们所有的节点   并进行dfs
	public void dfs() {
		isVisited = new boolean[vertexList.size()];
		//遍历所有的节点  进行dfs 回溯 
		for (int i = 0; i < getNumOfVertex(); i++) {
			if(!isVisited[i]) {
				dfs(isVisited,i);
			}
		}
	}
	//对一个节点进行广度优先遍历的方法
	private void bfs(boolean[] isVisited ,int i) {
		int u;// 表示队列的头节点对应下标
		int w;// 邻接节点的下标w
		//需要一个队列 节点访问 的顺序
		LinkedList queue = new LinkedList();
		//访问节点 输出节点信息
		System.out.print(getValueByIndex(i)+"=>");
		//标记为已访问
		isVisited[i] = true;
		//将节点加入队列 从尾部加入  从头部取出
		queue.addLast(i);
		while(! queue.isEmpty()) {
			//不为空 取出队列的投下表
			 u = (Integer) queue.removeFirst();
			 //得到第一个邻节点的下标w 
			 w = getFirstNeighbor(u);
			 while(w != -1) {//找到
				 //是否访问过
				 if(!isVisited[w]) {
					 System.out.print(getValueByIndex(w)+"=>");
					 //标记已经访问
					 isVisited[w] = true;
					 //入队
					 queue.addLast(w);
				 }
				 // 以u 为前驱点 找w后面下一个邻接点
				 w = getNextNeighbor(u, w);// 体现出广度优先
			 }
		}
	}
	// 遍历所有的节点 都进行广度优先搜索
	public void bfs() {
		isVisited = new boolean[vertexList.size()];
		for (int i = 0; i < getNumOfVertex(); i++) {
			if(!isVisited[i]) {
				bfs(isVisited, i);
			}
		}
	}
	
	// 图中 常用的方法
	// 返回节点的个数
	public int getNumOfVertex() {
		return vertexList.size();
	}
	// 显示图 对应 的矩阵
	public void showGraph() {
		for (int[] link : edges) {
			System.out.println(Arrays.toString(link));
		}
	}
	// 得到边的数目
	public int getNumOfEdges() {
		return numOfEdges;
	}
	
	// 返回节点i (下标 ) 对应的数据  0 => A  1 => B 2 => C
	public String getValueByIndex(int i) {
		return vertexList.get(i);
	}
	// 返回v1  和 v2 的权值 
	public int getWeight(int v1 ,int v2) {
		return edges[v1][v2];
		
	}
	
	
	
	// 插入结点
	public void insertVertex(String vertex) {
		vertexList.add(vertex);
	}
	
	// 添加边 
	/**
	 * 
	 * @param v1 表示点的下标 即 是  第几个顶点  "A" - "B"  "A" 0 - "B"  1 
	 * @param v2 表示第二个顶点对应的下标 
	 * @param weight 
	 */
	public void insertEdge(int v1,int v2,int weight) {
		edges[v1][v2] = weight;
		//因为是无向 图 
		edges[v2][v1] = weight;
		numOfEdges ++;
	}

}//@@@@@@@@
