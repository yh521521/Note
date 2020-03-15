package main

import (
	"fmt"
	_ "fmt"
)


func main(){

	nums := []int{2,3,4}
	// int[0] = 2
	// int[1] = 3
	// int[2] = 4

	//在使用 for range 循环遍历某个对象时，一般不会同时需要
	//key 或者 value，这个时候可以采用一些技巧，让代码变得更简单。
	//下面将前面的例子修改一下
	sum :=0
	//for range  遍历 _ 是一个匿名变量
	for  _,num := range nums{
		sum +=num
	}
	// 去掉_  则 会把 num 当成 key 则 sum = 0+1+2 = 3
	fmt.Println("sum:",sum)

	for i,num :=range nums{
		if num == 3{
			fmt.Println("index",i)
		}
	}

	kvs :=map[string]string{"a":"apple","b":"banana"}
	for k :=range kvs{
		fmt.Println("key:",k)
	}

	//range也可以用来枚举Unicode字符串。第一个参数是字符的索引
	//，第二个是字符（Unicode的值）本身。
	for i,c :=range "go"{
		fmt.Println(i,c)
	}
}
