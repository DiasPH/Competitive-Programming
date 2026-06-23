#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
//#define int long long
 
void solve () {
    int n; cin >> n;
    vector<vector<int>> v(n, vector<int>(3));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            int num; cin >> num;
            v.at(i).at(j) = num;
        }
    }

    vector<vector<int>> dp(n, vector<int>(3));

    for(int i = 0; i < 3; i++){
        dp[0][i] = v[0][i];
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j < 3; j++){
            if(j == 0){
                dp[i][j] = max(v[i][0] + dp[i-1][1], v[i][0] + dp[i-1][2]);
            }
            else if(j == 1){
                dp[i][j] = max(v[i][1] + dp[i-1][0], v[i][1] + dp[i-1][2]);
            }   
            else{
                dp[i][j] = max(v[i][2] + dp[i-1][0], v[i][2] + dp[i-1][1]);
            }     
        }
    }

    int res = max(dp[n-1][0], dp[n-1][1]);
    res = max(res, dp[n-1][2]);

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