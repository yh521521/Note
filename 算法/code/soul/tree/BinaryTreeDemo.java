package com.soul.tree;

public class BinaryTreeDemo {

	public static void main(String[] args) {
		//先需要创建 一棵二叉树
		BinaryTree binaryTree = new BinaryTree();
		//创建需要的节点 
		HeroNode root = new HeroNode(1 , "宋江");
		HeroNode node2 = new HeroNode( 2, "吴用");
		HeroNode node3 = new HeroNode( 3, "卢俊义");
		HeroNode node4 = new HeroNode( 4, "林冲");
		HeroNode node5 = new HeroNode( 5, "关胜");
		
		
		//说明 我们先手动创建二叉树 
		root.setLeft(node2);
		root.setRight(node3);
		node3.setRight(node4);
		node3.setLeft(node5);
		binaryTree.setRoot(root); 
		//测试
		//System.out.println("前序遍历"); // 1 2 3 4
		//binaryTree.preOrder();
//		测试
		//System.out.println("中序遍历"); //  2 1  3 4
		//binaryTree.infixOrder();
//		测试
		//System.out.println("后序遍历"); //  2   3 4  1 
		//binaryTree.postOrder();
//		System.out.println("前序遍历方式````````"); // 1 2 3 4
//		HeroNode resNode = binaryTree.preOrderSearch(5);
//		if(resNode != null) {
//			System.out.printf("找到了 ,信息为 no = %d name = %s",resNode.getNo(),resNode.getName());
//		}else {
//			System.out.printf("没有找到no = %d的英雄",5);
//		}
//		
//		System.out.println("中序遍历方式````````"); // 1 2 3 4
//		HeroNode resNode = binaryTree.infixOrderSearch(5);
//		if(resNode != null) {
//			System.out.printf("找到了 ,信息为 no = %d name = %s",resNode.getNo(),resNode.getName());
//		}else {
//			System.out.printf("没有找到no = %d的英雄",5);
//		}
//		System.out.println("后序遍历方式查找````````"); // 1 2 3 4
//		HeroNode resNode = binaryTree.postOrderSearch(5);
//		if(resNode != null) {
//			System.out.printf("找到了 ,信息为 no = %d name = %s",resNode.getNo(),resNode.getName());
//		}else {
//			System.out.printf("没有找到no = %d的英雄",5);
//		}
		
		//测试删除节点 
		System.out.println("删除前 ,前序遍历");
		binaryTree.preOrder();
		binaryTree.delNode(5);
		System.out.println("删除后,前序遍历");
		binaryTree.preOrder();
	}

}//@@@
//定义BinaryTree 二叉树
class BinaryTree{
	private HeroNode root;

	public void setRoot(HeroNode root) {
		this.root = root;
	}
	//删除节点 
	public void delNode(int no) {
		if(root != null) {
			// 如果只有一个root 节点 这里理解判断root 是不是就是要删除的节点
			if(root.getNo() == no) {
				root =null;
			}else {
				//递归删除 
				root.delNode(no);
			}
		}else {
			System.out.println("空数 不能删除");
		}
		
	}
	//前序遍历   实际是从根节点出发 
	public void preOrder() {
		if(this.root != null ) {
			this.root.preOrder();
		}else {
			System.out.println("1二叉树为空无法遍历");
		}
	}
	//中序遍历 
	public void infixOrder() {
		if(this.root != null ) {
			this.root.infixOrder();
		}else {
			System.out.println("2二叉树为空无法遍历");
		}
	}
		
	//后序遍历   
	public void postOrder() {
		if(this.root != null ) {
			this.root.postOrder();
		}else {
			System.out.println("3二叉树为空无法遍历");
		}
	}
	// 前序遍历
	public HeroNode preOrderSearch(int no) {
		if(root != null) {
			return root.preOrderSearch(no);
		}else {
			return null;
		}
	}
	// 中序遍历
	public HeroNode infixOrderSearch(int no) {
		if(root != null) {
			return root.infixOrderSearch(no);
		}else {
			return null;
		}
	}
	// 后序遍历
	public HeroNode postOrderSearch(int no) {
		if(root != null) {
			return this.root.postOrderSearch(no);
		}else {
			return null;
		}
	}
	
}

// 创建HeroNod节点   
// this 当前对象的引用 
class HeroNode{
	private int no;
	private String name;
	// 左指针
	private HeroNode left;// 默认为 null
	//右指针
	private HeroNode right;//默认为null
	public HeroNode(int no, String name) {
		this.no = no;
		this.name = name;
	}
	
	public int getNo() {
		return no;
	}

