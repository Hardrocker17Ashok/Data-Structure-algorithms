#include <iostream>
using namespace std;
void merge_sort(int arr[], int low, int mid, int high)
{
    int i, j, k;
    int real_arr[high + 1];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            real_arr[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            real_arr[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        real_arr[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        real_arr[k] = arr[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = real_arr[i];
    }
}
void make_condition(int arr[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        make_condition(arr, low, mid);
        make_condition(arr, mid + 1, high);
        merge_sort(arr, low, mid, high);
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
    int low = 0, high = n1;
    make_condition(arr, low, high);         //time complexity in all case o(n log n)
    cout << "the sorted array is " << endl;
    display(arr, n1);
    return 0;
}