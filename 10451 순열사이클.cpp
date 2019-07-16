#include <iostream>
#include <vector>

using namespace std;
vector<vector<int> >arr;
vector<bool> visited;
void dfs(int here) {
	visited[here] = true;
	int next = arr[here][0];
	if (visited[next]) return;
	dfs(next);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--) {
		int  N;
		cin >> N;
		arr = vector<vector<int> >(N + 1);
		visited = vector<bool>(N + 1);
		for (int i = 1; i <= N; ++i) {
			int t;
			cin>> t;
			arr[i].push_back(t);
		}
		int cnt = 0;
		for (int i = 1; i <= N; ++i) {
			if (!visited[i]) {
				dfs(i);
				cnt++;
			}				
		}
		cout << cnt<<"\n";

			

	}
	return 0;
}