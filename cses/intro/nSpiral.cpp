#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
#define int long long
 
void solve () {
    int x, y, res;
    cin >> y >> x;
    
    if(x == y){
        res = x * (x-1) + 1;
        cout << res << endl;
    }
    else if(x > y){
        if(x % 2 == 0){
            res = (x * (x-1) + 1) - (x-y);
            cout << res << endl;
        }
        else{
            res = (x * (x-1) + 1) + (x-y);
            cout << res << endl;
        }
    }
    else{
        if(y % 2 == 0){
            res = (y * (y-1) + 1) + (y-x);
            cout << res << endl;
        }
        else{
            res = (y * (y-1) + 1) - (y-x);
            cout << res << endl;
        }
    }
}
 
signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}