#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
#define int long long

string aux = "keep";
 
void solve () {
    int n; cin >> n;

    int tot = 0, fake = 0;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        string s; cin >> s;

        tot += a;
        
        if(s == "keep"){
            fake += b;
        }
        else fake += a;
    }

    cout << fake - tot << endl;
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