#include<bits/stdc++.h>

using namespace std;
const int N = 105;
vector<int> v[N];
int dis_from_src[N];
int dis_from_des[N];
bool vis[N];

void bfs(int src,int x){
    vis[src] = true;
    queue<int> q;
    if(x == 1)
        dis_from_src[src] = 0;
    else
        dis_from_des[src] = 0;
    q.push(src);
    while(!q.empty()){
        int par = q.front();
        q.pop();

        for(int ch: v[par]){
            if(!vis[ch]){
                q.push(ch);
                vis[ch] = true;
                if(x == 1)
                    dis_from_src[ch] = dis_from_src[par] + 1;
                else
                    dis_from_des[ch] = dis_from_des[par] + 1;
            }
        }
    }
}
int main(){
    int t;
    cin>>t;
    int cs = 1;
    while(t--){
        int n,e;
        cin>>n>>e;
        while(e--){
            int a,b;
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);

        }

        int s,d;
        cin>>s>>d;
        for (int i = 0; i < n; i++)
        {
            vis[i] = false;
            dis_from_src[i] = -1;
        }

        bfs(s,1);
        for (int i = 0; i < n; i++)
        {
            vis[i] = false;
            dis_from_des[i] = -1;
        }
        bfs(d,2);

        int ans = INT_MIN;

        for(int i =0;i<n;i++){
            ans = max(ans,dis_from_src[i]+dis_from_des[i]);
        }

        cout<<"Case "<<cs++<<": "<<ans<<endl;
        for(int i = 0;i<n;i++){
            v[i].clear();
        }

    }
    return 0;
}