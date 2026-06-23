#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
//#define int long long
 
void solve () {
    int n, m; cin >> n >> m;
    vector<int> maxp;
    multiset<int> tprice;

    for(int i = 0; i < n; i++){
        int num; cin >> num;
        tprice.insert(num);
    }
    for(int i = 0; i < m; i++){
        int num; cin >> num;
        maxp.push_back(num);
    }

    vector<int> res;

    for(int i = 0; i < m; i++){
        auto ub = tprice.upper_bound(maxp.at(i));
        if(ub != tprice.begin()){
            ub--;
            res.push_back(*ub);
            tprice.erase(ub);
        }
        else{
            res.push_back(-1);
        }
    }

    for(int i = 0; i < res.size(); i++){
        cout << res.at(i) << endl;
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