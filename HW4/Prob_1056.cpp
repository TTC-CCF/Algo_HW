#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int> > adj;
void dfs(vector<int>& vis, int cur){
    vis[cur] = 1;
    for (int i = 0; i < adj[cur].size(); ++i){
        if (!vis[adj[cur][i]]){
            dfs(vis, adj[cur][i]);
        }
    }
}

int dijkstra(int u){
    vector<int> dis(n, INT_MAX);
    vector<int> vis(n, 0);
    int ecc = -1;
    dis[u] = 0;
    queue<int> q;
    q.push(u);
    while(q.size()){
        int x = q.front();
        vis[x] = 1;
        ecc = max(ecc, dis[x]);
        q.pop();
        for (int i =0; i < adj[x].size(); ++i){
            if (!vis[adj[x][i]] && dis[adj[x][i]] > dis[x] + 1){
                dis[adj[x][i]] = dis[x]+1;
                q.push(adj[x][i]);
            }
        }
    }
    return ecc;
}

void solve(int cases){
    map<string, int> pos;
    vector<int> vis(n, 0);
    adj.clear();
    adj.resize(n);
    int cur_id = 0;
    for (int i = 0; i < m; ++i){
        string us,vs;
        cin>>us>>vs;
        int u,v;
        if (pos.find(us) == pos.end())
            pos[us] = cur_id++;
        
        if (pos.find(vs) == pos.end())
            pos[vs] = cur_id++;
        u = pos[us];
        v = pos[vs];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(vis,0);
    for (int i = 0; i < n; ++i){
        if (!vis[i]){
            cout << "Network "<<cases<<": DISCONNECTED\n\n";
            return;
        }
    }
    int maxi = -1;
    for (int i = 0; i < n; ++i){
        int ecti = dijkstra(i);
        maxi = max(maxi, ecti);
    }
    cout << "Network " << cases<<": "<< maxi<<"\n\n";

}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int c = 1;
    while (cin>>n>>m && n && m){
        solve(c);
        c++;
    }
    return 0;
}