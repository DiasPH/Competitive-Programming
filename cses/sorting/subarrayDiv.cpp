#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
#define int long long

int subCount(vector<int>& v, int k){
    int n = v.size(), res = 0, sum = 0;
    unordered_map<int,int> mp;

    for(int i = 0; i < n; i++){
        sum = (((sum + v[i]) % k + k) % k);

        if(sum == 0){ 
            res += 1;
        }

        res += mp[sum];

        mp[sum] += 1;
    }

    return res;
}
 
void solve () {
    int n; cin >> n;
    vector<int> v;

    for(int i = 0; i < n; i++){
        int num; cin >> num;
        v.push_back(num);
    }

    cout << subCount(v, n) << endl;

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