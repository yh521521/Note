package main

import (
	"fmt"
	_ "fmt"
)
func main(){
	i := 1
	for i<=3{
		fmt.Println(i)
		i = i+1
	}
	fmt.Println("11111")
	for j:=1; j<=9;j++{
		fmt.Println(j)
	}
	// example java  break  continue
	fmt.Println("12222")
	for n :=0 ;n<=5; n++{
		if n%2 == 0{
			continue
		}
		fmt.Println(n)
	}
	fmt.Println("3333")
	for n :=1 ;n<=5; n++{
		if n%2 == 0{
			break
		}

		fmt.Println(n)
	}

	//1
	//2
	//3
	//11111
	//1
	//2
	//3
	//4
	//5
	//6
	//7
	//8
	//9
	//12222
	//1
	//3
	//5


}