#include<iostream>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int num;cin>>num;
        if(num<5){
            cout<<"1"<<endl;
        }
        else{
            if(num%3==0){
                cout<<num/3<<endl;
            }
            else{
                cout<<(num/3)+1<<endl;
            }
        }
    }
    return 0;
}