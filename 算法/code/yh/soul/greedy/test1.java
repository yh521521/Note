package com.yh.soul.greedy;

import java.util.HashMap;
import java.util.HashSet;

public class test1 {

	public static void main(String[] args) {
		// 用一个hashSet存放所有的地区
		HashSet<String> allAreas = new HashSet<>();
		// 用Map存放电台和覆盖地区
		HashMap<String, HashSet<String>> broadcasts = new HashMap<>();
		HashSet<String> hashSet1 = new HashSet<>();
		hashSet1.add("北京");
		hashSet1.add("上海");
		hashSet1.add("天津");

		HashSet<String> hashSet2 = new HashSet<>();
		hashSet2.add("北京");
		hashSet2.add("广州");
		hashSet2.add("深圳");

		HashSet<String> hashSet3 = new HashSet<>();
		hashSet3.add("成都");
		hashSet3.add("上海");
		hashSet3.add("杭州");

		HashSet<String> hashSet4 = new HashSet<>();
		hashSet4.add("上海");
		hashSet4.add("天津");

		HashSet<String> hashSet5 = new HashSet<>();
		hashSet5.add("杭州");
		hashSet5.add("大连");

		broadcasts.put("K1", hashSet1);
		broadcasts.put("K2", hashSet2);
		broadcasts.put("K3", hashSet3);
		broadcasts.put("K4", hashSet4);
		broadcasts.put("K5", hashSet5);

		allAreas.add("北京");
		allAreas.add("上海");
		allAreas.add("天津");
		allAreas.add("成都");
		allAreas.add("杭州");
		allAreas.add("大连");
		allAreas.add("广州");
		allAreas.add("深圳");
		// 用于存放选择的电台
		HashSet<String> selects = new HashSet<>();
		// 申请一个指针指向选择的电台（maxKey）
		String maxKey = null;
		// 一个临时容器用于存放maxKey指向的地区和allAreas的交集
		HashSet<String> tempValue = new HashSet<>();
		HashSet<String> temp = new HashSet<>();
		while (allAreas.size() > 0) {
			// 每经过一次for循环就需要将maxKey置空，方便下次for中的if找出最大覆盖区域，非常重要的一步
			maxKey = null;
			// String key:broadcasts.keySet()即用循环取出broadcasts中的key
			for (String key : broadcasts.keySet()) {
				// 每经过一次循环，tempValue都会保存交集，因此要比较每一个Kx和allAreas中的最大交集就需要清空一次方便下一次
				// 的kx比较,非常重要的一步
				tempValue.clear();
				// 首先遍历集合，找到最大的为覆盖地区对应的kx，即maxKey指向的值

				// 取出key之后再从中取出对应的value值
				tempValue.addAll(broadcasts.get(key));
				// 求tempValue中的值与allAreas中交集，只要交集最大则将maxKey指向它
				// tempValue.retainAll(allAreas);会将tempValue和allAreas的交集结果放入tempValue集合中
				tempValue.retainAll(allAreas);

				// 让maxKey指向最大的覆盖区域的Kx, 首先需要满足交集不为空，并且maxKey为空或者tempValue中的值比maxKey指向的区域数目
				// 还要多那么就需要maxKey改变指向(maxKey指向的也需要与allAreas求交集之后再和tempValue与allAreas求交集之后的比较)
				if (maxKey != null) {
					temp = broadcasts.get(maxKey);
					temp.retainAll(allAreas);

				}
				if (tempValue.size() > 0 && (maxKey == null || tempValue.size() > temp.size())) {
					maxKey = key;

				}

			}
			// 当经过一轮的遍历之后，maxKey就找到了最大的覆盖区域，此时就应该将maxKey指向的kx加入到selects中
			if (maxKey != null) {

				selects.add(maxKey);
				// 然后从allAreas中删除maxKey指向的地区
				allAreas.removeAll(broadcasts.get(maxKey));
			}
		}
		System.out.println("贪婪算法的求得的选择电台:" + selects);
	}
}
