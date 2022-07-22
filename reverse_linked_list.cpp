#include <iostream>
using namespace std;
class don
{
public:
    int data;
    don *next;
    don(int val)
    {
        data = val;
        next = NULL;
    }
};
void linked(don *&node, int val)
{
    don *n = new don(val);
    if (node == NULL)
    {
        node = n;
        return;
    }
    don *temp = node;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void display(don *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}
don *reverse(don *&node)
{
    don *prev = NULL;
    don *curent = node;
    don *ahead;
    while (curent != NULL)
    {
        ahead = curent->next;
        curent->next = prev;
        prev = curent;
        curent = ahead;
    }
    return prev;
}
int main()
{
    don *node = NULL;
    linked(node, 1);
    // cout<<*node<<endl;
    linked(node, 2);
    linked(node, 3);
    linked(node, 4);
    linked(node, 5);
    display(node);
    don *sol = reverse(node);
    cout << endl
         << "after reversing" << endl;
    display(sol);
    return 0;
}