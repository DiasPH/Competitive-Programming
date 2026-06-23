#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
#define int long long
 
void solve () {
    int n; cin >> n;

    int aux = 1, res = 0;
    while(aux < n){
        aux *= 5;
        if(aux <= n){
            res += n / aux;
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