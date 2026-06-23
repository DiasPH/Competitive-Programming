#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
//#define int long long

void solve(){
    int x, y;
    cin >> x;
    cin >> y;
    if(x % 2 != 0 && y % 2 != 0){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if(TC){
        cin >> TC;
        while(TC--) solve();
    }else{
        solve();
    }
    return 0;
}