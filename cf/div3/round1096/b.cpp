#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
//#define int long long

void solve(){
  string s;
  cin >> s;

  if(s.size() % 2 != 0){
    cout << "NO" << endl;
  }
  else{
        int cont = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                cont++;
            }
            else{
                cont--;
            }
        }
        if(cont){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
   }
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if(TC){
        cin >> TC;
        while(TC--) solve();
    }else{
        solve();
    }
    return 0;
}