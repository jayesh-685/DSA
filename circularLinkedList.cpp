#include "bits/stdc++.h"
using namespace std;

//next of last node is head/first node
// can be both singly linked and doubly linked

struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};
// in a single element circular linked list head->next = head;

void traverse (Node* head) {
    if (head == NULL)
        return;
    Node* curr = head;
    do {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
    
}

int main () {
    Node *head=new Node(10);
	Node *temp1=new Node(20);
	Node *temp2=new Node(30);
	head->next=temp1;
	temp1->next=temp2;
    temp2->next = head;
    traverse(head);
}