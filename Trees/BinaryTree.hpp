#include <bits/stdc++.h>
/**
 * This header file contains all the declarations and util functions to be used while solving binary trees question
 */
class Node
{

public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        right = left = NULL;
    }
};