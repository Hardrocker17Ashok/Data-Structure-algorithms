#include <bits/stdc++.h>
using namespace std;
bool matching(string ss)
{
    stack<char> st;
    for (int i = 0; i < ss.size(); i++)
    {
        if (ss[i] == '(' || ss[i] == '[' || ss[i] == '{')
        {
            st.push(ss[i]);
        }
        else{
            if(st.empty()){
                return false;
            }
        else if (ss[i] == ')')
        {
            if (st.top() == '(')
            {
                st.pop();
            }
            else
            {
                return false;
                break;
            }
        }
        else if (ss[i] == ']')
        {
            if (st.top() == '[')
            {
                st.pop();
            }
            else
            {
                return false;
                break;
            }
        }
        else if (ss[i] == '}')
        {
            if (st.top() == '{')
            {
                st.pop();
            }
            else
            {
                return false;
                break;
            }
        }
        }
    }
    cout<<"yaaaa"<<endl;
    if (st.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}
// using with array
bool matching_with_array(string ss)
{
    char *arr = new char[100000];
    int top = -1;
    for (int i = 0; i < ss.size(); i++)
    {
        if (ss[i] == '(' || ss[i] == '[' || ss[i] == '{')
        {
            arr[i] = ss[i];
            top++;
        }
        else if (ss[i] == ')')
        {
            if (arr[top] == '(')
            {
                top--;
            }
            else
            {
                return false;
                break;
            }
        }
        else if (ss[i] == ']')
        {
            if (arr[top] == '[')
            {
                top--;
            }
            else
            {
                return false;
                break;
            }
        }
        else if (ss[i] == '}')
        {
            if (arr[top] == '{')
            {
                top--;
            }
            else
            {
                return false;
                break;
            }
        }
    }
    if (top < 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    string ss;
    cin >> ss;
    // using stack
    // if (matching(ss))
    // {
    //     cout << "the string is valid" << endl;
    // }
    // else
    // {
    //     cout << "the string is invalid" << endl;
    // }
    // using array
    if (matching_with_array(ss))
    {
        cout << "the string is valid" << endl;
    }
    else
    {
        cout << "the string is invalid" << endl;
    }

    return 0;
}