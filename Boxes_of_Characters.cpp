#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int con = 0;
        int vow = 0;
        int dig = 0;
        for(char c : s){
            if(c =='a' || c=='e' || c == 'i' || c == 'o' || c == 'u' ){
                vow++;
            }else if(isdigit(c)){
                dig++;
            }else{
                con++;
            }
        }
        int box = 0;
        while(con > 0 || vow > 0 || dig > 0){
            box++;
            con = max (0,con-3);
            vow = max(0,vow-2);
            dig = max(0,dig-1);
        }
        cout<<box<<endl;
    }
    return 0;
}