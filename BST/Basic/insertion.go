package main

import "fmt"

type node struct {
	value int
	left  *node
	right *node
}

func insert(n *node, val int) *node {
	if n == nil {
		return &node{value: val}
	}
	if val <= n.value {
		n.left = insert(n.left, val)
	} else {
		n.right = insert(n.right, val)
	}
	return n
}

func preOrder(n *node) {
	if n == nil {
		return
	}
	fmt.Print(n.value, " ")
	preOrder(n.left)
	preOrder(n.right)
}

func main() {
	var root *node
	s := []int{10, 1, 2, 5, 34, 3, 413, 1, 341, 3, 41, 41, 341}

	for _, val := range s {
		root = insert(root, val)
	}

	preOrder(root)
	fmt.Println()
}
