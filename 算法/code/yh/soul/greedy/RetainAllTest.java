package com.yh.soul.greedy;

import java.util.HashSet;

public class RetainAllTest {

	public static void main(String[] args) {
		
		HashSet<String> hashSet1 = new HashSet<String>();
		HashSet<String> hashSet2 = new HashSet<String>();
		hashSet1.add("1");
		hashSet1.add("2");
		hashSet1.add("100");
		
		
		hashSet2.add("1");
		hashSet2.add("2");
		hashSet2.add("200");
		hashSet1.retainAll(hashSet2);
		//hashSet1:yh:[1, 2] 交集 
		System.err.println("hashSet1:yh:"+hashSet1);
	}

}
