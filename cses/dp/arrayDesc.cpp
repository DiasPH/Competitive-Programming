#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
#define int long long
const int modulo = 1e9 + 7;

int modulador(int a, int b){
    return (a+b) % modulo;
}
 
void solve () {
    int n, m; cin >> n >> m;
    vector<int> v;

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }

    vector<vector<int>> dp(n, vector<int>(m+1, 0));

    if(v[0] == 0){
        for(int i = 1; i <= m; i++){
            dp[0][i] = 1;
        }
    }
    else{
        dp[0][v[0]] = 1;
    }

    for(int i = 0; i < n-1; i++){
        if(v[i] == 0){
            for(int j = 1; j <= m; j++){
                if(dp[i][j] != 0){
                    dp[i+1][j] = modulador(dp[i+1][j], dp[i][j]);

                    if(j > 1){
                        dp[i+1][j-1] = modulador(dp[i+1][j-1], dp[i][j]);
                        
                    }
                    if(j < m){
                        dp[i+1][j+1] = modulador(dp[i+1][j+1], dp[i][j]);
                    }
                }
            }
        }
        else{
            if(dp[i][v[i]] != 0){
                    dp[i+1][v[i]] = modulador(dp[i+1][v[i]], dp[i][v[i]]);

                    if(v[i] > 1){
                        dp[i+1][v[i]-1] = modulador(dp[i+1][v[i]-1], dp[i][v[i]]);
                        
                    }
                    if(v[i] < m){
                        dp[i+1][v[i] + 1] = modulador(dp[i+1][v[i] + 1], dp[i][v[i]]);
                    }
                }
        }
    }

    int res = 0;

    if(v[n-1] > 0){
        res = dp[n-1][v[n-1]];
    }

    else{
        for(int i = 1; i <= m; i++){
            if(dp[n-1][i] != 0){
                res = modulador(res, dp[n-1][i]);
            }
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