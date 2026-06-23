#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
//#define int long long
const int modulo = 1e9 + 7;
 
void solve () {
    int n; cin >> n;

    int res = 1;
    for(int i = 0; i < n; i++){
        res *= 2;
        res = res % modulo;
    }

    cout << res % modulo << endl;
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