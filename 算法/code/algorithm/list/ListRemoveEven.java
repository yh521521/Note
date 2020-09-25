package com.algorithm.list;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

/**
 * 
  * 表 中有 6 5 1 4  2  删除表中 所有的偶数项
  * @author dell
  *
  */
public class ListRemoveEven {

	public static void main(String[] args) {
		//CopyOnWriteArrayList<Integer> list = new CopyOnWriteArrayList<Integer>();
		//List<Integer> list = new ArrayList<Integer>();
		LinkedList<Integer> list = new LinkedList<Integer>();
		list.add(6);
		list.add(5);
		list.add(1);
		list.add(4);
		list.add(2);
		remove3(list);
		System.out.println("输出删除偶数项的表 ");
		for (Integer i : list) {
			System.out.println("yh:::"+i); 
		}	
//		for (int i = 0; i < list.size(); i++) {
//			System.out.println("yh:::"+list.get(i));
//		}
	}
	// 方法1 
	public static void remove1(List<Integer> list) {
		int i= 0;
		while (i  < list.size()) {
			if(list.get(i) % 2 == 0) {
				list.remove(i);
			}else {
				i++;
			}
		}
	}
	
	// 方法2 
	/**
	 * 当方法检测到对象的并发修改，但不允许这种修改时，抛出此异常。
	 * ConcurrentModificationException
	 * @param list
	 */
		public static void remove2(List<Integer> list) {
			for (Integer i : list) {
				if(i % 2 == 0) {
					list.remove(i);
				}
				
			}
		}
		
		// 方法3  最优解  
		public static void remove3(List<Integer> list) {
			
			Iterator<Integer> itr = list.iterator();
			while (itr.hasNext()) {
				if(itr.next() % 2 == 0) {
					itr.remove();
				}
				
			}
		}

}//@@@


