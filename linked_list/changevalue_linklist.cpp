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
    // displaying the linked list
    void display(don *node)
    {
        while (node != NULL)
        {
            cout << node->data << " ";
            node = node->next;
        }
    }
    // change value of node on spesific index in the linked list
    don *change_at_a_index(don *&node, int index, int val)
    {
        don *n = new don(val);
        don *p = node;
        if (index == 0)
        {
            n->next = p->next;
            node = n;
            free(p);
            return node;
        }
        for (int i = 0; i < (index - 1); i++)
        {
            p = p->next;
        }
        don *deee = p->next;
        n->next = p->next->next;
        p->next = n;
        free(deee);
        return node;
    }
    //  change value of the any node in the linked list
    don *change_at_any_node(don *&node, int node_ele, int val)
    {
        don *n = new don(val);
        don *p = node;
        if (p->data == node_ele)
        {
            n->next = p->next;
            node = n;
            free(p);
            return node;
        }
        while (p->next->data != node_ele)
        {
            p = p->next;
        }
        don *deee = p->next;
        n->next = p->next->next;
        p->next = n;
        free(deee);
        return node;
    }
    // change of starting node in the linked list
    don *change_starting_node(don *&node, int val)
    {
        don *n = new don(val);
        don *p = node;
        n->next = p->next;
        node = n;
        free(p);
        return node;
    }
    // change of the last node in the linked list
    don *change_ending_node(don *&node, int val)
    {
        don *n = new don(val);
        don *p = node;
        while (p->next->next != NULL)
        {
            p = p->next;
        }
        don *deee = p->next;
        p->next = n;
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
         << "enter the index and value whose you want change node value" << endl;
    int index, value;
    cin >> index >> value;
    node->change_at_a_index(node, index, value);
    node->display(node);
    cout << endl;
    cout << "enter the value of node and value whose you want change at any node" << endl;
    int val, node_number;
    cin >> node_number >> val;
    node->change_at_any_node(node, node_number, val);
    node->display(node);
    cout << endl;
    cout << "change node of the starting" << endl;
    int val1;
    cin >> val1;
    node->change_starting_node(node, val1);
    node->display(node);
    cout << endl
         << "enter value whosr you change the ending node" << endl;
    int val3;
    cin >> val3;
    node->change_ending_node(node, val3);
    node->display(node);
    return 0;
}