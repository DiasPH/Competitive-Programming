#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
//#define int long long
 
void solve () {
    int n; cin >> n;
    vector<int> v;
    
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        v.push_back(num);
    }

    vector<int> dp(n);
    dp[0] = v[0];
    dp[1] = v[1];

    for(int i = 2; i < n; i++){
        dp[i] = dp[i-2] + v[i];
    }

    sort(dp.begin(), dp.end());

    cout << dp[n-1] << endl;
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