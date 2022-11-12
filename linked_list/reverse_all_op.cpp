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
void display(don *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}
// reverse all node behyend the given value and value of ahead will bi same
don *reverse_back(don *&node,int val)
{
    don*n=node;
    don*pre=NULL;
    don*curr=node;
    don*ahead;
    while(curr->data!=val){
        ahead=curr->next;
        curr->next=pre;
        pre=curr;
        curr=ahead;
    }
    n->next=curr;
    return pre;
}
// reverse the linked list node whose given pair
don *reverse_pair(don *&node,int pair)
{
    // don*n=node;
    don*pre=NULL;
    don*curr=node;
    don*ahead;
    int c=0;
    while(curr!=NULL && c<pair){
        ahead=curr->next;
        curr->next=pre;
        pre=curr;
        curr=ahead;
        c++;
    }
    if(ahead!=NULL){
    node->next=reverse_pair(ahead,pair);
    }
    return pre;
}
int main()
{
    don *node = NULL;
    linked(node, 1);
    // cout<<*node<<endl;
    linked(node, 2);
    linked(node, 3);
    linked(node, 4);
    linked(node, 5);
    linked(node, 6);
    linked(node, 7);
    display(node);
    // int val1;cin>>val1;
    // don *sol1 = reverse_back(node,val1);
    // cout << endl
    //      << "after reversing" << endl;
    // display(sol1);
    int val2;cin>>val2;
    don *sol2 = reverse_pair(node,val2);
    cout << endl
         << "after reversing" << endl;
    display(sol2);
    return 0;
}