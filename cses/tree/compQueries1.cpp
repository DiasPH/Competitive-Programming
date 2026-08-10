#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
#define int long long

const int MAXN = 2e5 + 5;
const int LOG = 20;

vector<int> adj[MAXN];
int up[MAXN][LOG];
int depth[MAXN];

void dfs(int u, int pai, int d = 1){
    depth[u] = d;
    up[u][0] = pai;

    for(int j = 1; j < LOG; j++){
        up[u][j] = up[ up[u][j-1] ][j-1];
    }

    for(auto v : adj[u]){
        if(v != pai){
            dfs(v, u, d + 1);
        }
    }
}

int boss(int u, int diff){
    for(int j = 0; j < LOG; j++){
        if((diff >> j) & 1){
            u = up[u][j];
        }
    }


    if(u == 0) u = -1;
    return u;
}

 
void solve () {
    int n, q; cin >> n >> q;

    for(int i = 2; i <= n; i++){
        int num; cin >> num;

        adj[num].push_back(i);
        adj[i].push_back(num);
    }

    dfs(1, -1, 0);

    for(int i = 0; i < q; i++){
        int x, k; cin >> x >> k;

        cout << boss(x, k) << endl;
        
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