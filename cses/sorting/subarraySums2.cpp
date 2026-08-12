#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
#define int long long
 
void solve () {
    int n, x; cin >> n >> x;
    vector<int> v;

    for(int i = 0; i < n; i++){
        int num; cin >> num;
        v.push_back(num);
    }

    map<int,int> mp;
    mp[0] = 1;

    int sum = 0, res = 0;

    for(int i = 0; i < n; i++){
        sum += v[i];

        if(mp.count(sum-x)){
            res += mp[sum - x];
        }

        mp[sum]++;
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