#include <iostream>
#include <stack>
using namespace std;
// if given a sentence than reverse below!
void reverse_sentence(string s)
{
    stack<string> st;
    for (int i = 0; i < s.length(); i++)
    {
        string nn = "";
        while (s[i] != ' ' && i < s.length())
        {
            nn += s[i];
            i++;
        }
        st.push(nn);
    }
    while (!(st.empty()))
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}
// if given a word than reverse below!
void reverse_word(string sss)
{
    stack<char> ch;
    for (int i = 0; i < sss.length(); i++)
    {
        ch.push(sss[i]);
    }
    while (!(ch.empty()))
    {
        cout << ch.top();
        ch.pop();
    }
    cout << endl;
}
int main()
{
    string ss;
    getline(cin, ss);
    cout << "the string is==>";
    for (int i = 0; i < ss.length(); i++)
    {
        cout << ss[i];
    }
    cout << endl
         << "reverse by stack==>";
    reverse_sentence(ss);
    cout << endl;

    // for word
    // cout<<"simple string==>";
    // for (int i = 0; i < ss.length(); i++)
    // {
    //     cout << ss[i];
    // }
    // cout << endl
    //      << "reverse by stack==>";
    // reverse_word(ss);
    return 0;
}