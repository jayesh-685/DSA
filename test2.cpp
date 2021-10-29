#include "bits/stdc++.h"
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};
vector<vector<int>> levelOrder(Node *node)
{
    vector<vector<int>> v;
    if (node == NULL)
        return v;
    vector <int> temp;
    
}

int main()
{
    cout << "Hello world!" << endl;
}