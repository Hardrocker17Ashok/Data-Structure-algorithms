#include <iostream>
using namespace std;

// creating Heap from array
void heapify(int arr[], int num, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < num && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < num && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, num, largest);
    }
}
void heapsort(int arr[], int num)
{
    // change in max_heap
    for (int i = (num / 2) - 1; i >= 0; i--)
    {
        heapify(arr, num, i);
    }
    for (int i = num - 1; i >= 0; i--)
    {
        // move current root element to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // call heapify function
        heapify(arr, i, 0);
    }
}

// printing array
void print_array(int arr[], int num)
{
    for (int i = 0; i < num; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[] = {2, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    int n = 11;

    cout << "The array before sorting " << endl;
    print_array(arr, n);

    // sorting array using heap sort
    heapsort(arr, n);

    cout << "The array after sorting " << endl;
    print_array(arr, 11);
    return 0;
}