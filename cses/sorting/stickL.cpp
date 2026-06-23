#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
#define int long long
 
void solve () {
    int n; cin >> n;
    vector<int> v;

    for(int i = 0; i < n; i++){
        int num; cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    int mediana = ceil(n/2), res = 0;
    for(int i = 0; i < n; i++){
        res += abs(v.at(i) - v.at(mediana));
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