#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
//#define int long long
const int maxn = 2*(1e5) + 5;
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
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dist[1] = 0;
    dfs(1, 0);

    int maximo = -1, index = 1;
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

    maximo = -1, index = 1;
    for(int i = 1; i <= n; i++){
        if(dist[i] > maximo){
            maximo = dist[i];
            index = i;
        }
    }

    vector<int> rotaA;
    rotaA.push_back(0);
    for(int i = 1; i <= n; i++){
        rotaA.push_back(dist[i]);
        dist[i] = 0;
    }
    dfs(index, 0);
    vector<int> rotaB;
    rotaB.push_back(0);
    for(int i = 1; i <= n; i++){
        rotaB.push_back(dist[i]);
        dist[i] = 0;
    }

    for(int i = 1; i <= n; i++){
        cout << max(rotaA[i], rotaB[i]) << " ";
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