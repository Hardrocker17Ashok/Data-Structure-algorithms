#include <iostream>
#include <queue>
#include <stack>
using namespace std;
queue<int> qu;

// WITH QUEUEU LIBRARY
// add element in queue
void push(int num)
{
    qu.push(num);
}
// reversing queue with recursive
void reversing_with_recursive()
{
    if (qu.empty())
    {
        return;
    }
    int top = qu.front();
    qu.pop();
    reversing_with_recursive();
    push(top);
}
// reversing queue with itrative
void reversing_with_itraitive()
{
    queue<int> qu1 = qu;
    stack<int> st;
    while (!qu1.empty())
    {
        int ele = qu1.front();
        st.push(ele);
        qu1.pop();
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}
// display queue
void display()
{
    // queue<int>&dupli=qu;   //with refernce
    queue<int> dupli = qu; // without reference
    while (!dupli.empty())
    {
        cout << dupli.front() << " ";
        dupli.pop();
    }
    cout << endl;
}
// WITH ARRAY
class quu
{
public:
    int n = 100;
    int rear;
    int front;
    int *arr;
    quu()
    {
        rear = -1;
        front = -1;
        arr = new int[n];
    }
    void push_arr(int vl)
    {
        if (rear == n - 1)
        {
            cout << "the queue is full " << endl;
            return;
        }
        if (front == -1)
        {
            front++;
        }
        rear++;
        arr[rear] = vl;
    }
    void reversive()
    {
        if (front > rear)
        {
            front = rear = -1;
            return;
        }
        int top = arr[front];
        front++;
        reversive();
        push_arr(top);
    }
    void show()
    {
        int ii = front, j = rear;
        for (int i = ii; i <= j; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{

    // with queue library
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    cout << "the real queue is " << endl;
    display();
    cout << "the queue after reversing with recursive method  " << endl;
    reversing_with_recursive();
    display();
    cout << "the queue after reversing with itrative method  " << endl;
    reversing_with_itraitive();

    // with array
    cout << endl
         << "recurisive with array implement" << endl
         << endl;
    quu j;
    j.push_arr(1);
    j.push_arr(2);
    j.push_arr(3);
    j.push_arr(4);
    j.push_arr(5);
    cout << "before reversive " << endl;
    j.show();
    j.reversive();
    cout << "after reversive " << endl;
    j.show();
    return 0;
}
