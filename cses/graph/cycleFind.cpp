#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
#define int long long

typedef struct Edge{
    int a, b, w;
}edge;


const int INF = 1e18 + 5;
int n;
vector<edge> edges;

void bellmanFord(vector<int> pai, vector<int> dist){
    int x;

    for(int i = 1; i <= n; i++){
        x = -1;
        for(edge e : edges){
            if(dist[e.b] > dist[e.a] + e.w){
                dist[e.b] = max(-INF, dist[e.a] + e.w);
                pai[e.b] = e.a;
                x = e.b;
            }
        }
    }

    if(x == -1){
        cout << "NO" << endl;
    }
    else{
        for(int i = 1; i <= n; i++){
            x = pai[x];
        }
        vector<int> res;
        for(int v = x;; v = pai[v]){
            res.push_back(v);
            if(v == x && res.size() > 1) break;
        }

        reverse(res.begin(), res.end());

        cout << "YES" << endl;
        for(int v : res){
            cout << v << " ";
        }
        cout << endl;
    }
}

void solve () {
    int m; cin >> n >> m;
    vector<int> dist(n+1, 0);
    vector<int> pai(n+1, -1);

    for(int i = 0; i < m; i++){
        int a, b, w; cin >> a >> b >> w;
        edge e = {a, b, w};
        edges.push_back(e);
    }

    bellmanFord(pai, dist);
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