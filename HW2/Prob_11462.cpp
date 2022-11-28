#include<bits/stdc++.h>
using namespace std;
int n;
int ages[2000001] = {};
void solve(){
    for (int i = 0 ;i < n; ++i){
        cin >> ages[i];
    }
    sort(ages, ages+n);
    for (int i = 0; i < n; ++i){
        if (i == n-1) cout << ages[i] << "\n";
        else cout << ages[i] << " ";
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    while (cin>>n){
        if (!n) break;
        solve();
    }
    return 0;
}