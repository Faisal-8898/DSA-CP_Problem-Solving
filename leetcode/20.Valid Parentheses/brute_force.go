package main

func isValid(s string) bool {
	stack := []rune{}
	for _, ch := range s {
		if ch == '(' || ch == '{' || ch == '[' {
			stack = append(stack, ch)
		} else {

			if len(stack) == 0 {
				return false
			}

			if ch == ')' && stack[len(stack)-1] == '(' {
				stack = stack[:len(stack)-1]
			} else if ch == '}' && stack[len(stack)-1] == '{' {
				stack = stack[:len(stack)-1]
			} else if ch == ']' && stack[len(stack)-1] == '[' {
				stack = stack[:len(stack)-1]
			} else {
				return false
			}
		}
	}
	return len(stack) == 0
}
