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
    cout << endl;
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

Node* insertBegin (Node *head, int element) {
    // to add an element at start of linked list
    Node *newHead = new Node (element);
    newHead->next = head;
    return newHead;
}

Node* insertEnd (Node *head, int element) {
    Node *temp = new Node (element);
    if (head == NULL) {
        return temp;
    }
    Node *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}

// don't forget to deallocate memory of the nodes you are deleting
Node *deleteHead (Node *head) {
    if (head == NULL)
        return head;
    Node *temp = head->next;
    delete head;
    return temp;
}

Node *deleteTail (Node *head) {
    if (head == NULL)
        return NULL;
    if (head->next == NULL) {
        delete head;
        return NULL;
    }

    Node *curr = head;
    while (curr->next->next != NULL) {
        curr = curr->next;
    }
    delete curr->next;
    curr->next = NULL;
    return head;
    
}

Node *insertPos (Node *head, int data, int pos) {
    Node *newNode = new Node (data);

    // we have to change head if pos is 1
    if (pos == 1) {
        newNode->next = head;
        return newNode;
    }
    Node *curr = head;
    for (int i=1; i<pos-1 && curr != NULL; i++) {
        curr = curr->next;
    }
    if (curr == NULL)
        return head;
    newNode->next = curr->next;
    curr->next = newNode;
    return head;
}
int main() 
{ 
    // simple implementation
    // Node *head=new Node(10);
	// Node *temp1=new Node(20);
	// Node *temp2=new Node(30);
	// head->next=temp1;
	// temp1->next=temp2;
    // traverse(head);

    //compact implementation for 3 nodes
    // Node *head = new Node (10);
    // head->next = new Node (20);
    // head->next->next = new Node (30);
    //traverse(head);
    //recursionTraverse(head);    
    // even after using the traverse function we still get 10 20 30 from the next line because a copy of the pointer is made and the original pointer stays at the same position
    //cout << head->data << " " << head->next->data << " " << head->next->next->data << endl;
    // Node *head = NULL;
    // head = insertBegin(head, 5);
    // head = insertBegin(head, 10);
    // head = insertBegin(head, 15);
    // head = insertBegin(head, 20);
    // traverse(head);

    Node *head = NULL;
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 40);
    traverse(head);
    //head = deleteHead(head);
    //head = deleteTail(head);
    head = insertPos(head, 25, 6);
    traverse(head);
    return 0;
} 
