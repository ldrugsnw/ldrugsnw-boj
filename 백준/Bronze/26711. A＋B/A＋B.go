package main

import (
    "fmt"
    "math/big"
)

func main() {
    var a, b string
    fmt.Scanln(&a)
    fmt.Scanln(&b)

    bigA := new(big.Int)
    bigB := new(big.Int)

    bigA.SetString(a, 10)
    bigB.SetString(b, 10)

    sum := new(big.Int)
    sum.Add(bigA, bigB)

    fmt.Println(sum.String())
}
