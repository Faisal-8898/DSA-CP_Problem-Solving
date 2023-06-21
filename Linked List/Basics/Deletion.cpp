#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

struct Node *deleteAtFirst(struct Node *head)
{

    struct Node *p = head;
    head = p->next;
    free(p);
    return head;
}

struct Node *deleteAtLast(struct Node *head)
{

    struct Node *p = head;
    struct Node *q = head->next;
    

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);

    return head;
}

struct Node *deleteElementWithValue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }

    return head;
}

struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;

    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    // ALLOCATE MEMORY FOR NODES IN THE LINKED LIST IN HEAP
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // link first and second nodes
    head->data = 7;
    head->next = second;

    // link second and third
    second->data = 11;
    second->next = third;

    //  terminate the list in third node
    third->data = 66;
    third->next = NULL;

    cout << "linked list before deletion" << endl;
    linkedListTraversal(head);
    cout << endl;

    cout << "linked list after deletion" << endl;

    // head = deleteAtFirst(head);
    // head= deleteAtIndex(head,1);
    // head = deleteAtLast(head);
    head = deleteElementWithValue(head, 11);
    linkedListTraversal(head);

    return 0;
}