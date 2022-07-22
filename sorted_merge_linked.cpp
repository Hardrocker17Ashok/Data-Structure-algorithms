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
// sorted first linked list
don *sorted1(don *&node)
{
    don *i, *j;
    for (i = node; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                swap(i->data, j->data);
            }
        }
    }
    return node;
}
// sorted second linked list
don *sorted2(don *&node2)
{
    don *i, *j;
    for (i = node2; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                swap(i->data, j->data);
            }
        }
    }
    return node2;
}
// merge two sorted linked list by altertrative methods
don *marge_short(don *&node, don *&node2)
{
    don *p = node;
    don *q = node2;
    don *newhead = new don(-1);
    don *a = newhead;
    while (p != NULL && q != NULL)
    {
        if (p->data < q->data)
        {
            a->next = p;
            p = p->next;
        }
        else
        {
            a->next = q;
            q = q->next;
        }
        a = a->next;
    }
    while (p != NULL)
    {
        a->next = p;
        p = p->next;
        a = a->next;
    }
    while (q != NULL)
    {
        a->next = q;
        q = q->next;
        a = a->next;
    }
    return newhead->next;
}
void display(don *nodee)
{
    while (nodee != NULL)
    {
        cout << nodee->data << " ";
        nodee = nodee->next;
    }
}
// merge short by recursive methods
don *marge_short_by_recursive(don *&node, don *&node2)
{
    if (node == NULL)
    {
        return node2;
    }
    if (node2 == NULL)
    {
        return node;
    }
    don *result;
    if (node->data < node2->data)
    {
        result = node;
        result->next = marge_short_by_recursive(node->next, node2);
    }
    else
    {
        result = node2;
        result->next = marge_short_by_recursive(node, node2->next);
    }
    return result;
}
int main()
{
    don *node = NULL;
    don *node2 = NULL;
    int arr1[]={10,2,300,44,55};
    int arr2[]={400,44,5,6,50,500,2};
    for(int i=0;i<5;i++){
        linked(node,arr1[i]);
    }
    for(int i=0;i<7;i++){
        linked2(node2,arr2[i]);
    }
    
    display(node, node2);
    don *sol1 = sorted1(node);
    don *sol2 = sorted2(node2);
    cout << endl
         << "after sorting first and second linked list" << endl;
    display(sol1, sol2);
    cout << endl
         << "both linked list with merge short" << endl;
    // don*sol3=marge_short(node,node2);    //by altertrative method
    don *sol3 = marge_short_by_recursive(node, node2); // by recursive methodes
    display(sol3);
    return 0;
}