package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int, n)
	for i := range a {
		fmt.Scan(&a[i])
	}

	sort.Sort(sort.Reverse(sort.IntSlice(a)))

	var ans int
	for i := range a {
		if i%2 == 0 {
			ans += a[i]
		} else {
			ans -= a[i]
		}
	}

	fmt.Println(ans)
}
