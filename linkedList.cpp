#include <bits/stdc++.h> 
using namespace std; 

struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

void traverse (Node *head) {
    Node *curr = head;
	while (curr != NULL) {
		cout << curr->data << endl;
		curr = curr->next;
	}
}

// output will be same even if use the below code and also linked list won't be changed
/*
void traverse (Node *head) {
    while (head != NULL) {
        cout << head->data << endl;
        head = head->next;
    }
}
*/

void recursionTraverse (Node *head) {
    if (head == NULL)
        return;
    cout << head->data << endl;
    recursionTraverse(head->next);
}

Node* insertAtStart (Node *head, int element) {
    Node *newHead = new Node (element);
    newHead->next = head;
    return newHead;
}

int main() 
{ 
    // // simple implementation
    Node *head=new Node(10);
	Node *temp1=new Node(20);
	Node *temp2=new Node(30);
	head->next=temp1;
	temp1->next=temp2;
	// cout<<head->data<<"-->"<<temp1->data<<"-->"<<temp2->data;

    //compact implementation for 3 nodes
    // Node *head = new Node (10);
    // head->next = new Node (20);
    // head->next->next = new Node (30);
    //traverse(head);
    //recursionTraverse(head);    
    // even after using the traverse function we still get 10 20 30 from the next line because a copy of the pointer is made and the original pointer stays at the same position
    //cout << head->data << " " << head->next->data << " " << head->next->next->data << endl;
    traverse(insertAtStart(head, 5));
    return 0;
} 
