#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
#define int long long
const int maxn = 1e5+5;
const int maxp = 1e18 + 5;
vector<pair<int,int>> adj[maxn];
vector<int> dist(maxn, maxp);

vector<int> dijkstra(int start){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[start] = 0;
    pq.emplace(0, start);

    while(!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int d = top.first;
        int u = top.second;

        if(d > dist[u]){
            continue;
        }

        for(auto [v, w] : adj[u]){
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }

    return dist;
}
 
void solve () {
    int n, m; cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        int u, v, p; cin >> u >> v >> p;
        adj[u].emplace_back(v, p);
    }

    vector<int> res = dijkstra(1);

    for(int i = 1; i <= n; i++){
        cout << res[i] << " ";
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