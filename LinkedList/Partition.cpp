#include <bits/stdc++.h>
#include "LinkedList.hpp"

using namespace std;

// This approach is mostly "stable" in that elements stay in the original order with O(N) time complexity and O(1)
Node *partition(Node *head, int x)
{
    Node *beforeStart = NULL;
    Node *beforeEnd = NULL;
    Node *afterStart = NULL;
    Node *afterEnd = NULL;

    Node *current = head;
    /*Partition List*/

    while (current != NULL)
    {
        Node *next = current->next;
        current->next = NULL;
        if (current->data < x)
        {
            if (beforeStart == NULL)
            {

                beforeStart = current;
                beforeEnd = beforeStart;
            }
            else
            {
                beforeEnd->next = current;
                beforeEnd = current;
            }
        }
        else
        {
            if (afterStart == NULL)
            {
                afterStart = current;
                afterEnd = afterStart;
            }
            else
            {
                afterEnd->next = current;
                afterEnd = current;
            }
        }
        current = next;
    }
    if (beforeStart == NULL)
        return afterStart;
    beforeEnd->next = afterStart;
    delete current;
    return beforeStart;
}

/**
 * if we don't care about the original order of the list , if the interviewer hasn't specified that ,
 * we can instead rearrange the elements by growing the list at the at the head and tail
 */
Node *partition1(Node *node, int x)
{
    Node *head = node;
    Node *tail = node;
    Node *current = node;
    while (current != NULL)
    {
        Node *next = current->next;
        if (current->data < x)
        {
            current->next = head;
            head = current;
        }
        else
        {
            tail->next = current;
            tail = current;
        }
        current = next;
    }
    tail->next = NULL;
    delete current;
    return head;
}

int main()
{
    vector<int> arr = {3, 5, 8, 5, 10, 2, 1};
    Node *head = convertArr2LL(arr);
    cout << "Before partition " << endl;
    printLL(head);
    head = partition1(head, 5);
    cout << "After partition " << endl;
    printLL(head);
}
