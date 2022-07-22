#include<iostream>
using namespace std;
class structure{
    public:
    int data;
    structure *next;
    structure *prev;
    structure(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};
   //adding node of starting node in dubly linked list
void add_starting(structure*&node,int val){
    structure* n=new structure(val);
    n->next=node;
    if(node!=NULL){
    node->prev=n;
    }
    node=n;
}

    //creating dubly linked list
 void doubly_linked(structure* &node,int val){
    if(node==NULL){
       add_starting(node,val);
       return;
    }
    structure* n=new structure(val);
    structure*temp=node;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
 }
 void display(structure*node){
    while(node!=NULL){
        cout<<node->data<<" ";
        node=node->next;
    }
 }
 // insert node on any node in linked list
 void insert_any_node(structure*&node,int val,int element){
    if(node->data==element){
        add_starting(node,val);
        return;
    }
    structure*n=new structure(val);
    structure*p=node;
    while(p->next->data!=element){
        p=p->next;
    }
    n->next=p->next;
    p->next=n;
    n->prev=p;
    n->next->prev=n;
 }
int main(){
    structure *node=NULL;
    doubly_linked(node,1);
    doubly_linked(node,3);
    doubly_linked(node,4);
    doubly_linked(node,2);
    doubly_linked(node,5);
    doubly_linked(node,6);
    doubly_linked(node,7);
    display(node);
    cout<<endl<<"enter the value and after enter position"<<endl;
    int val,position;cin>>val>>position;
    insert_any_node(node,val,position);
    display(node);
    return 0;
}