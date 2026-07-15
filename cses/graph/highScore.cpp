#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
#define int long long

typedef struct Edge {
    int a, b, w;
}edge;

int n, m;
vector<Edge> edges;
const int INF = 1e18+1;
const int maxn = 2503;
vector<int> adj[maxn];
vector<int> adjInv[maxn];
int vis[maxn];
int visInv[maxn];
int pai[maxn];

bool compara(const edge &a, const edge &b){
    return a.a < b.a;
}

void dfs(int u){
    vis[u] = 1;
    
    for(auto v : adj[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

void dfsInv(int u){
    visInv[u] = 1;
    
    for(auto v : adjInv[u]){
        if(!visInv[v]){
            dfsInv(v);
        }
    }
}

void bellmanford(vector<int> dist){
    int x = -1;

    for(int i = 1; i <= n; i++){
        x = -1;
        for(edge e : edges){
            if(dist[e.a] != INF && dist[e.b] > dist[e.a] + e.w){
                dist[e.b] = max(dist[e.a] + e.w, -INF);
            }
        }
    }

    for(edge e : edges){
        if(dist[e.a] != INF && dist[e.b] > dist[e.a] + e.w){
                if(dist[e.b] != INF){
                    if(vis[e.b] && visInv[e.b]){
                        cout << -1 << endl;
                        return;
                    }
                }
            }
    }

    cout << -dist[n] << endl;
}

 
void solve () {
    cin >> n >> m;
    vector<int> dist(n+1, INF);
    dist[1] = 0;

    for(int i = 0; i < m; i++){
        int a, b, w; cin >> a >> b >> w;
        edge e = {a, b, -w};
        edges.push_back(e);

        adj[a].push_back(b);
        adjInv[b].push_back(a);
    }

    sort(edges.begin(), edges.end(), compara);

    dfs(1);
    dfsInv(n);

    bellmanford(dist);
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