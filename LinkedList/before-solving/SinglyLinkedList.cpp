#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
};

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
Node *removeHead(Node *head)
{
    if (!head)
        return NULL;
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}
Node *removeTail(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return head;
}

Node *deleteKNode(Node *head, int k)
{
    if (head == NULL || k == 0)
        return head;
    if (k == 1)
    {
        Node *temp = head;
        temp = head->next;
        delete temp;
        return head;
    }
    int count = 0;
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        count++;
        if (count == k)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
Node *delKNode(Node *head, int k)
{
    if (head == NULL || k == 0)
        return head;
    if (k == 1)
    {
        Node *temp = head;
        temp = head->next;
        delete temp;
        return head;
    }
    Node *temp = head;
    Node *prev = NULL;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        if (count == k)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
Node *removeEL(Node *head, int el)
{
    if (head == NULL)
        return head;
    if (head->data == el)
    {
        Node *temp = head;
        temp = head->next;
        delete temp;
        return head;
    }
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        if (temp->data == el)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *removeElement(Node *head, int el)
{
    if (head == NULL)
        return head;

    if (head->data == el)
    {
        Node *temp = head;
        temp = head->next;
        delete temp;
        return head;
    }

    Node *temp = head;
    Node *prev = NULL;
    while (temp->next != NULL)
    {
        if (temp->data == el)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
Node *insertHead(Node *head, int el)
{
    // Node *temp = new Node(el);
    // temp->next = head;
    // head = temp;
    // return head;
    return new Node(el, head);
}
Node *insertTail(Node *head, int el)
{
    if (head == NULL)
        return new Node(el);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new Node(el);
    return head;
}

Node *insertTail1(Node *head, int el)
{
    if (head == NULL)
        return new Node(el);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new Node(el);
    return head;
}

Node *insertBeforeK(Node *head, int el, int k)
{
    if (head == NULL)
    {
        if (k == 1)
        {
            return new Node(el);
        }
        else
        {
            return head;
        }
    }
    if (k == 1)
    {
        return new Node(el, head);
    }
    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == k - 1)
        {
            temp->next = new Node(el, temp->next);
            break;
        }
        temp = temp->next;
    }
    return head;
}
int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    Node *head = convertArr2LL(v);
    // cout << "Before removing tail" << endl;
    // printLL(head);
    // cout << "Removing tail" << endl;
    // head = removeTail(head);
    // printLL(head);
    head = insertBeforeK(head, 10, 3);
    printLL(head);
    return 0;
}
