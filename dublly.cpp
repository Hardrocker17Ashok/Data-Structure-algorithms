#include<iostream>
using namespace std;

class myself{
    public:
    int data;
    myself*next;
    myself*prv;
void display(myself* node){
    struct myself*p=node;
    while(p!=NULL){
        cout<<p->data<<endl;
        p=p->next;
    }
}

void display1(myself* node1){
    struct myself*p1=node1;
    while(p1!=NULL){
        cout<<p1->data<<endl;
        p1=p1->prv;
    }
}

myself* display2(myself* node2,int a){
    myself*p2=node2;
    myself*q2=p2->prv;
    for(int i=0;i<(a-1);i++){
        p2=p2->prv;
        q2=q2->prv;
    }
    p2->prv=q2->prv;
    free(q2);
    return node2;
}
// struct myself* insart_first(struct myself*ptr1,int element){
//     struct myself*as=(struct myself*)malloc(sizeof(struct myself));
//     as->data=element;
    
//     struct myself*p1=ptr1->next;
//     while(p1->next!=ptr1){
//         p1=p1->next;
//     }
//     p1->next=as;
//     as->next=ptr1;

//     return ptr1;
};
int main(){

    myself imp;
    myself *first;
    myself *second;
    myself *third;
    myself *fourth;
    myself *fiveth;

    first=(myself*)malloc(sizeof(myself ));
    second=(myself*)malloc(sizeof(myself ));
    third=(myself*)malloc(sizeof(myself ));
    fourth=(myself*)malloc(sizeof(myself ));
    fiveth=(myself*)malloc(sizeof(myself ));

    first->prv=NULL;
    first->data=100;
    first->next=second;

    second->prv=first;
    second->data=200;
    second->next=third;

    third->prv=second;
    third->data=300;
    third->next=fourth;

    fourth->prv=third;
    fourth->data=400;
    fourth->next=fiveth;

    fiveth->prv=fourth;
    fiveth->data=500;
    fiveth->next=NULL;

    cout<<"single"<<endl;
    imp.display(first);
    cout<<endl;

    cout<<"previou"<<endl;
    imp.display1(fiveth);
    cout<<endl;

    cout<<"delet"<<endl;
    imp.display2(fiveth,4);
    cout<<endl;
    imp.display1(fiveth);
    cout<<endl;
    // first=insart_first(first,25);
    // cout<<"after"<<endl;
    // display(first);
    return 0;
}