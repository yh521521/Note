package com.soul.binarysorttree;

public class BinarySortTreeDemo {

	public static void main(String[] args) {
		int[]  arr = {7,3,10,12,5,1,2,9};
		BinarySortTree binarySortTree = new BinarySortTree();
		//循环的添加节点到二叉排序树 
		for (int i = 0; i < arr.length; i++) {
			binarySortTree.add(new Node(arr[i]));
		}
		//中序遍历 
		System.out.println("中序遍历");
		binarySortTree.infixOrder();
		
		// 测试删除叶子节点 
		//binarySortTree.delNode(2);
		//binarySortTree.delNode(5);
		binarySortTree.delNode(10);
		System.out.println("删除节点后");
		binarySortTree.infixOrder();
		
	}

}//@@@@

//创建二叉排序树 
class BinarySortTree{
	private Node root;
	
	// 查找要删除的节点
	public Node search(int value) {
		if(root == null) {
			return null;
		}else {
			return root.search(value);
		}
	}
	// 查找父节点
	public Node searchParent(int value) {
		if(root == null) {
			return null;
		}else {
			return root.searchParent(value);
		}
	}
	/**返回以node 为根节点的二叉树的最小节点 的 值  
	 * 删除node  为根节点的二叉排序树的最小节点 
	 * @param node 传入的节点 (当作二叉排序树的根节点)
	 * @return 返回的是以node 为根节点的二叉树的最小节点 的 值 
	 */
	public int delRightTreeMin(Node node) {
		Node target = node;
		//循环的查找左子节点  就会找到最小值
		while(target.left != null) {
			target = target.left;
		}
		//这是 target 就指向了最小节点
		//删除了最小节点 
		delNode(target.value);
		return target.value;
	}
	
	
	
	//删除节点
	public void delNode(int value) {
		if(root == null) {
			return;
			
		}else {
			//1 需要先找到要删除的节点 targetNode 
			Node targetNode = search(value);
			//如果没有找到要删除的节点 
			if(targetNode == null) {
				return ;
			}
			// 如果我们发现当前这颗二叉排序树 只有一个节点
			if(root.left == null && root.right == null) {
				root = null;
				return ;
			}
			//去找到 targetNode 的父节点 
			Node parent = searchParent(value);
			//如果要删除的节点 是叶子节点
			if(targetNode.left == null && targetNode.right == null) {
				// 判断targetNode 是父节点的左子节点 还是右子节点
				if(parent.left != null && parent.left.value == value) { // 左子节点
					parent.left = null;
				}else if(parent.right != null && parent.right.value == value) { //右子节点
					parent.right = null;
				}
			}else if(targetNode.left != null && targetNode.right != null) { // 删除有两颗子树的节点
				int minVal = delRightTreeMin(targetNode.right);
				targetNode.value =minVal;
			}else {// 删除只有一棵子树的节点 
				// 如果要删除的节点有左子节点
				if(targetNode.left != null) {
					if(parent != null) {
						// 如果targetNode 是parent 的左子节点
						if(parent.left.value == value) {
							parent.left = targetNode.left;
						}else {
							//如果targetNode 是parent 的右子节点
							parent.right = targetNode.left;
						}
				   }else {
					   root = targetNode.left;
				   }
				}else {// 如果要删除的节点有右子节点
					if(parent != null) {
						// 如果targetNode 是parent 的左子节点
						if(parent.left.value == value) {
							parent.left = targetNode.right;
						}else {//如果targetNode 是parent 的右子节点
							parent.right = targetNode.right;
						}
					}else {
						 root = targetNode.right;
					}
				}
			}
		}
		
	}
	
	
	
	//添加节点的方法
	public void add(Node node) {
		if(root == null) {
			root = node;//如果root 为空 则直接让root指向node 
		}else {
			root.add(node);
		}
		
	}
	
	//遍历方法 
	//中序方法  
	public void infixOrder() {
		if(root != null) {
			root.infixOrder();
		}else {
			System.out.println("二叉排序树为空  不能遍历");
		}
	}
}//



//创建node节点 
class Node{
	
	int value ;
	Node left ;
	Node right;
	
	public Node(int value) {
		this.value = value;
	}
	
	
	//查找要删除的节点
	/**
	 * 
	 * @param value 希望删除的节点的值 
	 * @return 如果找到返回该节点  否则返回null 
	 */
	public Node search(int value) { 
		if(value ==this.value) {// 找到就是该节点
			return this;
		}else if(value < this.value) {//查找的值 小于当前节点 向左递归查询
			// 如果左子节点 为空
			if(this.left == null) {
				return null;
			}
			return this.left.search(value);
			 
		}else {// 如果查找的值 不小于当前节点 向右子树递归查找
			if(this.right == null) {
				return null;
			}
			return this.right.search(value);
			
		}
	}// ###
	
	//查找要删除节点的父节点 
	/**
	 * 
	 * @param value 查找的节点的值 
	 * @return 返回的是要删除的节点的父节点 如果没有就返回null 
	 */
	public Node searchParent(int value) {
		// 如果当前节点就是要删除的节点 的父节点 就返回
		if(this.left != null && this.left.value == value ||
				(this.right != null && this.right.value== value )) {
			return this;
		}else {
			// 如果查找的值 小于当前节点的值  并且当前节点的左子节点不为空
			if(value <this.value && this.left != null) {
				return this.left.searchParent(value);// 向左子树 递归查询
			}else if(value >= this.value && this.right != null) {
				return this.right.searchParent(value);// 向右子树 递归查询
			}else {
				return null; // 没有找到父节点
			}
		}
		
	}
			
	
	@Override
	public String toString() {
		return "Node [value=" + value + "]";
	}

	// 添加节点的方法
	// 递归的形式添加节点  要满足二叉排序的要求
	public void add(Node node) {
		if(node == null) {
			return;
		}
		// 判断传入的节点的值  和当前子树的根节点值  关系
		// this 指当前引用对象Node 也就是root节点
		if(node.value <this.value) { // 向左面添加
			// 如果当前节点 左子节点为null 
			if(this.left == null) {
				this.left = node;
			}else {
				// 递归的向左子树添加
				this.left.add(node);
			}
		}else { // 添加的节点指 大于当前的节点值 
			if(this.right == null) {
				this.right = node;
				
			}else {
				//递归的向右子树添加
				this.right.add(node);
			}
		}
	}
	
	//中序遍历二叉树
	public void infixOrder() {
		if(this.left != null) {
			this.left.infixOrder();
		}
		System.out.println(this);
		if(this.right != null) {
			this.right.infixOrder();
		}
		
	}
}//@@@



