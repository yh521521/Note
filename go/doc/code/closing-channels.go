package main

import (
	"fmt"
	_ "fmt")
/**
关闭通道表示不再向其发送值。
这对于与信道的接收器通信完成非常有用。
 */
func main() {
	jobs := make(chan int ,5)
	done := make(chan bool)

	go func(){
		for {
			j,more := <- jobs
			if more {
				fmt.Println("received job",j)
			}else {
				fmt.Println("received  all job")
				done <- true
				return
			}
		}
	}()
	for j:= 1; j<= 3 ;j++{
		jobs <-j
		fmt.Println("sent job",j)
	}
	close(jobs)
	fmt.Println("sent all jobs")
	<- done
}