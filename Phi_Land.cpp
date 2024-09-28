#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    
    for(char &c : s){
        if(c >= 'A' && c <= 'Z' ){
            c = c + 32;
        }
    }
    cout<<s<<endl;
    return 0;
}