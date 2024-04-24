#include <bits/stdc++.h>
#include "LinkedList.hpp"

using namespace std;

/**
 * Brute solution
 * Using hashmap
 */
Node *findIntersection(Node *list1, Node *list2)
{
    Node *temp = list1;
    unordered_map<Node *, bool> store;
    while (temp != NULL)
    {
        store[temp] = true;
        temp = temp->next;
    }

    temp = list2;
    while (temp != NULL)
    {
        if (store[temp])
        {
            return temp;
            break;
        }
        temp = temp->next;
    }
    return temp;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head1 = convertArr2LL(arr);
    Node *head2 = new Node(4);
    head2->next = head1->next->next->next;
    Node *intersection = findIntersection(head1, head2);
    cout << intersection->data;
}