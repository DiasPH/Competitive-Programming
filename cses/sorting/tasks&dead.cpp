#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
#define int long long
 
void solve () {
    int n; cin >> n;
    int tot = 0, sum = 0;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int a, d; cin >> a >> d;
        tot += d;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++){
        sum += v[i];
        tot -= sum;
    }

    cout << tot << endl;
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