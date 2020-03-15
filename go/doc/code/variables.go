package main

import (
	"fmt"
	_ "fmt"
)

func main(){
	// declare variables
	var a = "initial"
	fmt.Println(a)

	//declare multiple
	var b,c int = 1,2
	fmt.Println(b,c)

	//
	var d = true
	fmt.Println(d)

	//only declare but not assignment value
	var e int
	fmt.Println(e)


	//  initializing a variable
	f :="apple"
	fmt.Println(f)

	//initial
	//1 2
	//true
	//0
	//apple

}
