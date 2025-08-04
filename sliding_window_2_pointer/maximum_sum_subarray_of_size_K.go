package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var scanner = bufio.NewScanner(os.Stdin)

func scanLine() []string {
	scanner.Scan()
	return strings.Fields(scanner.Text())
}

func toInt(s string) int {
	i, _ := strconv.Atoi(s)
	return i
}

func main() {
	scanner.Split(bufio.ScanLines)

	n := toInt(scanLine()[0])

	for i := 0; i < n; i++ {
		line1 := scanLine()
		mSum := 0

		an, k := toInt(line1[0]), toInt(line1[1])

		numsStr := scanLine()
		arr := make([]int, an)
		for i := 0; i < an; i++ {
			arr[i] = toInt(numsStr[i])
		}
		wSum := 0
		for i := 0; i < k; i++ {
			wSum += arr[i]
		}

		for i := k; i < an; i++ {
			wSum += arr[i] - arr[i-k]
			if wSum > mSum {
				mSum = wSum
			}
		}

		fmt.Println(mSum)
	}
}
