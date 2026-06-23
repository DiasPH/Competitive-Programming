#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
#define int long long
 
void solve () {
    int n, x; cin >> n >> x;
    vector<pair<int,int>> v;

    for(int i = 0; i <= n; i++){
        if(i == 0){
            v.emplace_back(0, 0);
        }
        else{
            int w, u; cin >> w >> u;
            v.emplace_back(w, u);
        }
    }

    vector<vector<int>> dp(n+1, vector<int>(x+1));

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= x; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if(v[i].first <= j){
                dp[i][j] = max(dp[i-1][j - v[i].first] + v[i].second, dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[n][x] << endl;
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