#include <bits/stdc++.h>
using namespace std;

/**
 * Stack implementation using two queue
 */
// template <class T>
// class Stack
// {
// private:
//     queue<T> q1;
//     queue<T> q2;

// public:
//     void push(T x)
//     {
//         q2.push(x);
//         while (!q1.empty())
//         {
//             q2.push(q1.front());
//             q1.pop();
//         }
//         swap(q1, q2);
//     }
//     void pop1()
//     {
//         q1.pop();
//     }
//     T top()
//     {
//         return q1.front();
//     }
// };

/**
 * By using single queue we can do as follows
 */

template <class T>
class Stack
{
    queue<T> q;

public:
    void push(T x)
    {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    void pop()
    {
        q.pop();
    }
    T top()
    {
        return q.front();
    }
};

int main()
{
    Stack<int> s;
    s.push(5);
    s.push(4);
    s.push(2);
    s.push(3);
    s.push(2);
    s.push(1);
    s.push(0);
    s.push(1);
    s.pop();
    cout << s.top();
}