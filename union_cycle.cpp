#include<bits/stdc++.h>

using namespace std;
int const N = 1e5+5;
int parent[N];
int group_size[N];

void dsu_initialize(int n){
    for(int i =0;i<n;i++){
        parent[i] = -1;
        group_size[i] = 1;
    }
}
int dsu_find(int node)
{
    if (parent[node] == -1)
        return node;
    int leader = dsu_find(parent[node]);
    parent[node] = leader;
    return leader;
}
void dsu_union_size(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    if (group_size[leaderA] > group_size[leaderB])
    {
        parent[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        parent[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}
int main(){
    int n,e;
    cin>>n>>e;
    int cycle = false;
    dsu_initialize(n);
    while(e--){
        int a,b;
        cin>>a>>b;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        if(leaderA == leaderB){
            cycle = true;
        }else{
            dsu_union_size(a,b);
        }
    }
    if(cycle){
        cout<<"Cycle FOund"<<endl;
    }else{
        cout<<"Cycle not Found"<<endl;
    }
    return 0;
}