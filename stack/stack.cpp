#include <iostream>
#include <stack>
using namespace std;
// if given a word than reverse below!
void print(stack<int>st)
{
    while (!(st.empty()))
    {
        cout << st.top()<<" ";
        st.pop();
    }
    cout << endl;
}
// void find_people(stack<int>st){
//     while((!st.empty())){
//     }
// }
void print2(stack<int>st2)
{
    while (!(st2.empty()))
    {
        cout << st2.top()<<" ";
        st2.pop();
    }
    cout << endl;
}
// void find_people(stack<int>st){
//     while((!st.empty())){
//         if(p)
//     }
// }
void sweap(stack<int>&st,stack<int>&st2){
    st.swap(st2);
}
int main()
{
    cout<<"enter the size of stack1"<<endl;
    int num;cin>>num;
    stack<int>st;
    for (int i = 0; i < num; i++)
    {
        int val;cin>>val;
        st.push(val);
    }
     cout<<"enter the size of stack2"<<endl;
    int num1;cin>>num1;
    stack<int>st2;
    for (int i = 0; i < num1; i++)
    {
        int val2;cin>>val2;
        st2.push(val2);
    }
    // calculate size of stack
    cout<<"size of first stack= "<<st.size()<<endl;
    cout<<"print first stack"<<endl;
    print(st);
    cout<<"size of first stack= "<<st.size()<<endl;
    cout<<"print second stack"<<endl;
    print2(st2);
    sweap(st,st2);
    cout<<"after sweaping"<<endl;
    cout<<"print first stack"<<endl;
    print(st);
    cout<<"print second stack"<<endl;
    print2(st2);
    return 0;
}