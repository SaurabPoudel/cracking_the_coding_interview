#include <bits/stdc++.h>
#include "LinkedList.hpp"

using namespace std;

// Using hashset i.e. unordered set in cpp

void deleteDups(Node *head)
{
    if (head == NULL)
        return;

    unordered_set<int> seen;
    Node *prev = NULL;
    Node *current = head;

    while (current != NULL)
    {
        if (seen.find(current->data) != seen.end())
        {
            prev->next = current->next;
            delete current;
            current = prev->next;
        }
        else
        {
            seen.insert(current->data);
            prev = current;
            current = current->next;
        }
    }
}

// above solution has time complexity of O(N) and space complexity of O(N)
// when space is crucial he can increase time complexity to O(N^2) to compensate space complexity to O(1)
// Lets do that

void removeDumps(Node *head)
{
    Node *current = head;

    while (current != NULL)
    {
        Node *runner = current;
        while (runner->next != NULL)
        {
            if (runner->next->data == current->data)
            {
                Node *duplicate = runner->next;
                runner->next = runner->next->next;
                delete duplicate;
            }
            else
            {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

int main()
{
    vector<int> v = {4, 4, 4, 1, 2, 3, 5, 5, 3, 2};
    Node *head = convertArr2LL(v);
    cout << "Before removing dups" << endl;
    printLL(head);
    removeDumps(head);
    cout << "After removing dups" << endl;
    printLL(head);
}
