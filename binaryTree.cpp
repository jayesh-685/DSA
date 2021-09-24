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

int main () {
    Node* root = new Node (10);
    root->left = new Node (5);
    root->right = new Node (20);
    root->left->left = new Node (2);
}