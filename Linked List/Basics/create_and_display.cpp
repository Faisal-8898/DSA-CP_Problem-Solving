#include <bits/stdc++.h>
using namespace std;

// DECLARE STRUCTURE OF SSL NODE
struct node
{
    int value;
    node *next;
};

// ASSIGNING HEAD NULL
struct node *head = nullptr, *tail = nullptr;

// FUNCTION WHICH CREATE NEW NODE
void insertNode(int data)
{

    struct node *newNode = new node;
    newNode->value = data;
    newNode->next = nullptr;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }

    else
    {

        tail->next = newNode;
        tail = newNode;
    }
}

void displayList()
{
    node *curr = head;
    while (curr != NULL)
    {
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    insertNode(2);
    insertNode(4);
    insertNode(7);

    displayList();
}
