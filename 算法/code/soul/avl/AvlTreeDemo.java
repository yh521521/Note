package com.soul.avl;

/**
 * 平衡二叉树 avl 左子树 右子树旋转的前提 是  子树高度> 1 
 * 
 * @author dell
 *
 */
public class AvlTreeDemo {

	public static void main(String[] args) {
		//int[] arr = {4,3,6,5,7,8};
		//int[] arr = {10,12,8,9,7,6};
		//int[] arr = {10,11,7,6,8,9};
		int[] arr = {10,11,7,6,8,9};
		// 创建一个AVLTree 对象
		AvlTree avlTree = new AvlTree();
		// 添加节点
		for (int i = 0; i < arr.length; i++) {
			avlTree.add(new Node(arr[i]));
		}
		
		// 中序遍历
		System.out.println("中序遍历");
		avlTree.infixOrder();
		
		System.out.println("在没有左平衡处理前");
		System.out.println("树的高度"+avlTree.getRoot().height());
		System.out.println("树的左子树高度"+avlTree.getRoot().leftHeight());
		System.out.println("树的右子树高度"+avlTree.getRoot().rightHeight());
		System.out.println("当前的根节点"+avlTree.getRoot());
		System.out.println("根节点的左子节点"+avlTree.getRoot().right.right);
	}

}// @@@@

// 创建 AVL tree 
class AvlTree {
	private Node root;
	public Node getRoot() {
		return root;
	}
	// 查找要删除的节点
	public Node search(int value) {
		if (root == null) {
			return null;
		} else {
			return root.search(value);
		}
	}

	// 查找父节点
	public Node searchParent(int value) {
		if (root == null) {
			return null;
		} else {
			return root.searchParent(value);
		}
	}

	/**
	 * 返回以node 为根节点的二叉树的最小节点 的 值 删除node 为根节点的二叉排序树的最小节点
	 * 
	 * @param node 传入的节点 (当作二叉排序树的根节点)
	 * @return 返回的是以node 为根节点的二叉树的最小节点 的 值
	 */
	public int delRightTreeMin(Node node) {
		Node target = node;
		// 循环的查找左子节点 就会找到最小值
		while (target.left != null) {
			target = target.left;
		}
		// 这是 target 就指向了最小节点
		// 删除了最小节点
		delNode(target.value);
		return target.value;
	}

	// 删除节点
	public void delNode(int value) {
		if (root == null) {
			return;

		} else {
			// 1 需要先找到要删除的节点 targetNode
			Node targetNode = search(value);
			// 如果没有找到要删除的节点
			if (targetNode == null) {
				return;
			}
			// 如果我们发现当前这颗二叉排序树 只有一个节点
			if (root.left == null && root.right == null) {
				root = null;
				return;
			}
			// 去找到 targetNode 的父节点
			Node parent = searchParent(value);
			// 如果要删除的节点 是叶子节点
			if (targetNode.left == null && targetNode.right == null) {
				// 判断targetNode 是父节点的左子节点 还是右子节点
				if (parent.left != null && parent.left.value == value) { // 左子节点
					parent.left = null;
				} else if (parent.right != null && parent.right.value == value) { // 右子节点
					parent.right = null;
				}
			} else if (targetNode.left != null && targetNode.right != null) { // 删除有两颗子树的节点
				int minVal = delRightTreeMin(targetNode.right);
				targetNode.value = minVal;
			} else {// 删除只有一棵子树的节点
					// 如果要删除的节点有左子节点
				if (targetNode.left != null) {
					if (parent != null) {
						// 如果targetNode 是parent 的左子节点
						if (parent.left.value == value) {
							parent.left = targetNode.left;
						} else {
							// 如果targetNode 是parent 的右子节点
							parent.right = targetNode.left;
						}
					} else {
						root = targetNode.left;
					}
				} else {// 如果要删除的节点有右子节点
					if (parent != null) {
						// 如果targetNode 是parent 的左子节点
						if (parent.left.value == value) {
							parent.left = targetNode.right;
						} else {// 如果targetNode 是parent 的右子节点
							parent.right = targetNode.right;
						}
					} else {
						root = targetNode.right;
					}
				}
			}
		}

	}

	// 添加节点的方法
	public void add(Node node) {
		if (root == null) {
			root = node;// 如果root 为空 则直接让root指向node
		} else {
			root.add(node);
		}

	}

	// 遍历方法
	// 中序方法
	public void infixOrder() {
		if (root != null) {
			root.infixOrder();
		} else {
			System.out.println("二叉排序树为空  不能遍历");
		}
	}
}

//创建node节点 
class Node {

	int value;
	Node left;
	Node right;

	public Node(int value) {
		this.value = value;
	}

