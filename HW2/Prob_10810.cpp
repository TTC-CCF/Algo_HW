#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int times = 0;
int arr[500001] = {};
void merge(int l, int mid, int r){
    int li = l, ri = mid+1;
    vector<int> a;
    while (li <= mid && ri <= r){
        if (arr[li] < arr[ri]){
            a.push_back(arr[li]);
            li++;
        }
        else if (arr[li] > arr[ri]){
            a.push_back(arr[ri]);
            times += mid - li + 1;
            ri++;
        }
        else{
            a.push_back(arr[li]);
            a.push_back(arr[ri]);
            li++;
            ri++;
        }
    }
    while (li <= mid) {
        a.push_back(arr[li]); 
        li++;
    }
    while (ri <= r) {
        a.push_back(arr[ri]); 
        ri++;
    }
    int i = l;
    for (auto e : a){
        arr[i] = e;
        i++;
    }
}
void mergeSort(int l, int r){
    if (l < r){
        int mid = (l + r) >> 1;
        mergeSort(l, mid);
        mergeSort(mid+1, r);
        merge(l, mid, r);
    }
}
void solve(){
    for (int i = 0 ;i < n; ++i){
        cin >> arr[i];
    }
    mergeSort(0, n-1);
    cout << times << "\n";
    // for (int i = 0 ;i < n; ++i){
    //     cout << arr[i] << " ";
    // }
    // cout << "\n";
    //cout << times<<"\n";
}
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    while (cin>>n){
        if (!n) break;
        solve();
        times = 0;
    }
    return 0;
}