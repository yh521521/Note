package main

import (_"fmt"
	"time"
	_ "time"
)

func main()  {
	timer1 := time.NewTimer(2*time.Second)

	<- time1.C

}