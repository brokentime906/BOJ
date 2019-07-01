#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int,int>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);



	int N;
	cin >> N;
	vector<pii> a(N);
	for (int i = 0; i < N; ++i) {
		int a1, a2;
		cin >> a1 >> a2;
		a[i] = { a2,a1 };
	}
	sort(a.begin(), a.end());
	int beforeEndTime = -1;

	int ans = 0;
	for (int i = 0; i < N; ++i) {
		int curStartTime = a[i].second;
		int curEndTime = a[i].first;
		if (curStartTime < beforeEndTime) continue;
		beforeEndTime = curEndTime;
		ans++;
	}
	cout << ans;
}