package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	d := make([]int, n)
	m := map[int]int{}

	for i := range d {
		fmt.Scan(&d[i])
		m[d[i]]++
	}

	fmt.Println(len(m))
}
