package com.soul.huffmancode;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
/**
 * 计算机中 用补码 进行加减运算
 */
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * 赫夫曼编码
 * 
 * @author dell
 *
 */
public class HuffmanCode {

	public static void main(String[] args) {
		
		
		//测试压缩文件 
//		String srcFile = "g://tree.png";
//		String dstFile = "g://tree.zip";
//		zipFile(srcFile, dstFile);
//		System.out.println("压缩文件 ok ");
		
		// 测试解压文件
		String zipFile ="G://面试//tree.zip" ;
		String dstFile ="G://面试//tree.png" ;
		unZipFile(zipFile, dstFile);
		System.out.println("解压成功");
		/*
		  String content = "i like like like java do you like a java";
		byte[] contentBytes = content.getBytes();
		System.out.println(contentBytes.length);
		
		
		byte[] huffmanZip = huffmanZip(contentBytes);
		System.out.println("压缩后的结果是" +Arrays.toString(huffmanZip)+ "长度"+ huffmanZip.length);
		
		
		//System.out.println(byteToBitString((byte) 1));
		
		byte[] sourceBytes = decode(huffmanCodes, huffmanZip);
		System.out.println("原来的字符串"+new String(sourceBytes));
		
		*/
		
		
		// 分布过程
		/*
		List<Node> nodes = getNodes(contentBytes);
		System.out.println("11"+nodes);
		
		//测试创建的赫夫曼树
		System.out.println("赫夫曼树 ");
		Node huffmanTreeRoot = createHuffmanTree(nodes);
		System.out.println("前序遍历");
		huffmanTreeRoot.preOrder();
		
		//测试是否生成了赫夫曼编码 根节点 部分左右 传空字符串就行
		//getCodes(huffmanTreeRoot, "", stringBuilder);
		Map<Byte, String> huffmanCodes = getCodes(huffmanTreeRoot);
		System.out.println("~生成的赫夫曼编码表 ="+ huffmanCodes);
		// 测试
		byte[] huffmanCodesBytes = zip(contentBytes, huffmanCodes);
		System.out.println("huffmanCodesBytes:"+Arrays.toString(huffmanCodesBytes));
		*/
		
		// 发送huffmanCodesBytes 数组
		
	}
	
	
	// 编写一个方法 完成对压缩文件的解压
	/**
	 * 
	 * @param zipFile 准备解压的文件
	 * @param dstFile 将文件解压到哪个路径
	 */
	public static void unZipFile(String zipFile,String dstFile) {
		
		// 定义文件输入流
		InputStream is  = null;
		//定义一个对象输入流 
		ObjectInputStream ois = null;
		// 定义文件的输出流 
		OutputStream os = null;
		try {
			//创建文件输入流 
			 is = new FileInputStream(zipFile);
			 //创建一个和 is  关联的对象输入流 
			 ois = new ObjectInputStream(is);
			 // 读取bytes 数组  huffmanBytes
			 byte[]  huffmanBytes = (byte[]) ois.readObject();
			 // 读取赫夫曼编码表 
			 Map<Byte,String> huffmanCodes = (Map<Byte,String> )ois.readObject();
			 // 解码
			 byte[] bytes = decode(huffmanCodes, huffmanBytes);
			 //将 bytes 数组写入到
			 os = new FileOutputStream(dstFile);
			 //写数据到dstFile 文件
			 os.write(bytes);
		} catch (Exception e) {
			e.printStackTrace();
		}finally {
			
			try {
				os.close();
				ois.close();
				is.close();
			} catch (Exception e) {
				e.printStackTrace();
			}
			
			
		}
	}
	
