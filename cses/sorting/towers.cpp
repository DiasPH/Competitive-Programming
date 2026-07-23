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

    multiset<int> ms;
    ms.insert(v[0]);

    int res = 1;
    for(int i = 1; i < n; i++){
        auto x = ms.upper_bound(v[i]);
        if(x == ms.end()){
            ms.insert(v[i]);
            res++;
        }
        else{
            ms.erase(x);
            ms.insert(v[i]);
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