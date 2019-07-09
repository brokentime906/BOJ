#include <iostream>
#include <queue>

#define pii pair<int , int >

using namespace std;
vector<vector<bool>> visited;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int tc;
	cin >> tc;
	const int dR[8] = { -1,1,2,2,1,-1,-2,-2 };
	const int dC[8] = { -2,-2,-1,1,2,2,1,-1 };
	while (tc--) {
		int N;
		cin >> N;

		int sR, sC, eR, eC;
		cin >> sR >> sC >> eR >> eC;
		visited = vector<vector<bool>>(N, vector<bool>(N));
		
		queue<pair< pii , int > > q;
		q.push({ {sR,sC},0 });

		while (!q.empty()) {
			auto cur = q.front();
			q.pop();

			int cur_r = cur.first.first;
			int cur_c = cur.first.second;
			int cur_day = cur.second;

			if (cur_r == eR && cur_c == eC) {
				cout << cur_day;
				return 0;
			}

			if (visited[cur_r][cur_c]) continue;
			visited[cur_r][cur_c] = true;

			

			

		}


	}

	return 0;
}