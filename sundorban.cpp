#include<bits/stdc++.h>

using namespace std;
char a[50][50];
int dis[50][50];

bool vis[50][50];
int n;
vector<pair<int,int> > d = {{0,1},{0,-1},{1,0},{-1,0}};
bool valid(int ci,int cj){
    if(ci>=0 && ci<=n && cj>= 0 && cj<n)
        return true;
    else
        return false;
}
void bfs(int si,int sj){
    queue<pair<int,int> > q;
    q.push({si,sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;

    while(!q.empty()){
        pair<int,int> f = q.front();
        q.pop();
        for(int i = 0;i<4;i++){
            int ci = f.first + d[i].first;
            int cj = f.second + d[i].second;
            if(valid(ci,cj) && !vis[ci][cj] && a[ci][cj] != 'T'){
                vis[ci][cj] = true;
                q.push({ci,cj});
                dis[ci][cj] = dis[f.first][f.second] + 1;
            }
        }
        
    }
}
int main(){

    while(cin>>n){
        int si,sj,di,dj;
        memset(vis,false,sizeof(vis));
        memset(dis,-1,sizeof(dis));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin>>a[i][j];
                if(a[i][j] == 'S'){
                    si = i;
                    sj = j;
                }
                if(a[i][j] == 'E'){
                    di = i;
                    dj = j;
                }
            }
            
        }
        bfs(si,sj);
        cout << dis[di][dj] << endl;
        
    }
    return 0;
}