#include <bits/stdc++.h>
#define n 1000
using namespace std;
class Stack
{
    int top;
    int *arr;

public:
    Stack()
    {
        top = -1;
        arr = new int[n];
    }

    void push(int data)
    {
        if (top > n)
        {
            cout << "the stack is overflow" << endl;
            return;
        }
        top++;
        arr[top] = data;
    }
    void pop()
    {
        if (top < -1)
        {
            cout << "the stack is empty" << endl;
            return;
        }
        top--;
    }
    void print()
    {
        int copy = top;
        while (copy != -1)
        {
            cout << arr[copy] << " ";
            copy--;
        }
    }
    // search element  index
    void peek(int index)
    {
        int element = top - index + 1;
        if (element < 0)
        {
            cout << "not valid" << endl;
        }
        else
        {
            cout << "the element is = " << arr[element] << endl;
        }
    }
};
int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout << "the stack is" << endl;
    st.print();
    cout << "enter the index for search revesse" << endl;
    int ind;
    cin >> ind;
    st.peek(ind);
    return 0;
}