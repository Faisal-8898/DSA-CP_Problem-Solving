package main

func isValid(s string) bool {
	stack := []rune{}
	
    p := map[rune]rune{
        ')' : '(',
        '}' : '{',
        ']' : '[',
    }

    for _, ch := range s {
        if val, ok := p[ch]; ok {
            if len(stack) == 0 || stack[len(stack)-1] != val {
                return false
            }
            stack = stack[:len(stack)-1]
        } else {
            stack = append(stack, ch)
        }
    }

    return len(stack) == 0
}
