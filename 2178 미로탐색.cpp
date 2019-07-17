#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
int R, C;
int arr[104][104];
bool visited[104][104];
int main() {
	string t;
	cin >> R >> C;
	for (int i = 0; i < R; ++i) {
		cin >> t;
		for (int j = 0; j < C; ++j)
			arr[i+1][j+1] = (t[j] == '1' ? 1 : 0);
	}
	queue<pair<pair<int, int>, int> > q;

	q.push({ {1,1},1 });
	int dR[4] = { 0,-1,0,1 };
	int dC[4] = { -1,0,1,0 };
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		int curR = cur.first.first;
		int curC = cur.first.second;
		int curMove = cur.second;
		if (visited[curR][curC]) continue;
		visited[curR][curC] = true;
		for (int i = 0; i < 4; ++i) {
			int nextR = curR + dR[i];
			int nextC = curC + dC[i];
			if (nextR < 1 || nextR >R || nextC <1 || nextC >C) continue;
			if (visited[nextR][nextC]) continue; //방문됬으면 ㅂ
			if (arr[nextR][nextC] ==0) continue;    //벽은 제끼고
			if (nextR == R && nextC == C) {
				cout << curMove + 1;
				return 0;
			}
			q.push({ {nextR,nextC},curMove + 1 });
			
		}
	}
	for (int r = 1; r <= R; ++r) {
		for (int c = 1; c <= C; ++c)
			cout << arr[r][c] << " ";
		cout << endl;
	}
	//cout << " ?? ";

	return 0;
}