#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
//#define int long long
 
void solve () {
  int n, x;
  cin >> n >> x;
  map<int, int> mp;
  pair<int, int> res;
  bool ok = false;

  for(int i = 0; i < n; i++){
    int num;
    cin >> num;

    int aux = abs(num - x);

    if(mp.find(aux) != mp.end() && num < x && aux < x){
        res.first = i+1;
        res.second = mp.at(aux);
        ok = true;
        break;
    }

    if(mp.find(num) == mp.end()){
        mp.insert({num, i+1});
    }
  }

  if(ok){
    cout << res.first << " " << res.second << endl;
  }
  else{
    cout << "IMPOSSIBLE" << endl;
  }
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