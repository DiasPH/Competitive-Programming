#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
//#define int long long
 
void solve () {
    int n; cin >> n;
    vector<bool> v;

    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;

        if((x + y) % 3 == 0 && max(x, y) <= 2 * min(x, y)) v.push_back(true);
        else v.push_back(false);
    }

    for(int i = 0; i < n; i++){
        v[i] == true ? cout << "YES\n" : cout << "NO\n";
    }
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