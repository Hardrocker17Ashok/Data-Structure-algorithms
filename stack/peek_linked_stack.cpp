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
 void print_stack(structure*top){
    while(top!=NULL){
        cout<<top->data<<" ";
        top=top->next;
    }
    cout<<endl;
 }
//  search from any index
 int peek_function(structure*top,int point){
    structure*p=top;
    int count=1;
    while(p!=NULL&&count<point){
        p=p->next;
        count++;
    }
    if(p!=NULL){
        return p->data;
    }
    else{
        return -1;
    }
 }
//  find from bottom
int find_from_bottom(structure*top){
    structure*p=top;
    while(p->next!=nullptr){
        p=p->next;
    }
    return p->data;
}
int main(){
    structure *node=NULL;
    linked_push(node,1);
    linked_push(node,2);
    linked_push(node,3);
    linked_push(node,4);
    linked_push(node,5);
    cout<<"the stack is"<<endl;
    print_stack(node);
    cout<<"enter the index from where you find data"<<endl;
    int index;cin>>index;
    cout<<peek_function(node,index);
    cout<<endl<<"the bottom element from this stack"<<endl;
    cout<<find_from_bottom(node);
    return 0;
}