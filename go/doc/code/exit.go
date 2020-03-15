package main

import (
	"fmt"
	"os"

)
/**
使用os.Exit立即退出给定状态
 */
func main() {
	defer fmt.Println("!")
	//使用os.Exit时不会运行延迟，因此永远不会调用此fmt.Println。

	//以非零状态退出，则应使用os.exit。
	os.Exit(1)
}