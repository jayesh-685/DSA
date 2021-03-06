/*
A Tree is a non-linear data structure where each node is connected to a number of nodes with the help of pointers or references.
Basic Tree Terminologies:
Root: The root of a tree is the first node of the tree. 
Edge: An edge is a link connecting any two nodes in the tree. 
Siblings: The children nodes of same parent are called siblings. That is, the nodes with same parent are called siblings. 
Leaf Node: A node is said to be the leaf node if it has no children. 
Height of a Tree: Height of a tree is defined as the total number of levels in the tree or the length of the path from the root node to the node present at the last level. 

Binary Tree
A Tree is said to be a Binary Tree if all of its nodes have atmost 2 children. That is, all of its node can have either no child, 1 child, or 2 child nodes.
*/

#include "bits/stdc++.h"
using namespace std;

// binary tree implementation

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

// tree traversal

/*
Following are the generally used ways for traversing trees:

Inorder (Left, Root, Right)  
Preorder (Root, Left, Right)
Postorder (Left, Right, Root)

*/

void inorderTraverse(Node *root)
{
    if (root == NULL)
        return;
    inorderTraverse(root->left);
    cout << root->key << " ";
    inorderTraverse(root->right);
}

void preorderTraverse(Node *root)
{
    if (root == NULL)
        return;
    cout << root->key << " ";
    preorderTraverse(root->left);
    preorderTraverse(root->right);
}

void postorderTraverse(Node *root)
{
    if (root == NULL)
        return;
    postorderTraverse(root->left);
    postorderTraverse(root->right);
    cout << root->key << " ";
}

// calculate height of binary tree
// call function for left part, then for right part find max of them and return adding one to them
int getHeight(Node *root)
{
    if (root == NULL)
        return 0;
    else
        return max(getHeight(root->left), getHeight(root->right)) + 1;
}
// h+1 function calls so aux space required is O(h)

// print nodes at distance k

void printNodesK(Node *root, int k)
{
    if (root == NULL)
        return;
    if (k == 0)
    {
        cout << root->key << " ";
        return;
    }
    else
    {
        printNodesK(root->left, k - 1);
        printNodesK(root->right, k - 1);
    }
}
// time complexity is O(n) and aux space required is O(h) where h is height of tree

// level order traversal
// print nodes in horizontal fashion like first print all nodes at level 1 (left to right) then move to level 2 and so on

// one way is to first calculate height of binary tree and then call print nodes at k dist funcion for each time... O(hn)

// optimised way is too use a queue. Push the root, them pop and print it and then push its child nodes (if they exists) and continue it till the queue becomes empty;

// time complexity is theta(n) because we enqueue and dequeue each node exactly once and it takes theta(1) for both these operations
// auxillary space: in queue we will have at most one level at a time so auxillary space required is theta(w) where w is width of binary tree

// all in one line
/* void levelOrderTraversal (Node* root) {
    if (root == NULL)
        return;

    queue <Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        cout << curr->key << " ";
        q.pop();
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
    cout << endl;
}
*/

// line by line
void levelOrderTraversal(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (q.size() > 1)
    {
        Node *curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << curr->key << " ";
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
    cout << endl;
}

// my way, not the best
/* void levelOrderTraversal (Node* root) {
    if (root == NULL)
        return;

    queue <Node*> q;
    q.push(root);
    int count = 1, nextCount = 0;   // using them to print a newline when a level is printed

    while (!q.empty()) {
        Node* curr = q.front();
        cout << curr->key << " ";
        q.pop();
        count--;
        if (curr->left != NULL) {
            q.push(curr->left);
            nextCount++;
        }
        if (curr->right != NULL) {
            q.push(curr->right);
            nextCount++;
        }
        if (count == 0) {
            cout << endl;
            count = nextCount;
            nextCount = 0;
        }
    }
    cout << endl;
}
*/
// time complexity is theta(n+h) but since h<n so time complexity is theta(n)
// aux space is still theta(h) because max size of queue is h+1 and 1 is a constant

// one more way, using two loops

void levelOrderTraversal2(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            Node *curr = q.front();
            q.pop();
            cout << curr->key << " ";
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
        cout << endl;
    }
}

