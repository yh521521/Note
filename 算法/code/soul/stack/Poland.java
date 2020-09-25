package com.soul.stack;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

/**
 * 
 * 中缀表达式转为 后缀表达式
 * @author dell
 *
 */
public class Poland {


	public static void main(String[] args) {
		
		//中缀表达式转为 后缀表达式
		// 1 + ((2+3)*4) -5 ==> 1 2 3 + 4 * + 5 - 
		//2 直接对 str 进行操作 不方便 因此 先将 1 + ((2+3)*4) -5  存到 list 中 
		// 即 [1,+,(,(,2,+,3,),*,4,),-,5]
		//3 将得到的中缀表达式 对应的list => 后缀表达式  对应的list
		// 即  infixExpressionList:[1, +, (, (, 2, +, 3, ), *, 4, ), -, 5]
		String expression = "1+((2+3)*4)-5";
		List<String> infixExpressionList = toInfixExpressionList(expression);
		System.out.println("中缀表达式:"+infixExpressionList);
		List<String> parseSuffixExpressionList = parseSuffixExpressionList(infixExpressionList);
		//[1, 2, 3, +, 4, *, +, 5, -]
		System.out.println("后缀表达式:"+parseSuffixExpressionList);
		System.out.println("结果为"+calculate(parseSuffixExpressionList));
		
		
		
		// 定义逆波兰表达式 (3+4)*5-6 ====> 3 4 + 5 * 6 -
		// 说明 逆波兰 表达式的数字和符号使用空格隔开
		//String suffixExpression = "31 3 + 50 x 6 -";
//		String suffixExpression = "4 5 * 8 - 60 + 8 2 / +";
//		// 1 先将 3 4 + 5 x 6 放到arraylist 中
//		// 2 将list 作为参数 传给一个方法 遍历list 配合栈 完成计算
//
//		List<String> rpnList = getListString(suffixExpression);
//		System.out.println("result:  " + rpnList);
//		
//		int res = calculate(rpnList);
//		System.out.println("res:  " + res);
	}
	/**
	 * 将得到的存在list中的中缀表达式  转换为 计算机可以识别的后缀表达式 
	 * @param ls
	 * @return
	 */
	public static List<String> parseSuffixExpressionList(List<String> ls){
		//定义 数栈 符号栈 
		
		Stack<String> oper_stack = new Stack<String>();
		
		// 说明  因为s2 这个栈 在整个 转换过程中 没有pop 操作 而且后面我们需要  逆序输出 
		// 因此比较麻烦  不用 这个栈 Stack<String> num_stack = new Stack<String>(); 
		// 直接用list 
		//Stack<String> num_stack = new Stack<String>();
		List<String> num_list = new ArrayList<String>();
		for (String item : ls) {
			
			// 如果 是一个数 就 入栈 也就是这里的list 
			if(item.matches("\\d+")) {
				num_list.add(item);
			}else if(item.equals("(")){ // 左括号 
				oper_stack.push(item);
			}else if(item.equals(")")){
				
				// 如果是右括号  ")" 则依次 弹出 oper_stack 栈顶的运算符 并add 到list中 知道遇到右括号为止,此时将 这一对括号丢弃
				while(!oper_stack.peek().equals("(") ){
					num_list.add(oper_stack.pop());
				}
				// 将 ( 弹出 oper_stack  消除小括号 
				oper_stack.pop();
			}else {
				
				// 当 item 的优先级 小于等于 oper_stack 栈顶的运算符 ,将oper_stack 栈顶元素弹出 加入到list 中 
				while(oper_stack.size() != 0 && Operation.getValue(oper_stack.peek()) >=Operation.getValue(item) ) {
					num_list.add(oper_stack.pop());
				}
				//还需要将item 压入栈
				oper_stack.push(item);
			}
		}
		
		//将oper_stack 符号栈 中 剩余的运算符 依次弹出加入到list 中
		while(oper_stack.size() != 0) {
			num_list.add(oper_stack.pop());
		}
		// 因为 是存放到list 因此 按顺序 输出就是对应的逆波兰表达式
		return num_list;
	}
	
	
	/**
	 * s = "1+((2+3)*4)-5"
	 * 将中缀表达式 存入到list 中 
	 * @param str
	 * @return
	 */
	public static List<String> toInfixExpressionList(String s){
		// 定义list
		List<String> ls = new ArrayList<String>();
		int i = 0; // 这是一个指针 用于遍历 中缀表达式字符串
		String str; // 对多位数的拼接
		char c; // 遍历到一个字符 就放到 c 
		// 0 [48]  9 [57]
		do {
			// 如果c 是一个非数字   需要加入到ls 
			if((c = s.charAt(i)) <48 || (c = s.charAt(i)) >57) {
				ls.add(""+c);
				i++;//后移 
			}else {// 如果是一个数 需要考虑多位数
				str = "";
				// 将多位数子 看成char (单字符的拼接)
				while(i<s.length() && (c= s.charAt(i)) >=48 && (c= s.charAt(i)) <=57 ) {
					str +=c;//拼接
					i++;
				}
				ls.add(str);
			}
		} while (i < s.length());
		return ls;
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
	/**
	 * 根据后缀表达式  来 计算结果 
	 * @param list
	 * @return
	 */
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
/**
 * 编写一个类  Operation 可以返回一个运算符对应的优先级 
 * 
 */
class Operation{
	
	private static int ADD = 1;
	private static int SUM = 1;
	private static int MUL = 2;
	private static int DIV = 2;
	
	// 写一个方法  返回优先级的数字
	public static int getValue(String operation) {
		int result= 0;
		switch (operation) {
		case "+":
			result = ADD;
			break;
		case "-":
			result = SUM;
			break;
		case "*":
			result = MUL;
			break;
		case "/":
			result = DIV;
			break;
		default:
			System.out.println("不存在该运算符");
			break;
		}
		return result;
	}
}
