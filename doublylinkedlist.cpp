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

Node* insertBegin (Node* head, int data) {
    Node* newNode = new Node (data);
    if (head == NULL) {
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

Node* insertEnd (Node* head, int data) {
    Node* newNode = new Node (data);
    if (head == NULL)
        return newNode;
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Node* reverseDLL (Node* head) {
//     if (head == NULL)
//         return head;
//     int count = 1;
//     Node* begin = head;
//     Node* end = head;
//     while (end->next != NULL) {
//         count++;
//         end = end->next;
//     }
//     for (int i=1; i<=count/2; i++) {
//         int temp = begin->data;
//         begin->data = end->data;
//         end->data = temp;
//         begin = begin->next;
//         end = end->prev;
//     }
//     return head;
// }

Node* reverseDLL (Node* head) {
    if (head == NULL || head->next == NULL)
        return head;
    Node* curr = head;
    Node* temp = NULL;
    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    return temp->prev;
}

int main () {
    // Node *head = new Node (10);
    // head->next = new Node (20);
    // head->next->prev = head;
    // head->next->next = new Node (30);
    // head->next->next->prev = head->next;
    // traverse(head);
    Node* head = NULL;
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 40);
    head = insertEnd(head, 50);
    traverse(head);
    head = reverseDLL(head);
    traverse(head);

    Node* temp = NULL;
    temp = reverseDLL(temp);
    traverse(temp);
    temp = insertEnd(temp, 10);
    temp = reverseDLL(temp);
    traverse(temp);
}
