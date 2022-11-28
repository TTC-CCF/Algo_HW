#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    vector<int> P;
    int x;
    // string temp;
    // getline(cin,temp);
    // for (int i = 0; i < temp.length(); ++i){
    //     if (temp[i] != ' ')
    //         P.push_back(temp[i]-'0');
    // }
    while (cin>>x){
        P.push_back(x);
        if (cin.get() == '\n')
            break;
    }
    vector<string> Data(P.size()+1);
    for (int i = 0; i < P.size(); ++i){
        string s;
        cin >> s;
        Data[P[i]] = s;
    }
    cin.ignore(128, '\n');
    for (int i = 1; i < Data.size(); ++i)
        cout << Data[i] << "\n";
}
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T;
    cin >> T;
    string d;
    cin.ignore(127, '\n');
    while (T--){
        cin.ignore(128, '\n');
        solve();
        if (T != 0)
        cout << "\n";
    }
    return 0;
}