#include <iostream>
using namespace std;
void merge_sort(int arr1[], int arr2[], int arr3[], int n1, int n2)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k] = arr1[i];
            k++;
            i++;
        }
        else
        {
            arr3[k] = arr2[j];
            k++;
            j++;
        }
    }
    while (i < n1)
    {
        arr3[k] = arr1[i];
        k++;
        i++;
    }
    while (j < n1)
    {
        arr3[k] = arr2[j];
        k++;
        j++;
    }
}
void display(int arr3[], int k)
{
    for (int i = 0; i < k; i++)
    {
        cout << arr3[i] << " ";
    }
}
int main()
{
    int n1, n2;
    cout << "enter size of array 1 and array 2" << endl;
    cin >> n1 >> n2;
    int k = n1 + n2;
    int arr1[n1];
    int arr2[n2];
    int arr3[k];
    cout << "enter first array element" << endl;
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }
    cout << "enter second array element" << endl;
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }
    // merge sort using two sorted array
    merge_sort(arr1, arr2, arr3, n1, n2);
    cout << "the sorted array is " << endl;
    display(arr3, k);

    return 0;
}