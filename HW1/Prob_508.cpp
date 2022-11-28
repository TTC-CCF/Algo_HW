#include<bits/stdc++.h>
using namespace std;
map<char, string> morseTable;
string context[103];
string code[103];
string morseCode[10000];
int idx1 = 0, idx2 = 0;
void getData(){
    char data;
    string morse;
    while (cin.peek() != '*'){
        cin>>data>>morse;
        morseTable[data] = morse;
        cin.get();
    }
    while (cin.get()!='\n');
    while (cin.peek() != '*'){
        cin>>context[idx1];
        idx1++;
        cin.get();
    }
    while (cin.get()!='\n');
    while (cin.peek() != '*'){
        cin>>morseCode[idx2];
        idx2++;
        cin.get();
    }
    return;
}

int main(){
    // idx1 : context's index
    // idx2 : morseCode's index
    getData();
    sort(context, context+idx1);
    for (int i = 0; i < idx1; ++i){
        string s;
        for (auto j : context[i]){
            s += morseTable[j];
        }
        code[i] = s;
    }

    for (int i = 0; i < idx2; ++i){
        bool found = false, dup = false;
        for (int j = 0; j < idx1; ++j){
            if (code[j] == morseCode[i]){
                if (found) {
                    dup = true;
                    continue;
                }
                cout << context[j];
                found = true;
            }
        }
        if (dup) cout << "!\n";
        else if (!dup && found) cout << "\n";
        else if (!found){
            int mini = INT_MAX;
            int a = morseCode[i].length(), key;
            bool firstime = true;
            for (int j = 0; j < idx1; ++j){
                int b = code[j].length();
                int diff;
                bool fg = true;
                if (a > b){
                    for (int k = 0; k < b; ++k){
                        if (code[j][k] != morseCode[i][k]){
                            fg = false;
                            break;
                        }
                    }
                }
                else{
                    for (int k = 0; k < a; ++k){
                        if (code[j][k] != morseCode[i][k]){
                            fg = false;
                            break;
                        }
                    }
                }
                diff = abs(a-b);
                if (fg && firstime){
                    firstime = false;
                    key = j;
                }
                if (fg && mini > diff){
                    mini = diff;
                    key = j;
                }
            }
            cout << context[key] <<"?\n";
        }
    }
    return 0;
}