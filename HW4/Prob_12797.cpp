#include<bits/stdc++.h>
using namespace std;
#define inf 1000000
int n;

void solve(){
    string city[105];
    for (int i = 0; i < n; ++i)
        cin>>city[i];
    if (abs(city[0][0] - city[n-1][n-1]) == 32){
        cout << "-1\n";
        return;
    }
    int limit = pow(2,10)-1;
    int mini = inf;
    int start = (int)city[0][0];
    for (int set = 0; set <= limit; ++set){
        if ((65<=start && start<=74 && ((1<<(start-65)) & set) == 0)
        ||(97<=start && start<=106 && ((set^(1<<(start-97)))&(1<<(start-97))) == 0)){
            continue;
        }
        queue<pair<int,int> > q;
        vector<vector<int> > route(n,vector<int>(n,inf));
        bool vis[105][105] = {0};
        route[0][0] = 1;
        vis[0][0] = true;
        q.push({0,0});
        while (q.size()){
            int x = q.front().second;
            int y = q.front().first;
            q.pop();
            if (x+1<n && !vis[y][x+1]){
                int u = (int)city[y][x+1];
                if (65<=u && u<=74 && ((1<<(u-65)) & set) != 0){
                    q.push({y,x+1});
                    route[y][x+1] = route[y][x] + 1;
                    vis[y][x+1] = true;
                }
                else if (97<=u && u<=106 && ((set^(1<<(u-97)))&(1<<(u-97))) != 0){
                    q.push({y,x+1});
                    route[y][x+1] = route[y][x] + 1;
                    vis[y][x+1] = true;
                }
            }
            if (y+1<n && !vis[y+1][x]){
                int u = (int)city[y+1][x];
                if (65<=u && u<=74 && ((1<<(u-65)) & set) != 0){
                    q.push({y+1,x});
                    route[y+1][x] = route[y][x] + 1;
                    vis[y+1][x] = true;
                }
                else if (97<=u && u<=106 && ((set^(1<<(u-97)))&(1<<(u-97))) != 0){
                    q.push({y+1,x});
                    route[y+1][x] = route[y][x] + 1;
                    vis[y+1][x] = true;
                }
            }
            if (x-1>=0 && !vis[y][x-1]){
                int u = (int)city[y][x-1];
                if (65<=u && u<=74 && ((1<<(u-65)) & set) != 0){
                    q.push({y,x-1});
                    route[y][x-1] = route[y][x] + 1;
                    vis[y][x-1] = true;
                }
                else if (97<=u && u<=106 && ((set^(1<<(u-97)))&(1<<(u-97))) != 0){
                    q.push({y,x-1});
                    route[y][x-1] = route[y][x] + 1;
                    vis[y][x-1] = true;
                }
            }
            if (y-1>=0 && !vis[y-1][x]){
                int u = (int)city[y-1][x];
                if (65<=u && u<=74 && ((1<<(u-65)) & set) != 0){
                    q.push({y-1,x});
                    route[y-1][x] = route[y][x] + 1;
                    vis[y-1][x] = true;
                }
                else if (97<=u && u<=106 && ((set^(1<<(u-97)))&(1<<(u-97))) != 0){
                    q.push({y-1,x});
                    route[y-1][x] = route[y][x] + 1;
                    vis[y-1][x] = true;
                }
            }
            
        }
        mini = min(mini, route[n-1][n-1]);
    }
    int ans = (mini == inf ? -1:mini);
    cout << ans << "\n";
    
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    while (cin>>n){
        solve();
    }
}