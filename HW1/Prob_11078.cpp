#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int terms;
    cin >> terms;
    while (terms--){
        int student, n;
        cin >> student;
        n = student;
        set<int> s1, s2;
        for (int i = 0; i < n; ++i){
            int v;
            cin >> v;
            if(i)
                s2.insert(*s1.rbegin() - v);
            s1.insert(v);
        }
        
        cout << *s2.rbegin() << "\n";

    }
    return 0;
}