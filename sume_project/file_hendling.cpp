#include<iostream>
#include<fstream>
using namespace std;
int main(){
    string s;
    ifstream ashok("tu28 friend class.cpp");
    ashok>>s;
    while(ashok.eof()==0){
    getline(ashok,s);
    cout<<s<<endl;
    }
    return 0;
}