#include<bits/stdc++.h>
using namespace std;

int visitTime;
vector<int> _visit;

int sizeToint(string s){
    if (s == "XS")
        return 0;
    else if (s == "S")
        return 1;
    else if (s == "M")
        return 2;
    else if (s == "L")
        return 3;
    else if (s == "XL")
        return 4;
    else
        return 5;

}
bool dfs(vector<vector<int> >& Ts, int cur_idx, int cur_dep){
    int cur_size = Ts[cur_dep][cur_idx];
    _visit[cur_size]--;
    if (cur_dep < Ts.size()-1){
        if (_visit[cur_size] < 0) {
            _visit[cur_size]++;
            return false;
        }
        if (!(dfs(Ts, 0, cur_dep+1) || dfs(Ts, 1, cur_dep+1))){
            _visit[cur_size]++;
            return false;
        }
        else return true;
    }
    else {
        if (_visit[cur_size] < 0) {
            _visit[cur_size]++;
            return false;
        }
        else
            return true;
    }
}
void solve(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m;
    cin>>n>>m;
    visitTime = n / 6;
    _visit.clear();
    _visit.resize(6, visitTime);
    vector<vector<int> > Tshirtsize(m);
    for (int i = 0; i < m; ++i){
        string s1,s2;
        cin>>s1>>s2;
        int size1 = sizeToint(s1);
        int size2 = sizeToint(s2);
        Tshirtsize[i] = {size1,size2};
    }
    bool fg1 = dfs(Tshirtsize, 0, 0);
    _visit.clear();
    _visit.resize(6, visitTime);
    bool ans = fg1 || dfs(Tshirtsize, 1, 0);
    if (ans) cout << "YES\n";
    else cout << "NO\n";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}