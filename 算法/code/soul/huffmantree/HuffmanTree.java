package com.soul.huffmantree;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class HuffmanTree {

	public static void main(String[] args) {
		int[] arr = {13,7,8,3,29,6,1};
		Node root = createHuffmanTree(arr);
		preOrder(root);
	}
	
	// 编写一个前序遍历方法
	public static void preOrder(Node root) {
		if(root != null) {
			root.preOrder();
			
		}else {
			System.out.println("是空树 ,不能遍历");
		}
		
	}
	
	
	/**
	 * 
	 * @param arr 需要创建成 赫夫曼树的数组 
	 * @return 创建好后的 赫夫曼树的root节点 
	 */
	// 创建赫夫曼树 的方法
	public static Node createHuffmanTree(int[] arr) {
		// 第一步 为了操作方便 
		//1 遍历arr数组  
		//2 将arr 的每个元素构成一个node
		//3 将node 放入到arraylist 中 
		List<Node> nodes = new ArrayList<Node>();
		for (int  value : arr) {
			nodes.add(new Node(value));
		}
		// 我们处理的过程是一个循环的过程
		while(nodes.size() >1) {
		
			
			//排序从小到大 
			Collections.sort(nodes);
			System.out.println("nodes: "+nodes);
			//取出根节点权值最小的两棵二叉树
			//1 取出权值最小的节点(一个节点可以堪称最简单的二叉树)
			Node leftNode = nodes.get(0);
			//2) 取出权值第二小的节点
			Node rightNode = nodes.get(1);
			//3 构建一颗新的二叉树
			Node parent = new Node(leftNode.value+rightNode.value);
			parent.left = leftNode;
			parent.right = rightNode;
			//3) 从ArrayList 删除处理过的二叉树
			nodes.remove(leftNode);
			nodes.remove(rightNode);
			// 5)将parent 加入到Nodes  
			nodes.add(parent);
		
		}	
		// 返回赫夫曼树的root 节点 
		return nodes.get(0);
	}

}//@@@@@@@@@@
//创建节点类 
// 为了 让node 对象持续排序Collection 集合排序
// 让node 实现commparable 接口
class Node implements Comparable<Node>{
	int value ;//节点权值
	Node left ;//指向左子节点
	Node right ; // 指向右子节点
	
	// 前序遍历
	public void preOrder() {
		System.out.println(this);
		if(this.left != null) {
			this.left.preOrder();
		}
		if(this.right != null) {
			this.right.preOrder();
		}
	}
	
	
	public Node(int value) {
		this.value =value;
	}

	@Override
	public String toString() {
		return "Node [value=" + value + "]";
	}

	@Override
	public int compareTo(Node o) {
		// 从小到大排序this.value -o.value 
		// 从大到小排序-(this.value -o.value) 
		
		return this.value -o.value;
	}
	
}
