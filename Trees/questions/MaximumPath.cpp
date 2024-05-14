#include <bits/stdc++.h>
#include "../BinaryTree.hpp"

int maxPath(Node *node, int &maxi)
{

    if (node == NULL)
        return 0;

    int leftSum = std::max(0, maxPath(node->left, maxi));
    int rightSum = std::max(0, maxPath(node->right, maxi));

    maxi = std::max(maxi, leftSum + rightSum + node->data);

    return std::max(leftSum, rightSum) + node->data;
}

/**
 * Path node A -> node B
 *        10
 *      /    \
 *     9      20
 *          /    \
 *         15    7
 * @returns Maximum path sum
 * Here, 15 + 20 + 7 = 42
 * We use maximum height concept O(N) for this
 *  val + maxL + maxR
 */
int maxPathSum(Node *node)
{
    int maxi = INT_MIN;
    maxPath(node, maxi);
    return maxi;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    std::cout << "Maximum sum is " << maxPathSum(root);
}
