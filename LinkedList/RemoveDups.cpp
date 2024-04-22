#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};
void printLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

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

Node *convertArr2LL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int main()
{
    vector<int> v = {4, 4, 4, 1, 2, 3, 5, 5, 3, 2};
    Node *head = convertArr2LL(v);
    cout << "Before removing dups" << endl;
    printLL(head);
    deleteDups(head);
    cout << "After removing dups" << endl;
    printLL(head);
}
