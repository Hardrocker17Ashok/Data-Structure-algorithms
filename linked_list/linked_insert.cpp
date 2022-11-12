#include<iostream>
#include<stdlib.h>
using namespace std;
class ashok{
    public:
    int data;
    ashok *next;

   void display(ashok *ok){
        while(ok!=NULL){
            cout<<ok->data;
            cout<<" ";
            ok=ok->next;
        }
    }
    ashok *link_number(ashok *yes,int element,int index){
        ashok *ptr=(ashok*)malloc(sizeof(ashok));
        ptr->data=element;
        ashok *p1=yes;
        int i=0;
        while(i!=(index-1)){
        p1=p1->next;
        i++;
        }
        ptr->next=p1->next;
        p1->next=ptr;
        return yes;
    }
};

int main(){
    int element,index;
    ashok add;
    ashok *first;
    ashok *second;
    ashok *three;
    ashok *fourth;

    first=(ashok*)malloc(sizeof(ashok));
    second=(ashok*)malloc(sizeof(ashok));
    three=(ashok*)malloc(sizeof(ashok));
    fourth=(ashok*)malloc(sizeof(ashok));

    first->data=10;
    first->next=second;

    second->data=20;
    second->next=three;

    three->data=30;
    three->next=fourth;

    fourth->data=40;
    fourth->next=NULL;

    add.display(first);

    cout<<endl<<"enter the element for add in linked list "<<endl;
    cin>>element;
    cout<<endl<<"enter the index for add any element "<<endl;
    cin>>index;

    first=add.link_number(first,element,index);
    add.display(first);

    return 0;
}