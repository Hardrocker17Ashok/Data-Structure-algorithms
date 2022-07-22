#include<bits\stdc++.h>
using namespace std;
int main(){
    int lucky;
    vector<int>p ={12,11,1,20,3,14,2,3};
    for(int i=0;i<p.size();i++){
    cout<<p[i]<<" ";
    }
    cout<<endl;

    /*all perform for example delet first ,delet end ,delet number,
    insart first ,insert end,delet particular and so on*/

    // p.erase(p.begin());
    // p.erase(p.begin()+2);
    // p.insert(p.begin(),5);

    // for(int i=0;i<p.size();i++){
    // cout<<p[i]<<" ";
    // }

    /*searchin any number*/

    // cin>>lucky;
    // for(int i=0;i<p.size();i++){
    // if(p[i]==lucky){
    //     cout<<i;
    // }
    // else{
    //     cout<<"not found this number"<<end;
    // }
        /*deleting  any number*/

    // cin>>lucky;
    // for(int i=0;i<p.size();i++){
    // if(p[i]==lucky){
    //     p.erase(p.begin()+i);
    // }

    // }
    // for(int i=0;i<p.size();i++){
    // cout<<p[i]<<" ";
    // }
    return 0;
}