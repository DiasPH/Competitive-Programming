#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
//#define int long long
const int maxn = 1000 + 5;
int n, m;
char matriz[maxn][maxn];
bool vis[maxn][maxn];
vector<pair<int,int>> moves = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
pair<int, int> pai[maxn][maxn];

bool verify(int i, int j){
    if(i >= 0 && i < n && j >=0 && j < m && vis[i][j] == 0 && matriz[i][j] != '#'){
        return true;
    }
    else return false;
}

vector<int> prevList(pair<int,int> start, pair<int,int> end){
    pair<int,int> aux = end;
    vector<int> res;
    while(aux != start){
        pair<int,int> temp = pai[aux.first][aux.second];
        if(temp.first != aux.first){
            if(temp.first < aux.first){
                res.push_back(1);
            }
            else{
                res.push_back(3);
            }
        }
        else if(temp.second != aux.second){
            if(temp.second > aux.second){
                res.push_back(2);
            }
            else{
                res.push_back(4);
            }
        }

        aux = temp;
    }

    reverse(res.begin(), res.end());

    return res;
}



vector<int> bfs(pair<int,int> start, pair<int,int> end){
    int i = start.first, j = start.second;
    queue<pair<int,int>> q;
    q.push({i, j});
    vis[i][j] = true;

    while(!q.empty()){
        pair<int, int> pos = q.front();
        q.pop();
        int x = pos.first;
        int y = pos.second;

        for(auto [a, b] : moves){
            if(verify(x + a, y + b)){
                vis[x+a][y+b] = true;
                pai[x+a][y+b] = {x, y};
                q.push({x+a, y+b});
                
            }
        }
    }

    if(!vis[end.first][end.second]){
        return {};
    }
    return prevList(start, end);
}


void solve () { 
    cin >> n >> m;

    pair<int,int> start, end;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c; cin >> c;
            matriz[i][j] = c;
            vis[i][j] = false;

            if(c == 'A'){
                start = {i, j};
            }
            else if(c == 'B'){
                end = {i, j};
            }
        }
    }

    vector<int> res = bfs(start, end);

    if(res.empty()){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        cout << res.size() << endl;

        for(int i = 0; i < res.size(); i++){
            if(res[i] == 1){
                cout << "D";
            }
            else if(res[i] == 2){
                cout << "L";
            }
            else if(res[i] == 3){
                cout << "U";
            }
            else{
                cout << "R";
            }
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