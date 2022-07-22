#include <iostream>
using namespace std;
class structure
{
public:
    int data;
    structure *next;
    structure(int val)
    {
        data = val;
        next = NULL;
    }
};
// insert of ending node
void circular_linked(structure *&node, int val)
{
    structure *n = new structure(val);
    if (node == NULL)
    {
        n->next = n;
        node = n;
        return;
    }
    structure *temp = node;
    while (temp->next != node)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = node;
}
void display(structure *node)
{
    structure *start = node;
    do
    {
        cout << node->data << " ";
        node = node->next;
    } while (node != start); // if we inisilize here null replace of start so we will see circular limked list
}
//  insert value of starting node

structure *inser_at_starting(structure *&node, int val)
{
    structure *n = new structure(val);
    structure *temp = node;
    while (temp->next != node)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = node;
    node = n;
    return node;
}
// insert at a node
structure *inser_at_a_node(structure *&node, int node_ele, int val)
{
    structure *n = new structure(val);
    structure *temp = node;
    if (node->data == node_ele)
    {
        while (temp->next != node)
        {
            temp = temp->next;
        }
        temp->next = n;
        n->next = node;
        node = n;
        return node;
    }
    while (temp->next->data != node_ele)
    {
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next = n;
    return node;
}
int main()
{
    structure *node = NULL;
    circular_linked(node, 1);
    // cout<<"hello"<<endl;
    circular_linked(node, 3);
    circular_linked(node, 4);
    circular_linked(node, 2);
    circular_linked(node, 5);
    circular_linked(node, 6);
    circular_linked(node, 7);
    display(node);
    cout << endl
         << "enter the value whose you want add at starting node" << endl;
    int val;
    cin >> val;
    inser_at_starting(node, val);
    display(node);
    cout << "enter the value of node and value of new node whose you want add" << endl;
    int val1, node_ele;
    cin >> node_ele >> val1;
    inser_at_a_node(node, node_ele, val1);
    display(node);
    return 0;
}