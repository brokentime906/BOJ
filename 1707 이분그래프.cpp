#include <iostream>
#include <vector>

using namespace std;

int V, E;
vector<vector<int>>arr;
vector<int>visited;
bool dfs(int here, int color) {
	visited[here] = color;
	for (auto next : arr[here]) {
		if (visited[next] == color) return false; // 같은색
		if (visited[next] == 3-color) continue;         // 다른색
		// 한번이라도 방문된 곳이 있다면 확인하는것 
		if (dfs(next, 3 - color) == false) return false;
	}
	return true;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		
		cin >> V >> E;
		arr = vector<vector<int>>(V + 1);
		visited = vector<int>(V + 1);
		for (int i = 0; i < E; ++i) {
			int s, e;
			cin >> s >> e;
			arr[s].push_back(e);
			arr[e].push_back(s);
		}
		bool found = false;
		for (int i = 1; i <= V; ++i)
			if (visited[i]) continue;
			else {
				if (!dfs(i, 2)) {
					cout << "NO"; 
					found = true;
					break;
				}
			}
		if (!found)
			cout << "YES";			
	}
	return 0;
}