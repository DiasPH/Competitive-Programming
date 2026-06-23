#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
//#define int long long
const int maxn = 1e5 + 5;
vector<int> adj[maxn];
int inbreed[maxn];
vector<int> lista;
int vis[maxn];

void bfs(int start){
    queue<int> q;
    q.push(start);
    lista.push_back(start);

    while(!q.empty()){
        auto u = q.front();
        q.pop();

        for(auto v : adj[u]){
            inbreed[v]--;
            if(inbreed[v] == 0 && vis[v] == 0){
                vis[v] = 1;
                lista.push_back(v);
                q.push(v);
            }
        }
    }
}
 
void solve () {
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    for(int i = 1; i <= n; i++){
        for(int j : adj[i]){
            inbreed[j]++;
        }
    }

    for(int i = 1; i <= n; i++){
        if(inbreed[i] == 0 && vis[i] == 0){
            bfs(i);
        }
    }

    for(int i = 0; i < lista.size(); i++){
        cout << lista[i] << " ";
    }

    cout << endl;
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