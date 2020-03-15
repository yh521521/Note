package main

import (
	"fmt"
	"os"

)
/**

go build构建二进制文件。
 */
func main() {
	argsWithProg := os.Args
	argsWithoutProg := os.Args[1:]

	arg := os.Args[2]
	fmt.Println(argsWithProg)
	fmt.Println(argsWithoutProg)
	fmt.Println(arg)


}
