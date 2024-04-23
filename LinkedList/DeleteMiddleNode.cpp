#include <bits/stdc++.h>
#include "LinkedList.hpp"

using namespace std;

void deleteNode(Node *head)
{
    if (head == NULL || head->next == NULL)
        return;
    Node *nextNode = head->next;
    head->data = nextNode->data;
    head->next = nextNode->next;
}

int main()
{
    vector<int> v = {4, 1, 2, 3, 5, 3, 2};
    Node *head = convertArr2LL(v);
    deleteNode(head->next->next);
    printLL(head);
}