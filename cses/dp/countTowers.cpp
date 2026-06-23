#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
#define int long long
const int maxn = 1e6 + 2;
const int modulo = 1e9 + 7;
 
void solve () {
    int n; cin >> n;
    vector<vector<int>> dp(maxn, vector<int>(2));

    for(int i = 1; i <= maxn; i++){
        for(int j = 1; j <= 2; j++){
            dp[i].push_back(0);
        }
    }

    dp[1][0] = 1;
    dp[1][1] = 1;

    for(int i = 2; i <= maxn; i++){
        dp[i][0] = (2 * dp[i-1][0] + dp[i-1][1]) % modulo;
        dp[i][1] = (4 * dp[i-1][1] + dp[i-1][0]) % modulo;
    }

    for(int i = 0; i < n; i++){
        int num; cin >> num;
        cout << (dp[num][0] + dp[num][1])  % modulo << endl;
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