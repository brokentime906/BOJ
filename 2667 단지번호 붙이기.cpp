#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int arr[27][27];
bool visited[27][27];
int nR[4] = { 0,-1,0,1 };
int nC[4] = { -1,0,1,0 };
int node_count;
void dfs(int r, int c) {
	visited[r][c] = true;
	node_count++;
	for (int i = 0; i < 4; ++i) {
		int nextR = r + nR[i];
		int nextC = c + nC[i];
		if (nextR > N || nextC > N || nextR < 1 || nextC < 1) continue;
		if (visited[nextR][nextC]) continue;
		if(arr[nextR][nextC] )
			dfs(nextR, nextC);
	}
}
int main() {
	cin >> N;
	string t;
	
	for (int i = 0; i < N; ++i) {
		cin >> t;
		for (int j = 0; j < N; ++j)
			arr[i+1][j+1] = (t[j] == '1' ? 1 : 0);
	}
	
	int cnt = 0;
	vector<int> ans;
	for (int r = 1; r <= N; ++r) {
		for (int c = 1; c <= N; ++c) {
			if (!visited[r][c] &&arr[r][c] ==1 ) {
				node_count = 0;
				dfs(r, c);
				cnt++;
				ans.push_back(node_count);
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << cnt<<"\n";

	for (auto x : ans)
		cout << x<<"\n";

	//for (int i = 1; i <= N; ++i)
	//{
	//	for (int j = 1; j <= N; ++j)
	//	//	cout << arr[i][j] << " ";
	////	cout << endl;
	//}

	return 0;
}