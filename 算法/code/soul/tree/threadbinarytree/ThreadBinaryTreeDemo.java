package com.soul.tree.threadbinarytree;



/**
 * 线索化二叉树   [ 8 ,3 ,10 ,1  ,14 ,6 ]
 * @author dell
 *
 */
public class ThreadBinaryTreeDemo {

	public static void main(String[] args) {
		// 测试中序线索二叉树
		HeroNode root = new HeroNode( 1, "tom");
		HeroNode node2 = new HeroNode(3 , "jack");
		HeroNode node3 = new HeroNode( 6, "smith");
		HeroNode node4 = new HeroNode(8 , "mary");
		HeroNode node5 = new HeroNode(10 , "king");
		HeroNode node6 = new HeroNode( 14, "dim");
		
		// 二叉树 后面 可以 递归创建 目前使用手动创建  
		root.setLeft(node2);
		root.setRight(node3);
		node2.setLeft(node4);
		node2.setRight(node5);
		
		
		node3.setLeft(node6);
		
		//测试中序线索化 
		ThreadBinaryTree tree = new ThreadBinaryTree();
		tree.setRoot(root);
		tree.threadNodes();
		
		// 测试 以 10 号节点 为 测试节点 
		HeroNode leftNode = node5.getLeft();
		HeroNode rightNode = node5.getRight();
		System.out.println("10号节点的前驱节点是输出  "+leftNode); // 3 
		System.out.println("10号节点的后继节点是输出  "+rightNode); //1 
		
		// 当线索化 二叉树后 能使用原来的方法遍历吗
		System.out.println("线索化的方式遍历线索化二叉树");
		tree.threadList();
	}

}//@@@@@@@@

//定义ThreadBinaryTree 实现了线索化功能的二叉树
class ThreadBinaryTree{
	private HeroNode root;
	//为了实现线索化 需要创建要给 指向当前节点的指针
	// 在递归进行线索化 pre 总是保留前一个节点 
	private HeroNode pre = null;
	public void setRoot(HeroNode root) {
		this.root = root;
	}
	//重载线索化 threadNodes 方法
	public void threadNodes() {
		this.threadNodes(root);
	}
	
	// 遍历线索化二叉树
	public  void threadList() {
		//定义一个变量  存储当前遍历的节点 从root 开始
		HeroNode node = root;
		while(node != null) {
			//循环找到 leftType == 1的节点 第一个找到就是8节点 
			//后面随着遍历而变化 ,因为 当leftType == 1 时 说明该节点 是按照线索化 处理后的有效节点
			while(node.getLeftType() == 0) {
				node = node.getLeft();
			}
			//打印当前这个节点
			System.out.println(node);
			//如果当前节点的右指针 指向的是后继节点 就一直输出
			while(node.getRightType() == 1) {
				//获取当前节点 的后继节点
				node = node.getRight();
				System.out.println(node);
			}
			// 替换这个遍历的节点
			node = node.getRight();
			
		}
	}
	
	
	// 编写对二叉树进行中序线索化的方法
	// node 就是需要线索化的节点
	public void threadNodes(HeroNode node) {
		//如果node == null 不能线索化
		if(node == null) {
			return;
		}
		// 1 先线索化左子树
		threadNodes(node.getLeft());
		// 2 线索化当前节点 
		//处理当前节点的  前驱   节点
		if(node.getLeft() == null) {
			// 让当前节点的左指针 指向前驱节点 
			node.setLeft(pre);
			//修改当前节点的左指针类型 指向前驱节点
			node.setLeftType(1);
		}
		// 处理后继节点
		if( pre != null && pre.getRight() == null) {
			pre.setRight(node);
			pre.setRightType(1);
		}
		
		// 每处里 一个节点后 让当前节点是下一个节点的前驱节点 
		pre = node;
		// 3 再 线索化右子树 
		threadNodes(node.getRight());
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

// 创建heroNode

class HeroNode{
	private int no;
	private String name;
	// 左指针
	private HeroNode left;// 默认为 null
	//右指针
	private HeroNode right;//默认为null
	
	//leftType  == 0 指向左子树  ==1 指向前驱节点
	//rightType  == 0 指向右子树  ==1 指向后继节点
	private int leftType ;
	private int rightType;
	
	public int getLeftType() {
		return leftType;
	}

	public void setLeftType(int leftType) {
		this.leftType = leftType;
	}

	public int getRightType() {
		return rightType;
	}

	public void setRightType(int rightType) {
		this.rightType = rightType;
	}

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
