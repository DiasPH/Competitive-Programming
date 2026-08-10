#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
#define int long long

const int MAXN = 2e5 + 5;
const int LOG = 20;

vector<int> adj[MAXN];
int up[MAXN][LOG];
int depth[MAXN];

void dfs(int u, int pai, int d = 0){
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

int lca(int u, int v){
    if(depth[u] < depth[v]){
        swap(u, v);
    }

    int diff = depth[u] - depth[v];

    for(int j = 0; j < LOG; j++){
        if((diff >> j) & 1){
            u = up[u][j];
        }
    }

    if(u == v) return u;

    for(int j = LOG -1; j >= 0; j--){
        if(up[u][j] != up[v][j]){
            u = up[u][j];
            v = up[v][j];
        }
    }

    return up[u][0];
}

 
void solve () {
    int n, q; cin >> n >> q;

    for(int i = 2; i <= n; i++){
        int num; cin >> num;

        adj[num].push_back(i);
        adj[i].push_back(num);
    }

    dfs(1, 0, 0);

    for(int i = 0; i < q; i++){
        int u, v; cin >> u >> v;

        cout << lca(u, v) << endl;
        
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