package main

import (
	"fmt"
	_ "fmt"
)

func vals()(int,int){
	return 3,7
}

func main(){

	a,b := vals()
	fmt.Println(a)
	fmt.Println(b)
	//需要传入两个值  但是我只想要一个
	//可以用匿名变量代替
	_,c := vals()
	fmt.Println(c)

}

