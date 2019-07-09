#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	vector<int> heights(9);
	int sum = 0;
	for (int i = 0; i < 9; ++i) {
		cin >> heights[i];
		sum += heights[i];
	}
	sort(heights.begin(), heights.end());

	for (int i = 0; i < 9; ++i) {
		for (int j = i + 1; j < 9; ++j) {
			if (sum - heights[i] - heights[j] == 100) {
				//cout << "   ----  " << i << " " << j << endl;
				for (int k = 0; k < 9; ++k) {
					if (k != i && k != j) {
						cout << heights[k] << endl;
					}
				}
				return 0;
			}

		}
	}

	return 0;
}