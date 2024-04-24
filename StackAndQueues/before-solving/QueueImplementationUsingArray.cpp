#include <bits/stdc++.h>
using namespace std;

template <class T>
class Queue
{
private:
    T front;
    T rear;
    int capacity;
    T *arr;

public:
    Queue(int size)
    {
        capacity = size;
        front = rear = -1;
        arr = new int[capacity];
    }

    ~Queue()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return (rear + 1) % capacity == front;
    }

    void enqueue(int item)
    {
        if (isFull())
        {
            cout << "Array is already full \n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        if (front == -1)
        {
            front = rear;
        }
    }
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot deque \n";
        }
        int item = arr[front];
        if (front == rear)
        {
            front = rear - 1;
        }
        else
        {
            front = (front + 1) % capacity;
        }
        return item;
    }
    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. No front element";
            return -1;
        }
        return arr[front];
    }
};

int main()
{
    Queue<int> q(5);
    q.enqueue(4);
    q.enqueue(2);
    q.enqueue(4);
    q.enqueue(3);
    q.enqueue(2);
    q.enqueue(1);

    cout << "First element is " << q.peek() << endl;

    q.dequeue();
    cout << "Front element after deque is " << q.peek() << endl;
}