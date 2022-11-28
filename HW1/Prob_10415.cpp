#include<bits/stdc++.h>
using namespace std;
bool press[10]={false};
int pressNumber[10]={0};
void c(){
    press[0] = false;
    if (!press[1]){
        pressNumber[1]++;
        press[1] = true;
    }
    if (!press[2]){
        pressNumber[2]++;
        press[2] = true;
    }
    if (!press[3]){
        pressNumber[3]++;
        press[3] = true;
    }
    if (!press[6]){
        pressNumber[6]++;
        press[6] = true;
    }
    if (!press[7]){
        pressNumber[7]++;
        press[7] = true;
    }
    if (!press[8]){
        pressNumber[8]++;
        press[8] = true;
    }
    if (!press[9]){
        pressNumber[9]++;
        press[9] = true;
    }
}
void d(){
    press[0] = press[9] = false;
    if (!press[1]){
        pressNumber[1]++;
        press[1] = true;
    }
    if (!press[2]){
        pressNumber[2]++;
        press[2] = true;
    }
    if (!press[3]){
        pressNumber[3]++;
        press[3] = true;
    }
    if (!press[6]){
        pressNumber[6]++;
        press[6] = true;
    }
    if (!press[7]){
        pressNumber[7]++;
        press[7] = true;
    }
    if (!press[8]){
        pressNumber[8]++;
        press[8] = true;
    } 
}
void e(){
    press[0] = press[9] = press[8] = false;
    if (!press[1]){
        pressNumber[1]++;
        press[1] = true;
    }
    if (!press[2]){
        pressNumber[2]++;
        press[2] = true;
    }
    if (!press[3]){
        pressNumber[3]++;
        press[3] = true;
    }
    if (!press[6]){
        pressNumber[6]++;
        press[6] = true;
    }
    if (!press[7]){
        pressNumber[7]++;
        press[7] = true;
    }
    
}
void f(){
    press[0] = press[9] = press[8] = press[7] = false;
    if (!press[1]){
        pressNumber[1]++;
        press[1] = true;
    }
    if (!press[2]){
        pressNumber[2]++;
        press[2] = true;
    }
    if (!press[3]){
        pressNumber[3]++;
        press[3] = true;
    }
    if (!press[6]){
        pressNumber[6]++;
        press[6] = true;
    }
}
void g(){
    press[0] = press[9] = press[8] = press[7] = press[6] = false;
    if (!press[1]){
        pressNumber[1]++;
        press[1] = true;
    }
    if (!press[2]){
        pressNumber[2]++;
        press[2] = true;
    }
    if (!press[3]){
        pressNumber[3]++;
        press[3] = true;
    }
}
void a(){
    press[0] = press[9] = press[8] = press[7] = press[6] = press[3] = false;
    if (!press[1]){
        pressNumber[1]++;
        press[1] = true;
    }
    if (!press[2]){
        pressNumber[2]++;
        press[2] = true;
    }
}
void b(){
    press[0] = press[9] = press[8] = press[7] = press[6] = press[3] = press[2] = false;
    if (!press[1]){
        pressNumber[1]++;
        press[1] = true;
    }
}
void C(){
    press[0] = press[9] = press[8] = press[7] = press[6] = press[3] = press[1] = false;
    if (!press[2]){
        pressNumber[2]++;
        press[2] = true;
    }
}
void D(){
    press[9] = false;
    if (!press[0]){
        pressNumber[0]++;
        press[0] = true;
    }
    if (!press[1]){
        pressNumber[1]++;
        press[1] = true;
    }
    if (!press[2]){
        pressNumber[2]++;
        press[2] = true;
    }
    if (!press[3]){
        pressNumber[3]++;
        press[3] = true;
    }
    if (!press[6]){
        pressNumber[6]++;
        press[6] = true;
    }
    if (!press[7]){
        pressNumber[7]++;
        press[7] = true;
    }
    if (!press[8]){
        pressNumber[8]++;
        press[8] = true;
    } 
}
void E(){
    press[8] = press[9] = false;
    if (!press[0]){
        pressNumber[0]++;
        press[0] = true;
    }
    if (!press[1]){
        pressNumber[1]++;
        press[1] = true;
    }
    if (!press[2]){
        pressNumber[2]++;
        press[2] = true;
    }
    if (!press[3]){
        pressNumber[3]++;
        press[3] = true;
    }
    if (!press[6]){
        pressNumber[6]++;
        press[6] = true;
    }
    if (!press[7]){
        pressNumber[7]++;
        press[7] = true;
    }
}
void F(){
    press[7] = press[8] = press[9] = false;
    if (!press[0]){
        pressNumber[0]++;
        press[0] = true;
    }
    if (!press[1]){
        pressNumber[1]++;
        press[1] = true;
    }
    if (!press[2]){
        pressNumber[2]++;
        press[2] = true;
    }
    if (!press[3]){
        pressNumber[3]++;
        press[3] = true;
    }
    if (!press[6]){
        pressNumber[6]++;
        press[6] = true;
    }
}
void G(){
    press[6] = press[7] = press[8] = press[9] = false;
    if (!press[0]){
        pressNumber[0]++;
        press[0] = true;
    }
    if (!press[1]){
        pressNumber[1]++;
        press[1] = true;
    }
    if (!press[2]){
        pressNumber[2]++;
        press[2] = true;
    }
    if (!press[3]){
        pressNumber[3]++;
        press[3] = true;
    }
}
void A(){
    press[3] = press[6] = press[7] = press[8] = press[9] = false;
    if (!press[0]){
        pressNumber[0]++;
        press[0] = true;
    }
    if (!press[1]){
        pressNumber[1]++;
        press[1] = true;
    }
    if (!press[2]){
        pressNumber[2]++;
        press[2] = true;
    }
    
}
void B(){
    press[2] = press[3] = press[6] = press[7] = press[8] = press[9] = false;
    if (!press[0]){
        pressNumber[0]++;
        press[0] = true;
    }
    if (!press[1]){
        pressNumber[1]++;
        press[1] = true;
    }
}
int main(){
    int t;
    string note;
    scanf("%d", &t);
    cin.get();
    while (t--){
        memset(pressNumber, 0, sizeof(pressNumber));
        memset(press, false, sizeof(press));
        note.clear();
        getline(cin, note, '\n');
        for (auto n : note){
            switch(n){
                case 'c':
                    c();
                    break;
                case 'd':
                    d();
                    break;
                case 'e':
                    e();
                    break;
                case 'f':
                    f();
                    break;
                case 'g':
                    g();
                    break;
                case 'a':
                    a();
                    break;
                case 'b':
                    b();
                    break;
                case 'C':
                    C();
                    break;
                case 'D':
                    D();
                    break;
                case 'E':
                    E();
                    break;
                case 'F':
                    F();
                    break;
                case 'G':
                    G();
                    break;
                case 'A':
                    A();
                    break;
                case 'B':
                    B();
                    break;
            }
        }
        for (int i = 0; i < 10; ++i){
            if (i < 9)
                printf("%d ", pressNumber[i]);
            else
                printf("%d\n", pressNumber[i]);
        }
    }
    
}