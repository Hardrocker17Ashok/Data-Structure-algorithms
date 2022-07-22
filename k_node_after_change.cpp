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
// int lenth(don*node){
//      int l=0;
//     while(node!=NULL){
//         node=node->next;
//         l++;
//     }
//     return l;
// }
// changes part of after k node 
don*node_from_k_node(don *&node,int index)
{
    don*newend;
    don*newhead;
    don*p=node;
    int co=1;
    while (p->next!= NULL)
    {
        if (co==index)
        {
            newend=p;
        }
        if(co==index+1){
            newhead=p;
        }
        p = p->next;
        co++;
    }
    newend->next=NULL;
    p->next=node;
    // node=newhead;
    return newhead;
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
    cout<<"enter the index "<<endl;
    int index;cin>>index;
    don*sol=node_from_k_node(node,index);
    cout<<"after changing linked list"<<endl;
    display(sol);
    return 0;
}