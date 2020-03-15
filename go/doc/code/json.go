package main

import (
	"encoding/json"
	"fmt"
)

/**
Marshal与Unmarshal
 Marshal 将数据编码成json字符串
Unmarshal 将json字符串解码到相应的数据结构
 */
type response1 struct{
	Page int
	Fruits []string
}
type response2 struct{
	Page   int      `json:"page"`
	Fruits []string `json:"fruits"`


}

type Stu struct {
	Name  interface{} `json:"name"`
	Age   interface{}
	High  interface{}
	Sex   interface{}
	Class interface{} `json:"class"`
}

type Class struct {
	Name  string
	Grade int
}

//type Stu struct {
//	Name  string `json:"name"`
//	Age   int
//	High  bool
//	sex   string
//	Class *Class `json:"class"`
//}
//
//type Class struct {
//	Name  string
//	Grade int
//}

func main() {
	//实例化一个数据结构 用于生成 字符串
	stu :=Stu{
		Name :"张三",
		Age : 18,
		High :true,
		Sex : "男",
	}

	//指针变量
	cla := new (Class)
	cla.Name = "1班"
	cla.Grade=3
	stu.Class=cla
	//Marshal 失败时 err!= nil
	jsonStu ,err := json.Marshal(stu)
	if err != nil{
		fmt.Println("生成json 字符串错误")
	}
	//jsonStu 是[] byte 类型转化成 string 类型便于查看
	fmt.Println(jsonStu)
	fmt.Println(string(jsonStu))

/**
  [123 34 110 97 109 101 34 58 34 229 188 160 228 184 137 34 44 34 65 103 101 34 58 49 56 44 34 72 105 103 104 34 58 116 114 117 101 44 34 83 101 120 34 58 34 231 148 183 34 44 34 99 108 97 115 115 34 58 123 34 78 97 109 101 34 58 34 49 231 143 173 34 44 34 71 114 97 100 101 34 58 51 125 125]
  {"name":"张三","Age":18,"High":true,"Sex":"男","class":{"Name":"1班","Grade":3}}


	只要是可导出成员（变量首字母大写），都可以转成json。因成员变量sex是不可导出的，故无法转成json。

	如果变量打上了json标签，如Name旁边的 `json:"name"` ，那么转化成的json key就用该标签“name”，否则取变量名作为key，如“Age”，“HIgh”。

	bool类型也是可以直接转换为json的value值。Channel， complex 以及函数不能被编码json字符串。当然，循环的数据结构也不行，它会导致marshal陷入死循环。

	指针变量，编码时自动转换为它所指向的值，如cla变量。
	（当然，不传指针，Stu struct的成员Class如果换成Class struct类型，效果也是一模一样的。只不过指针更快，且能节省内存空间。）

	最后，强调一句：json编码成字符串后就是纯粹的字符串了。

*/
}