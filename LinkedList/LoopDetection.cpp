#include <bits/stdc++.h>
#include "LinkedList.hpp"

using namespace std;

/**
 * Brute solution using hash map
 * TC = O(N)
 * SC = O(N)
 */
bool loopDetected1(Node *head)
{
    Node *temp = head;
    unordered_map<Node *, bool> store;
    while (temp != NULL)
    {
        if (store[temp])
        {
            return true;
        }
        store[temp] = true;
        temp = temp->next;
    }
    return false;
}
/**
 * Using tortoise hare algorithm we can solve this question
 * TC = O(N);
 * OC = O(1);
 */
bool loopDetected(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast->next != NULL && fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if (slow == fast)
            return true;
    }
    return false;
}

int main()
{
    vector<int> arr = {2, 3, 4, 5, 6};
    Node *head = convertArr2LL(arr);
    Node *temp = head;
    temp->next->next->next->next->next = head->next->next->next;
    if (loopDetected(head))
    {
        cout << "Loop Detected";
    }
    else
    {
        cout << "No Loop Detected";
    }
}
