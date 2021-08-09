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
    cout << endl;
}

// O(n)
// Node* insertBegin (Node* head, int data) {
//     Node* newHead = new Node (data);
//     if (head == NULL) {
//         newHead->next = newHead;
//     } else {
//         Node* curr = head;
//         while (curr->next != head)
//             curr = curr->next;
//         curr->next = newHead;
//         newHead->next = head;
//     }
//     return newHead;
// }

// O(1)  insert the new element after the head then exchange the head and newNode data
Node* insertBegin (Node* head, int data) {
    Node* newHead = new Node (head->data);
    head->data = data;
    newHead->next = head->next;
    head->next = newHead;
    return head;
}

int main () {
    Node *head=new Node(10);
	Node *temp1=new Node(20);
	Node *temp2=new Node(30);
	head->next=temp1;
	temp1->next=temp2;
    temp2->next = head;
    traverse(head);
    head = insertBegin(head, 5);
    traverse(head);
}