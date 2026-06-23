#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
#define int long long
const int modulo = (1e9 + 7);
 
void solve () {
    int n; cin >> n;

    vector<int> vals;

    vals.push_back(1);

    for(int i = 2; i <= n; i++){
        int sum = 0;
        for(int j = 1; j <= 6; j++){
            if(i - j > 0){
                sum += vals.at(i - j - 1) % modulo;
            }
            else false;
        }
        if(i < 7) sum++ % modulo;
        vals.push_back(sum);
    }

    cout << vals.at(n-1) % modulo << endl;
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