package com.soul.linkedlist;

import java.util.Stack;

/**
 * 演示栈stack的基本使用
 * @author dell
 *
 */
public class TestStack {

	public static void main(String[] args) {
		Stack<String> stack = new Stack();
		// 入栈  LIFO 后入先出 的规则
		stack.add("jack");
		stack.add("tom");
		stack.add("smith");
		// 出栈 
		while(stack.size()>0) {
			System.out.println("弹栈 "+stack.pop());
		}
	}

}
