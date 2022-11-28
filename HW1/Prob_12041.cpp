#include<bits/stdc++.h>
#define int long long 
using namespace std;
int fib[24][2] = {{1,1}};
void init(){
    for (int i = 1; i < 24; ++i){
        fib[i][0] = fib[i-1][0] + fib[i-1][1];
        fib[i][1] = fib[i-1][1] + fib[i][0];
    }
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    init();
    int terms;
    cin>>terms;
    while (terms--){
        int N, i, j, level, mode;
        string ans="";
        cin >> N >> i >> j;
        
        for (int k = i; k <= j; ++k){
            level = N > 47 ? (46+(N%2))/2:N/2;
            mode = N%2;

            int index = k + 1;
            while (level != 0){
                if (mode == 0){
                    if (index > fib[level-1][0]){
                        index -= fib[level-1][0];
                        mode = 1;
                    }
                }
                else if (mode == 1){
                    if (index > fib[level-1][1]){
                        index -= fib[level-1][1];
                        mode = 0;
                        level++;
                    }
                }
                level--;
            }
            if (mode == 1)
                ans += '1';
            else    
                ans += '0';
        }
        cout << ans << "\n";
    }
    return 0;
}