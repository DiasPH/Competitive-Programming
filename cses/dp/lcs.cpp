#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
//#define int long long
 
void solve () {
    int n, m; cin >> n >> m;
    vector<int> v1(n+1), v2(m+1);

    for(int i = 1; i <= n; i++){
        int num; cin >> num;
        v1[i] = num;
    }

    for(int i = 1; i <= m; i++){
        int num; cin >> num;
        v2[i] = num;
    }

    v1[0] = 0;
    v2[0] = 0;

    vector<vector<int>> dp(n+1, vector<int>(m+1));

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if(v1[i] == v2[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    vector<int> res;

    int aux = 0;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(dp[i][j] == aux + 1 && v1[i] == v2[j]){
                res.push_back(v1[i]);
                aux++;
                break;
            }
        }
    }


    cout << dp[n][m] << endl;
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;
    
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