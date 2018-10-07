package main

import "fmt"

func main() {
	var n, y int
	fmt.Scan(&n, &y)

	m, g, s := -1, -1, -1

	for i := 0; i <= n; i++ {
		for j := 0; i+j <= n; j++ {
			if 10000*i+5000*j+1000*(n-i-j) == y {
				m = i
				g = j
				s = n - i - j
			}
		}
	}

	fmt.Println(m, g, s)
}
