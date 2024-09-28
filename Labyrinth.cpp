#include <bits/stdc++.h>
using namespace std;
bool vis[1005][1005];
int dis[1005][1005];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;
char grid[1005][1005];
pair<int,int> parent[1005][1005];
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        int a = par.first, b = par.second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ci = a + d[i].first;
            int cj = b + d[i].second;
            if (valid(ci, cj) == true && vis[ci][cj] == false && grid[ci][cj] != '#')
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[a][b] + 1;
                parent[ci][cj] = {a,b};
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    int si, sj,di,dj;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if(grid[i][j] == 'A'){
                si = i;
                sj = j;
            }
            if(grid[i][j] == 'B'){
                di = i;
                dj = j;
            }
        }
    }
    

    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    bfs(si, sj);
    if(vis[di][dj]){
        cout<<"YES\n";
        cout<<dis[di][dj]<<endl;
        vector<pair<int,int>> path;
        pair <int,int> p = {di,dj};
        while(!(p.first== si && p.second == sj)){
            path.push_back(p);
            p = parent[p.first][p.second];
        }
        path.push_back({si,sj});
        reverse(path.begin(),path.end());
        string ans = "";
        for (int i = 1; i < path.size(); i++)
        {
            if(path[i-1].first == path[i].first){
                if(path[i-1].second + 1 == path[i].second){
                    ans.push_back('R');
                }else{
                    ans.push_back('L');
                }
            }else{
                if(path[i-1].first + 1 == path[i].first ){
                    ans.push_back('D');
                }else{
                    ans.push_back('U');
                }

            }
        }
        cout<<ans<<endl;
        
    }else{
        cout<<"NO\n";
    }
    
    return 0;
}