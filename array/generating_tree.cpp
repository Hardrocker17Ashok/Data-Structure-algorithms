// we can generate a tree 
#include<iostream>
using namespace std;
class binary{
    public:
    int data;
    binary*left;
    binary*right;
};
    binary* genrate_node(int val){
       binary *n1=new binary();
       n1->data=val;
       n1->left=NULL;
       n1->right=NULL;
       return n1;
    }
    void print(binary*node){
        if(node!=NULL){
            cout<<node->data<<endl;
            print(node->left);
            print(node->right);
        }
    }
int main(){
    binary *p1,*p2,*p3,*p4,*p5,*p6,*p7;
    // generating node of tree
    p1=genrate_node(10);
    p2=genrate_node(20);
    p3=genrate_node(30);
    p4=genrate_node(40);
    p5=genrate_node(50);
    p6=genrate_node(60);
    p7=genrate_node(70);
    // creating a tree by genrating node
    p1->left=p2;
    p1->right=p3;

    p2->left=p4;
    p2->right=p5;

    p3->left=p6;
    p3->right=p7;
    // its degined as below
    /*
           10
           /\
          /  \
         20  30
       /\     /\    
      /  \   /  \
     40  50 60  70 
    */
//    after generating we will trevalsal on this tree
    return 0;
}