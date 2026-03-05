package main

func twoSum(nums []int, target int) []int {

    m := make(map[int]int)
    for index, value := range nums {
        m[value] = index
    }

    for i, num := range nums {
        complement := target - num
        if j, ok := m[complement]; ok && j != i {
            return []int{i, j}
        }
    }

	return nil
}