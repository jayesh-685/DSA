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

int main () {
    /* string s;
    cin >> s;
    cout << balancedParenthesis(s) << endl; */

    twoStacks s (10);
    s.push1(5);
    s.push2(50);
    cout << s.pop1() << " " << s.pop2() << endl;
    
    return 0;
}