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

int main () {
    string s;
    cin >> s;
    cout << balancedParenthesis(s) << endl;
    /* stack <char> s;
    s.push('a');
    cout << s.top() << endl;
    string str = "abcd";
    cout << str.length() << endl;
    if (str[0] == s.top())
        cout << true << endl; */
}