package com.soul.stack;
/**
 *  栈实现综合计算器 (中缀表达式 )
 * @author dell
 *
 */
public class Calculator {

	public static void main(String[] args) {
		//表达式的运算
		//String expression= "712+2*6-312";
		String expression= "72*2*2+6-3/3";
		// 创建两个栈  数栈  符号栈 
		ArrayStack2 numStack = new ArrayStack2(10);
		ArrayStack2 operStack = new ArrayStack2(10);
		
		int index = 0;// 用于扫描
		int num1 = 0;
		int num2 = 0;
		int oper = 0;
		int res = 0;
		String  keepNum = ""; // 用于拼接多位数
		char ch = ' ';// 将每次扫描得到char 保存到ch 
		// while 循环扫描expression 
		while (true) {
			// 依次得到expression 的每一个字符	
			ch = expression.substring(index, index+1).charAt(0);
			// 判断ch 是什么 然后做相应的处理
			if(operStack.isOper(ch)) { // 如果是运算符
				//判断当前的符号栈是否为空 
				if(!operStack.isEmpty()) {
					// 不为空  处理
					// 如果 符号栈有操作符 就进行比较 如果当前的操作符优先级小于或等于 栈中的操作符
					// 就需要从数栈中弹出pop 两个数 
					//然后从符号栈 pop 出一个符号 进行运算 将得到的记过 入数栈  然后将当前的 操作符入符号栈 
					if(operStack.priority(ch) <=operStack.priority(operStack.peek()) ) {
						//数栈 抛出两个数 
						num1 = numStack.pop();
						num2 = numStack.pop();
						oper = operStack.pop(); // 从符号栈 把存在符号 弹出来
						res = numStack.cal(num1, num2, oper);
						// 入栈 
						numStack.push(res);
						// 当前做对比的符号 入符号栈
						operStack.push(ch);
					}else {
						//如果当前的操作符的优先级大于栈中的操作符 就直接 入符号栈 
						operStack.push(ch);
					}
				}else {
					// 是空  直接入栈 
					operStack.push(ch);
				}
				
			}else {
				// 如果是数  则直接入数栈 1 对应的ascii 码值为 49  2 为50 
				// 此种情况 只适用  单 位 数 四则运算
				//numStack.push(ch - 48 );
				// 处理多位数是 不能发现是一个数 就立即 入栈 因为可能是多位数
				// 在处理数  ,需要向expression 的表达式 的index后 再 看以为 
				// 如果是数就进行扫描  如果是符号 才 入栈 
				// 需要定义一个字符串变量  用于拼接
				
				
				// 处理多位数
				keepNum += ch;
				// 如果 ch 已经是expression 的最后一位 就直接入栈 
				if(index == expression.length() -1) {
					numStack.push(Integer.parseInt(keepNum));
				}else {//判断下一个字符是不是数字  如果是数字 就继续扫描  如果是运算符 则入栈
					if(operStack.isOper(expression.substring(index+1, index+2).charAt(0))) {
						// 如果后一位是操作符   入栈  keppNum =  "1"  或 "1234"
	 					numStack.push(Integer.parseInt(keepNum));
	 					// 清空keepNum
	 					keepNum = "";
						}
				}
				
				
			}
			// 让 index +1  并判断是否扫描到expression 最后
			index++;
			if(index >= expression.length()) {
				break;
			}
		}
		// 当表达式 扫描完毕 就顺序的哦那个 数栈 和符号栈 中pop 出相应的数和 符号  并运行'
		while(true) {
			// 如果符号栈为空 则计算到最后的结果  数栈 只有一个数字 就是我们计算的的结果
			if(operStack.isEmpty()) {
				break;
			}
			num1 = numStack.pop();
			num2 = numStack.pop();
			oper = operStack.pop(); // 从符号栈 把存在符号 弹出来
			res = numStack.cal(num1, num2, oper);
			// 入栈 
			numStack.push(res);
		}
		// 将数栈 的最后结果弹栈 
		System.out.println("表达式求得的记过为: "+numStack.pop());
		
		
	}

}
//先创建一个栈  
class ArrayStack2{
	
	private int maxSize ; // 栈的大小
	private int[] stack;// 数组 数组模拟栈 数据就放在该数组中
	private int top= -1; //栈 顶
	//private int top= -1; //栈 顶
	public ArrayStack2(int maxSize) {
		this.maxSize = maxSize;
		stack = new int[this.maxSize];
		
	}
	// 返回当前栈顶的值 不是真正的top 如果弹栈的话 就没有这个数据了
	public int peek() {
		return stack[top]; // 返回栈顶的值  而不是去弹栈操作
	}
	
	// 栈 满 
	public boolean isFull() {
		return top == maxSize-1;
	}
	// 栈 是否为空
	public boolean isEmpty() {
		return top == -1;
	}
	//入栈
	public void push(int value) {
		// 判断栈 是否满 
		if(isFull()) {
			System.out.println("栈满 了");
			return;
		}
		top++;
		stack[top] = value;
	}
	//出栈 
	public int pop() {
		// 判断栈 是否为空
		if(isEmpty()) {
			// 抛出异常
			throw new RuntimeException("栈空 ,没有数据");
		}
		int value = stack[top];
		top--;
		return value;
		
		// 遍历栈  从栈 顶 开始显示数据
		
	}
	public void list() {
		if(isEmpty()) {
			System.out.println("栈空 没有数据");
			return;
		}
		for (int i = top; i>=0; i--) {
			System.out.printf("stack[%d]=%d\n",i,stack[i]);
			
		}
		
	}
	
	//返回运算符的优先级 优先级 是人为来确定的 优先级用数字来表示 数字越大 优先级越高
	public int priority(int oper) {
		if(oper == '*' || oper =='/') {
			return 1;
		}else if(oper == '+' || oper =='-') {
			return 0;
		}else {
			return -1;// 假定目前的表达式只有 + - * / 
		}
	}
	//判断是不是一个运算符
	public boolean isOper(char val) {
		return val == '+'||val=='-'||val == '*'||val=='/';
	}
	// 计算方法
	public int cal(int num1,int num2,int oper) {
		int res = 0 ; //用于存放计算结果
		switch (oper) {
		case '+':
			res = num1 + num2;
			break;
		case '-':
			res = num2 - num1;
			break;
		case '*':
			res = num1 * num2;
			break;
		case '/':
			res = num2 / num1;
			break;
		default:
			break;
		}
		return res;
	}
}