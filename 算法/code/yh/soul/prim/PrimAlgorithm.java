package com.yh.soul.prim;

import java.util.Arrays;

/**
 * 最小生成树  mst  最小生成树
 * @author dell
 *
 */
public class PrimAlgorithm {

	public static void main(String[] args) {
		
		//测试图是否创建成功
		char[] data = new char[]{'A','B','C','D','E','F','G'};
		int vertex = data.length;
		//邻接矩阵的关系使用二维数组表示   横纵都为 abcdefg   权值很大 意味着 不连通  10000 表示 两个点不连通
		 int [][]weight=new int[][]{
	            {10000,5,7,10000,10000,10000,2},
	            {5,10000,10000,9,10000,10000,3},
	            {7,10000,10000,10000,8,10000,10000},
	            {10000,9,10000,10000,10000,4,10000},
	            {10000,10000,8,10000,10000,5,4},
	            {10000,10000,10000,4,5,10000,6},
	            {2,3,10000,10000,4,6,10000},};
	            
	            // 创建MGraph 对象
	            MGraph graph = new MGraph(vertex);
	            //创建一个MinTree 对象
	            MinTree minTree = new MinTree();
	            minTree.createGraph(graph, vertex, data, weight);
	            //输出
	            minTree.showGraph(graph);
	            // 测试普利姆算法
	           // System.err.println("开始了");
	           minTree.prim(graph, 0);
	}

}//@@@

//创建最小生成树  ---> 村庄修路问题 h
class MinTree{
	
	//创建图的邻接矩阵
	/**
	 * 
	 * @param graph 图对象
	 * @param vertex 图对应的顶点个数
	 * @param data 图的各个顶点的值 
	 * @param weight 图的 邻接矩阵 
	 */
	public void createGraph(MGraph graph,int vertex  ,char[] data, int[][] weight) {
		
		for ( int i = 0; i < vertex; i++) {// 顶点
			graph.data[i] = data[i];
			for ( int j = 0; j < vertex; j++) {
				graph.weight[i][j] = weight[i][j];
			}
		}
	}
	
	// 显示图的方法
	
	public void showGraph(MGraph graph) {
		// 传过来的是一个对象   调用图的weight(二维) 属性    
		// 遍历的话 直接输出一行  二维数组是由多个一维数组构成
		for (int[] link : graph.weight ) {
			System.out.println(Arrays.toString(link));
		}
		
	}
	
	
	//编写prim 算法  得到最小生成树
	/**
	 * 
	 * @param graph 图 
	 * @param v 表示从第几个顶点 开始生成 'A' ->0 'B' --> 1...  取值为 0 到 7 
	 */
	public void prim(MGraph graph,int v) {
		
		// visited[] 标记节点/ 顶点   是否被访问过 
		int[] visited = new int[graph.vertex];
		// visited 默认元素的是0 表示没有访问过  int[] 数组 java 语言  不 赋值  就为0
		// 其它语言的话 需要遍历赋值  为0 操作 
//		for (int i = 0; i < graph.vertex; i++) {
//			visited[i] = 0;
//		}
		
		//把当前这个节点 标记为已访问
		visited[v] = 1;
		// h1 h2 记录两个顶点的下标  
		int h1 = -1;
		int h2 = -1;
		int minWeight = 10000; //将minWeight 初始成一个大的数值 ,后面在遍历过程中,会被替换 
		// 也就是说 比如 7个顶点  会产生 6 个边 
		
		for (int k = 1; k < graph.vertex; k++) { // 因为 有graph.vertex 顶点  普利姆算法结束后 有 graph.vertex -1 条边 
			// 确定每一次生成的子图 和哪个节点的距离最近
			for (int i = 0; i < graph.vertex; i++) {// i节点表示被访问的节点
				for (int j = 0; j < graph.vertex; j++) {//j 节点表示还没访问过的节点
					if(visited[i] ==1 && visited[j] == 0 && graph.weight[i][j] < minWeight) {
						//替换minWeight (寻找已经访问过的节点 和未访问过的节点间的权值最小的边)
						minWeight = graph.weight[i][j];
						h1 = i;
						h2 = j;
					}
				}
			}
			// 找到了第一条边 
			System.out.println("边<"+graph.data[h1]+","+graph.data[h2]+">权值:"+minWeight);
			//将当前这个节点标记未 已经访问 
			visited[h2] = 1;
			// minWeight 重新设置为最大值 10000
			minWeight = 10000;
		}
		
	}
	
} //@@@

class MGraph{
	int vertex ;// 表示图的  节点/顶点  个数
	char[] data;// 存放节点数据 
	int[][] weight ; // 存放边 就是邻接矩阵  就是二维数组
	
	public   MGraph (int vertex) {
		this.vertex = vertex;
		data = new char[vertex];
		weight = new int[vertex][vertex];
	}
}
