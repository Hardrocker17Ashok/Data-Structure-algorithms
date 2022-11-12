#include <iostream>
#define n 1000
using namespace std;
class stack
{
    int *arr;
    int top;

public:
    stack()
    {
        arr = new int[n];
        top = -1;
    }
    void push(int x)
    {
        if (top == n - 1)
        {
            cout << "stack is full" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "stack is empty now" << endl;
            return;
        }
        top--;
    }
    // find maximum number
    int find_maximum()
    {
        int check = -1;
        for (int i = top; i >= 0; i--)
        {
            if (arr[i] > check)
            {
                check = arr[i];
            }
        }
        return check;
    }
    // find minimum number
    int find_minimum()
    {
        int check = arr[top];
        for (int i = top; i >= 0; i--)
        {
            if (arr[i] < check)
            {
                check = arr[i];
            }
        }
        return check;
    }
    void print()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(50);
    st.push(500);
    st.push(9);
    st.push(11);
    cout << "the stack is = " << endl;
    st.print();
    cout << "the maximum element is=>" << st.find_maximum() << endl;
    cout << "the minimum element is=>" << st.find_minimum() << endl;
    return 0;
}