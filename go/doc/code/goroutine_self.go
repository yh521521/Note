package main

import (
	"fmt"
	_ "fmt"
	"sync"
	_ "time"
)


//并行通信——数据各位同时传送；
//
//串行通信——数据一位位顺序传送。
var wg sync.WaitGroup
func hello(i int){
	defer wg.Done()
	fmt.Println("hello ",i)
}
func main()  {

	////hello()
	//go hello()
	//fmt.Println("main goroutine done!")
	//time.Sleep(time.Second)
	//wg.Add(1)
	//go hello()
	//fmt.Println("main goroutine done!")
	//wg.Wait()

	for i:=0;i<8 ;i++{
		wg.Add(1)
		go hello(i)
	}
	wg.Wait()
}
