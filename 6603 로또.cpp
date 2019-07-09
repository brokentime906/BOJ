#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
vector<int>ans;
void pick(int N, int toPick ) {
	if (toPick == 0) {
		for (auto data : ans)
			cout << arr[data] << " ";
		cout << "\n";
		return;
	}
	int next_idx = ans.empty() ? 0 : ans.back() + 1;
	for (int i = next_idx; i < N; ++i) {
		ans.push_back(i);
		pick(N, toPick - 1);
		ans.pop_back();
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int K;
	//cin >> K;
	while (cin>> K ) {
		if (K == 0) break;
		ans.clear();
		
		arr = vector<int>(K);
		for (int i = 0; i < K; ++i)
			cin >> arr[i];
		pick(K, 6);
		cout << "\n";
		
	}
	return 0;
}