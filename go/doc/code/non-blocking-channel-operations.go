package main

import (
	"fmt"
	_ "fmt"

)
//没有缓冲区并且没有接收器
func main(){

	messages := make(chan string)
	singals := make(chan bool)

	select {
	case msg := <- messages:
		fmt.Println("received message",msg)
	default:
		fmt.Println("no message received")
	}
	msg := "hi"
	select {
	case messages <- msg:
		fmt.Println("sent message",msg)
	default:
		fmt.Println("no message sent")
	}
	select {
	case msg := <- messages:
		fmt.Println("received message",msg)
	case sig := <- singals :
		fmt.Println("received singal",sig)
	default:
		fmt.Println("no activity")

	}
}


