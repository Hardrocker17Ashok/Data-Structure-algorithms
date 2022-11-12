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
//  delete any given node

structure *delete_at_node(structure *&node, int val)
{
    structure *temp = node;
    if(temp->data==val){
        while (temp->next!=node)
        {
            temp=temp->next;
        }
        structure*deee=temp->next;
        temp->next=node->next;
        node=temp->next;
        free(deee);
        return node;
    }
    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    structure *deee=temp->next;
    temp->next=temp->next->next;
    free(deee);
    return node;
}
// delete ending  node
structure *delete_ending_node(structure *&node)
{
    structure *temp = node;
    {
        while (temp->next->next != node)
        {
            temp = temp->next;
        }
        structure*deee=temp->next;
        temp->next = node;
        free(deee);
        return node;
    }
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
    delete_at_node(node, val);
    display(node);
    cout<<endl<<"after the deleting ending node"<<endl;
    delete_ending_node(node);
    display(node);
    return 0;
}