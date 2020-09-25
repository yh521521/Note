package com.soul.linkedlist;

import java.util.Stack;

public class SingleLinkedListDemo {

	public static void main(String[] args) {
		// 测试 
		//先创建 节点 
		HeroNode hero1 = new HeroNode(1,"宋江","及时雨");
		HeroNode hero2 = new HeroNode(2,"卢俊义","玉麒麟");
		HeroNode hero3 = new HeroNode(3,"吴用","智多星");
		HeroNode hero4 = new HeroNode(4,"林冲","豹子头");
		
		//创建链表
		SingleLinkedList singleLinkedList = new SingleLinkedList();
		
	
		//加入
		singleLinkedList.add(hero1);
		singleLinkedList.add(hero4);
		singleLinkedList.add(hero2);
		singleLinkedList.add(hero3);
		//测试单链表的反转 
		System.out.println("原来链表的情况~~~~~~");
		singleLinkedList.list();
		
		// 反转 
//		System.out.println("链表反转后的情况~~~~~~");
//		reverseList(singleLinkedList.getHead());
//		singleLinkedList.list();
		
		System.out.println("测试逆序打印单链表");
		reversePrint(singleLinkedList.getHead());
		
		// 按照编号的顺序来添加
//		singleLinkedList.addByorder(hero1);
//		singleLinkedList.addByorder(hero4);
//		singleLinkedList.addByorder(hero2);
//		singleLinkedList.addByorder(hero3);
//		singleLinkedList.addByorder(hero3);
//		singleLinkedList.list();
//		System.out.println("+++++++++++++++++++++++++++++++++");
//		// 修改节点
//		HeroNode newHeroNode = new HeroNode(2,"小卢","玉麒麟~~~~~~~");
//		singleLinkedList.update(newHeroNode);
//		//显示 
//		singleLinkedList.list();
//		
//		//删除一个节点
//		singleLinkedList.del(1);
//		singleLinkedList.del(4);
////		singleLinkedList.del(2);
////		singleLinkedList.del(3);
//		System.out.println("删除后的链表情况 ~~~~~~~");
//		singleLinkedList.list();
//		
//		// 测试一下 求单链表中有效节点的个数
//		System.out.println("有效节点的个数:"+getLength(singleLinkedList.getHead()));
//		//测试得到倒数第 k 个节点
//		HeroNode res  = findLastIndexNode(singleLinkedList.getHead(), 3);
//		System.out.println("倒数第 k 个节点"+res);
	}
	
	
	public static void reversePrint(HeroNode head) {
		if(head.next == null) {
			return ; //空链表 不能打印
		}
		// 创建要给的一个栈  将各个节点压栈  LIFO 后入先出
		Stack<HeroNode> stack = new Stack<HeroNode>();
		HeroNode cur = head.next;
		//将链表的所有节点压入栈 
		while (cur!= null) {
			stack.push(cur); // 压栈 
			cur = cur.next; // cur 后移  这样就可以压入下一个节点
		}
		// 弹栈 
		while (stack.size()>0) {
			System.out.println("弹栈"+stack.pop());
		}
		
	}
	
	
	
	// 将单链表 反转 
	public static void reverseList(HeroNode head) {
		//当前链表为空(head.next == null) 
		//或者只有一个节点head.next.next == null  无需反转 直接返回
		if(head.next == null || head.next.next == null) {
			return ;
		}
		
		//定义一个辅助 的指针(变量) 帮助我们遍历原来的链表
		HeroNode cur = head.next;
		HeroNode next = null ;// 指向当前的节点的下一个节点
		HeroNode reverseHead = new HeroNode(0, "", "");
		// 遍历原来的 的链表 
		// 并从头到位遍历原来的链表 每遍历一个节点  就将其取出
		// 并放在 新的链表 reverseHead 的最前端 
		
		while (cur != null) {
			next = cur.next;// 先暂时保存当前节点的下一个节点 因为后面需要使用
			//将 cur 的下一个节点 指向新的链表的最前端
			cur.next = reverseHead.next;
			reverseHead.next = cur; // 将 cur连接到新的链表上
			// 让 cur 后移 
			cur = next;
		}
		//将head.next 指向reverseHead.next 实现单链表的反转
		head.next = reverseHead.next;
	}
	
	
	
	
	
	
	
	
	// 查找单链表中的倒数第k 个节点 
	// 1   编写一个方法 接收head 节点 同时接收一个index 
	// 2 index 表示是倒数第index 个节点 
	// 3 先把链表 从头到尾遍历一下  得到链表的总的长度 getLength 
	// 4 得到size 后   ,从链表 的第一个开始遍历 (size -index) 个
	// 找到返回该节点   否则  返回null
	public static HeroNode findLastIndexNode(HeroNode head,int index) {
		//判断如果链表为空 返回null
		if(head.next == null) {
			return null;
		}
		// 第一次遍历 得到链表的长度 节点个数
		int size = getLength(head);
		//第二次遍历 size -index 位置 就是我们要找的  倒数第k 个节点
		//index 校验 
		if(index <= 0 || index >size) {
			return null;
		}
		// 定义辅助变量 for 循环定位到倒数的index 
		HeroNode cur = head.next;
		for(int i = 0;i<size -index;i++) {
			 cur = cur.next;
		}
		return cur;
		
	}
	
	
	// 获取到单链表的节点个数(如果是带头节节点的链表  需求 :  不需要统计头节点)
	// 
	public static int getLength(HeroNode head) {
		if(head.next == null) {
			return 0;
		}
		int length = 0;
		// 定义一个辅助的变量 // 这里我们没有统计头节点
		HeroNode cur = head.next;
		while(cur != null) {
			length ++;
			cur = cur.next; // 遍历
		}
		return length;
	}

}
// 定义SingleLinkedList 管理我们的英雄
class SingleLinkedList{
	// 先初始化一个头节点 头节点 不要动   不存在具体的数据
	private HeroNode head  = new HeroNode(0, "", "");
	
