#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
#define int long long
const int modulo = 1e9 + 7;
 
void solve () {
    int n, x; cin >> n >> x;
    vector<int> v;

    for(int i = 0; i < n; i++){
        int num; cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    vector<int> dp(x + 1);

    dp.at(0) = 1;
    for(int i = 1; i <= n; i++){
        dp.at(i) = 0;
    }

    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n; j++){
            if(i - v.at(j) >= 0){
                dp[i] += dp[i - v.at(j)] % modulo;
            }
        }
    }

    cout << dp[x]  % modulo << endl;

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