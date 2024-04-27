#include <bits/stdc++.h>
#include "../BinaryTree.hpp"

using namespace std;

vector<int> inorderTraversal(Node *root)
{
    vector<int> inorder;
    Node *node = root;
    stack<Node *> st;
    while (true)
    {
        if (node != NULL)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty())
                break;
            node = st.top();
            st.pop();
            inorder.push_back(node->data);
            node = node->right;
        }
    }
    return inorder;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    for (const int elem : inorderTraversal(root))
    {
        cout << elem << " ";
    }
}