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
    void show_linked(don *&node, int val)
    {
        don *n = new don(val);
        if (node == NULL)
        {
            node = n;
            return;
        }
        don *sh = node;
        while (sh->next != NULL)
        {
            sh = sh->next;
        }
        sh->next = n;
    }
    void display(don *node)
    {
        while (node != NULL)
        {
            cout << node->data << " ";
            node = node->next;
        }
    }
    // delet spesific index of node
    don *delet_at_a_index(don *&node, int index)
    {
        don *p = node;
        if (index == 0)
        {
            node = p->next;
            free(p);
            return node;
        }
        for (int i = 0; i < (index - 1); i++)
        {
            p = p->next;
        }
        don *deee = p->next;
        p->next = p->next->next;
        free(deee);
        return node;
    }
    //  delet the any node in the linked list
    don *delet_at_a_node(don *&node, int val)
    {
        don *p = node;
        if (p->data == val)
        {
            node = p->next;
            free(p);
            return node;
        }
        while (p->next->data != val)
        {
            p = p->next;
        }
        don *deee = p->next;
        p->next = p->next->next;
        free(deee);
        return node;
    }
    // delete of starting node
    don *delet_starting_node(don *&node)
    {
        don *p = node;
        node = p->next;
        free(p);
        return node;
    }
    // delete of ending node
    don *delet_ending_node(don *&node)
    {
        don *p = node;
        while (p->next->next != NULL)
        {
            p = p->next;
        }
        don *deee = p->next;
        p->next = NULL;
        free(deee);
        return node;
    }
};

int main()
{
    don *node = NULL;
    node->show_linked(node, 10);
    node->show_linked(node, 5);
    node->show_linked(node, 3);
    node->show_linked(node, 4);
    node->show_linked(node, 1);
    node->show_linked(node, 6);
    node->show_linked(node, 7);
    node->show_linked(node, 8);
    node->display(node);
    cout << endl
         << endl
         << "enter the index number whose you want deleting" << endl;
    int index;
    cin >> index;
    node->delet_at_a_index(node, index);
    node->display(node);
    cout << endl
         << "enter the value of node whose you want delete" << endl;
    int val;
    cin >> val;
    node->delet_at_a_node(node, val);
    node->display(node);
    cout << endl
         << "delete node starting" << endl;
    node->delet_starting_node(node);
    node->display(node);
    cout << endl
         << "delete the ending node" << endl;
    node->delet_ending_node(node);
    node->display(node);
    return 0;
}