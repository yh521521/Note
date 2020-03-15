package main

import (
	"bufio"
	"fmt"
	"net/http"
)

func main() {
	resp, err := http.Get("http://gobyexample.com")
	if err != nil {
		panic(err)
	}
	defer resp.Body.Close()
	fmt.Println("Response status:", resp.Status)
	sacnner := bufio.NewScanner(resp.Body)
	for i := 0; sacnner.Scan() && i < 100; i++ {
		fmt.Println(sacnner.Text())

	}
	if err := sacnner.Err(); err != nil {
		panic(err)
	}
}
