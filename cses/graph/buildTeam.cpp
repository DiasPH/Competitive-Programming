#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
//#define int long long
const int maxn = 1e5 + 7;
int team[maxn];
vector<int> adj[maxn];
multimap<int, int> mm;

bool bfs(int u){
    queue<int> q;
    q.push(u);
    team[u] = 1;

    while(!q.empty()){
        u = q.front();
        q.pop();

        for(auto v : adj[u]){
            if(team[v] == 0){
                team[v] = (team[u] == 1) ? 2 : 1;
                q.push(v);
            }
            else if(team[v] == team[u]){
                return false;
            }
        }
    }

    return true;
}


 
void solve () {
    int n, m; cin >> n >> m;

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool ok = true;
    for(int i = 1; i <= n; i++){
        if(team[i] == 0){
           ok = bfs(i);
        }
    }

    if(ok){
        for(int i = 1; i <= n; i++){
            cout << team[i] << " ";
        }
        cout << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
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