#include <bits/stdc++.h>
#include "LinkedList.hpp"

using namespace std;

/**
 * A naive solution with the help of stack
 * Time complexity O(N) {O(2N)}
 * Space complexity O(N)
 */
bool isPallindrome1(Node *head)
{
    stack<int> st;
    Node *temp = head;
    while (temp != NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        if (temp->data != st.top())
            return false;
        temp = temp->next;
        st.pop();
    }
    delete temp;
    return true;
}

Node *reverseLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *newHead = reverseLinkedList(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

bool isPallindrome1(Node *head)
{
    if (head == NULL || head->next == NULL)
        return true;
    Node *slow = head;
    Node *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *newHead = reverseLinkedList(slow->next);
    Node *first = head;
    Node *second = newHead;

    while (second != NULL)
    {
        if (first->data != second->data)
        {
            reverseLinkedList(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseLinkedList(newHead);
    return true;
}
/**
 * Optimal solution
 * Time complexity O(N)
 * Special Complexity O(N)
 */
bool isPallindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
        return true;
    Node *fast = head;
    Node *slow = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *newHead = reverseLinkedList(slow->next);

    Node *first = head;
    Node *second = newHead;

    while (second != NULL)
    {
        if (first->data != second->data)
        {
            reverseLinkedList(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseLinkedList(newHead);
    return true;
}

int main()
{
    vector<int> arr = {3, 2, 2, 4, 4, 2, 2, 3};
    Node *head = convertArr2LL(arr);
    if (isPallindrome(head))
    {
        cout << "Pallindrome" << endl;
    }
    else
    {
        cout << "Not Pallindrome" << endl;
    }
}