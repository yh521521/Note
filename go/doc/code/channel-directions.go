package main

import (
	"fmt"

)

func ping(pings   chan<- string,msg string)  {
	pings <- msg
}

func pong(pings <- chan string,pongs chan <- string ){
	msg := <-pings //输入
	pongs <- msg //输出

}
func	main(){
	pings := make(chan string ,1)  //创建管道 pings chan string
	pongs := make(chan string ,1) // pongs chan string
	ping (pings,"passed message")
	pong(pings,pongs)
	fmt.Println(<- pongs)
}