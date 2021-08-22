#include "bits/stdc++.h"
using namespace std;

struct myQueue {
    int* arr;
    int front, rear;

    myQueue (int x) {
        arr = new int [x];
        front = rear = -1;
    }

    void enqueue (int n) {
        if (front == -1) {
            front = rear = 0;
            arr[front] = n;
        } else {
            arr[++rear] = n;
        }
    }

    int dequeue () {
        if (front == rear) {
            int temp = arr[front];
            front = rear = -1;
            return temp;
        } else {
            int temp = arr[front];
            front++;
            return temp;
        }
    }
};