package main

import (
	"fmt"
	"math"
)

func main() {
	x := math.NaN()
	y := x + 1
	s := make(map[float64]bool)

	s[x] = true
	s[x] = true
	s[y] = true

	fmt.Println("size           :", len(s))
	fmt.Println("has x          :", s[x])
	fmt.Println("has stored y   :", s[y])
	fmt.Println("has fresh x + 1:", s[x+1])
	fmt.Println(s)
}