	// 返回头节点 
	public HeroNode getHead() {
		return head;
	}

	// 添加节点到单向链表 
	// 当不考虑编号顺序时候  
	// 1 找到当前链表的最后节点 
	//2 将最后这个节点的next 指向新的节点 
	public void add(HeroNode heroNode) {
		// 因为head 节点不能动 因此我们需要一个辅助遍历 temp 
		HeroNode temp  = head;
		//遍历 链表 找到最后
		while (true) {
			// 找到链表最后
			if(temp.next == null) {
				break;
			}
			// 如果没有找到最后  将 temp 后移 
			temp = temp.next;
		}
		// 当退出while 循环时  temp 就指向了 链表的最后
		// 将最后的这个节点next  指向新的节点
		temp.next = heroNode;
	}
	// 第二种添加英雄时  根据排名将英雄插入到指定位置
	
	public void addByorder(HeroNode heroNode) {
		//因为头节点不能动 因为我们仍然通过一个辅助指针 来帮助添加的位置
		//因为单链表 因为我们找到temp 是位于 添加位置的第一个节点
		
		HeroNode temp = head;
		boolean flag = false; // 添加的编号是否存在 默认为false
		while(true) {
			if(temp.next == null) { // temp 已经在链表的最后
				break;				
			}
			if(temp.next.no > heroNode.no) { // 位置找到 就在temp 的后面插入
				break;				
			}else if(temp.next.no == heroNode.no) { // 说明希望添加的heronode  的编号已经存在了
				
				flag = true; // 编号存在
				break;
			}
			temp = temp.next;//后移  遍历当前链表
		}
		// 判断flag 的值 
		if(flag) { // 编号已存在 不能添加
			System.out.printf("准备插入的英雄编号%d已经存在 ,不能加入\n",heroNode.no);
		}else {
			//插入到链表中去 temp 的后面
			heroNode.next = temp.next;
			temp.next = heroNode;	
		}
	}
	// 修改节点的信息  根据no 编号 编号no 是不能改的
	public void update(HeroNode newHeroNode) {
		//判断是否为空
		if(head.next == null) {
			System.out.println("链表为空~");
			return;
		}
		// 找到需要修改的节点  根据no编号
		// 定义 一个辅助变量
		HeroNode temp = head.next;
		boolean flag = false; // 表示是否找到该节点
		while(true) {
			if(temp == null) { // 链表结束了 遍历完了
				break;
			}
			if(temp.no == newHeroNode.no) {
				// 找到
				flag = true;
				break;
			}
			temp = temp.next;
		}
		// 根据flag  判断是否找到要修改的节点
		if(flag) {
			temp.name = newHeroNode.name;
			temp.nickname = newHeroNode.nickname;
		}else {
			System.out.printf("没有找到编号%d 的节点 不能修改\n",newHeroNode.no);
		}
	}
	
	// 删除节点 
	// 1 head 不动  因此我们需要一个temp 辅助节点找到待测节点的前一个节点
	//2 在比较时  是temp.next.no 和需要删除的节点的no 比较
	public void del(int no) {
		HeroNode temp = head;
		boolean flag =false; //标志是否找到待删除节点
		while (true) {
			if(temp.next.no == no) {
				//找到的待删除节点的前一个节点temp
				flag = true;
				break;
			}
			temp = temp.next;//temp 后移 遍历 
		}
		//判断flag 
		if(flag) { //找到
			temp.next = temp.next.next;
		}else {
			System.out.printf("要删除的%d节点不存在",no);
		}
	}
	// 显示链表  遍历
	public void  list() {
		// 判断链表是否为空
		if(head.next == null) {
			System.out.println("链表为空");
			return;
		}
		// 因为头节点  不能动 因此我们需要一个辅助变量 来遍历
		HeroNode temp = head.next;
		while (true) {
			// 判断是否到链表最后
			if(temp == null ) {
				break;
			}
			// 输出节点的信息
			System.out.println("打印temp :"+temp);
			// 后移  将temp 后移 
			temp = temp.next;
		}
	}
}
// 定义一个hero节点  每个heronode 对象就是一个节点 
class HeroNode{
	public int no;
	public String name;
	public String nickname;
	public HeroNode next;
	public HeroNode(int no, String name, String nickname) {
		
		this.no = no;
		this.name = name;
		this.nickname = nickname;
	}
	@Override
	public String toString() {
		return "HeroNode [no=" + no + ", name=" + name + ", nickname=" + nickname + "]";
	}
	
	
}
