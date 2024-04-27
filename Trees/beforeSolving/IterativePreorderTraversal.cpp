#include <bits/stdc++.h>
#include "../BinaryTree.hpp"

using namespace std;

vector<int> preorderTraversal(Node *root)
{
    vector<int> preorder;
    if (root == NULL)
        return preorder;
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        root = st.top();
        st.pop();
        preorder.push_back(root->data);
        if (root->left != NULL)
            st.push(root->left);
        if (root->right != NULL)
            st.push(root->right);
    }
    return preorder;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    for (const int elem : preorderTraversal(root))
    {
        cout << elem << " ";
    }
}