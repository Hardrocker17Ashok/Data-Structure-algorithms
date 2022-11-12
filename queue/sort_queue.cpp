#include <bits/stdc++.h>
using namespace std;
queue<int> qu;
stack<int> st;
// add element in queue
void push(int num)
{
    qu.push(num);
}
// using vector
void sort_vector()
{
    vector<int> v;
    while (!qu.empty())
    {
        int val = qu.front();
        v.push_back(val);
        qu.pop();
    }
    sort(v.begin(), v.end());
    for (auto it : v)
    {
        qu.push(it);
    }
}
// using stack
void result(int val)
{
    if (st.empty() || st.top() > val)
    {
        st.push(val);
        return;
    }
    int n = st.top();
    st.pop();
    result(val);
    st.push(n);
}
void sort_stack()
{
    if (qu.empty())
    {
        return;
    }
    int val = qu.front();
    qu.pop();
    sort_stack();
    result(val);
}
void main_sort()
{
    sort_stack();
    while (!st.empty())
    {
        qu.push(st.top());
        st.pop();
    }
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
    push(5);
    push(4);
    push(1);
    push(15);
    push(10);
    push(6);
    cout << "the real queue is " << endl;
    display();
    cout << "the queue after sorting  " << endl;
    // sort_vector();
    main_sort();
    display();
    return 0;
}
