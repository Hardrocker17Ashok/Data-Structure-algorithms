#include <bits/stdc++.h>
using namespace std;
int prefix(string s)
{
    stack<char> st;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0'); // '0' because convert string to integer
        }
        else
        {
            int num1 = st.top();
            st.pop();
            int num2 = st.top();
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(num1 + num2);
                break;
            case '-':
                st.push(num1 - num2);
                break;
            case '*':
                st.push(num1 * num2);
                break;
            case '/':
                st.push(num1 / num2);
                break;
            case '^':
                st.push(num1 ^ num2);
                break;
            default:
                cout << "plz enter correct cherector" << endl;
                break;
            }
        }
    }
    return st.top();
}

// from array
int solved_from_array(string ss)
{
    int *arr = new int[1000];
    int top = ss.size();
    for (int i = ss.size() - 1; i >= 0; i--)
    {
        if (ss[i] >= '0' && ss[i] <= '9')
        {
            arr[i] = (ss[i] - '0');
            top--;
        }
        else
        {
            int n1 = arr[top];
            top++;
            int n2 = arr[top];
            switch (ss[i])
            {
            case '+':
                arr[top] = n1 + n2;
                break;
            case '-':
                arr[top] = n1 - n2;
                break;
            case '*':
                arr[top] = n1 * n2;
                break;
            case '/':
                arr[top] = n1 / n2;
                break;
            case '^':
                arr[top] = n1 ^ n2;
                break;
            default:
                cout << "plz enter correct cherector" << endl;
                break;
            }
        }
    }
    return arr[top];
}
int main()
{
    string name;
    cin >> name;
    // cout<<prefix(name);              //from orignal stack         //time complexity o(L):where L=lengh of string
    cout << solved_from_array(name); // from using array stack     //time complexity o(L):where L=lengh of string
    return 0;
}
