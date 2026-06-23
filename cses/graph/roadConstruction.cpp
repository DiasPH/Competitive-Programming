#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
//#define int long long
const int maxn = 1e5+5;
int n;
int pai[maxn];
int tam[maxn];
int comp, maximo;


void make_set(int u){
    pai[u] = u;
    tam[u] = 1;
}

int find_set(int u){
    if(u == pai[u]){
        return u;
    }
    return pai[u] = find_set(pai[u]);
}

void union_sets(int u, int v){
    u = find_set(u);
    v = find_set(v);
    if(u != v){
        if(tam[u] < tam[v]){
            swap(u, v);
        }
        pai[v] = u;
        tam[u] += tam[v];
        comp--;
        maximo = max(maximo, tam[u]);
    }
}

void solve () {
    int m; cin >> n >> m;
    vector<pair<int,int>> edges;
    comp = n; maximo = 1;

    for(int i = 1; i <= n; i++){
        make_set(i);
    }

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        edges.emplace_back(u, v);
    }

    for(int i = 0; i < m; i++){
        union_sets(edges[i].first, edges[i].second);
        cout << comp << " " << maximo << endl;
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