#include <iostream>
#include <queue>
using namespace std;
queue<int> qu;
// add element in queue
void push(int num)
{
    qu.push(num);
}
// pop element from it's queue
void pop()
{
    if (qu.empty())
    {
        cout << "the stack  is already empty" << endl;
        return;
    }
    qu.pop();
}
// peek any element fron this queue
int peek(int index)
{
    queue<int> check = qu;
    while (!check.empty() && 0 < index - 1)
    {
        index--;
        check.pop();
    }
    return check.front();
}
// check queue that queue is empty ya NO
bool empty()
{
    if (qu.empty())
    {
        return true;
    }
    return false;
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
int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    cout << "the queue is " << endl;
    display();
    cout << "find/peek this indexes" << endl;
    int ind;
    cin >> ind;
    cout << peek(ind) << endl;
    pop();
    pop();
    cout << "the queue after poping " << endl;
    display();
    return 0;
}
