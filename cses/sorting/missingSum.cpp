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

    if(v[0] != 1){
        cout << 1 << endl;
        return;
    }

    int x = 1, sum = 1;

    for(int i = 1; i < n; i++){
        if(v[i] <= x+1){
            sum += v[i];
            x = sum;
        }
        else{
            cout << x+1 << endl;
            return;
        }
    }

    cout << x + 1 << endl;
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