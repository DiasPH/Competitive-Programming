#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
#define int long long
const int modulo = 1e9 + 7;
const int maxn = 1e5 + 5; 
vector<int> adj[maxn];
bool vis[maxn];
vector<int> dp(maxn, 0);
int n;

void bfs(int start){
    queue<int> q;
    vector<int> indegree(n, 0);

    for(int i = 1; i <= n; i++){
        for(int prox : adj[i]){
            indegree[prox]++;
        }
    }

    for(int i = 1; i < n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(auto v : adj[u]){
            indegree[v]--;
            dp[v] += dp[u] % modulo;
            if(indegree[v] == 0){
                q.push(v);
            }
        }
    }
}   


void solve () {
    int m; cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    dp[1] = 1;

    bfs(1);

    cout << dp[n] % modulo << endl;

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