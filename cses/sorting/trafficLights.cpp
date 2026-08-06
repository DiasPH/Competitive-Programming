#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
#define int long long
 
void solve () {
    int x, n; cin >> x >> n;
        vector<int> v;

        for(int i = 0; i < n; i++){
            int num; cin >> num;
            v.push_back(num);
        }

        set<int> s;
        s.insert(0);
        s.insert(x);

        multiset<int> ms;
        ms.insert(x);

        for(int i = 0; i < n; i++){
            auto ind = s.lower_bound(v[i]);
            auto r = ind;
            auto l = prev(ind);

            ms.insert(*r - v[i]);
            ms.insert(v[i] - *l);

            auto it = ms.find(*r - *l);
            ms.erase(it);

            s.insert(v[i]);

            cout << *ms.rbegin() << " ";
        }

        cout << endl;
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