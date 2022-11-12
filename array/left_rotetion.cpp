#include<iostream>
using namespace std;

/* travarsal*/

void travarsal(int arr[],int num){
for(int i=0;i<num;i++){
        cout<<arr[i];
        cout<<" ";
}
}

void replace2(int arr[],int num){
    int stor=arr[0];
    for(int i=0;i<(num-1);i++){
        arr[i]=arr[i+1];
    }
        arr[num-1]=stor;
}
int main(){
    int arr[20];
    int num,i;
    cout<<"enter the number "<<endl;
    cin>>num;
    for(int i=0;i<num;i++){
        cin>>arr[i];
    }
    cout<<"the array is"<<endl; 
    travarsal(arr,num);
    cout<<endl;
    cout<<"replace all term of array is"<<endl;
    for(i=0;i<num;i++)
    { 
    replace2(arr,num);
    travarsal(arr,num);
    cout<<endl;
    }
    // cout<<endl;
    // cout<<"replace two term array is"<<endl; 
    // replace2(arr,num);
    // travarsal(arr,num);
    // cout<<endl;
    // cout<<"replace three term array is"<<endl; 
    // replace2(arr,num);
    // travarsal(arr,num);
    return 0;
}