#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
//#define int long long

const int maxn = 1e5 + 7;
bool vis[maxn];
multimap<int, int> mm;
vector<int> adj[maxn];

void dfs(int u, int key){
    vis[u] = true;
    mm.insert({key, u});
    for(auto v : adj[u]){
        if(!vis[v]){
            dfs(v, key);
        }
    }
} 


void solve () {
    int n, m; cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int key = 1, cont = 0;
    for(int i = 1; i <= n; i++){
        if(vis[i] == 0){
            dfs(i, key);
            cont++;
            key++;
        }
    }

    cout << --cont << endl;

    auto f = mm.begin();
    int index = f->first, aux = f->second;
    for(auto i : mm){
        if(i.first != index){
            cout << aux << " " << i.second << endl;
            index = i.first;
            aux = i.second;
        }
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