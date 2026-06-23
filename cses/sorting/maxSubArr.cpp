#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
#define int long long

int max(int x, int y){
    if(x >= y){
        return x;
    }
    else return y;
}
 
void solve () {
    int n; cin >> n;
    vector<int> v;
    
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        v.push_back(num);
    }

    int sum = v.at(0), maximo = -10e9 - 5;
    int l = 0, r = 0;
    for(int i = 1; i < n; i++){
        if(v.at(i) > v.at(i) + sum){
            sum = v.at(i);
        }
        else{
            sum += v.at(i);
        }

        maximo = max(sum, maximo);
    }

    

    cout << max(sum, maximo) << endl;
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