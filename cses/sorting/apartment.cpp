#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
#define int long long
 
void solve () {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> a;
    for(int i = 0; i < n; i++){
        int ps;
        cin >> ps;
        a.push_back(ps);
    }
    sort(a.begin(), a.end());

    vector<int> b;
    for(int i = 0; i < m; i++){
        int as;
        cin >> as;
        b.push_back(as);
    }
    sort(b.begin(), b.end());

    int res = 0;
    int ind = 0;
    for(int i = 0; i < m; i++){
        for(int j = ind; j < n; j++){
            if(b.at(i) < a.at(j) - k){
                break;
            }
            if(b.at(i) > a.at(j) + k){
                ind = j+1;
            }
            if(abs(b.at(i) - a.at(j)) <= k){
                res++;
                ind = j+1;
                break;
            }
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