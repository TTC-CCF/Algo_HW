#include<bits/stdc++.h>
using namespace std;
int main(){
    int c;
    cin>>c;
    while(c--){
        int n, t, m;
        cin>>n>>t>>m;
        vector<int> time(m+1);
        for (int i = 1; i <= m; ++i){
            cin>>time[i];
        }
        if(m <= n) {
            cout << time[m]+t << " 1\n"; 
            continue;
        }
        int round = ceil(m/(double)n);
        int cur_time;
        if (m%n>0){
            cur_time = time[m%n]+2*t;
            for (int i = m%n+n; i <= m; i+=n){
                if (time[i] <= cur_time){
                    if (i == m)
                        cur_time += t;
                    else    
                        cur_time += 2*t;
                }
                else{
                    if (i == m)
                        cur_time = time[i] + t;
                    else
                        cur_time = time[i] + 2*t;
                }
            }
        }
        else{
            cur_time = time[n]+2*t;
            for (int i = 2*n; i <= m; i += n){
                if (time[i] <= cur_time){
                    if (i == m)
                        cur_time += t;
                    else
                        cur_time += 2*t;
                }
                else{
                    if (i == m)
                        cur_time = time[i] + t;
                    else
                        cur_time = time[i] + 2*t;
                }
            }
        }
        cout << cur_time << " " << round<<"\n";
    }
    return 0;
}