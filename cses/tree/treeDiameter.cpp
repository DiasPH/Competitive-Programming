#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
//#define int long long
const int maxn = 2e5 + 5;
vector<int> adj[maxn];
int dist[maxn];

void dfs(int u, int pai){
    for(auto v : adj[u]){
        if(v != pai){
            dist[v] = dist[u] + 1;
            dfs(v, u);
        }
    }
}


void solve () {
    int n; cin >> n;

    for(int i = 0; i < n; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dist[1] = 0;
    dfs(1, 0);

    int index = 1, maximo = 0;
    for(int i = 1; i <= n; i++){
        if(dist[i] > maximo){
            maximo = dist[i];
            index = i;
        }
    }

    for(int i = 1; i <= n; i++){
        dist[i] = 0;
    }

    dfs(index, 0);

    int res = 0;
    for(int i = 1; i <= n; i++){
        res = max(res, dist[i]);
    }

    cout << res << endl;
    
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