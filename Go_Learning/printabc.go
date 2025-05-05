package main

import (
	"fmt"
	"runtime"
	"sync"
	"sync/atomic"
)

var turn int32 = 0 // 0: a, 1: b, 2: c

func printCharAtomic(char string, myTurn int32, n int, wg *sync.WaitGroup) {
	defer wg.Done()
	for i := 0; i < n; i++ {
		for atomic.LoadInt32(&turn) != myTurn {
			runtime.Gosched() // 出让 CPU，防死循环占满
		}
		fmt.Print(char)
		atomic.StoreInt32(&turn, (myTurn+1)%3)
	}
}

func main() {
	n := 10
	var wg sync.WaitGroup
	wg.Add(3)

	go printCharAtomic("a", 0, n, &wg)
	go printCharAtomic("b", 1, n, &wg)
	go printCharAtomic("c", 2, n, &wg)

	wg.Wait()
	fmt.Println()
}