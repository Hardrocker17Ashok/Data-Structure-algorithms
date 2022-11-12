#include <iostream>
using namespace std;
int partitioning(int arr[], int low, int high)
{
    int pi = arr[low];
    int real_arr[high + 1];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (arr[i] <= pi)
        {
            i++;
        }
        while (arr[j] > pi)
        {
            j--;
        }
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}
void quick_sort(int arr[], int low, int high)
{
    int pivot;
    if (low < high)
    {
        pivot = partitioning(arr, low, high);
        quick_sort(arr, low, pivot - 1);
        quick_sort(arr, pivot + 1, high);
    }
}
void display(int arr[], int k)
{
    for (int i = 0; i < k; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int n1;
    cout << "enter size of array 1" << endl;
    cin >> n1;
    int arr[n1];
    cout << "enter array element" << endl;
    for (int i = 0; i < n1; i++)
    {
        cin >> arr[i];
    }
    int low = 0;
    int high = n1;
    quick_sort(arr, low, high); // time complexity in all case o(n log n)
    cout << "the sorted array is " << endl;
    display(arr, n1);
    return 0;
}