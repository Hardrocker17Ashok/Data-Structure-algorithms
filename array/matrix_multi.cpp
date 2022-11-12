#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
    cin>>t;
	while(t--){
	    int num;cin>>num;
	    string s;cin>>s;
	    int length=s.size();
	    int c1=0;
	    if(length<4){
	        cout<<"yes"<<endl;
	    }
	    else{
	        for(int i=0;i<4;i++){
	            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
	                c1++;
	            }
	        }
	            if(c1==0){
	                cout<<"no"<<endl;
	            }
	            else{
	                cout<<"yes"<<endl;
	            }
	    }
	}
	return 0;
}
