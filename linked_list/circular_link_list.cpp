#include<iostream>
using namespace std;
class structure{
    public:
    int data;
    structure *next;
    structure(int val){
        data=val;
        next=NULL;
    }
};
 void circular_linked(structure* &node,int val){
    structure* n=new structure(val);
    if(node==NULL){
       n->next=n;
       node=n;
       return;
    }
    structure*temp=node;
    while(temp->next!=node){
        temp=temp->next;
    }
    temp->next=n;
    n->next=node;
 }
 void display(structure*node){
    structure* start=node;
    do{
        cout<<node->data<<" ";
        node=node->next;
    }
    while(node!=start);     // if we inisilize here null replace of start so we will see circular limked list
 }
int main(){
    structure *node=NULL;
    circular_linked(node,1);
    // cout<<"hello"<<endl;
    circular_linked(node,3);
    circular_linked(node,4);
    circular_linked(node,2);
    circular_linked(node,5);
    circular_linked(node,6);
    circular_linked(node,7);
    display(node);
    return 0;
}