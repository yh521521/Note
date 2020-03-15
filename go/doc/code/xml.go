package main

import	 (
	"encoding/xml"
	"fmt"
)
type Plant struct{

	XMLName xml.Name `xml:"plant"`
	Id      int      `xml:"id,attr"`
	Name    string   `xml:"name"`
	Origin  []string `xml:"origin"`
}
/**
对格式要求很严格
 */
func (p Plant)String() string {
	//return  fmt.Springf("Plant id =%v ,name =%v origin = %v",p.Id,p.Name,pOrigin)
	return fmt.Sprintf("Plant id=%v, name=%v, origin=%v",
		p.Id, p.Name, p.Origin)

}
func main() {
	coffee := &Plant{ Id: 27,Name: "Coffee"}
	coffee.Origin = []string{"Ethiopia","Brazil"}
	out,_ :=xml.MarshalIndent(coffee," "," ")
	fmt.Println(string(out))
	fmt.Println(string(out))

}
