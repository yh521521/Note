package main

import (
	"fmt"
	_ "fmt"
)

func main()  {
	//func make(t Type, size ...IntegerType) Type
	//如果我们发送给该通道的元素值未被取走，
	//那么该通道最多可以暂存（或者说缓冲）size 个元素值。
	//size  0 1 都会报错 至少为 3
	messages := make(chan string,2)
	messages <-"buffeded"  //发送数据
	messages <- "channel"  //发送数据

	fmt.Println(<- messages) //接收数据
	fmt.Println(<- messages)//接收数据


}
