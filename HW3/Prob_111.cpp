#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, siz = 0;
    string line;
    vector<int> rank;
    while(getline(cin,line)){
        stringstream buf;
        buf<<line;
        int * temp = new int[21];
        n = 0;
        while(buf>>temp[n]){
            n++;
        }
        if (n == 1){
            siz = temp[0];
            buf.str("");
            buf.clear();
            rank.clear();
            rank.resize(siz+1);
            getline(cin,line);
            buf<<line;
            for (int i = 1; i <= siz; ++i){
                buf>>rank[i];
            }
        }
        else{
            vector<int> cases(n+1);
            for (int i = 1; i <= siz; ++i){
                int key;
                key = temp[i-1];
                cases[key] = i;
            }
            for (int i = 1; i <= siz; ++i){
                cases[i] = rank[cases[i]];
            }
            vector<int> v;
            v.push_back(cases[1]);
            int len = 1;
            for (int i = 2; i <= siz; ++i){
                if (cases[i] < v.back()){
                    int pos = lower_bound(v.begin(),v.end(),cases[i])-v.begin();
                    v[pos] = cases[i];
                }
                else{
                    v.push_back(cases[i]);
                    len++;
                }
            }
            cout << len<<"\n";
        }

    }
}