#include <iostream>
#include <stack>
using namespace std;
void print(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}
void short_element(stack<int> &st, int ele)
{
    if (st.empty() || st.top()<ele)
    {
        st.push(ele);
        return;
    }
    int to = st.top();
    st.pop();
    short_element(st, ele);
    st.push(to);
}
void short_funk(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int ele = st.top();
    st.pop();
    short_funk(st);
    short_element(st, ele);
}
int main()
{
    stack<int> st;
    cout << "enter the size of stak" << endl;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        st.push(val);
    }
    print(st);
    short_funk(st);
    cout << "after shorting  stack " << endl;
    print(st);
    return 0;
}