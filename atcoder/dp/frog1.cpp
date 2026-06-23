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
    dp[1] = abs(v.at(0) - v.at(1));
    for(int i = 2; i < n; i++){
        dp[i] = min(dp[i-1] + abs(v.at(i) - v.at(i-1)), dp[i-2] + abs(v.at(i) - v.at(i-2)));
    }

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