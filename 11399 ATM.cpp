#include <iostream>
#include <algorithm>

using namespace std;

int a[1001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long N;
	cin >> N;

	for (int i = 0; i < N; ++i)
		scanf("%lld", &a[i]);

	sort(a, a+N);
	int ans = 0;
	int sum = 0;
	for (long long i = 0; i < N; ++i) {
		sum += a[i];
		ans += sum;
	}
	cout << ans;
}