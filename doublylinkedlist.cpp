#include "bits/stdc++.h"
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node (int d) {
        data = d;
        prev = NULL;
        next = NULL;
    }
};

void traverse (Node* head) {
    while (head != NULL) {
        cout << head->data << endl;
        head = head->next;
    }
}

int main () {
    // Node *head = new Node (10);
    // head->next = new Node (20);
    // head->next->prev = head;
    // head->next->next = new Node (30);
    // head->next->next->prev = head->next;
    // traverse(head);
    Node *head = new Node (10);
    Node *temp1 = new Node (20);
    Node *temp2 = new Node (30);
    head->next = temp1;
    temp1->prev = head;
    temp1->next = temp2;
    temp2->prev = temp1;
    traverse(head);
}
