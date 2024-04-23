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