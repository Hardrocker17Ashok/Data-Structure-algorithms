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
// displaying linked listed

void display(don *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}
// find maximum value in given linked list
void maximum_elements(don *node)
{
    int element = -1;
    don *p = node;
    while (p != NULL)
    {
        if (p->data > element)
        {
            element = p->data;
        }
        p = p->next;
    }
    cout << "the maximum node in linked list \n"
         << element << endl;
}
// find minimum element in linked list
void minimum_elements(don *node)
{
    int element = node->data;
    don *p = node;
    while (p != NULL)
    {
        if (p->data < element)
        {
            element = p->data;
        }
        p = p->next;
    }
    cout << "the minimum node in linked list \n"
         << element << endl;
}
int main()
{
    don *node = NULL;
    int arr[] = {400, 44, 5, 6, 50, 500, 2};
    for (int i = 0; i < 7; i++)
    {
        linked(node, arr[i]);
    }
    cout << "the real linked llst here" << endl;
    display(node);
    cout << endl;
    maximum_elements(node);
    minimum_elements(node);
    return 0;
}