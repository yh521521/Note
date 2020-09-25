package com.soul.stack;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

/**
 * 逆波兰表达式
 * 
 * @author dell
 *
 */
public class PolandNotation {

	public static void main(String[] args) {

		// 定义表达式 (3+4)*5-6 ====> 3 4 + 5 * 6 -
		// 说明 逆波兰 表达式的数字和符号使用空格隔开
		//String suffixExpression = "31 3 + 50 x 6 -";
		String suffixExpression = "4 5 * 8 - 60 + 8 2 / +";
		// 1 先将 3 4 + 5 x 6 放到arraylist 中
		// 2 将list 作为参数 传给一个方法 遍历list 配合栈 完成计算

		List<String> rpnList = getListString(suffixExpression);
		System.out.println("result:  " + rpnList);
		
		int res = calculate(rpnList);
		System.out.println("res:  " + res);
	}

	/**
	 * 将表达式 存到list 中
	 * 
	 * @param suffixExpression
	 * @return List
	 */
	public static List<String> getListString(String suffixExpression) {

		// 分割 suffixExpression 空格
		String[] split = suffixExpression.split(" ");
		// 定义一个list
		List<String> list = new ArrayList<String>();
		// 遍历
		for (String ele : split) {
			list.add(ele);

		}
		return list;

	}

	public static int calculate(List<String> list) {
		// 创建栈 只需要一个栈 即可
		Stack<String> stack = new Stack<String>();
		// 遍历 list
		for (String item : list) {
			// 正则表达式取数
			if (item.matches("\\d+")) { // /d 匹配一个数字
				// 入栈
				stack.push(item);
			} else {
				// pop 出 两个数 并运算 再次入栈
				int after = Integer.parseInt(stack.pop());
				int front = Integer.parseInt(stack.pop());
				int res = 0;
				if (item.equals("+")) {
					res = front + after;
				} else if (item.equals("-")) {
					res = front - after;
				} else if (item.equals("*")) {
					res = front * after;
				} else if (item.equals("/")) {
					res = front / after;
				} else {
					throw new RuntimeException();
				}
				// 把 res 入栈
				stack.push(res + "");
			}

		}

		// 最后留在stack 中的数据就是运算结果
		return Integer.parseInt(stack.pop());

	}

}
