#include <bits/stdc++.h>
#include "LinkedList.hpp"

using namespace std;

Node *returnKthToLast1(Node *head, int k)
{
    if (head == NULL || k <= 0)
        return NULL;
    Node *slow = head;
    Node *fast = head;

    for (int i = 0; i < k; i++)
    {
        if (fast == NULL)
            return NULL;
        fast = fast->next;
    }
    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

Node *returnKthToLast(Node *head, int k, int &count)
{
    if (head == NULL)
        return NULL;
    Node *node = returnKthToLast(head->next, k, count);
    count++;
    if (count == k)
    {
        return head;
    }
    return node;
}

Node *returnKthToLastWrapper(Node *head, int k)
{
    int count = 0;
    return returnKthToLast(head, k, count);
}
int main()
{
    vector<int> v = {4, 1, 2, 3, 5, 3, 2};
    Node *head = convertArr2LL(v);
    cout << "Original array" << endl;
    printLL(head);
    head = returnKthToLastWrapper(head, 3);
    cout << "Kth to last" << endl;
    printLL(head);
}