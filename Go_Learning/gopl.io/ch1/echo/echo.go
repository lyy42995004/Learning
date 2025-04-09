package main

import (
	"fmt"
	"os"
	"strings"
)

// echo3
func main() {
	fmt.Println(strings.Join(os.Args[1:], " "));
}

// // echo2
// func main() {
// 	s, sep := "", ""
// 	for _, arg := range os.Args[1:] {
// 		s += sep + arg;
// 		sep = " ";
// 	}
// 	fmt.Println(s);
// }

// // echo1
// func main() {
// 	var s, sep string
// 	for i := 1; i < len(os.Args); i++ {
// 		s += sep + os.Args[i];
// 		sep = " ";
// 	}
// 	fmt.Println(s);
// }