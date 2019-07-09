#include <iostream>
#include <queue>

#define pii pair<int, int>

using namespace std;
vector<vector<int>> arr;
vector<vector<bool>> visited;
int main() {

	int ROW, COL;
	cin >> COL >> ROW;

	arr = vector<vector<int>>(ROW+2,vector<int>(COL+2));
	visited = vector<vector<bool>>(ROW + 2, vector<bool>(COL + 2));
	
	queue< pair <pii, int > >q;


	for (int r = 1; r <= ROW; ++r) {
		for (int c = 1; c <= COL; ++c) {
			cin >> arr[r][c];
			if (arr[r][c] ==1) {
				visited[r][c] = true;
				q.push({ {r,c},0 });
			}
				
		}
	}
	int max_day = 0;
	int dr[4] = { 0,-1,0,1 };
	int dc[4] = { -1,0,1,0 };

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int r = cur.first.first;
		int c = cur.first.second;
		int day = cur.second;
		if (day > max_day)
			max_day = day;
		for (int i = 0; i < 4; ++i) {
			int nextR = r + dr[i];
			int nextC = c + dc[i];
			if (nextR == 0 || nextC == 0 || nextR > ROW || nextC > COL) continue;
			if (visited[nextR][nextC]) continue;
			if (arr[nextR][nextC] == -1)continue;
			q.push({ {nextR,nextC},day + 1 });
			visited[nextR][nextC] = true;
		}
	}
	bool found = false;
	for (int r = 1; r <= ROW; ++r) {
		for (int c = 1; c <= COL; ++c) {
			if (!visited[r][c] && arr[r][c] != -1) {
				found = true;
				break;
			}			
		}
		if (found) break;
	}

	cout << (found ? -1 :max_day);
	
	return 0;
}