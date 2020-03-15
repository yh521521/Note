package main

import (
	"flag"
	"fmt"
)

func main() {

	//声明的几种方式
	wordPtr := flag.String("word", "foo", "a string")
	numbPtr:=  flag.Int("numb", 42, "an int")
	boolPtr := flag.Bool("fork", false, "a bool")
	var svar string
	//&svar 地址值
	flag.StringVar (&svar, "svar", "bar", "a string var")
	//解析执行
	flag.Parse()

	fmt.Println("word:", *wordPtr)
	fmt.Println("numb:", *numbPtr)
	fmt.Println("fork:", *boolPtr)
	fmt.Println("svar:", svar)
	fmt.Println("tail:", flag.Args())

}

