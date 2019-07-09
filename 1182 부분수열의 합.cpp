#include <iostream>
#include <vector>


using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, S;
	cin >> N >> S;
	vector<int> arr(N);
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	int ans = 0;
	//cout << ((5 >> 1) & 1);
	for (int i = 0; i < (1 << N); ++i) {
		int cur_num = 0;
		for (int idx = 0; idx < N; ++idx) {
			if ((1 << idx) & i)
				cur_num += arr[idx];
		}
		if (S == cur_num) ans++;
	}
	if (S == 0)ans--;
	cout << ans;

	return 0;
}