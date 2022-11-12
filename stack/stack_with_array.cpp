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
    int Top()
    {
        if (top == -1)
        {
            cout << "no element in stack" << endl;
            return -1;
        }
        return arr[top];
    }
    bool empty()
    {
        return top == -1;
    }
    void print(){
        int copy=top;
        while(copy!=-1){
            cout<<arr[copy]<<" ";
            copy--;
        }
        cout<<endl;
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
    // prnt stack
    cout<<"the stack is = "<<endl;
    st.print();
    // some operation on stack whereby we can check that stack condition(empty ya full)
    cout << "the top element is=>" << st.Top() << endl;
    st.pop();
    cout << "the top element is=>" << st.Top() << endl;
    st.pop();
    st.pop();
    st.pop();
    cout << "the top element is=>" << st.Top() << endl;
    return 0;
}