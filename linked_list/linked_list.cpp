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
 void linked(structure* &node,int val){
    structure* n=new structure(val);
    if(node==NULL){
        node=n;
        return;
    }
    structure*temp=node;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
 }
 void display(structure*node){
    while(node!=NULL){
        cout<<node->data<<" ";
        node=node->next;
    }
 }
int main(){
    structure *node=NULL;
    linked(node,1);
    // cout<<*node<<endl;
    linked(node,2);
    linked(node,3);
    linked(node,4);
    linked(node,5);
    display(node);
    return 0;
}