#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
//#define int long long
 
void solve () {
    int n, m; cin >> n >> m;
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

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--; b--;

        set<int> pares;

        if(v[a] > 1) pares.insert(v[a] - 1);
        if(v[a] < n) pares.insert(v[a]);

        if(v[b] > 1) pares.insert(v[b] - 1);
        if(v[b] < n) pares.insert(v[b]);

        for(int x : pares){
            if(s[x - 1] > s[x]){
                cont--;
            }
        }

        swap(v[a], v[b]);
        s[v[a] - 1] = a;
        s[v[b] - 1] = b;

        for(int x : pares){
            if(s[x - 1] > s[x]){
                cont++;
            }
        }

        cout << cont << endl;

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