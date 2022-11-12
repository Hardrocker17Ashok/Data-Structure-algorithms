#include <iostream>
#include <queue>
#include <stack>
using namespace std;
stack<int> st1;
stack<int> st2;
// add element in queue
void push(int num)
{
    st1.push(num);
}
// pop element from it's queue
void pop()
{
    if (!st1.empty() && !st2.empty())
    {
        cout << "the queue is empty" << endl;
        return;
    }
    if (st2.empty())
    {
        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
    }
    int tt = st2.top();
    st2.pop();
}
// check queue that queue is empty ya NO
bool empty()
{
    if (st1.empty() && st2.empty())
    {
        return true;
    }
    return false;
}
// display queue
void display()
{
    if (!st2.empty())
    {
        stack<int> st3 = st2; // without reference
        while (!st3.empty())
        {
            cout << st3.top() << " ";
            st3.pop();
        }
        cout << endl;
    }
    else
    {
        stack<int> st3 = st1; // without reference
        stack<int> st4;
        while (!st3.empty())
        {
            st4.push(st3.top());
            st3.pop();
        }
        while (!st4.empty())
        {
            cout << st4.top() << " ";
            st4.pop();
        }
        cout << endl;
    }
}
int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    cout << "the queue is " << endl;
    display();
    pop();
    pop();
    cout << "the queue after poping " << endl;
    display();
    return 0;
}
