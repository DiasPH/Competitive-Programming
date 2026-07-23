#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
//#define int long long
 
void solve () {
    int n; cin >> n;
    vector<int> v, s(n);
 
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        v.push_back(num);
    }
 
    
    for(int i = 0; i < n; i++){
        s[v[i] - 1] = i;
    }
 
    int aux = -1, cont = 1;
    for(int i = 0; i < n; i++){
        if(aux > s[i]){
            cont++;
        }
 
        aux = s[i];
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