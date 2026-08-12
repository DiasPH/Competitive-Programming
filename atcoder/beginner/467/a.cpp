#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
#define int long long
 
void solve () {
    int h, w; cin >> h >> w;
    

    if((w * 100/00) >= (25 * h * h)) cout << "Yes" << endl;
    else cout << "No" << endl;
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