#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* hello = head;
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    while (hello->next != nullptr && hello != nullptr) {
        if (hello->val == hello->next->val) {
            ListNode* hello1 = hello->next;
            hello->next = hello1->next;
            delete hello1;
        } else
            hello = hello->next;
    }
    return head;
}

// Function to create a new node and insert it at the end of the linked list
void insertNode(ListNode*& head, int value) {
    ListNode* newNode = new ListNode(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        ListNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the linked list
void display(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    ListNode* head = nullptr;

    // Insert nodes into the linked list
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 3);
    insertNode(head, 3);
    insertNode(head, 4);

    cout << "Original linked list: ";
    display(head);

    // Remove duplicates
    head = deleteDuplicates(head);

    cout << "Linked list after removing duplicates: ";
    display(head);

    return 0;
}
