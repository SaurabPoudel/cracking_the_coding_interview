#include <bits/stdc++.h>
#include "LinkedList.hpp"

using namespace std;

/**
 * Digits are stored in reverse order
 * @param l1 Node* @param l2  Node*
 * @returns Node*
 */
Node *addLists(Node *l1, Node *l2, int carry)
{
    if (l1 == NULL && l2 == NULL && carry == 0)
    {
        return NULL;
    }
    Node *result = new Node();
    int value = carry;

    if (l1 != NULL)
    {
        value += l1->data;
    }
    if (l2 != NULL)
    {
        value += l2->data;
    }
    result->data = value % 10;

    if (l1 != NULL || l2 != NULL)
    {
        result->next = addLists(l1 == NULL ? NULL : l1->next, l2 == NULL ? NULL : l2->next, value >= 10 ? 1 : 0);
    }
    return result;
}

Node *addListsWrapper(Node *l1, Node *l2)
{
    return addLists(l1, l2, 0);
}
int main()
{
    vector<int> arr1 = {7, 1, 6};
    vector<int> arr2 = {5, 9, 2};
    Node *head1 = convertArr2LL(arr1);
    Node *head2 = convertArr2LL(arr2);
    Node *sum = addListsWrapper(head1, head2);
    cout << "Ones Tens Hundreds" << endl;
    printLL(sum);
}