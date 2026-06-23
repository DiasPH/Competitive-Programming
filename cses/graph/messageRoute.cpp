#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
//#define int long long
const int maxn = 1e5 + 7;
bool vis[maxn];
vector<int> adj[maxn];
int prev[maxn];

vector<int> path(int start, int end, vector<int> prev){
    vector<int> temp;

    temp.push_back(end);
    while(end != start){
        temp.push_back(prev[end]);
        end = prev[end];
    }

    reverse(temp.begin(), temp.end());

    return temp;
}

vector<int> bfs(int u, int end, vector<int> prev){
    queue<int> q;
    vis[u] = true;
    q.push(u);

    while(!q.empty()){
        u = q.front();
        q.pop();

        for(auto v : adj[u]){
            if(!vis[v]){
                vis[v] = true;
                q.push(v);
                prev[v] = u;
            }
        }
    }

    if(!vis[end]) return {};

    return path(1, end, prev);
}




void solve () {
    int n, m; cin >> n >> m;

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> prev(n+1);
    vector<int> res = bfs(1, n, prev);
    
    if(res.empty()){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        cout << res.size() << endl;

        for(int i = 0; i < res.size(); i++){
            cout << res[i] << " ";
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