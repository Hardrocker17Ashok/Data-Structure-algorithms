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
void linked2(don *&node2, int val)
{
    don *n1 = new don(val);
    if (node2 == NULL)
    {
        node2 = n1;
        return;
    }
    don *temp1 = node2;
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = n1;
}
// displaying both linked listed

void display(don *node, don *node2)
{
    cout << endl
         << "first linked list" << endl;
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl
         << "second linked list" << endl;
    while (node2 != NULL)
    {
        cout << node2->data << " ";
        node2 = node2->next;
    }
}

// join both linked list given number
don *marge_short(don *&node, don *&node2, int index)
{
    don *p = node;
    don *q = node2;
    while (index--)
    {
        if (p == nullptr)
        {
            cout << "the linked list is no more index available" << endl;
        }
        p = p->next;
    }
    while (q->next != NULL)
    {
        q = q->next;
    }
    q->next = p;
    return node;
}
// function for gatting lenth of both linked list
int length(don *head)
{
    don *temp = head;
    int l = 0;
    while (temp != nullptr)
    {
        temp = temp->next;
        l++;
    }
    return l;
}
//  find mearging point data
int find_mearge_data(don *&node, don *&node2)
{
    int l1 = length(node);
    int l2 = length(node2);
    int real = 0;
    don *q1;
    don *p1;
    if (l1 > l2)
    {
        real = l1 - l2;
        p1 = node;
        q1 = node2;
    }
    else
    {
        real = l2 - l1;
        p1 = node2;
        q1 = node;
    }
    while (real--)
    {
        p1 = p1->next;
        if (p1 == nullptr)
        {
            return -1;
        }
    }
    while (p1 != nullptr && q1 != nullptr)
    {
        if (p1 == q1)
        {
            return p1->data;
        }
        p1 = p1->next;
        q1 = q1->next;
    }
    return -1;
}
int main()
{
    don *node = NULL;
    don *node2 = NULL;
    int arr1[] = {10, 2, 300, 44, 55};
    int arr2[] = {400, 44, 5, 6, 50, 500, 2};
    for (int i = 0; i < 5; i++)
    {
        linked(node, arr1[i]);
    }
    for (int i = 0; i < 7; i++)
    {
        linked2(node2, arr2[i]);
    }
    cout << "both linked list";
    display(node, node2);
    cout << endl;
    marge_short(node, node2, 3);
    cout << "after mearging both linked list";
    display(node, node2);
    cout << endl
         << "both linked list mearging data is = ";
    cout << find_mearge_data(node, node2);
    return 0;
}

// find merge point
