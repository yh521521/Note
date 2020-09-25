package com.yh.soul.greedy;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;

/**
 * 思考1:
 * 为什莫要用HashMap  HashSet 呢 
 * HashMap 是存储的键值对  key- value  ,HashSet 是存储的对象  
 *  
 *  得到的选择结果是 yh:[K1, K2, K3, K5]
 *  贪婪算法得到的结果不一定是最优的结果[有时候是会是最优解] ,但都是相对近似接近最优解的结果
 *  [k2,k3,k4,k5] 也可以覆盖全部的地区 
 * @author dell
 *
 */
public class GreedyAlgorithm {


	public static void main(String[] args) {
		
		// 常见广播电台 放到map 中
		HashMap<String, HashSet<String>> broadCasts = new HashMap<>();
		// 将各个电台放入到 broadCasts
		HashSet<String> hashSet1 = new HashSet<>();
		hashSet1.add("北京");
		hashSet1.add("上海");
		hashSet1.add("天津");

		HashSet<String> hashSet2 = new HashSet<>();
//		hashSet2.add("广州");
//		hashSet2.add("北京");
//		hashSet2.add("深圳 ");
		
		
		hashSet2.add("北京");
		hashSet2.add("广州");
		hashSet2.add("深圳");
		
		
		HashSet<String> hashSet3 = new HashSet<>();
		hashSet3.add("成都");
		hashSet3.add("上海");
		hashSet3.add("杭州 ");

		HashSet<String> hashSet4 = new HashSet<>();
		hashSet4.add("上海");
		hashSet4.add("天津");

		HashSet<String> hashSet5 = new HashSet<>();
		hashSet5.add("杭州");
		hashSet5.add("大连");

		// 加入到map
		broadCasts.put("K1", hashSet1);
		broadCasts.put("K2", hashSet2);
		broadCasts.put("K3", hashSet3);
		broadCasts.put("K4", hashSet4);
		broadCasts.put("K5", hashSet5);
		
		// allAreas 存放所有的地区
		HashSet<String> allAreas = new HashSet<>();

		allAreas.add("北京");
		allAreas.add("上海");
		allAreas.add("天津");
		allAreas.add("广州");
		allAreas.add("深圳");
		allAreas.add("成都");
		allAreas.add("杭州");
		allAreas.add("大连");
		// 创建ArrayList 存放选择的电台集合
		ArrayList<String> selects = new ArrayList<String>();
		String maxKey = null;
		// 定义一个临时的集合 ,保存在遍历过程中 ,存放遍历过程中的电台覆盖的地区 和当前还没有覆盖的地区的交集
		HashSet<String> tempSet = new HashSet<>();
		// 定义给maxKey 保存在一次遍历过程中 能够覆盖最大未覆盖地区
		// 的地区对应的电台的key
		// 如果maxKey 不为null 则会加入到selects

		while (allAreas.size() != 0) { // 如果allAreas 不为0 则表示还没有覆盖到所有的地区
			// 每进行一次while ,需要将maxKey 置空
			maxKey = null;
			// 遍历broadCasts 取出对应的key
			for (String key : broadCasts.keySet()) {
				// 没进行一次for循环
				tempSet.clear();
				// 当前这个key能够覆盖的地区
				 HashSet<String> areas = broadCasts.get(key);
				tempSet.addAll(areas);
				// 求出tempSet和allAreas 集合的交集 ,交集 会赋给tempSet
				tempSet.retainAll(allAreas);
				// 如果当前这个集合包含的未覆盖地区的数量 比maxKey 指向的集合地区还多
				// 就需要重置maxKey
				// tempSet.size() > broadCasts.get(maxKey).size() 体现出贪婪算法的特点
				
				if (tempSet.size() > 0 &&
						(maxKey == null || tempSet.size() > broadCasts.get(maxKey).size())) {
					maxKey = key;
				}
			}
			// maxKey !=null 就应该将maxKey 加入selects
			if (maxKey != null) {
				selects.add(maxKey);
				// 将maxKey 指向的广播电台覆盖的地区 从 allAreas 去掉
				allAreas.removeAll(broadCasts.get(maxKey));
			}

		}
		System.out.println("得到的选择结果是 yh:" + selects);

	}

}// @@@@@@
