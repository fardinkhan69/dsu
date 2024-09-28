#include<bits/stdc++.h>

using namespace std;
int const N = 1e5+5;
int par[N];

void dsu_initialiazation(int n){
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
    }
    par[1]=3;
    par[2] = 1;
    
}
int find(int node){
    if(par[node] == -1){
        return node;
    }
    int leader = find(par[node]);
    par[node] = leader;
    return leader;

}
int main(){
    dsu_initialiazation(4);
    

    cout<<find(0)<<endl;
    cout<<find(1)<<endl;
    cout<<find(2)<<endl;
    

    
    return 0;
}