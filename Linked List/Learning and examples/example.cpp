#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL; 
    }
};

void insertAtHead(Node *&head, int d)
{

    // NEW NODE CREATE
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void print(Node *head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data<< " ";
        /* code */
        temp = temp->next;
    }
}


int main()
{
    Node *node1 = new Node(67);

    //HEAD POINTER TO NODE1
    Node* head = node1;
    print (head);

    insertAtHead(head , 12);
    print (head);

}