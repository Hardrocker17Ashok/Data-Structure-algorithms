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
bool isempty(structure*top){
if(top==NULL){
    return true;
}
else{
    return false;
}
}
 structure* linked_push(structure* &top,int val){
        structure* n=new structure(val);
    if(top==NULL){
        top=n;
    }
    else{
        n->next=top;
        top=n;
        return top;
 }
 }
 structure* linked_pop(structure* &top){
    if(isempty(top)){
        cout<<"stack is empty"<<endl;
        return 0;
    }
    else{
        structure* tnum=top->next;
        structure*num=top;
        top=top->next;
        free(num);
        return tnum;
    }
 }
 void print_stack(structure*top){
    while(top!=NULL){
        cout<<top->data<<" ";
        top=top->next;
    }
    cout<<endl;
 }
int main(){
    structure *node=NULL;
    linked_push(node,1);
    linked_push(node,2);
    linked_push(node,3);
    linked_push(node,4);
    linked_push(node,5);
    print_stack(node);
    linked_pop(node);
    linked_pop(node);
    print_stack(node);
    linked_pop(node);
    linked_pop(node);
    linked_pop(node);
    linked_pop(node);
    return 0;
}