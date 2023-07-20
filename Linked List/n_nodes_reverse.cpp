#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *next;
};

node *head = nullptr, *tail = nullptr;

void insertNode(int value){
    struct node * newNode = new node;
    newNode->data = value;
    newNode->next = nullptr;


    if(head == NULL){
        head = newNode;
        tail = newNode;
    }


    else{
        tail->next = newNode;
        tail = newNode;

    }
}

void displayList(node* head){
    struct node* curr = head ;
    while( curr!= NULL){
        cout<< curr->data<< " ";
        curr = curr->next;
    }

}

node* reverse(node* head){
    node* cur = head;
    node* pre = nullptr;
    while(cur!=NULL){
        node * temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur =temp;

    }
    return pre;
}

int main(){
insertNode(9);
   insertNode(3);
   insertNode(0);
   node * HEAD = reverse(head);


   displayList(HEAD);
}