#include <bits/stdc++.h>
#include "../BinaryTree.hpp"

using namespace std;

void printPreOrder(Node *node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    printPreOrder(node->left);
    printPreOrder(node->right);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    printPreOrder(root);
}