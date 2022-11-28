#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    while(cin>>n){
        if (n == 0) break;
        vector<string> words;
        string line;
        cin.get();
        while (1){
            getline(cin,line);
            bool have_character = false;
            for (auto c:line){
                if ((int)c <= 126 and (int)c >= 33){
                    have_character = true;
                    break;
                }
            }
            if (!have_character)
                break;
            for (int i = 0; i < line.length(); ++i){
                string s = "";
                bool inloop = false;
                while(line[i] <= 126 and line[i] >= 33){
                    s += line[i];
                    i++;
                    inloop = true;
                }
                if(inloop)
                    words.push_back(s);
            }
        }
        int numwords = words.size();
        vector<int> dp(numwords+2);
        vector<int> path(numwords+2);
        int* prelensum = new int[numwords+1];
        prelensum[0] = 0;
        for (int i = 1; i <= numwords; ++i)
            prelensum[i] = prelensum[i-1] + words[i-1].length();
        // for (int i = 0; i <= numwords; ++i)
        //     cout << prelensum[i] << " ";
        // cout <<"\n";
        for (int i = numwords; i > 0; --i){
            dp[i] = dp[i+1] + 500;
            path[i] = i;
            for (int j = i + 1; j <= numwords && prelensum[j]-prelensum[i-1]+j-i <= n; ++j){
                int spaces = n - prelensum[j] + prelensum[i-1];
                int spshorter = spaces/(j-i);
                int numshorter = (spshorter+1)*(j-i) - spaces;
                int cost = numshorter*(spshorter-1)*(spshorter-1)+(j-i-numshorter)*spshorter*spshorter;
                if (dp[i] >= dp[j+1]+cost){
                    dp[i] = dp[j+1]+cost;
                    path[i] = j+1;
                }
            }
        }
        // for (int i = 0; i < numwords; ++i){
        //     cout << dp[i] << " ";
        // }
        // cout << "\n";
        // for (int i = 0; i < numwords; ++i)
        //     cout << path[i] <<" ";
        // cout << "\n";
        int idx = 1;
        while (idx <= numwords){
            if (path[idx] > idx){
                int to = path[idx]-1;
                int from = idx - 1;
                int blanks = n - prelensum[to] + prelensum[from];
                int shorter_blanks = blanks/(to-from-1);
                int numshorter = (shorter_blanks+1)*(to-from-1)-blanks;
                int cnt = 0;
                cout << words[from];
                for (int i = from+1; i < to; ++i){
                    for (int j = 0; j < shorter_blanks; ++j){
                        cout << " ";
                    }
                    cnt++;
                    if (cnt > numshorter) 
                        cout << " ";
                    cout <<words[i];
                }
                cout << "\n";
                idx = path[idx];
            }
            else{
                cout << words[idx-1] << "\n";
                idx++;
            }
        }
        cout << "\n";
    }
    return 0;
}