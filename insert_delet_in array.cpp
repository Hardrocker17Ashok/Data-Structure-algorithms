#include<iostream>
using namespace std;

/* travarsal*/

void travarsal(int arr[],int num){
for(int i=0;i<num;i++){
        cout<<arr[i];
        cout<<" ";
}
}

/*insart*/

void insarton(int arr[],int num,int element,int capicity,int index){
    if(num>capicity){
        cout<<"wrong";
    }
    for(int i=(num-1);i>=index;i--){
        arr[i+1]=arr[i];
    }
    arr[index]=element;
    cout<<"right";
}
// delet the element

void deletion(int arr[],int size,int index){
    for(int i=index;i<size;i++){
        arr[i]=arr[i+1];
    }
}

int main(){
    int arr[20];
    int num,element,capicity=20,index1,index2;
    cout<<"enter the number of array "<<endl;
    cin>>num;
    for(int i=0;i<num;i++){
        cin>>arr[i];
    }
    cout<<"enter the number of element and index1"<<endl;
    cin>>element>>index1;
    travarsal(arr,num);
    cout<<endl;
    insarton(arr,num,element,capicity,index1);
    num +=1;
    cout<<"after insartion the array is"<<endl; 
    travarsal(arr,num);

    cout<<"now enter delet index"<<endl;
    cin>>index2;
    deletion(arr,num,index2);
    num-=1;
    cout<<"after deleting the array is"<<endl; 
    travarsal(arr,num);
    return 0;
}