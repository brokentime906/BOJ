#include <iostream>
#include <vector>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;
	vector<int> a(N);
	for (auto & data : a) {
		cin >> data;
	}
	
	int ans = 0;
	for (int i = a.size() - 1; i >= 0; --i) {
		int numOfPaper = K / a[i];
		int remainder = K % a[i];

		ans += numOfPaper;
		K = remainder;
		
	}
	cout << ans;
	return 0;
}