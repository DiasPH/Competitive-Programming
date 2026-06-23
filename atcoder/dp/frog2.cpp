#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
//#define int long long
 
void solve () {
    int n, k; cin >> n >> k;
    vector<int> v;

    for(int i = 0; i < n; i++){
        int num; cin >> num;
        v.push_back(num);;
    }

    vector<int> dp(n, 1e9);
    dp[0] = 0;

    for(int i = 1; i < n; i++){
        for(int j = 1; j <= k; j++){
            if(i - j >= 0){
                dp[i] = min(dp[i], dp[i-j] + abs(v.at(i) - v.at(i - j)));
            }
            else break;
        }
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