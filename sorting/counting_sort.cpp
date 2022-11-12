#include <iostream>
#include <limits>
using namespace std;
int find_max_element(int arr[], int num)
{
    int max = INT_MIN;
    for (int i = 0; i < num; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
int counting_sort(int arr[], int num)
{
    int max_ele = find_max_element(arr, num);
    int *arr1 = new int[max_ele];
    for (int i = 0; i < max_ele + 1; i++)
    {
        arr1[i] = 0;
    }
    for (int i = 0; i < num; i++)
    {
        arr1[arr[i]] = arr1[arr[i]] + 1;
    }
    int ii = 0, jj = 0;
    while (ii <= max_ele)
    {
        if (arr1[ii] > 0)
        {
            arr[jj] = ii;
            arr1[ii]--;
            jj++;
        }
        else
        {
            ii++;
        }
    }
}
void display(int arr[], int num)
{
    for (int i = 0; i < num; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int n1;
    cout << "enter size of array " << endl;
    cin >> n1;
    int arr[n1];
    cout << "enter array element" << endl;
    for (int i = 0; i < n1; i++)
    {
        cin >> arr[i];
    }
    counting_sort(arr, n1); // time complexity in all case o(n+k)
    cout << "the sorted array is " << endl;
    display(arr, n1);
    return 0;
}