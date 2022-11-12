// heap is two type
// 1-> max heap
// 2-> min heap

/*
max heap => all parent node biggest from own child node
mix heap => all parent node smallest from own child node

And heap is creat as a complete binary tree , means all node store 0 ya 2 child node
*/
#include <iostream>
using namespace std;

// max heap
void heapify1(int arr[], int num, int i)
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
        heapify1(arr, num, largest);
    }
}
void built_maxheap(int arr[], int num)
{
    for (int i = (num / 2) - 1; i >= 0; i--)
    {
        heapify1(arr, num, i);
    }
}

// min heap
void heapify2(int arr[], int num, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < num && arr[left] < arr[largest])
    {
        largest = left;
    }
    if (right < num && arr[right] < arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify2(arr, num, largest);
    }
}
void built_minheap(int arr[], int num)
{
    for (int i = (num / 2) - 1; i >= 0; i--)
    {
        heapify2(arr, num, i);
    }
}
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
    int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    // normal tree
    /*
                  1
                 /\
                /  \
                3   5          1-3-5-4-6-13-10-9-8-15-17
               /\   /\
              /  \ /  \
             4   6 13 10
            /\   /\
           9 8  15 17
    */
    cout << "the array before convert heap " << endl;
    print_array(arr, 11);

    // creating maxheap from array
    built_maxheap(arr, 11);
    cout << "the array after convert max_heap " << endl;
    print_array(arr, 11);

    // convert max_heap
    /*
             17
             /\
            /  \
           15   13             17-15-13-9-6-5-10-4-8-3-1
           /\   /\
          /  \ /  \
         9   6 5 10
        /\   /\
       4  8 3  1
*/

    // creating min_heap from array
    built_minheap(arr, 11);
    cout << "the array after convert min_heap " << endl;
    print_array(arr, 11);

    // convert min_heap
    /*
              1
             /\
            /  \
            3   5             1-3-5-4-6-13-10-9-8-15-17
           /\   /\
          /  \ /  \
         4   6 13 10
        /\   /\
       9  8 15 17
*/
    return 0;
}