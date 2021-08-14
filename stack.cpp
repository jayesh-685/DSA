#include "bits/stdc++.h"
using namespace std;

struct myStack {
    int* arr;
    int cap;    // capacity of stack;
    int top;    // index of topmost element

    myStack (int c) {
        cap = c;
        arr = new int [cap];
        top = -1;   // since stack is empty index of top most element is -1
    }

    // to add an element to the stack
    void push (int x) {
        // corner case if stack is full
        if (top == cap-1) { 
            cout << "stack at max capacity" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }

    // returning last element and removing it
    int pop () {
        // corner case if stack is empty
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }
        int last = arr[top];
        top--;
        return last;
    }

    int peek () {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }
        return arr[top];
    }

    int size () {
        return top+1;
    }

    bool isEmpty () {
        return (top == -1);
    }
};

int main () {
    myStack s (5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << s.peek() << " " << s.size() << endl;
    cout << s.pop() << " " << s.peek() << " " << s.size() << endl;
}