#include <iostream>
#define n 100
using namespace std;

class queue
{
    int front, rear;
    int *arr;

public:
    queue()
    {
        arr = new int[n];
        front = -1;
        rear = -1;
    }
    void add_at_rear(int val)
    {
        if (front == n - 1)
        {
            cout << "the queue is full" << endl;
            return;
        }
        if (front == -1)
        {
            front++;
        }
        rear++;
        arr[rear] = val;
    }
    void add_at_front(int val)
    {
        if (rear == n - 1)
        {
            cout << "the queue is full" << endl;
            return;
        }
        if (front == -1)
        {
            front = 0;
            arr[rear++] = val;
        }
        else if (front == 0)
        {
            cout << "we can not add of the front because not empty space of front side " << endl;
            return;
            //     cout<<"and other wise you add element of front side in o(n) time complexity so pree 1"<<endl;
            //      for(int i=front;i<rear;i++){
            //     arr[i+1]=arr[i];
            // }
            // arr[front]=val;
        }
        else
        {
            arr[front--] = val;
        }
    }
    void delete_at_front()
    {
        if (front == -1 || front > rear)
        {
            cout << "the queue is empty you dont delete any element" << endl;
            return;
        }
        front++;
    }
    void delete_at_rear()
    {
        if (rear == -1)
        {
            cout << "the queue is empty you dont delete any element" << endl;
            return;
        }
        rear--;
    }
    void display()
    {
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{

    // with array
    queue obj;
    obj.add_at_rear(10);
    obj.add_at_rear(20);
    obj.add_at_rear(30);
    obj.add_at_rear(40);
    obj.add_at_rear(50);
    obj.add_at_rear(50);
    obj.add_at_rear(5000);
    obj.add_at_rear(500);
    cout << "the dequeue after adding element of the rear position " << endl;
    obj.display();

    obj.delete_at_front();
    obj.delete_at_front();
    // obj.delete_at_front();
    // obj.delete_at_front();
    obj.add_at_front(11);
    obj.add_at_front(22);
    obj.add_at_front(33);
    // obj.add_at_front(44);
    // obj.add_at_front(55);
    cout << "the dequeue after adding element of the  front position " << endl;
    obj.display();

    obj.delete_at_rear();
    obj.delete_at_rear();
    obj.delete_at_rear();
    cout << "the dequeue after deleting element of the rear position " << endl;
    obj.display();

    obj.delete_at_front();
    obj.delete_at_front();
    cout << "the dequeue after deleting element of the front position " << endl;
    obj.display();
    return 0;
}