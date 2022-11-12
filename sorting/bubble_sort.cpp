#include <iostream>
using namespace std;
// bubble sort with sweaping
void bubble_sort1(int arr[], int num)
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
// bubble sort another way
void bubble_sort2(int arr[], int num)
{
    for (int i = 0; i < num; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
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
    bubble_sort1(arr, num); // its right way for bubble sort
    // bubble_sort2(arr,num);           //its  anothor way for bubble sort
    display(arr, num);
    return 0;
}