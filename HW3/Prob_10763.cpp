#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    while(cin>>n){
        if (n == 0) break;
        vector<int> from(n),des(n);
        for (int i = 0; i < n; ++i){
            int f,d;
            cin>>f>>d;
            from[i] = f;
            des[i] = d;
        }
        sort(from.begin(),from.end());
        sort(des.begin(),des.end());
        bool fg = true;
        for (int i = 0; i < n; ++i){
            if (from[i] != des[i]){
                fg = false;
                cout << "NO\n";
                break;
            }
        }
        if (fg){
            cout << "YES\n";
        }
    }
}