#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
vector<vector<int> > mst_e;
vector<pair<int,int> > mst_es;

int _find(int u, vector<int>& parent){
    if (parent[u] == -1) return u;
    else return _find(parent[u], parent);
}

void find_subtree(int cur, int other_tree, vector<int>& vis){
    if (cur == other_tree) return;
    vis[cur] = true;
    for (int i = 0; i < mst_e[cur].size(); ++i){
        if (!vis[mst_e[cur][i]]){
            find_subtree(mst_e[cur][i], other_tree, vis);
        }
    }
}

void solve(){
    vector<pair<int,pair<int,int> > > order;
    vector<vector<int> > route(n, vector<int>(n));
    vector<vector<bool> > mst(n,vector<bool>(n,false));
    vector<vector<int> > mini_alt(n,vector<int>(n, INT_MAX));
    mst_e.clear();
    mst_es.clear();
    mst_e.resize(n);
    for (int i = 0; i<m; ++i){
        int u,v,c;
        cin>>u>>v>>c;
        if (u>v) swap(v,u);
        order.push_back({c,{u,v}});
        route[u][v] = c;
        route[v][u] = c;
    }
    sort(order.begin(), order.end());
    
    int edges = 0, idx = 0, ans = 0;
    vector<int> parent(n, -1);
    vector<int> lev(n, 0);
    while (edges < n-1){
        int x = _find(order[idx].second.first, parent);
        int y = _find(order[idx].second.second, parent);
        if (x != y){
            if(lev[x] > lev[y]){
                parent[y] = x;
                lev[x]++;
            }
            else{
                parent[x] = y;
                lev[y]++;
            }
            ans += order[idx].first;
            mst[order[idx].second.first][order[idx].second.second] = true;
            mst[order[idx].second.second][order[idx].second.first] = true;
            mst_e[order[idx].second.first].push_back(order[idx].second.second);
            mst_e[order[idx].second.second].push_back(order[idx].second.first);
            mst_es.push_back({order[idx].second.first,order[idx].second.second});
            edges++;
        }
        idx++;
    }
    for (int i = 0; i < n-1; ++i){
        int x = mst_es[i].first;
        int y = mst_es[i].second;
        vector<int> vis(n);
        find_subtree(x,y,vis);
        for (int j = 0; j < m; ++j){
            int a = order[j].second.first;
            int b = order[j].second.second;
            int c = order[j].first;
            if (((vis[a] and !vis[b]) || (!vis[a] and vis[b])) and !mst[a][b]){
                mini_alt[x][y] = order[j].first;
                mini_alt[y][x] = order[j].first;
                break;
            }
        }
    }
    int q;
    int sum = 0;
    cin>>q;
    for (int i = 0; i < q; ++i){
        int u, v, c;
        cin>>u>>v>>c;
        if (mst[u][v]){
            if (mini_alt[u][v] < c){
                sum += mini_alt[u][v]-route[u][v];
            }
            else
                sum += c - route[u][v];
        }
    }
    if (m == 0) cout << "0.0000\n";
    else cout << fixed << setprecision(4) << (sum/(double)q )+ ans << "\n";

}
int32_t main(){
    while (cin>>n>>m){
        if (n == 0 && m == 0) break;
        else solve();
    }
        
}