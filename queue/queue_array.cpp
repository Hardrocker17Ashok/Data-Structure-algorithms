#include<iostream>
#define n 10 
using namespace std;

// with array
class queue{
    int front,back;
    int *arr;
    public:
    queue(){
        arr= new int[n];
        front=-1;
        back=-1;
    }
    void inqueue(int val){
        if(front==n-1){
            cout<<"the queue is full"<<endl;
            return;
        }
        if(front==-1){
            front++;
        }
        back++;
        arr[back]=val;
    }
    void dequeue(){
        if(front==-1||front>back){
            cout<<"the queue is empty you dont delete any element"<<endl;
            return;
        }
        front++;
    }
    void display(){
        for(int i=front;i<back;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){

    // with array
    queue obj;
    obj.inqueue(10);
    obj.inqueue(20);
    obj.inqueue(30);
    obj.inqueue(40);
    obj.inqueue(50);
    obj.display();
    obj.dequeue();
    obj.dequeue();
    obj.display();
   return 0;
}