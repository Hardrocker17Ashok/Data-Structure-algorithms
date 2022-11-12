#include <bits/stdc++.h>
using namespace std;
deque<int> de;
// add element in dequeue
void add_rear(int num)
{
    de.push_back(num);
}
void add_front(int num)
{
    de.push_front(num);
}
// pop element from it's queue
void remove_rear()
{
    if (de.empty())
    {
        cout << "the dueue is already empty" << endl;
        return;
    }
    de.pop_back();
}
void remove_front()
{
    if (de.empty())
    {
        cout << "the queue is already empty" << endl;
        return;
    }
    de.pop_front();
}

// display DEque
void display()
{
    // DEque<int>&dupli=de;   //with refernce
    deque<int> dupli = de; // without reference
    while (!dupli.empty())
    {
        cout << dupli.front() << " ";
        dupli.pop_front();
    }
    cout << endl;
}
int main()
{
    add_rear(10);
    add_rear(20);
    add_rear(30);
    add_rear(40);
    cout << "the queue after adding element of the rear position" << endl;
    display();
    add_front(500);
    add_front(5000);
    add_front(50000);
    add_front(500000);
    add_front(5);
    cout << "the queue after adding element of the front position" << endl;
    display();
    remove_rear();
    remove_rear();
    remove_rear();
    remove_rear();
    cout << "the queue after remove element of the rear position" << endl;
    display();
    remove_front();
    remove_front();
    remove_front();
    cout << "the complete queue is " << endl;
    display();
    return 0;
}
