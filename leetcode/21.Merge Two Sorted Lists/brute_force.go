/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
    if (list1 == nil){
        return list2
    }  
    if (list2 == nil) {
        return list1
    }

    dummy := &ListNode{}
    head := dummy

    for list1 != nil && list2 != nil {
        if list1.Val < list2.Val {
            head.Next = &ListNode{Val: list1.Val}
            head = head.Next
            list1 = list1.Next
        } else {
            head.Next = &ListNode{Val: list2.Val}
            head = head.Next
            list2 = list2.Next
        }
    }

    for list1 != nil {
           head.Next = &ListNode{Val: list1.Val}
           head = head.Next
           list1 = list1.Next
    }

    for list2 != nil {
        head.Next = &ListNode{Val: list2.Val}
        head = head.Next
        list2 = list2.Next
    }

    return dummy.Next;
}