#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool checkHansu(string & str) {
	if (str.size() <= 2) return true;
	int diff = int(str[0]) - int(str[1]);	
	for (int i = 1; i < str.size()-1; ++i) {
		int cur_diff = int(str[i]) - int(str[i+1]);
		if (diff != cur_diff)
			return false;
	}
	return true;
}

int main() {

	int N;
	cin >> N;
	int ans = 0;
	for (int num = 1; num <= N; ++num) {
		string numStr = to_string(num);
		if (checkHansu(numStr))
			ans++;
	}
	cout << ans;

	return 0;
}