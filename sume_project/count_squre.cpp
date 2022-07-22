#include<bits/stdc++.h>
using namespace std;
int main(){
    int num,j=1,i;
    int count=0;
    int chek=0;
    cout<<"enter the number"<<endl;
    cin>>num;
    lable:
    for(i=1;i<num;i++)
    {
    count=count+pow(j,2);
    chek++;
    j++;
    if(count==num){
        cout<<chek;
        break;
    }
    else if(count>num){
        count=count-pow((j-1),2);
        chek=(chek-1);
        i=1;
        j=1;
        goto lable;
    }
    }
    return 0;
}