#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
//#define int long long
 
void solve () {
    set<int> s;
    int n, res = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        if(s.count(val) == 0){
            res++;
        }
        else continue;
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