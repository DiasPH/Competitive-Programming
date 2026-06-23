#include<bits/stdc++.h>
const int maxn = 3e5 + 5;

int n, m;
int matriz[maxn][maxn];
vector<vector<pair<int,int>>> pai(maxn, vector<pair<int,int>>(maxn));

vector<pair<int,int>> moves = {{1,0}, {-1,0}, {0,1}, {0, -1}};

bool verify(int i, int j){
	if(i >= 0 && i < n && j >=0 && j < m && dist[i][j] == -1 && matriz[i][j] == '.'){
		return true;
	}
	else return false;
}

vector<vector<int>> bfs(int i, int j){
	vector<vector<int>> dist(n, vector<int>(m), -1);
	queue<pair<int,int>> q;
	dist[i][j] = 0;
	q.emplace(i, j);
	while(!q.empty()){
		auto [x, y] =  q.front();
		q.pop();
		for(auto [a,b] : moves){
			if(verify(x+a, y+b)){
				dist[x+a][y+b] = dist[x][y] + 1;
				q.emplace(x+a, y+b);
				pai[x+a][y+b] = {x, y};
			}
		}
	}
	return dist;
}

int main(){
	cin >> n >> m;
	for(int i = 0;i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> matriz[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){

		}
	}
}

