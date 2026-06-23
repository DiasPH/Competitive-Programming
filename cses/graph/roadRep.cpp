#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
#define int long long
const int maxn = 1e5+5;
 
typedef struct Edge{
    int u, v, w;
    bool operator<(Edge const& other){
        return w < other.w;
    }
}edge;

int n;

int pai[maxn];
int ranque[maxn];

void init_set(int u){
    pai[u] = u;
    ranque[u] = 0;
}

int find(int u){
    if(pai[u] != u){
        pai[u] = find(pai[u]);
    }

    return pai[u];
}

void setUnion(int u, int v){
    int raizU = find(u);
    int raizV = find(v);

    if(raizU == raizV) return;

    if(ranque[raizV] < ranque[raizU]){
        swap(raizV, raizU);
    }
    pai[raizV] = raizU;

    if(ranque[raizV] == ranque[raizU]){
        ranque[raizU]++;
    }
}

 
int kruskal(vector<edge> edges){
    vector<int> tree_id(n+1);
    int cost = 0;
 
    for(int i = 1; i <= n; i++){
       init_set(i);
    }
 
    sort(edges.begin(), edges.end());
 
    for(edge e : edges){
        if(find(e.u) != find(e.v)){
            cost += e.w;
            setUnion(e.u, e.v);
        }
    }
 
    for(int i = 2; i <= n; i++){
        if(find(i) != find(i-1)){
            return -1;
        }
    }
 
    return cost;
}
 
 
 
void solve () {
    int m; cin >> n >> m;
    vector<edge> edges;
 
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        edge e = {u, v, w};
        edges.push_back(e);
    }
 
 
    int res = kruskal(edges);
    
    if(res == -1){
        cout << "IMPOSSIBLE" << endl;
    }
    else cout << res << endl;
 
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