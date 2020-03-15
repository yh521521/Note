package main

import (
	"fmt"
	"net/http"
)

func hello( w http.ResponseWriter,req *http.Request)  {
	
	fmt.Println(w,"hello\n")
}
func headers(w http.ResponseWriter, req *http.Request)  {
	for name ,headers:= range req.Header{
		for _,h := range headers{
			fmt.Fprintf(w, "%v: %v\n", name, h)
		}
	}
}
func main() {
	//我们使用http.HandleFunc便利函数在服务器路由上注册处理 程序。
	//它在net/http包中设置默认路由器，并以函数作为参数。
	http.HandleFunc("/hello",hello)
	http.HandleFunc("/headers",headers)

	//我们用端口和处理程序调用ListenAndServe
	http.ListenAndServe(":8090",nil)
}