#include <bits/stdc++.h>
#include "LinkedList.hpp"

using namespace std;

/**
 * Brute solution
 * Using hashmap
 */
Node *findIntersection1(Node *list1, Node *list2)
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

Node *collisionPoint(Node *head1, Node *head2, int size)
{
    while (size != 0)
    {
        size--;
        head1 = head1->next;
    }

    while (head1 != head2)
    {
        head1 = head1->next;
        head2 = head2->next;
    }
    return head1;
}

/**
 * Better solution
 * Time Complexity O(N1+2N2) where N2 is longer linkedlist
 * Space Complexity O(1)
 */
Node *findIntersection(Node *head1, Node *head2)
{
    int n1 = 0, n2 = 0;
    Node *t1 = head1;
    Node *t2 = head2;
    while (t1 != NULL)
    {
        n1++;
        t1 = t1->next;
    }
    while (t2 != NULL)
    {
        n2++;
        t2 = t2->next;
    }

    if (n1 > n2)
    {
        return collisionPoint(head1, head2, n1 - n2);
    }
    else
    {
        return collisionPoint(head2, head1, n2 - n1);
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head1 = convertArr2LL(arr);
    Node *head2 = new Node(4);
    head2->next = head1->next->next;
    Node *intersection = findIntersection(head1, head2);
    cout << intersection->data;
}