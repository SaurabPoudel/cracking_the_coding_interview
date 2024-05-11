#include <bits/stdc++.h>
#include "../BinaryTree.hpp"

using namespace std;

int maxDepth(Node *root)
{
    if (root == NULL)
        return 0;

    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);

    return 1 + max(lh, rh);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "Maximum Depth " << maxDepth(root);
}