package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	var a = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	count := 0
LOOP:
	for {
		for i := 0; i < n; i++ {
			if a[i]%2 == 0 {
				a[i] = a[i] / 2
			} else {
				break LOOP
			}
		}
		count++
	}

	fmt.Println(count)
}
