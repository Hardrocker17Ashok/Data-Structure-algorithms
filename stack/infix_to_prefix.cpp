#include <bits/stdc++.h>
using namespace std;
int funk(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
string infix_to_prefix(string s)
{
    stack<char> st;
    string res;
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            s[i] = ')';
        }
        else if (s[i] == ')')
        {

            s[i] = '(';
        }
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
        {
            res += s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && funk(st.top()) > funk(s[i]))
            {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
    {
        if (res[i] == '(')
        {
            res[i] = ')';
        }
        else if (res[i] == ')')
        {
            res[i] = '(';
        }
    }
    return res;
}
int main()
{
    string name;
    cout << "enter string" << endl;
    cin >> name;
    cout << infix_to_prefix(name);
    return 0;
}
