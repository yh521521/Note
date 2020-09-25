package com.soul.linkedlist;
/**
 * 约瑟夫问题
 * @author dell
 *
 */
public class Josepfu {
	
	
	public static void main(String[] args) {
		//构建环形链表
		CircleSingleLinkedList cir = new CircleSingleLinkedList();
		cir.addBoy(25); // 加入5 个节点
		cir.showBoy();
		
		//小孩出圈 
		cir.countBoy(1, 2, 5); // 出圈
	}

}
// 创建一个环形的单向 链表
class  CircleSingleLinkedList{
	// 创建一个first节点  当前没有编号 
	private Boy first = new Boy(-1);
	// 添加小孩节点  构建成一个环形的链表 nums 表示节点的个数
	public void addBoy(int nums) {
		//节点数  校验 
		if(nums <1) {
			System.out.println("nums 的值 不正确");
			return;
		}
		Boy curBoy = null; // 辅助指针 用来构建环形链表
		// 使用for 循环创建循环链表
		for (int i = 1; i <= nums; i++) {
			// 根据编号创建小孩节点
			Boy boy = new Boy(i);
			//如果是一个小孩节点
			if(i ==1 ) {
				first =boy;
				// 自己构成一个环状 
				first.setNext(first);// 构成环
				curBoy = first;// 让 curboy 指向第一个小孩 
			}else {
				curBoy.setNext(boy);
				boy.setNext(first);
				curBoy = boy;
			}
		}
		
	}
	// 遍历当前的环形链表
	public void showBoy() {
		// 判断节点是否为空
		if(first == null) {
			System.out.println("链表为空");
			return ;
		}
		//因为first 不能动 , 所以我们仍使用一个辅助指针完成遍历
		Boy curBoy = first;
		while (true) {
			System.out.printf("小孩的编号%d\n",curBoy.getNo());
			if(curBoy.getNext() == first ) { // 已经遍历完毕
				break;
			}
			curBoy = curBoy.getNext();// curBoy 后移 
		}
		
	}
	// 根据用户 的输入 计算出小孩出圈的顺序
	/**
	 * 
	 * @param startNo 从第几个小孩开始数数 
	 * @param countNum 表示数几下
	 * @param nums 表示最初有多少个小孩在圈中 
	 */
	public void countBoy(int startNo,int countNum,int nums){
		//先对数据进行校验   假设 就3个子节点  你从第 4 个开始数数就不行
		if(first == null || startNo <1 || startNo >nums ) {
			System.out.println("参数输入有误,请重新输入");
			return;
		}
		// 创建要给辅助指针 帮助完成小孩出圈 
		Boy helper= first;
		// 需要创建一个辅助指针(变量)helper  事先应该向环形链表的最后这个节点
		while (true) {
			if(helper.getNext() == first) { // 说明helper 指向最后的小孩节点
				break;
			}
			 helper = helper.getNext();
		}
		// 小孩报数前  先让 first 和 helper 移动k-1 次
		for(int j =0;j<startNo-1;j++) {
			first= first.getNext();
			helper = helper.getNext();
		}
		
		//当小孩报数时 让 first 和helper 指针同时 移动m-1 次 然后出圈
		// 这是一个循环操作 直到该圈中  只有一个节点 
		while(true) {
			if(helper == first  ) { // 说明圈中只有一个节点 
				break;
			}
			// 让 first 和helper 指针同时 移动countNum-1 次 然后出圈
			for(int j= 0;j<countNum-1;j++) {
				first= first.getNext();
				helper = helper.getNext();
			}
			// 这时first 指向的节点 就是要出圈的小孩节点 
			System.out.printf("小孩%d出圈\n",first.getNo());
			//这时 将first 指向的小孩出圈 
			first = first.getNext();
			helper.setNext(first);// 
		}
		System.out.printf("最后留在圈中的小孩编号%d\n",helper.getNo());
	}
}


// 先创建一个boy 类         表示一个节点
class Boy{
	private int no ;// 编号
	private Boy next ; // 指向下一个节点  默认null
	
	public Boy(int no) {
		this.no = no;
	}

	public int getNo() {
		return no;
	}

	public void setNo(int no) {
		this.no = no;
	}

	public Boy getNext() {
		return next;
	}

	public void setNext(Boy next) {
		this.next = next;
	}
	
}
