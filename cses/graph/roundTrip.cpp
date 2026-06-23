#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
//#define int long long
const int maxn = 1e5 + 5;
bool vis[maxn];
vector<int> adj[maxn];
int pai[maxn];
bool ok = false;
vector<int> h(maxn, 0);

vector<int> listaPai(int start, int end){
    vector<int> res;
    res.push_back(end);
    int aux = end;
    
    while(aux != start){
        aux = pai[aux];
        res.push_back(aux);
    }

    res.push_back(end);

    return res;
}

void dfs(int u){
    vis[u] = true;

    for(auto v : adj[u]){
        if(!vis[v]){
            pai[v] = u;
            dfs(v);
        }
        else if(v != pai[u] && !ok){
            h = listaPai(v, u);
            ok = true;
            break;
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

    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i);
            if(ok) break;
        }
    }

    if(!ok){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        cout << h.size() << endl;

        for(int i = 0; i < h.size(); i++){
            cout << h[i] << " ";
        }

        cout << endl;
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