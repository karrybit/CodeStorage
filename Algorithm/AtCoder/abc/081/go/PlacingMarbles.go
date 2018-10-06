package main

import "fmt"

func main() {
	var s string
	fmt.Scan(&s)

	ans := 0
	for i := 0; i < len(s); i++ {
		if s[i] == '1' {
			ans++
		}
	}

	fmt.Println(ans)
}
