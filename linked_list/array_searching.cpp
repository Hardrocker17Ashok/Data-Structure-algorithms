#include<iostream>
using namespace std;

/* for liner sarching */

int liner_sarching(int arr[],int size,int element){
    for(int i=0;i<size;i++)
    {
        if(arr[i]==element)
        {
            return i;
        }
    }
}

/* code of binary sarching*/

int binary_sarching(int arr[],int size,int element)
{
    int low,mid,high;
    low=0;
    high=(size-1);
    while(low<=high)
    {
    mid=(high+low)/2;
    if(arr[mid]==element){
        return mid;
    }
    else if(arr[mid]<element){
        low=mid+1;
    }
    else if(arr[mid]>element){
        high=mid-1;
    }
    }
    return -1;
}
int main(){
    int arr[20];
    int index,element,size;
cout<<"enter the size"<<endl;
    cin>>size;
    cout<<"enter the array "<<endl;
for(int i=0;i<size;i++){
    cin>>arr[i];    
}
    cout<<"the display arry is "<<endl;
for(int i=0;i<size;i++){
    cout<<arr[i];
    cout<<" ";    
}
    cout<<endl;
    cout<<"enter the element number"<<endl;
    cin>>element;
// cout<<"the element  "<<element<<"  of index is  "<<liner_sarching(arr,size,element);
cout<<"the element  "<<element<<"  of index is  "<<binary_sarching(arr,size,element);
return 0;
}