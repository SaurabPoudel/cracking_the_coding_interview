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