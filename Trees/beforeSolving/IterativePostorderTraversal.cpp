/**
 * lets implement the iterative post order traversal with the help of two stack
 */

#include <bits/stdc++.h>
#include "../BinaryTree.hpp"

using namespace std;

/**
 * Using two stacks
 * @param Node*
 * @returns vector<int>
 */
vector<int> postorderTraversal1(Node *root)
{
    vector<int> postorder;
    if (root == NULL)
        return postorder;
    stack<Node *> st1, st2;
    st1.push(root);

    while (!st1.empty())
    {
        root = st1.top();
        st1.pop();
        st2.push(root);
        if (root->left != NULL)
        {
            st1.push(root->left);
        }
        if (root->right != NULL)
        {
            st1.push(root->right);
        }
    }

    while (!st2.empty())
    {
        postorder.push_back(st2.top()->data);
        st2.pop();
    }

    return postorder;
}

/**
 * Using a single stack
 * TC: 0(N)
 * OC: O(N)
 * @param Node*
 * @returns vector<int>
 */
vector<int> postorderTraversal2(Node *root)
{
    vector<int> postorder;
    Node *curr = root;
    stack<Node *> st;
    if (curr == NULL)
        return postorder;
    while (curr != NULL || !st.empty())
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            Node *temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                postorder.push_back(temp->data);
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->data);
                }
            }
            else
            {
                curr = temp;
            }
        }
    }
    return postorder;
}

vector<int> postorderTraversal(Node *root)
{
    vector<int> postorder;
    stack<Node *> st;
    Node *curr = root;
    if (root == NULL)
    {
        return postorder;
    }

    while (curr != NULL || !st.empty())
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {

            Node *temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                postorder.push_back(temp->data);
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->data);
                }
            }
            else
            {
                curr = temp;
            }
        }
    }
    return postorder;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    for (int elem : postorderTraversal(root))
    {

        cout << elem << " ";
    }
}