#include "bits/stdc++.h"
using namespace std;

struct myQueue {
    int* arr;
    int size, cap;

    myQueue (int x) {
        arr = new int [x];
        size = 0;
        cap = x;
    }

    bool isEmpty () {
        return (size==0);
    }

    bool isFull () {
        return (size==cap);
    }
    void enqueue (int n) {
        if (isFull())
            return;
        arr[size] = n;
        size++;
    }

    void dequeue () {
        if (isEmpty()) 
            return;
        for (int i=0; i<size-1; i++)
            arr[i] = arr[i+1];
        size--;
    }

    int getFront () {
        if (isEmpty())
            return INT_MIN;
        return arr[0];
    }

    int getRear () {
        if (isEmpty())
            return INT_MIN;
        return arr[size-1];
    }
        
};

int main () {
    myQueue q (10);
    cout << q.isEmpty() << endl;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(20);
    cout << q.isEmpty() << " " << q.isFull() << endl;
    cout << q.getFront() << " " << q.getRear() << endl;
    q.dequeue();
    cout << q.getFront() << " " << q.getRear() << endl;
}