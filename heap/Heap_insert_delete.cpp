#include <iostream>
using namespace std;

// creating Heap
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
void built_maxheap(int arr[], int num)
{
    for (int i = (num / 2) - 1; i >= 0; i--)
    {
        heapify(arr, num, i);
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

// insert an element in heap array
void insert(int arr[], int &num, int element)
{
    num = num + 1;
    arr[num - 1] = element;
    // heapify(arr,num,num-1);
    int i = num - 1;
    while (i > 0)
    {
        int perent = i / 2;
        if (arr[perent] < arr[i])
        {
            int temp = arr[perent];
            arr[perent] = arr[i];
            arr[i] = temp;
            i = perent;
        }
        else
        {
            return;
        }
    }
}

// deleting an element from heap array
void delete1(int arr[], int &num)
{
    int lastelement = arr[num - 1];
    arr[0] = lastelement;
    num = num - 1;

    // we can call heapify function for delete
    // heapify(arr,num,0);
    int i = 0;
    while (i < num / 2)
    {
        int left = arr[2 * i + 1];
        int right = arr[2 * i + 2];
        int larger = left > right ? 2 * i + 1 : 2 * i + 2;
        if (arr[larger] > arr[i])
        {
            int temp = arr[larger];
            arr[larger] = arr[i];
            arr[i] = temp;
            i = larger;
        }
        else
        {
            return;
        }
    }
}
int main()
{
    int arr[] = {2, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    int n = 11;
    // creating maxheap from array
    built_maxheap(arr, n);

    cout << "the array before insert element from heap" << endl;
    print_array(arr, n);

    // insering element in heap
    insert(arr, n, 100);

    cout << "the array after insert element from heap " << endl;
    print_array(arr, n);

    // deleting element in heap
    delete1(arr, n);
    delete1(arr, n);

    cout << "the array after deleting element from heap " << endl;
    print_array(arr, 11);
    return 0;
}