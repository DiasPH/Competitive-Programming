#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
//#define int long long
 
void solve () {
    int x; cin >> x;
    int y; cin >> y;

    int a = (x + y)/2;
    int b = x - a;

    if(b < a) swap(a, b);

    cout << a << " " << b << endl;;
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