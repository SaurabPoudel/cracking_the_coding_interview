#include <bits/stdc++.h>
#include "../BinaryTree.hpp"

using namespace std;

/**
 * Slight tweak to function returning height of the binary tree to avoid O(N^2) complexity
 * @param Node *root
 * @returns -1 if BT is not balanced and height if BT is balanced
 */
int balancedHeight(Node *root)
{
    if (root == NULL)
        return 0;

    int lh = balancedHeight(root->left);
    int rh = balancedHeight(root->right);

    if (lh == -1 || rh == -1 || abs((lh - rh) > 1))
        return -1;

    return 1 + max(lh, rh);
}

bool isBalanced(Node *root)
{
    return balancedHeight(root) != -1;
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

    if (isBalanced(root))
        cout << "Balanced";
    else
        cout << "Not Balanced";
}