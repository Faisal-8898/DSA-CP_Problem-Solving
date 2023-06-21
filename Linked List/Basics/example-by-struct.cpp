#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void linkedListTraversal( struct Node* ptr){
    while(ptr!=NULL){
    cout<< ptr-> data<< " ";
    ptr = ptr -> next;
    }
}

int main(){
struct Node *head;
struct Node *second;
struct Node *third;


//ALLOCATE MEMORY FOR NODES IN THE LINKED LIST IN HEAP
head = (struct Node*) malloc(sizeof(struct Node));
second = (struct Node*) malloc(sizeof(struct Node));
third = (struct Node*) malloc (sizeof(struct Node));    
 
 //link first and second nodes
 head -> data= 7;
 head -> next=second;

 // link second and third
 second -> data= 11;
 second -> next = third;

//  terminate the list in third node
third-> data= 66;
third -> next = NULL;

linkedListTraversal(head);

return 0;

}