#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *head = nullptr;
struct node *tail = nullptr;

void insertNewNode(int value)
{
    struct node *nnode = new node;
    nnode->data = value;
    nnode->next = nullptr;

    if (head == NULL)
    {
        head = nnode;
        tail = nnode;
    }
    else
    {
        tail->next = nnode;
        tail = nnode;
    }
}

void deleteNodeEnd()
{
    struct node *temp, *temp1;
    temp = head;
    while (temp ->next!= NULL)
    {
        temp1 = temp;
        temp = temp->next;
    }
    temp1->next=nullptr;
    free(temp);
}

void Display()
{

    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    insertNewNode(7);
    insertNewNode(45);
    insertNewNode(13);
    insertNewNode(84);
    insertNewNode(23);
    deleteNodeEnd();
    Display();
}