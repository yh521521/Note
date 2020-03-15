package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

/**
键盘录入 输入的变成大写
 */
func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		cul := strings.ToUpper(scanner.Text())
		fmt.Println(cul)
	}

	if err := scanner.Err();
	err != nil{
		fmt.Fprintln(os.Stderr,"error",err)
		os.Exit(1)
	}


	}
