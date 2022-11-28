#include<bits/stdc++.h>
using namespace std;
int n;
void if_else(string order, int level, string tas){
    if (level == n){
        cout << tas<<"writeln(";
        for (int i = 0; i < n; ++i){
            if (i < n-1)
            cout << order[i]<<",";
            else
            cout << order[i]<<")\n";
        }
    }
    else{
        string changes = order;
        for (int i = 0; i < level+1; ++i){
            if (i == 0){
                cout << tas + "if ";
                cout << order[level-1]<<" < "<<order[level]<<" then\n";
            }
            else if (i < level){
                cout << tas<<"else if ";
                cout << order[level - i - 1]<<" < "<<order[level]<<" then\n";
            }
            else {
                cout << tas<<"else\n";
            }
            if_else(changes, level+1, tas+"    ");
            if (level - i - 1 >= 0){
                char temp = changes[level - i];
                changes[level - i] = changes[level - i - 1];
                changes[level - i - 1] = temp;
            }
        }
    }
}
void solve(){
    cin>>n;
    cout << "program sort(input,output);\nvar\n";
    char alph = 'a';
    string alphs;
    for (int i = 0; i < n; ++i){
        if (i < n-1){
            cout << alph << ",";
        }
        else {
            cout << alph << " : integer;\nbegin\n";
        }
        alphs.push_back(alph);
        alph++;
    }
    cout <<  "    readln(";
    for (int i = 0; i < n; ++i){
        if (i < n-1)
        cout <<alphs[i]<<',';
        else 
        cout << alphs[i];
    }
    cout << ");\n";
    string tabs = "    ";

    if_else(alphs, 1, tabs);
    cout << "end.\n";
}
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    cin.ignore(123, '\n');
    while (T--){
        cin.ignore(123, '\n');
        solve();
        if (T!=0)
        cout << "\n";
    }
}