#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll const N = 2e5 + 5;
ll int par[N];
ll int group_size[N];
void dsu_initialize(ll n)
{
    for (ll i = 0; i < n; i++)
    {
        par[i] = -1;
        group_size[i] = 1;
    }
}

ll dsu_find(ll node)
{
    if (par[node] == -1)
        return node;
    ll leader = dsu_find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union_by_size(ll node1, ll node2)
{
    ll leaderA = dsu_find(node1);
    ll leaderB = dsu_find(node2);

    if (group_size[leaderA] > group_size[leaderB])
    {
        par[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        par[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}
class Edge{
    public:
    ll u;
    ll v;
    ll w;;
    Edge(ll u,ll v,ll w){
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
bool cmp(Edge a1,Edge b1){
    return a1.w < b1.w;
}
int main()
{
    ll n, e;
    cin >> n >> e;
    dsu_initialize(n);
    vector<Edge> EdgeList;
    while(e--){
        ll u,v,w;
        cin>>u>>v>>w;
        EdgeList.push_back(Edge(u,v,w));

    }
    sort(EdgeList.begin(),EdgeList.end(),cmp);
    ll totalCost = 0;
    for(Edge ed : EdgeList){
        ll leaderU = dsu_find(ed.u);
        ll leaderV = dsu_find(ed.v);
        if(leaderU == leaderV)
            continue;
        else{
            dsu_union_by_size(ed.u,ed.v);
            totalCost += ed.w;
        }
    }
    int firstLeader = dsu_find(0);
    bool allConnected = true;
    for(int i = i;i<n;i++){
        if(dsu_find(i) != firstLeader){
            allConnected = false;
            break;
        }
    }
    if(allConnected){
        cout<<totalCost<<endl;
    }else{
        cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}