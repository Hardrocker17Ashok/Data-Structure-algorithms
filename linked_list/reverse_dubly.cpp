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
 // reverse of dubly linkd list
 structure* reverse_dubly(structure*&node){
    structure*pre=NULL;
    structure*current=node;
    structure*ahead;
    while(current!=NULL){
        ahead=current->next;
        current->next=pre;
        pre=current;
        current=ahead;
    }
    return pre;
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
    structure*sol=reverse_dubly(node);
    cout<<endl<<"reversing the linked list"<<endl;
    display(sol);
    return 0;
}