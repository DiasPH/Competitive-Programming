#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
//#define int long long
 
void solve () {
    string s; cin >> s;
    string z; cin >> z;

    int n = s.size(), m = z.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1));

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0){
                dp[i][j] = j;
            }
            else if(j == 0){
                dp[i][j] = i;
            }
            else if(s[i-1] != z[j-1]){
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
            }
            else{ 
                dp[i][j] = dp[i-1][j-1];
            }
        }
    }
 
    cout << dp[n][m] << endl;
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