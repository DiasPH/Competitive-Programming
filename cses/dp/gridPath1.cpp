#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
#define int long long
const int modulo = 1e9 + 7;
 
void solve () {
    int n; cin >> n;
    vector<vector<pair<char,int>>> v(n, vector<pair<char,int>>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char c; cin >> c;
            v.at(i).at(j).first = c;
            v.at(i).at(j).second = 0;
        }
    }

    v[0][0].first == '.' ? v[0][0].second = 1 : v[0][0].second = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(v.at(i).at(j).first == '.'){
                if(j-1 >= 0 && v.at(i).at(j-1).first == '.'){
                    v.at(i).at(j).second += v.at(i).at(j-1).second % modulo;
                }
                if(i - 1 >= 0 && v.at(i-1).at(j).first == '.'){
                    v.at(i).at(j).second += v.at(i-1).at(j).second % modulo;
                }
            }
        }
    }

    cout << v.at(n-1).at(n-1).second % modulo << endl;
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