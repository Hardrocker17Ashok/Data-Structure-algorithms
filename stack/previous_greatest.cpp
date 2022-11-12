#include <bits/stdc++.h>
using namespace std;
void nge(int arr[], int size)
{
    int n = size;
    int arr1[n];
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() < arr[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            arr1[i] = -1;
        }
        else
        {
            arr1[i] = st.top();
        }
        st.push(arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
}
void nse(int arr[], int size)
{
    int n = size;
    int arr1[n];
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() > arr[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            arr1[i] = -1;
        }
        else
        {
            arr1[i] = st.top();
        }
        st.push(arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
}
int main()
{
    cout << "enter size of vector" << endl;
    int num;
    cin >> num;
    int arr[num];
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
    // find previous next greatest element for each index value [in o(n)time complexity]
    cout << "array with next greatest element" << endl;
    nge(arr, num);
    // find previous next smallest element for each index value [in o(n)time complexity]
    cout << "array with next smallest element" << endl;
    nse(arr, num);
    return 0;
}