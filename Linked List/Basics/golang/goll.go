package main

import "fmt"

type node struct {
	value int
	next  *node
}

func inserttrail(head **node, value int) {
	newnode := &node{value: value}
	if *head == nil {
		*head = newnode
		return
	}
	curr := *head

	for curr.next != nil {
		curr = curr.next
	}
	curr.next = newnode
}

func inserHead(head **node, value int) {
	newNode := &node{value: value, next: *head}
	*head = newNode
}

func search(head *node, target int) bool {
	for head != nil {
		if head.value == target {
			return true
		}
		head = head.next
	}
	return false
}

func deleteByValue(head **node, target int) {
	if *head == nil {
		return
	}

	if (*head).value == target {
		*head = (*head).next
		return
	}

	prev := *head
	curr := (*head).next

	for curr != nil && curr.value != target {
		prev = curr
		curr = curr.next
	}

	if curr != nil {
		prev.next = curr.next
	}
}

func printlist(head *node) {
	for head != nil {
		fmt.Printf("%d-> ", head.value)
		head = head.next
	}

	fmt.Println("nil")
}

func main() {
	var head *node

	inserttrail(&head, 12)
	inserttrail(&head, 20)
	inserttrail(&head, 30)
	inserttrail(&head, 40)

	printlist(head)
}
