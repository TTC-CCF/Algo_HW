#include<bits/stdc++.h>
using namespace std;
   
int main(){
    int weight, iq;
    vector<vector<int> > WSI(1001);
    int i = 0;
    while (cin>>weight>>iq){
        WSI[i].push_back(weight);
        WSI[i].push_back(iq);
        WSI[i].push_back(i+1);
        i++;
    }
    sort(WSI.begin(), WSI.begin()+i);

    // for (int j = 0; j < i; ++j){
    //     cout << WSI[j][0] << " " << WSI[j][1] << " " << WSI[j][2] << "\n";
    // }
    vector<int> value;
    vector<int> dp(i);
    int len = 1;
    value.push_back(WSI[0][1]);
    dp[0] = 1;

    for (int j = 1; j < i;++j){
        if (WSI[j][1] >= value.back()){
            int pos = lower_bound(value.begin(), value.end(), WSI[j][1], greater<int>())-value.begin();
            value[pos] = WSI[j][1];
            dp[j] = pos+1;
        }
        else{
            value.push_back(WSI[j][1]);
            len++;
            dp[j] = len;
        }
    }
    vector<int> ans;
    cout << len<<"\n";
    for (int j = i-1; j>= 0; --j){
        if (dp[j] == len){
            ans.push_back(WSI[j][2]);
            len--;
        }
    }
    for (int j = ans.size()-1; j >=0; --j){
        cout << ans[j]<<"\n";
    }
    
    

    return 0;
}