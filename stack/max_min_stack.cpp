#include <iostream>
#include <stack>
using namespace std;
stack<int> st;
stack<int> dupli;
void print()
{
    stack<int> tt = st;
    while (!(tt.empty()))
    {
        cout << tt.top() << " ";
        tt.pop();
    }
    cout << endl;
}
int maximum()
{
    stack<int> st1 = st;
    dupli.push(st1.top());
    st1.pop();
    while (!st1.empty())
    {
        if (st1.top() > dupli.top())
        {
            dupli.push(st1.top());
            st1.pop();
        }
        else
        {
            st1.pop();
        }
    }
    return dupli.top();
}
int minimum()
{
    stack<int> st2 = st;
    dupli.push(st2.top());
    st2.pop();
    while (!st2.empty())
    {
        if (st2.top() < dupli.top())
        {
            dupli.push(st2.top());
            st2.pop();
        }
        else
        {
            st2.pop();
        }
    }
    return dupli.top();
}
int main()
{
    cout << "enter the size of stack1" << endl;
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        int val;
        cin >> val;
        st.push(val);
    }
    cout << "the stack is = " << endl;
    print();
    // find maximum and minimum value in o(n) time
    /* and for o(1) time complexity we can use aother stack with taking the input and
       store maximum and minimum element in o(1) time compleity*/
    cout << "the maximum is " << maximum() << " and the minimum value is " << minimum() << endl;
    return 0;
}