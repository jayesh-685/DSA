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

struct Node {
    int key;
    Node* left;
    Node* right;
    Node (int k) {
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

void inorderTraverse (Node* root) {
    if (root == NULL) 
        return;
    inorderTraverse(root->left);
    cout << root->key << " ";
    inorderTraverse(root->right);   
}

void preorderTraverse (Node* root) {
    if (root == NULL) 
        return;
    cout << root->key << " ";
    preorderTraverse(root->left);
    preorderTraverse(root->right);   
}

void postorderTraverse (Node* root) {
    if (root == NULL) 
        return;
    postorderTraverse(root->left);
    postorderTraverse(root->right); 
    cout << root->key << " ";
}

// calculate height of binary tree
// call function for left part, then for right part find max of them and return adding one to them  
int getHeight (Node* root) {
    if (root == NULL)
        return 0;
    else
        return max(getHeight(root->left), getHeight(root->right)) + 1;
}
// h+1 function calls so aux space required is O(h)

// print nodes at distance k

void printNodesK (Node* root, int k) {
    if (root == NULL)
        return;
    if (k == 0) {
        cout << root->key << " ";
        return;
    } else {
        printNodesK(root->left, k-1);
        printNodesK(root->right, k-1);
    }
}
// time complexity is O(n) and aux space required is O(h) where h is height of tree

// level order traversal
// print nodes in horizontal fashion like first print all nodes at level 1 (left to right) then move to level 2 and so on

// one way is to first calculate height of binary tree and then call print nodes at k dist funcion for each time... O(hn)

// optimised way is too use a queue. Push the root, them pop and print it and then push its child nodes (if they exists) and continue it till the queue becomes empty;

void levelOrderTraversal (Node* root) {
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
// time complexity is theta(n) because we enqueue and dequeue each node exactly once and it takes theta(1) for both these operations
// auxillary space: in queue we will have at most one level at a time so auxillary space required is theta(w) where w is width of binary tree 

int main () {
    Node* root = new Node (10);
    root->left = new Node (5);
    root->right = new Node (20);
    root->left->left = new Node (2);
    root->left->right = new Node (7);
    root->right->left = new Node (10);
    root->right->right = new Node (30);
    root->left->left->left = new Node (1);
    //postorderTraverse(root);
    //cout << getHeight(root) << endl;
    // printNodesK(root, 2);
    // cout << endl;
    levelOrderTraversal(root);
}