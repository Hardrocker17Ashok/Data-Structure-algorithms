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
    //  insert vlue at the last node
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
    // insert value on spesific index of node
    don *insert_at_a_index(don *&node, int index, int val)
    {
        don *n = new don(val);
        if (index == 0)
        {
            n->next = node;
            node = n;
            return node;
        }
        don *p = node;
        for (int i = 0; i < (index - 1); i++)
        {
            p = p->next;
        }
        n->next = p->next;
        p->next = n;
        return node;
    }
    //  insert the any node in the linked list
    don *insert_at_a_node(don *&node, int node_ele, int val)
    {
        don *n = new don(val);
        don *p = node;
        if (p->data == node_ele)
        {
            n->next = node;
            node = n;
            return node;
        }
        while (p->next->data != node_ele)
        {
            p = p->next;
        }
        n->next = p->next;
        p->next = n;
        return node;
    }
    // insert of starting node
    don *insert_starting_node(don *&node, int val)
    {
        don *n = new don(val);
        n->next = node;
        node = n;
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
         << "enter the index and value whose you want inserting" << endl;
    int index, value;
    cin >> index >> value;
    node->insert_at_a_index(node, index, value);
    node->display(node);
    cout << endl
         << "enter the value of node and value whose you want insert at a node" << endl;
    int val, node_number;
    cin >> node_number >> val;
    node->insert_at_a_node(node, node_number, val);
    node->display(node);
    cout << endl
         << "insert node of the starting" << endl;
    int val1;
    cin >> val1;
    node->insert_starting_node(node, val1);
    node->display(node);
    // cout<<endl<<"delete the ending node"<<endl;
    // node->delet_ending_node(node);
    // node-> display(node);
    return 0;
}