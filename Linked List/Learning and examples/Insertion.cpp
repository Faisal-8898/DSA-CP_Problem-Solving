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

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;

    return ptr;
}

struct Node *insertAtLast(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head;   

    while (p->next != NULL)
    {
        p = p->next;
    }

     p-> next= ptr;
     ptr-> next = NULL;

    return head;
}

struct Node *insertAtNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head;   
    

     ptr-> next = prevNode->next;
     prevNode->next= ptr;

    return head;
}

struct Node * insertAtIndex(struct Node *head , int data , int index){
    struct Node * ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr -> data = data;
    struct Node * p = head;
    int i = 0;
    while ( i!= index-1){
        p = p->next;
        i++;
    }

    ptr-> next = p->next;
    p-> next = ptr;

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

    // linkedListTraversal(head);
    // head = insertAtFirst(head, 56);
    // head= insertAtIndex(head , 78, 1);
    // head= insertAtLast(head , 78);
    // head= insertAtNode(head, second, 1000);
    linkedListTraversal(head);


    return 0;
}