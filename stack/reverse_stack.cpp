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
void add_reversing_element(stack<int> &st, int ele)
{
    if (st.empty())
    {
        st.push(ele);
        return;
    }
    int to = st.top();
    st.pop();
    add_reversing_element(st, ele);
    st.push(to);
}
void reverse_funk(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int ele = st.top();
    st.pop();
    reverse_funk(st);
    add_reversing_element(st, ele);
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
    reverse_funk(st);
    cout << "after reversing stack" << endl;
    print(st);
    return 0;
}