#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
//#define int long long
 
void solve () {
    int n; cin >> n;
    string s; cin >> s;
    string aux = s;
    sort(aux.begin(), aux.end());

    int index = n;
    char temp;
    for(int i = 0; i < n; i++){
        if(s[i] != aux[i]){
            index = i;
            break;
        }
    }

    for(int i = n-1; i > index; i--){
        if(s[i] == aux[index]){
            char x = s[index];
            s[index] = s[i];
            s[i] = x;
            break;
        }
    }

    cout << s << endl;
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