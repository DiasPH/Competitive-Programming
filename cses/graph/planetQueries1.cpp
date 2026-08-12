#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
#define int long long
const int MAXN = 2e5+5;
const int LOG = 30;

vector<int> adj[MAXN];
int up[MAXN][LOG];

void bl(int n){
    for(int j = 1; j < LOG; j++){
        for(int i = 1; i <= n; i++){
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }
}

int destino(int x, int k){
    for(int i = 0; i < LOG; i++){
        if((k >> i) & 1){
            x = up[x][i];
        }
    }

    return x;
}

void solve () {
    int n, q; cin >> n >> q;

    for(int i = 1; i <= n; i++){
        int num; cin >> num;
        up[i][0] = num;
    }

    bl(n);

    for(int i = 0; i < q; i++){
        int x, k; cin >> x >> k;

        cout << destino(x, k) << endl;
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