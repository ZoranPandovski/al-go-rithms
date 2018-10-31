package main

import(
	"fmt"
)

func main(){
	var p,g,a,b,A,B,S_A,S_B int

	fmt.Println("The Point of this program is to Perform",
		"DeffieHellmanKeyExchange.\n Enter modulo(p)")

	_,err1 := fmt.Scanf("%d",&p)
	if (err1 != nil) {
		fmt.Println("Invalid input")
	}

	fmt.Println("Enter primitive root of %d",p)
	_,err2 := fmt.Scanf("%d",&g)
	if (err2 != nil) {
		fmt.Println("Invalid input")
	}

	fmt.Println("")
	_,err3 := fmt.Scanf("%d",&p)
	if (err1 != nil) {
		fmt.Println("Invalid input")
	}

	fmt.Println("")
	_,err4 := fmt.Scanf("%d",&p)
	if (err1 != nil) {
		fmt.Println("Invalid input")
	}

	fmt.Println("")
	_,err5 := fmt.Scanf("%d",&p)
	if (err1 != nil) {
		fmt.Println("Invalid input")
	}

	fmt.Printf("LCM of %d,%d is %d\n",x,y,lcm(x,y))
}
