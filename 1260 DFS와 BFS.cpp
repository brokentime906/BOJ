#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool visited[1005];
void dfs(vector<vector<int>>& adj , int here) {
	cout << here+1 << " ";
	visited[here] = true;
	for (int i = 0; i < adj[here].size(); ++i) {
		int there = adj[here][i];
		if (!visited[there])
			dfs(adj,there);
	}
}
void bfs(vector<vector<int>>&adj,int here) {
	queue<int>q;
	q.push(here);
	vector<bool>visited(adj.size(), false);
	while ( !q.empty()) {
		
		int cur = q.front();
		
		q.pop();
		if (visited[cur]) continue;
		visited[cur] = true;
		cout << cur + 1 << " ";
		for (int i = 0; i < adj[cur].size(); ++i) {
			
			int there = adj[cur][i];
			
			if (!visited[there]) q.push(there);
		}
	}
}

int main() {

	int N, M, V;
	cin >> N >> M >> V;
	vector<vector<int>> adj(N);
	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	V--;
	for (int i = 0; i < adj.size(); ++i) {
		sort(adj[i].begin(), adj[i].end());
	}
	dfs(adj,V);
	cout<< endl;
	
	bfs(adj, V);
	return 0;
}