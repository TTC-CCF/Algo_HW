#include<bits/stdc++.h>
using namespace std;
int p, q, r, s, t, u;
double func(double x){
    return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}
int main(){
    double ans[10000];
    int i = 0;
    while (scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF){

        if (func(0)*func(1)>0)
            printf("No solution\n");
        else{
            double low=0, high=1;
            while (high-low > 0.0000001){
                double mid = (low + high)/2;
                if (func(mid)>0)
                    low = mid;
                else
                    high = mid;  
            }
            printf("%.4f\n", low);
        }
    }
    
}