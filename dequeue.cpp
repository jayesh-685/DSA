// doubly ended queue

#include "bits/stdc++.h"
using namespace std;

// linked list implementation

struct Node {
    int data;
    Node* next;
    Node (int x) {
        data = x;
        next = NULL;
    }
};


// array implementation

struct myDequeue {
    int* arr;
    int size, capacity;

    myDequeue (int cap) {
        capacity = cap;
        arr = new int [capacity];
        size = 0;
    }

    bool isEmpty () {
        return (size == 0);
    }

    bool isFull () {
        return (size == capacity);
    }

    void insertFront (int x) {
        if (isFull())
            cout << "Array is full" << endl;
        else {
            for (int i=size; i>0; i--)
                arr[i] = arr[i-1];
            arr[0] = x;
            size++;
        }
    }

    void insertEnd (int x) {
        if (isFull())
            cout << "Array is full" << endl;
        else {
            arr[size++] = x;
        }
    }

    void deleteFront () {
        if (isEmpty())
            cout << "Array is empty" << endl;
        else {
            for (int i=0; i<size-1; i++)
                arr[i] = arr[i+1];
            size--;
        }
    }

    void deleteRear () {
        if (isEmpty())
            cout << "Array is empty" << endl;
        else
            size--;
    }

    int getFront () {
        if (size == 0)
            return INT_MIN;
        return arr[0];
    }

    int getRear () {
        if (size == 0)
            return INT_MIN;
        return arr[size-1];
    }

    int getSize () {
        return size;
    }
};

int main () {
    /* myDequeue dq (10);
    cout << dq.isEmpty() << " " << dq.isFull() << endl;
    dq.insertFront(5);
    dq.insertFront(10);
    dq.insertEnd(50);
    dq.insertEnd(40);
    cout << dq.getFront() << " " << dq.getRear() << " " << dq.getSize() << endl;
    cout << dq.isEmpty() << " " << dq.isFull() << endl; */
}