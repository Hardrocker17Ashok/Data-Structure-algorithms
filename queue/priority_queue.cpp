#include <bits/stdc++.h>
using namespace std;
priority_queue<int> pq;
// add element in priority_queue
// and element with priorty base in decending order
void push(int num)
{
    pq.push(num);
}
// pop element from it's priority_queue
void pop()
{
    if (pq.empty())
    {
        cout << "the stack  is already empty" << endl;
        return;
    }
    pq.pop();
}
void display()
{
    // queue<int>&dupli=qu;   //with refernce
    priority_queue<int> dupli = pq; // without reference
    while (!dupli.empty())
    {
        cout << dupli.topvw() << " ";
        dupli.pop();
    }
    cout << endl;
}
int main()
{
    push(10);
    push(200);
    push(30);
    push(4);
    push(50);
    cout << "the queue is " << endl;
    display();
    pop();
    pop();
    cout << "the queue after poping " << endl;
    display();
    return 0;
}
