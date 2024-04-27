#include <bits/stdc++.h>
#include "BinaryTree.hpp"

using namespace std;
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
}