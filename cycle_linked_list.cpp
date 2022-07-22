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
    void linked_list(don *&node, int val)
    {
        don *n = new don(val);
        if (node == NULL)
        {
            node = n;
            return;
        }
        don *p = node;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = n;
    }
    void display_linked_list(don *node)
    {
        while (node != NULL)
        {
            cout << node->data << " ";
            node = node->next;
        }
    }
};
void make_cycle_linked(don *&node, int position)
{
    don *p = node;
    don *newending = node;
    int count = 0;
    while (p->next != NULL)
    {
        if (count == position)
        {
            newending = p;
        }
        p = p->next;
        count++;
    }
    p->next = newending;
}
bool check_sycle(don *&node)
{
    don *slowtptr = node;
    don *fastptr = node;
    while (fastptr != NULL && fastptr->next != NULL)
    {
        slowtptr = slowtptr->next;
        fastptr = fastptr->next->next;
        if (fastptr == slowtptr)
        {
            return true;
        }
    }
    return false;
}
// If you want remove the cycle linked list
void remove_cycle(don *node)
{
    don *slowptr = node;
    don *fastptr = node;
    do
    {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
    } while (slowptr != fastptr);
    fastptr = node;
    while (fastptr->next != slowptr->next != NULL)
    {
        fastptr = fastptr->next;
        slowptr = slowptr->next;
    }
    slowptr->next = NULL;
}
int main()
{
    don *head = NULL;
    head->linked_list(head, 1);
    head->linked_list(head, 2);
    head->linked_list(head, 3);
    head->linked_list(head, 4);
    head->linked_list(head, 5);
    head->linked_list(head, 6);
    head->linked_list(head, 7);
    head->linked_list(head, 8);
    head->linked_list(head, 9);
    head->linked_list(head, 10);
    head->linked_list(head, 11);
    head->linked_list(head, 12);
    head->linked_list(head, 13);
    head->linked_list(head, 14);
    head->linked_list(head, 15);
    head->display_linked_list(head);
    cout << endl
         << "enter the position there you create cyle linked list" << endl;
    int pos;
    cin >> pos;
    make_cycle_linked(head, pos);
    // head->display_linked_list(head);
    cout << check_sycle(head) << endl;
    remove_cycle(head);
    head->display_linked_list(head);
    return 0;
}