	// 返回左子树的高度
	public int leftHeight() {
		if (left == null) {
			return 0;
		}
		return left.height();
	}

	// 返回右子树的高度
	public int rightHeight() {
		if (right == null) {
			return 0;
		}
		return right.height();
	}

	// 返回当前节点的高度 以该节点为根节点的树的高度
	public int height() {
		return Math.max(left == null ? 0 : left.height(), right == null ? 0 : right.height())+ 1;
	}
	
	
	//左旋转方法
	private void leftRotate() {
		
		//创建新的节点 以 当前根节点的值 创建的
		Node newNode = new Node(value);
		//把 新的节点左子树设置成当前节点的左子树 
		newNode.left = left;
		// 把新的节点的右子树设置成当前节点的右子树的左子树
		newNode.right = right.left;
		// 把当前节点的值 替换成右子节点的值 
		value = right.value;
		// 把当前节点的右子树设置成右子树的右子树
		right = right.right;
		//把当前节点的左子树(左子节点) 设置成新的节点
		left = newNode;
	}
	//右旋转方法
	private void rightRotate() {
		Node newNode = new Node(value);
		newNode.right = right;
		newNode.left = left.right;
		value = left.value;
		left = left.left;
		right = newNode;
		
	}
	
	
	
	// 查找要删除的节点
	/**
	 * 
	 * @param value 希望删除的节点的值
	 * @return 如果找到返回该节点 否则返回null
	 */
	public Node search(int value) {
		if (value == this.value) {// 找到就是该节点
			return this;
		} else if (value < this.value) {// 查找的值 小于当前节点 向左递归查询
			// 如果左子节点 为空
			if (this.left == null) {
				return null;
			}
			return this.left.search(value);

		} else {// 如果查找的值 不小于当前节点 向右子树递归查找
			if (this.right == null) {
				return null;
			}
			return this.right.search(value);

		}
	}// ###

	// 查找要删除节点的父节点
	/**
	 * 
	 * @param value 查找的节点的值
	 * @return 返回的是要删除的节点的父节点 如果没有就返回null
	 */
	public Node searchParent(int value) {
		// 如果当前节点就是要删除的节点 的父节点 就返回
		if (this.left != null && this.left.value == value || (this.right != null && this.right.value == value)) {
			return this;
		} else {
			// 如果查找的值 小于当前节点的值 并且当前节点的左子节点不为空
			if (value < this.value && this.left != null) {
				return this.left.searchParent(value);// 向左子树 递归查询
			} else if (value >= this.value && this.right != null) {
				return this.right.searchParent(value);// 向右子树 递归查询
			} else {
				return null; // 没有找到父节点
			}
		}

	}

	@Override
	public String toString() {
		return "Node [value=" + value + "]";
	}

	// 添加节点的方法
	// 递归的形式添加节点 要满足二叉排序的要求
	public void add(Node node) {
		if (node == null) {
			return;
		}
		// 判断传入的节点的值 和当前子树的根节点值 关系
		// this 指当前引用对象Node 也就是root节点
		if (node.value < this.value) { // 向左面添加
			// 如果当前节点 左子节点为null
			if (this.left == null) {
				this.left = node;
			} else {
				// 递归的向左子树添加
				this.left.add(node);
			}
		} else { // 添加的节点指 大于当前的节点值
			if (this.right == null) {
				this.right = node;

			} else {
				// 递归的向右子树添加
				this.right.add(node);
			}
		}
		
		// 当添加完一个节点后 如果  : (右子树的高度- 左子树的高度) > 1 左旋转
		if(rightHeight()-leftHeight() > 1 ) {
			//如果它的右子树的左子树的高度大于它的右子树的右子树的高度
			
			if(right != null && right.leftHeight() > right.rightHeight()) {
				//先对它的右子节点进行右旋转 
				right.rightRotate();
				// 然后在对当前节点进行左旋转
				leftRotate();// 左旋转
			}else {
				// 直接 左旋转
				leftRotate();
			}
			return ;// 必须要
			
		}
		// 当添加完一个节点后 如果 (左子树的高度- 右子树的高度) > 1 右旋转
		if(leftHeight() -  rightHeight() > 1 ) {
			//如果它的左子树的右子树的高度大于它的左子树的高度
			if(left != null && left.rightHeight() > left.leftHeight()) {
				//先对当前节点的左节点(左子树) -> 左旋转
				left.leftRotate();
				//再对当前节点进行右旋转
				rightRotate();
			}else {
				rightRotate();// 右旋转
			}
			
		}
	}

	// 中序遍历二叉树
	public void infixOrder() {
		if (this.left != null) {
			this.left.infixOrder();
		}
		System.out.println(this);
		if (this.right != null) {
			this.right.infixOrder();
		}

	}
}// @@@
