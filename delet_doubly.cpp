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
   //deleting node of starting node in dubly linked list
void deleting_starting(structure*&node){
    structure*deee=node;
    node->next->prev=NULL;
    node=node->next;
    free(deee);
}
  //deleting the ending node
  void deleting_ending(structure*&node){
    structure*p=node;
    while(p->next->next!=NULL){
        p=p->next;
    }
    structure*deee=p->next;
    p->next=NULL;
    free(deee);
}
    //creating dubly linked list
 void doubly_linked(structure* &node,int val){
    structure* n=new structure(val);
    if(node==NULL){
       n->next=node;
    if(node!=NULL){
    node->prev=n;
    }
    node=n;
       return;
    }
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
 // deleting node on any node in linked list
 void delete_any_node(structure*&node,int element){
    if(node->data==element){
        deleting_starting(node);
        return;
    }
    structure*p=node;
    while(p->data!=element){
        p=p->next;
    }
    if(p->next==NULL){
        deleting_ending(node);
        return;
    }
    p->prev->next=p->next;
    p->next->prev=p->prev;
    free(p);
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
    cout<<endl<<"enter position where you want delete the node"<<endl;
    int position;cin>>position;
    delete_any_node(node,position);
    display(node);
    return 0;
}