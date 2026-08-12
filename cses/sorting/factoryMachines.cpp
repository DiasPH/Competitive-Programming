#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
#define int long long
 
void solve () {
    int n, k; cin >> n >> k;
    vector<int> v;

    for(int i = 0; i < n; i++){
        int num; cin >> num;
        v.push_back(num);
    }

    int l = 1, r = 1e18+5;
    int m = (l+r)/2, res = 1e18+5;
    while(l <= r){
        int cont = 0;
        m = (l+r)/2;
        
        for(int i =0; i < n; i++){
            cont += m/v[i];
            if(cont > k){
                cont = k;
                break;
            }
        }

        if(cont >= k){
            res = min(res, m);
            r = m - 1;
        }
        else{
            l = m + 1;
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