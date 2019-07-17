#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N;
int mapp[103][103];
int colorMap[103][103];
int dR[4] = { 0,-1,0,1 };
int dC[4] = { -1,0,1,0 };

bool can_go(int r, int c) {
	for (int i = 0; i < 4; ++i) {
		int nextR = r + dR[i];
		int nextC = c + dC[i];
		if (nextR < 1 || nextR > N || nextC <1 || nextC >N) continue;
		if (mapp[nextR][nextC] == 0)
			return true;
	}
	return false;
}
queue< pair< pair<int, int >, pair<int, int > > >q;
void dfs(int r, int c, int color) {
	colorMap[r][c] = color;
	if (can_go(r, c))
		q.push({ {r,c}, {color , 0} });
	for (int i = 0; i < 4; ++i) {
		int nextR = r + dR[i];
		int nextC = c + dC[i];
		if (nextR < 1 || nextR > N || nextC <1 || nextC >N) continue;
		if (mapp[nextR][nextC] == 1 && colorMap[nextR][nextC] == 0)
			dfs(nextR, nextC, color);
	}
}
int main() {

	
	cin >> N;

	for (int r = 1; r <= N; ++r)
		for (int c = 1; c <= N; ++c)
			cin >> mapp[r][c];
	int color = 0;
	for (int r = 1; r <= N; ++r)
		for (int c = 1; c <= N; ++c)
			if (colorMap[r][c] == 0 && mapp[r][c] ==1) {
				dfs(r, c, ++color);
			}
	/*cout << endl << endl;
				
	for (int r = 1; r <= N; ++r) {
		for (int c = 1; c <= N; ++c)
			cout<< colorMap[r][c]<< " ";
		cout << endl;
	}*/
		
	// 섬 색칠 하기 끝
	int min_ans = 1111111111;
	int distMap[103][103];
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int cur_R = cur.first.first;
		int cur_C = cur.first.second;
		int cur_color = cur.second.first;
		int cur_dist = cur.second.second;
		/*cout << cur_R << " " << cur_C << " " << cur_color << " " << cur_dist << endl;
		if (cur_color != colorMap[cur_R][cur_C] &&colorMap[cur_R][cur_C] != 0) {
			cout << ( cur_dist + distMap[cur_R][cur_C] ) ;
			return 0;
		}*/
		//if (colorMap[cur_R][cur_C]) continue;
		//if(cur_dist != 0)
		//cout << cur_R << " " << cur_C << " " << cur_color << " " <<cur_dist << endl;
		for (int i = 0; i < 4; ++i) {
			int nextR = cur_R + dR[i];
			int nextC = cur_C + dC[i];
			if (nextR < 1 || nextR > N || nextC <1 || nextC >N) continue; //판 넘은건 안보는게 맞고
			if (mapp[nextR][nextC] == 0) {  //바다인것 중에서
				if (colorMap[nextR][nextC] == cur_color) continue; //이미 같은색이면 pass
				if (colorMap[nextR][nextC] == 0) {                 //색칠 안된 바다면 색칠하고 +1로 넣어줌
					colorMap[nextR][nextC] = cur_color;
					mapp[nextR][nextC] = 1;
					q.push({{ nextR,nextC }, { cur_color,cur_dist + 1 }});
					distMap[nextR][nextC] = cur_dist + 1;
				}				
			}			
			else { 
				if (cur_color != colorMap[nextR][nextC] ) {
					/*for (int i = 1; i <= N; ++i) {
						for (int j = 1; j <= N; ++j)
							cout << colorMap[i][j] << " ";
						cout << endl;
					}*/
					//cout << "  this  " << nextR << " " << nextC << " " << cur_color << " " << colorMap[nextR][nextC] << " " <<cur_dist<<endl;
					if (cur_dist + distMap[nextR][nextC] < min_ans)
						min_ans = cur_dist + distMap[nextR][nextC];
				}
				
			}
			
		}
	}
	cout << min_ans;
	return 0;
}