#include<bits/stdc++.h>
using namespace std;
int n, m;
int _find(vector<int> parent, int u){
    if (parent[u] == -1) return u;
    else return _find(parent, parent[u]);
}
void solve(){
    vector<pair<int,pair<int,int> > > edgeweight(m);
    for (int i =0; i < m; ++i){
        int u,v,w;
        cin>>u>>v>>w;
        edgeweight[i] = {w,{u,v}};
    }
    
    sort(edgeweight.begin(), edgeweight.end());
    int cur_edges = 0, idx = 0;
    vector<int> ans;
    vector<int> par(n,-1);
    vector<int> lev(n,0);
    bool fg = true;
    while (cur_edges < n-1 && idx < m){
        int u = _find(par, edgeweight[idx].second.first);
        int v = _find(par, edgeweight[idx].second.second);
        if (u != v){
            if (lev[u] < lev[v]){
                par[u] = v;
                lev[v]++;
            }
            else{
                par[v] = u;
                lev[u]++;
            }
            cur_edges++;
        }
        else{
            fg = false;
            ans.push_back(edgeweight[idx].first);
        }
        idx++;
    }
    if (fg && idx == m) cout << "forest\n";
    else{
        for (; idx < m; ++idx){
            ans.push_back(edgeweight[idx].first);
        }
        for (int i = 0; i<ans.size(); ++i){
            if (i == ans.size()-1) cout << ans[i] << "\n";
            else cout << ans[i] << " ";
        }
    }
    
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    while (cin>>n>>m && (n || m)){
        solve();
    }
    return 0;
}