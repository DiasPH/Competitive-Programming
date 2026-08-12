#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
#define int long long
 
void solve () {
    int n, x; cin >> n >> x;
    vector<int> v;

    for(int i = 0; i < n; i++){
        int a; cin >> a;
        v.push_back(a);
    }



    int sum = 0, l = 0, r = 0, res = 0;
    while(l < n){
        if(r <= n-1){
            if(sum + v[r] > x){
                while(sum + v[r] > x){
                    sum -= v[l];
                    l++;
                }
            }
            sum += v[r];

            if(sum == x) res++;

            r++;
        }
        else{
            sum -= v[l];
            l++;
            if(sum == x) res++;
        }
    }

    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}