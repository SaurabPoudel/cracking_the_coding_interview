#include <bits/stdc++.h>
#include "../BinaryTree.hpp"

using namespace std;

int height(Node *root, int &diameter)
{
    if (root == NULL)
        return 0;

    int lh = height(root->left, diameter);
    int rh = height(root->right, diameter);
    diameter = max(diameter, lh + rh);
    return 1 + max(lh, rh);
}

int findDiameter(Node *root)
{
    int diameter = 0;
    height(root, diameter);
    return diameter;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right = new Node(4);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "Diameter of Binary Tree " << findDiameter(root);
}