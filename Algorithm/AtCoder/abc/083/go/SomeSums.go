package main

import "fmt"

func main() {
	var n, a, b int
	fmt.Scan(&n, &a, &b)

	ans := 0
	for i := 1; i <= n; i++ {
		j := i
		k := 0
		for {
			k += j % 10
			j /= 10
			if j == 0 {
				break
			}
		}

		if a <= k && k <= b {
			ans += i
		}
	}

	fmt.Println(ans)
}
