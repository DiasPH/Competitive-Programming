#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
//#define int long long
 
int max(int x, int y){
    if(x >= y){
        return x;
    }
    else return y;
}

void solve () {
    int n; cin >> n;
    vector<pair<int, int>> vp;

    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        vp.push_back({b, a});
    }

    sort(vp.begin(), vp.end());

    int res = 1;
    for(int i = 1; i < vp.size(); i++){
       if(vp.at(i).second >= vp.at(i-1).first){
        res++;
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