#include<iostream>
using namespace std;
int main(){
    int arr[10],max,i,j,temp;
    int size;
    cout<<"enter the number of size"<<endl;
    cin>>size;
    cout<<"enter the array number "<<endl;
    for(i=0;i<size;i++){
        cin>>arr[i];
    }  

    /*  FOR BIGGEST AND SMALLEST */  

    // // for maximum number
    // max=arr[0];
    // for(i=0;i<size;i++){
    //     if(arr[i]>max){
    //     max=arr[i];
    //     }
    // }
    // max=arr[0];
    //    cout<<max<<endl;
    // // for minimum number
    // // for(i=0;i<size;i++){
    // //     if(arr[i]<max){
    // //     max=arr[i];
    // //     }
    // // }
    // // cout<<max<<endl;

    /* NOW GENRATE  INCREASE ORDER ARRAY */

    for(i=0;i<size;i++){
        for(j=(i+1);j<size;j++){
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for(i=0;i<size;i++){
    cout<<arr[i]<<endl;
    }

    /* NOW GENRATE  DECREASE ORDER ARRAY */

    // for(i=0;i<size;i++){
    //     for(j=(i+1);j<size;j++){
    //         if(arr[i]<arr[j]){
    //             temp=arr[i];
    //             arr[i]=arr[j];
    //             arr[j]=temp;
    //         }
    //     }
    // }
    // for(i=0;i<size;i++){
    // cout<<arr[i]<<endl;
    // }
return 0;
}