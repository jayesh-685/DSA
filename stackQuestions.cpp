#include "bits/stdc++.h"
using namespace std;

bool matching (char a, char b) {
    return ((a=='(' && b==')') || (a=='[' && b==']') || (a=='{' && b=='}'));
}
bool balancedParenthesis (const string &s) {
    stack <char> parenthesis;
    for (int i=0; i<s.length(); i++) {
        if (s[i]=='[' || s[i]=='{' || s[i]=='(')
            parenthesis.push(s[i]);
        else {
            if (parenthesis.empty()) 
                return false;
            else if (!matching(parenthesis.top(), s[i])) 
                return false;
            else 
                parenthesis.pop();
        }
    }
    if (parenthesis.empty())
        return true;
    return false;
}

// implement 2 stacks in one array
// we can start one stack from start of array and other one from end of array

struct twoStacks {
    int* arr;
    int top1, top2;
    int cap;

    twoStacks (int x) {
        arr = new int [x];
        cap = x;
        top1 = -1;
        top2 = x;
    }

    void push1 (int n) {
        if (top1 < top2-1) {
            top1++;
            arr[top1] = n;
        } else 
            cout << "Overflow" << endl;
    }

    void push2 (int n) {
        if (top1 < top2-1) {
            top2--;
            arr[top2] = n;
        } else 
            cout << "Overflow" << endl;
    }

    int pop1 () {
        if (top1 == -1)
            return INT_MIN;
        else {
            int temp = arr[top1];
            top1--;
            return temp;
        }
    }

    int pop2 () {
        if (top2 == cap)
            return INT_MAX;
        else {
            int temp = arr[top2];
            top2++;
            return temp;
        }
    }
};

// implement k stacks in an array
// we use three arrays, one to store elements, one to store prev of each element and one to store top of each head. We store index of free space in a separate variable
// each stack might not be contiguous, like we may have 3 elements of stack 0 then 2 elements of stack 2 and two more elements of stack 0

struct kStacks {
    int* arr;   // array to store elements
    int* prev;  // to store index of prev of each element
    int* top;   // to store top of each stack
    int freeTop;    // to keep track of free stack
    int k, cap;     // no of stacks and capacity

    kStacks (int stacks, int n) {
        freeTop = 0;
        k = stacks;
        cap = n;
        arr = new int [n];
        prev = new int [n];
        // we inititalize it this way so that is stores the index of next element and we can use it to update freetop
        for (int i=0; i<n-1; i++) {
            prev[i] = i+1;
        }
        prev[n-1] = -1;
        top = new int [stacks];
        for (int i=0; i<k; i++)
            top[i] = -1;
    }

    void push (int x, int sn) {
        int i = freeTop;
        arr[i] = x;
        freeTop = prev[i];
        prev[i] = top[sn];
        top[sn] = i;
    }

    int pop (int sn) {
        int i = top[sn];
        top[sn] = prev[i];
        prev[i] = freeTop;
        freeTop = i;
        return arr[i];
    }
}; 

// given the stock price on each day, you have to calculate span for each day which is the no of days stock price was less or equal including that day
void stockSpan (int arr[], int n) {
    for (int i=0; i<n; i++) {
        int spanCount = 1;
        for (int j=i-1; j>=0 && arr[j] <= arr[i]; j--) 
            spanCount++;
        cout << spanCount << " ";
    }
}

int main () {
    /* string s;
    cin >> s;
    cout << balancedParenthesis(s) << endl; */

    /* twoStacks s (10);
    s.push1(5);
    s.push2(50);
    cout << s.pop1() << " " << s.pop2() << endl; */

    /* kStacks s (3, 10);
    s.push(5, 0);
    s.push(10, 0);
    s.push(15, 1);
    cout << s.pop(0) << endl;
    cout << s.pop(1) << endl;
    cout << s.pop(0) << endl; */

    int arr[] = {13, 15, 12, 14, 16, 8, 6, 4, 10, 30};
    stockSpan(arr, 10);
    
    return 0;
}