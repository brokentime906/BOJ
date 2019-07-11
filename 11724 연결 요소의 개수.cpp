#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>>arr;
bool visited[1002];
void dfs(int here) {
	visited[here] = true;
	for (auto next : arr[here]) {
		if (visited[next]) continue;
		dfs(next);
	}
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;	
	arr = vector<vector<int>>(N + 1);
	for (int i = 0; i < M; ++i) {
		int s, e;
		cin >> s >> e;
		arr[s].push_back(e);
		arr[e].push_back(s);
	}
	int ans = 0;
	for (int i = 1; i <= N; ++i) {
		if (visited[i]) continue;
		dfs(i);
		ans++;
	}

	cout << ans;
	return 0;
}