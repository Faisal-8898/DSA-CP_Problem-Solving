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

void insertPosition(int value, int position)
{

    struct node *nnode = new node;
    struct node *temp, *temp1;
    nnode->data = value;
    nnode->next = nullptr;

    if (head == NULL)
    {
        head = nnode;
        tail = nnode;
    }
    else
    {
        temp = head;
        int i = 1;
        while (i < position && temp != NULL)
        {
            temp1 = temp;
            temp = temp->next;
            i++;
        }
        nnode->next = temp;
        temp1->next = nnode;
    }
}

void Display(node *&head)
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

    insertPosition(999, 3);
    Display(head);
}