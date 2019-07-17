#include <iostream>
#include <string>

using namespace std;
int arr1[103][103];
int arr2[103][103];
bool visited1[103][103];
bool visited2[103][103];
int N;
int dR[4] = { 0,-1,0,1 };
int dC[4] = { -1,0,1,0 };
void dfs(int r, int c, int mode) {
	if (mode == 1) {
		visited1[r][c] = true;
		for (int i = 0; i < 4; ++i) {
			int nextR = r + dR[i];
			int nextC = c + dC[i];
			if (nextR <1 || nextR> N || nextC<1 || nextC>N)continue;
			if (visited1[nextR][nextC])continue;
			if (arr1[r][c] == arr1[nextR][nextC])
				dfs(nextR, nextC,mode);
		}
	}
	if (mode == 2) {
		visited2[r][c] = true;
		for (int i = 0; i < 4; ++i) {
			int nextR = r + dR[i];
			int nextC = c + dC[i];
			if (nextR <1 || nextR> N || nextC<1 || nextC>N)continue;
			if (visited2[nextR][nextC])continue;
			if (arr2[r][c] == arr2[nextR][nextC])
				dfs(nextR, nextC, mode);
		}
	}
}
int main() {
	
	cin >> N;
	string t;
	for (int r = 1; r <= N; ++r) {
		cin >> t;
		for (int c = 1; c <= N; ++c) {
			if (t[c - 1] == 'R') {
				arr1[r][c] = 1;
				arr2[r][c] = 1;
			}				
			else if (t[c - 1] == 'G') {
				arr1[r][c] = 2;
				arr2[r][c] = 1;
			}
			else {
				arr1[r][c] = 3;
				arr2[r][c] = 2;
			}
		}
	}
	int cnt1 = 0;
	int cnt2 = 0;
	for (int r = 1; r <= N; ++r) {
		for (int c = 1; c <= N; ++c) {
			if (!visited1[r][c]) {
				dfs(r, c, 1);
				cnt1++;
			}
			if (!visited2[r][c]) {
				dfs(r, c, 2);
				cnt2++;
			}

		}
	}
	cout << cnt1 << " " << cnt2;
	return 0;
}