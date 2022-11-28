#include<bits/stdc++.h>
using namespace std;
string num;
bool cpm(char a, char b){
    return a > b;
}
void solve(){
    cout << "Original number was "<< num << "\n";
    string as, de;
    map<int, int> hash;
    int pre_diff = -1, len = 0;
    as = de = num;
    hash[stoi(num)]++;
    while (len<=1000){
        sort(as.begin(), as.end());
        sort(de.begin(), de.end(), cpm);
        int n1 = stoi(as);
        int n2 = stoi(de);
        int diff = n2 - n1;
        hash[diff]++;
        cout << n2 << " - " << n1 << " = " << diff << "\n";
        len++;
        if (hash[diff] == 2 || len == 1000){
            cout << "Chain length " << len << "\n\n";
            break;
        }
        pre_diff = diff;
        stringstream ss;
        ss << diff;
        as = ss.str();
        de = ss.str();
    }   
}
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    while (1){
        cin>>num;
        if (num == "0")break;
        solve();
    }
    return 0;
}