int sizeOfTree(Node *root)
{
    if (root == NULL)
        return 0;
    else
        return sizeOfTree(root->left) + sizeOfTree(root->right) + 1;
}
// since we visit each node exactly once, time complexity is O(n)
// at any moment, the maximum no of funcion calls would be h+1 where h is height of binray tree (+ 1 because of root = null case) so aux space required is O(h)

// iterative solution

int IsizeOfTree(Node *root)
{
    if (root == NULL)
        return 0;

    queue<Node *> q;
    q.push(root);
    int size = 1;

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        if (curr->left != NULL)
        {
            q.push(curr->left);
            size++;
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
            size++;
        }
    }
    return size;
}
// time complexity is O(n) and aux space required is O(w) w = width of binary tree

int getMax(Node *root)
{
    if (root == NULL)
        return INT_MIN;
    return max(root->key, max(getMax(root->left), getMax(root->right)));
}
// time complexity is O(n) and aux space required is O(h)

// can also be done iteratively like level order traversal using a queue
// time complexity is O(n) and aux space required is O(w)

// print left view of binary tree
// print the left most element at each level

// iterative solution
void leftView(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(NULL);
    q.push(root);

    while (q.size() > 1)
    {
        Node *curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            q.push(NULL);
            cout << q.front()->key << endl;
            continue;
        }
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
}
// theta(n) theta(w)

// can also do using 2 loops, just print only when i = 0
void leftView2(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (i == 0)
                cout << curr->key << endl;
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
    }
}

// recursive solution
// we will use preorder traversal for this

int maxLevel = 0;

void printLeftView(Node *root, int currLevel)
{
    if (root == NULL)
        return;

    if (currLevel > maxLevel)
    {
        cout << root->key << endl;
        maxLevel = currLevel;
    }
    printLeftView(root->left, currLevel + 1);
    printLeftView(root->right, currLevel + 1);
}

void leftViewRecursive(Node *root)
{
    printLeftView(root, 1);
}

// if for every node its value is equal to sum of left and right node (if they exixst) then tree is said to satisfy children sum property
bool childrenSum(Node *root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return true;
    int sum = 0;
    if (root->left != NULL)
        sum += root->left->key;
    if (root->right != NULL)
        sum += root->right->key;
    return sum == root->key && childrenSum(root->left) && childrenSum(root->right);
}
// O(n) O(h)

// check for balanced tree
// tree is balanced if the diff in height of left and right sub tree is atmost 1
// we use the previously done getHeight function

bool isBalanced(Node *root)
{
    if (root == NULL)
        return true;
    int leftH = getHeight(root->left);
    int rightH = getHeight(root->right);
    return (abs(leftH - rightH) <= 1 && isBalanced(root->left) && isBalanced(root->right));
} // O(n^2) because we are calling getHeight function for each node

// can be optimized if we get size of tree and check if it is balanced or not in a single function call, so we can return a pair or we can return -1 if tree is unbalanced and otherwise return height of tree(>=0)

int isBalanced2(Node *root)
{
    if (root == NULL)
        return 0;
    int leftH = isBalanced2(root->left);
    int rightH = isBalanced2(root->right);

    return (leftH != -1 && rightH != -1 && abs(leftH - rightH) <= 1) ? max(leftH, rightH) + 1 : -1;
}
// traversing every node exactly once so O(n)

int maxWidth(Node *root)
{
    if (root == NULL)
        return 0;
    int count = 0;
    int maxCount = 0;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        for (int i = 0; i < q.size(); i++)
        {
            Node *curr = q.front();
            q.pop();
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
        int count = q.size();
        maxCount = max(count, maxCount);
    }
    return maxCount;
} // theta(n) theta(w)

// convert binary tree to doubly linked list, use left pointer as prev and right as next, use inorder traversal to determine order of list, use the space already allocated for tree

int main()
{
    Node *root = new Node(30);
    root->left = new Node(12);
    root->right = new Node(18);
    root->left->left = new Node(6);
    root->left->right = new Node(6);
    root->right->left = new Node(6);
    root->right->right = new Node(12);
    root->left->left->left = new Node(6);
    //postorderTraverse(root);
    //cout << getHeight(root) << endl;
    // printNodesK(root, 2);
    // cout << endl;
    //levelOrderTraversal2(root);
    //cout << IsizeOfTree(root) << endl;
    //cout << getMax(root) << endl;
    //leftViewRecursive(root);
    //cout << childrenSum(root);
    //cout << isBalanced2(root);
    cout << maxWidth(root) << endl;
}