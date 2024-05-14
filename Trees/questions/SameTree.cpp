#include <bits/stdc++.h>
#include "../BinaryTree.hpp"

bool isSameTree(Node *p, Node *q)
{
    if (p == NULL && q == NULL)
    {
        return p == q;
    }
    return p->data == q->data && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
int main()
{
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->right = new Node(6);

    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);
    root2->right->right = new Node(6);

    if (isSameTree(root1, root2))
    {
        std::cout << "Same Tree";
    }
    else
    {
        std::cout << "Different Tree";
    }
}