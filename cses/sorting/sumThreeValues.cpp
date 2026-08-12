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

    set<int> s;
    for(int i = 0; i < n; i++){
        if(s.count == 0){
            vector<int> v;
            v.push_back(v[i]);
            int fixo = x - v[i];
            s.insert(v[i]);

            

        }
    }
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