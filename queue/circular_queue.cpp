#include <iostream>
#define n 6
using namespace std;
class queue
{
    int rear;
    int front;
    int *arr;
    int ch = 0;

public:
    queue()
    {
        rear = -1;
        front = -1;
        arr = new int[n];
    }
    void inqueue(int val)
    {
        if ((rear + 1) % n == front)
        {
            cout << "the queue is full " << endl;
            return;
        }
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % n;
        ch++;
        arr[rear] = val;
    }
    int dequeue()
    {
        if (front == -1)
        {
            cout << "the queue is empty " << endl;
            return -1;
        }
        int result = arr[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % n;
        }
        return result;
    }
    void display()
    {
        int du = front;
        int mu = rear;
        cout << arr[((du + 1) % n) - 1] << " ";
        while ((du + 1) % n != (mu + 1) % n)
        {
            cout << arr[(du + 1) % n] << " ";
            du = (du + 1) % n;
        }
        cout << endl;
    }
    int peek()
    {
        if (front == -1)
        {
            cout << "the queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }
};
int main()
{
    queue st;
    st.inqueue(10);
    st.inqueue(20);
    st.inqueue(30);
    st.inqueue(40);
    st.inqueue(50);
    st.inqueue(120);
    cout << "the orignal queue is " << endl;
    st.display();
    cout << st.dequeue() << " ";
    cout << st.dequeue() << " ";
    cout << st.dequeue() << " ";
    cout << endl
         << "and after delete the queue is " << endl;
    st.display();
    st.inqueue(60);
    st.inqueue(70);
    st.inqueue(80);
    cout << "add element after rear equal n and add element circularlly the queue is " << endl;
    st.display();
    cout << "the first element of queue is " << endl;
    cout << st.peek();
    return 0;
}