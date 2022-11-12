#include <iostream>
using namespace std;
// selection sort
void selection_sort(int arr[], int num)
{
    int i, j, key;
    for (i = 0; i < num; i++)
    {
        key = i;
        for (j = i + 1; j < num; j++)
        {
            if (arr[key] > arr[j])
            {
                key = j;
            }
        }
        int temp;
        temp = arr[i];
        arr[i] = arr[key];
        arr[key] = temp;
    }
}
void display(int arr[], int num)
{
    for (int i = 0; i < num; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int num;
    cin >> num;
    int arr[num];
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
    selection_sort(arr, num); // best,average and worst time complexity is o(n^n)
    display(arr, num);
    return 0;
}