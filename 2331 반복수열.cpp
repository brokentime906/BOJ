#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>


using namespace std;


string A;
int P;

int baesu[11];
int make_next_num(string cur_num) {
	int ret = 0;
	for (int i = 0; i < cur_num.size(); ++i) {
		int now_num = int(cur_num[i]-'0');
		ret +=  baesu[now_num];
	}
	return ret;
}
int make_baesu(int num) {
	int ret = num;
	for (int i = 1; i < P; ++i)
		ret *= num;
	return ret;
}
int main() {


	cin >> A >> P;
	int cur_num = atoi(A.c_str());
	for (int i = 0; i < 11; ++i)
		baesu[i] = make_baesu(i);
	int cnt = 0;
	set<int>ans;
	vector<int>sunsu;
	ans.insert(cur_num);
	sunsu.push_back(cur_num);
	while (true) {
		cur_num = make_next_num(A);
		//cout << cur_num << endl;
		if (ans.count(cur_num))
			break;
		ans.insert(cur_num);
		A = to_string(cur_num);
		cnt++;
		sunsu.push_back(cur_num);
	}
	for (int i = 0; i < sunsu.size(); ++i)
		if (sunsu[i] == cur_num)
			cout << i;
	

	return 0;
}