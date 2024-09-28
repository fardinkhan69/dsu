#include <bits/stdc++.h>
using namespace std;
bool vis[1005][1005];
int dis[1005][1005];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
char a[1005][1005];
int n, m;
int cnt ;
bool valid(int i, int j)
{
    if(i >= 0 && i<n && j>=0 && j<m){
        return true;
    }else{
        return false;
    }
}

void dfs(int si, int sj)
{
    vis[si][sj] = true;
    cnt++;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) && !vis[ci][cj] && a[ci][cj] == '.')
        {
            dfs(ci, cj);
        }
    }
}
int main(){

    cin>>n>>m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>a[i][j];

        }
        
    }
    int mn = INT_MAX;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(a[i][j] == '.' && !vis[i][j]){
                flag = 1;
                cnt = 0;
                dfs(i,j);
                mn=min(mn,cnt);
            }

        }
        
    }

    if(flag){
        cout<<mn<<endl;
    }else{
        cout<<-1<<endl;
    }
    
    return 0;
}