	//编写方法 将一个文件进行压缩 
	/**
	 * 
	 * @param srcFile 你传入的希望压缩的文件的全路径   (源文件)
	 * @param dstFile 我们压缩后将压缩文件放到哪个目录  (目标文件)
	 */
	public static void zipFile(String srcFile,String dstFile) {
		
		// 创建输出流 
		OutputStream os = null; //写出 
		ObjectOutputStream oos = null;
		//创建文件的输入流
		FileInputStream is = null;  //读入
		
		try {
			//创建文件的输入流
			 is = new FileInputStream(srcFile);
			//创建一个和源文件大小一样的byte[]
			byte[] b = new byte[is.available()];
			// 读取文件
			is.read(b);
			//直接对源文件压缩
			byte[] huffmanBytes = huffmanZip(b);
			//创建文件的输出流  存放压缩文件 
			 os = new FileOutputStream(dstFile);
			 // 创建一个和文件输出流 关联的 objectOutputStream
			  oos = new ObjectOutputStream(os);
			 // 把 赫夫曼编码的后的字节 数组写入 压缩文件
			  oos.writeObject(huffmanBytes);
			  //这里我们以对象流的方式写入赫夫曼编码 目的 是为了以后我们恢复源文件使用
			  // 注意一定要把 赫夫曼编码写入 压缩文件 
			  oos.writeObject(huffmanCodes);
			
		} catch (Exception e) {
			e.printStackTrace();
		}finally {
			try {
				is.close();
				oos.close();
				os.close();
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	// 完成数据的解压 
	// 1 将huffmanCodesBytes[-88, -65, -56, -65, -56, -65, -55, 77, -57, 6, -24, -14, -117, -4, -60, -90, 28]
	// 重写先转成赫夫曼编码对应的二进制 字符串1010....
	// 2 赫夫曼编码对应的 二进制的字符串 1010... => 对照赫夫曼编码 = >  i like like like java 
	
	// 编写一个方法  完成对压缩数据的解码 
	/**
	 * 
	 * @param huffmanCodes 赫夫曼编码表map
	 * @param huffmanBytes 赫夫曼编码得到的字节数组
	 * @return  就是原来的字符串对应的数组
	 */
	private static byte[] decode(Map<Byte,String> huffmanCodes,byte[] huffmanBytes) {
		
		//1 先得到huffmanBytes 对应的二进制字符串 形式1010
		StringBuilder sb = new StringBuilder();
		// 将byte 数组 转成二进制的字符串 
		for (int i = 0; i < huffmanBytes.length; i++) {
			byte b = huffmanBytes[i];
			//判断是不是最后一个字节
			boolean flag = (i == huffmanBytes.length -1);
			sb.append(byteToBitString(!flag, b));
		}
		//System.out.println("赫夫曼字节数组对应的二进制字符串"+sb.toString());
		
		// 把 字符串按照指定的赫夫曼编码进行解码
		// 把赫夫曼编码表进行调换  因为要反向查询 
		Map<String, Byte> map = new HashMap<String ,Byte>();
		for (Map.Entry<Byte, String> entry : huffmanCodes.entrySet()) {
			map.put(entry.getValue(), entry.getKey());
		}
		//System.out.println("map"+map);
		//return null;
		//创建结合 粗放byte 
		List<Byte> list = new ArrayList<>();
		// i 可以理解为是索引 扫描sb 
		for (int i = 0; i < sb.length();) {
			int count = 1; //计数器 
			boolean flag = true;
			Byte b= null;
			
			while(flag) {
				//递增的取出key 
				String key = sb.substring(i,i+count); // i 不动 count 移动 直到 匹配到一个字符
				b = map.get(key);
				if(b == null) { // 说明还没有匹配到
					count ++;
				}else {
					//匹配到
					flag = false;
				}
			}
			list.add(b);
			i += count; // i 直接 移动到count 的位置 
		}
		
		//当for 循环结束后 我们list 中就存放了所有的字符 i like like 
		//把 list 中的数组放入到byte[]
		
		byte[] b = new byte[list.size()];
		for (int i = 0; i < b.length; i++) {
			b[i] = list.get(i);
		}
		
		return b;
	}
	
	
	
	
	/**
	 * 将一个byte  转成一个二进制字符串
	 * @param flag 标志 是否需要补高位 如果是true 表示需要补高位  false 不需要补高位
	 * 如果是最后一个字节 无需补高位
	 * @param b 传入的 byte 
	 * @return 该b 对应的二进制 字符串 (注意是按照补码返回)
	 */
	private static String byteToBitString(boolean flag,byte b) {
		// 定义变量保存b 
		int temp = b;
		// 如果是正数 我们还存在补高位的 问题  模
		if(flag) {
			temp |= 256;// 按位 与  
		}
		// 返回的是二进制的补码
		String str = Integer.toBinaryString(temp);
		System.out.println("str::"+str);
		if(flag) {
			return str.substring(str.length() -8);
		}else {
			return str;
		}
		
		
	}
	
	// 使用一个方法 将前面的方法封装起来 便于我们的调用 
	/**
	 * 
	 * @param bytes 原始的字符串对应的字节数组 
	 * @return  经过赫夫曼编码处理后的字节数组 ( 压缩后的数组)
	 */
	private static byte[] huffmanZip(byte[] bytes) {
		
		List<Node> nodes = getNodes(bytes);
		// 根据nodes创建赫夫曼树 
		Node huffmanTreeRoot = createHuffmanTree(nodes);
		// 对应的赫夫曼编码 (根据赫夫曼树)
		Map<Byte, String> huffmanCodes = getCodes(huffmanTreeRoot);
		// 根据生成的编码   ,压缩得到  压缩后的赫夫曼编码字节数组
		byte[] huffmanCodesBytes = zip(bytes, huffmanCodes);
		return huffmanCodesBytes;
		
		
	}
	
	
	
	//编写一个方法 将字符串 对应的byte 数组  通过赫夫曼编码表 返回一个赫夫曼编码 压缩后的byte 数组
	/**
	 * 
	 * @param bytes 原始的字符串对应的byte[] 
	 * @param huffmanCodes 生成的赫夫曼编码 
	 * @return 返回 赫夫曼编码  处理后的byte[]
	 */
	private static byte[]  zip(byte[] bytes,Map<Byte,String> huffmanCodes) {
		// 利用huffmanCodes 将bytes 转成赫夫曼编码对应的字符串
		StringBuilder stringBuilder = new StringBuilder();
		//遍历bytes数组
		for (byte b : bytes) {
			stringBuilder.append(huffmanCodes.get(b));
		}
		System.out.println("测试111"+stringBuilder.toString());
		//1111010100010111111110010001011111111001000101111111100100101001101110001110000011011101000111100101000101111111100110001001010011011100
		// 转成byte[] 
		//统计返回的byte[]  huffmanCodesBytes 长度
		int len;
		// 一句话搞定int len = len = (stringBuilder.length() + 7) / 8
		if(stringBuilder.length() % 8 == 0) {
			len = stringBuilder.length() / 8;
		}else {
			len = stringBuilder.length() / 8 + 1;
		}
		
		// 创建存储压缩后的byte 数组 
		byte[] huffmanCodesBytes = new byte[len];
		int index = 0; //记录第几个byte
		for (int i = 0; i < stringBuilder.length(); i+=8) { // 每8 位 对应一个byte 所以步长加 8 
			String  strByte;
			if(i+8 >stringBuilder.length()) { // 不够 8  位
				strByte = stringBuilder.substring(i);
			}else {
				strByte = stringBuilder.substring(i,i+8);
			}
			
			// 将strByte 转成一个byte 放入到 一个huffmanCodesBytes   按照二进制
			huffmanCodesBytes[index] = (byte) Integer.parseInt(strByte,2) ; 
			index++;
			
		}
		return huffmanCodesBytes;
	}
	
	
	// 生成赫夫曼树对应的赫夫曼编码
	// 1) 将 赫夫曼编码表 存放在Map<Byte,String> 形式 
	//32->01 97 ->100 100->11000等形式 
	
	// 静态修饰的随之类的加载而加载 
	
	
	static Map<Byte,String> huffmanCodes = new HashMap<Byte, String>();
	//2) 在生成赫夫曼编码表时 需要去拼接路径  定义一个stringbuilder  存储某个叶子节点的路径
	
	static StringBuilder stringBuilder = new   StringBuilder();
	
	//为了调用方便 我们重载getCodes
	private static Map<Byte,String> getCodes(Node root){
		if(root == null) {
			return null;
			
		}
		//处理root 的左子树 
		getCodes(root.left,"0",stringBuilder);
		//处理root 的右子树 
		getCodes(root.right,"1",stringBuilder);
		return huffmanCodes;
	}
	
	
	/**
	 * 功能  将传入的node 节点 的所有叶子结点 的赫夫曼编码 并放入到huffmanCodes 集合中
	 * @param node 传入的节点 默认从根节点传
	 * @param code 路径 左子节点 是 0 右子节点 是1 
	 * @param sbBuilder 用于拼接路径 
	 */
	private static void getCodes(Node node,String code,StringBuilder stringBuilder) {
		
		StringBuilder stringBuilder2 = new StringBuilder(stringBuilder);
		// 将node 加入到 stringBuilder2 
		stringBuilder2.append(code);
		if(code != null) { // code == null 不处理
			// 当前node 是叶子节点还是非叶子节点
			if(node.data == null) {// 非叶子节点 
				//递归处理
				//向左
				getCodes(node.left, "0", stringBuilder2);
				// 向有递归
				getCodes(node.right, "1", stringBuilder2);
			}else { // 说明是一个叶子节点 
				//表示 找到某个叶子节点的最后 
				huffmanCodes.put(node.data, stringBuilder2.toString());
				
			}
		}
	}
	
	// 前序遍历 
	
	private static void preOrder(Node root) {
		if(root != null) {
			root.preOrder();
			
		}else {
			System.out.println("赫夫曼树 为空 ");
		}
	}
	/**
	 * 
	 * @param bytes 接收字节数组
	 * @return 返回就是list 形式 [Node [data=32, weight=9], Node [data=97, weight=5], Node [data=100, weight=1], Node [data=101, weight=4], Node [data=117, weight=1], Node [data=118, weight=2], Node [data=105, weight=5], Node [data=121, weight=1], Node [data=106, weight=2], Node [data=107, weight=4], Node [data=108, weight=4], Node [data=111, weight=2]]

	 */
	private static List<Node> getNodes(byte[] bytes){
		
		// 创建一个ArrayList 
		ArrayList<Node> nodes = new ArrayList<Node>();
		// 遍历bytes 统计每一个bytes 出现的次数 ->map [key ,value]
		Map<Byte, Integer> counts = new HashMap<>();
		for (byte b : bytes) {
			Integer count = counts.get(b);
			if(count == null) {//Map 还没有这个字符数据 第一次
				counts.put(b, 1);
			}else {
				counts.put(b, count+1);
			}
		}
		// 把 每个键值对 转成一个Node 对象 并加入到nodes 集合    entrySet 键值对
		for (Map.Entry<Byte, Integer> entry : counts.entrySet()) {
			nodes.add(new Node(entry.getKey(), entry.getValue()));
		}
		return nodes;
	}
	
	// 可以通过List 创建对应的赫夫曼树
	private static Node createHuffmanTree(List<Node> nodes) {
		
		while (nodes.size() > 1 ) {
			//排序  从小到大 
			Collections.sort(nodes);
			// 取出 第一颗 最小的二叉树
			Node leftNode = nodes.get(0);
			// 取出 第二颗 最小的二叉树
			Node rightNode = nodes.get(1);
			// 创建一棵 新的二叉树 ,它的根节点 没有data 只有权值 
			Node parent = new Node(null,leftNode.weight+rightNode.weight) ;
			parent.left = leftNode;
			parent.right = rightNode;
			
			//将已经处理的两颗二叉树从nodes list 数组中移除 
			nodes.remove(leftNode);
			nodes.remove(rightNode);
			//将新的二叉树 加入到nodes  
			nodes.add(parent);
		}
		//nodes  最后的节点 就是赫夫曼树的根节点 
		return nodes.get(0);
	}

}// @@@@@@@@@

// 创建Node  数据 和权值 
class Node implements Comparable<Node> {
	Byte data;// 存放数据本身 比如 'a' = 97 ' ' = 32
	int weight;// 权值 表示字符出现的次数
	Node left;
	Node right;

	public Node(Byte data, int weight) {
		this.data = data;
		this.weight = weight;
	}

	@Override
	public int compareTo(Node o) {
		// 从小到大顺序
		return this.weight - o.weight;
	}

	@Override
	public String toString() {
		return "Node [data=" + data + ", weight=" + weight + "]";
	}
	
	// 前序遍历
	public void preOrder() {
		System.out.println(this);
		if(this.left != null) {
			this.left.preOrder();
		}
		if(this.right != null) {
			this.right.preOrder();
		}
	}

}
