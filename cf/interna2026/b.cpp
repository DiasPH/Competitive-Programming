#include <bits/stdc++.h>
 
using namespace std;

#define endl '\n' 
//#define int long long
 
void solve () {
    int h, a, b; cin >> h >> a >> b;

    if(h >= a && h <= b){
        cout << "SIM" << endl;
    }
    else{
        cout << "NAO" << endl;
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