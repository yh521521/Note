package main

import (
	"fmt"
	_ "fmt"
	"time"
	_ "time"

)
func main(){
	//创建 一个管道
	c1 := make(chan string ,1)
	go func(){
		time.Sleep(2*time.Second)  // 超时 2秒
		//管道赋值
		c1 <- "result 1"
	}()

	select {
	case res := <-c1:
		fmt.Println(res)
	case <- time.After(1*time.Second):   //case  判断 超时1 秒直接输出 timeout 1
		fmt.Println("timeout 1")
	}
	//创建一个管理
	c2 := make(chan string ,1)
	go func() {
		time.Sleep(2*time.Second)
		//管道赋值
		c2 <- "result 2"
	}()

	select {
	case res := <-c2:
		fmt.Println(res)
	case <- time.After(3*time.Second): // 超时3秒 才会输出 timeout2
		fmt.Println("timeout 2")
	}
}