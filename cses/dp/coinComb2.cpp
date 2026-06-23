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

    vector<int> dp(x + 1);

    sort(v.begin(), v.end());

    dp.at(0) = 1;
    for(int i = 1; i <= x; i++){
        dp.at(i) = 0;
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++){
        for(int j = 1; j <= x; j++){
            if(j - v.at(i) >= 0){
                dp[j] += dp[j - v.at(i)] % modulo;
            }
        }
    }

    cout << dp[x] % modulo << endl;
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