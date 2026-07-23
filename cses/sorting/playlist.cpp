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

    map<int,int> mp;
    mp.insert({v[0], 0});
    int maior = 1, cont = 1;
    int l = 0;
    for(int r = 1; r < n; r++){
        if(mp.find(v[r]) != mp.end()){
            if(mp.at(v[r]) < l){
                mp.at(v[r]) = r;
                cont++;
            }
            else{
                l = mp.at(v[r]) + 1;
                mp.at(v[r]) = r;

                cont = r-l+1;
            }
        }
        else{
            mp.insert({v[r], r});
            cont++;
        }

        maior = max(maior, cont);
    }

    cout << maior << endl;
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