	public void setNo(int no) {
		this.no = no;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public HeroNode getLeft() {
		return left;
	}

	public void setLeft(HeroNode left) {
		this.left = left;
	}

	public HeroNode getRight() {
		return right;
	}

	public void setRight(HeroNode right) {
		this.right = right;
	}

	@Override
	public String toString() {
		return "HeroNode [no=" + no + ", name=" + name + "]";
	}
	
	//递归删除节点 
	// 1 如果删除的节点 是叶子节点则 删除该节点  
	//2 如果删除节点是 非叶子 节点  则 删除该子树 
	public void delNode(int no ) {
		
		// 如果当前的子节点不为空 并且左子节点 就是要删除的节点 
		// 就将 this.left = null  并且返回
		if(this.left!= null && this.left.no == no) {
			this.left = null;
			return;
		}
		// 如果当前的右子节点不为空 并且右子节点 就是要删除的节点 
		// 就将 this.right = null  并且返回
		if(this.right!= null && this.right.no == no) {
			this.right = null;
			return;
		}
		// 左子树递归删除 
		if(this.left!= null) {
			this.left.delNode(no);;
		}
		// 右子树递归删除 
		if(this.right!= null) {
			this.right.delNode(no);;
		}
	}
	
	//编写前序遍历的方法 
	public void preOrder() {
		System.out.println("前序"+this);//先输出父节点
		//递归向左子树前序遍历
		if(this.left != null) {
			this.left.preOrder();
		}
		//递归向右子树遍历
		if(this.right != null) {
			this.right.preOrder();
		}
	}
	// 中序遍历
	public void infixOrder() {
		//递归向左子树遍历
		if(this.left != null) {
			this.left.infixOrder();
		}
		//输出父节点
		System.out.println("中序"+this);
		//递归向右子树遍历
		if(this.right != null) {
			this.right.infixOrder();
		}
	}
	//后续遍历
	public void postOrder() {
		//递归向左子树遍历
		if(this.left != null) {
			this.left.postOrder();
		}
		
		//递归向右子树遍历
		if(this.right != null) {
			this.right.postOrder();
		}
		//输出父节点
		System.out.println("后序"+this);
	}
	// 前序遍历查找
	/**
	 * 
	 * @param no 查找no 
	 * @return 如果找到就返回该node 如果没有则返回null 
	 */
	public HeroNode preOrderSearch(int no) {
		System.out.println("进入前序遍历");
		// 比较当前节点 是不是
		if(this.no == no) {
			return this;
		}
		// 则判断当前节点的左子节点是否为空 如果不为空  则递归前序查找
		// 如果左递归前序查找  找到节点 则返回
		HeroNode resNode = null;
		if(this.left != null) {
			resNode =this.left.preOrderSearch(no);
		}
		if(resNode != null) {// 说明我们左子树 找到了
			return resNode;
		}
		// 如果左递归前序查找  找到节点 则返回 否则继续判断
		// 当前的节点 右子节点是否为空  如果不为空  则继续向右递归前序查找 
		if(this.right != null) {
			resNode = this.right.preOrderSearch(no);
		}
		return resNode;
	}
	/**
	 * 中序遍历查找
	 * @param no
	 * @return
	 */
	public HeroNode infixOrderSearch(int no) {
		
		// 判断当前节点的左子节点 是否为空 如果不为空  则递归中序查找 
		HeroNode resNode = null;
		if(this.left != null) {
			resNode = this.left.infixOrderSearch(no);
		}
		if(resNode != null) {
			return resNode;
		}
		System.out.println("进入中序查找");
		// 如果找到 则返回 如果没有找到 就和当前节点 比较  如果是  则 返回当前节点
		if(this.no == no) {
			return this;
		}
		// 否则 继续进行右递归的中序查找 
		if(this.right != null) {
			resNode = this.right.infixOrderSearch(no);
		}
		return resNode;
	}
	/**
	 * 后续遍历查找
	 * @param no
	 * @return
	 */
	public  HeroNode postOrderSearch(int no) {
		//判断当前节点的子节点是否为空  如果不为空 则递归查找
		HeroNode resNode = null;
		if(this.left != null) {
			resNode = this.left.postOrderSearch(no);
		}
		if(resNode != null) { // 说明左子树 找到 
			return resNode;
		}
		
		// 如果左子树 没有找到 则向右 子树 递归进行后序 遍历查找
		if(this.right != null) {
			resNode = this.right.postOrderSearch(no);
		}
		if(resNode != null) {
			return resNode;
		}
		System.out.println("进入后序查找");
		// 如果左右子树都没找到   就比较当前节点是不是
		if(this.no == no) {
			return this;
		}
		return resNode;
	}
	
}
