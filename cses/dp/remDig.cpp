#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
//#define int long long
 
void solve () {
    int n, cont = 0; cin >> n;
    int num = n;
    
    while(num > 0){
        
        string s = to_string(num);
        sort(s.begin(), s.end(), greater<int>());
        int val = s[0] - '0';
        num -= val;
        cont++;
    }

    cout << cont << endl;
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