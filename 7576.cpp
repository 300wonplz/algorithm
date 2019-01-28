// 문제 출처
// https://www.acmicpc.net/problem/7576
#include <iostream>
#include <queue>

using namespace std;

int map[1002][1002] = {0};
int visit[1001][1001] = {0};
int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1, 0} };
queue< pair<int, int> > q;

int col, row;
int max_val;

bool check_dir(int next_a, int next_b){
	return next_a >=1 && next_a <= col && next_b >= 1 && next_b <= row;
}

void dfs(){
	while(!q.empty()){
		int position_a = q.front().first;
		int position_b = q.front().second;
		q.pop();

		for(int i = 0 ; i < 4 ; i++){
			int next_a = position_a + dir[i][0];
			int next_b = position_b + dir[i][1];
			
			if(check_dir(next_a, next_b) && !visit[next_a][next_b]){
				q.push(pair<int, int>(next_a, next_b));
				map[next_a][next_b] = map[position_a][position_b] + 1;
				visit[next_a][next_b] = 1;
			}

			if(map[next_a][next_b] > max_val)
				max_val = map[next_a][next_b];
		}

	}
}

int main(void){
	cin >> row >> col;

	for(int i = 1 ; i <= col ; i ++){
		for(int j = 1 ; j <= row ; j++){
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= col ; ++i){
		for(int j = 1 ; j <= row ; j++){
			if( map[i][j] == 1 ){
				q.push(pair<int, int>(i, j));
				visit[i][j] = 1;
			}else if(map[i][j] == -1){
				visit[i][j] = 1;
			}
		}
	}
	
	dfs();

	bool check = true;
	for(int i = 1 ; i <= col ; i++){
		for(int j = 1 ; j <= row ; j++){
			if(map[i][j] == 0){
				check = false;
				break;
			}
		}
	}

	if(check){
		if(max_val == 0)
			cout << max_val << endl;
		else
			cout << max_val-1 << endl;
	}else
		cout << "-1" << endl;

	return 0;
}