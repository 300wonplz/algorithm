// 문제 출처
// https://www.acmicpc.net/problem/2589
#include <iostream>
#include <queue>

using namespace std;

int map[51][51] = {0};
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int visit[51][51] = {0};
int col, row;
int maximum = 0;

queue< pair<int, int> > q;

void bfs(int a, int b){
		
	q.push(pair<int,int>(a, b));

	map[a][b] = 1;
	visit[a][b] = 1;

	while(!q.empty()){
		int position_a = q.front().first;
		int position_b = q.front().second;
		q.pop();

		for(int i = 0 ; i < 4 ; i++){
			int next_a = position_a + dir[i][0];
			int next_b = position_b + dir[i][1];

			if(next_a >= 1 && next_a <= col && next_b >= 1 && next_b <= row && !visit[next_a][next_b] && map[next_a][next_b]){
				q.push(pair<int, int>(next_a, next_b));
				visit[next_a][next_b] = 1;
				map[next_a][next_b] = map[position_a][position_b]+1;

				if(map[next_a][next_b] > maximum)
					maximum = map[next_a][next_b];
			}
		}
	}

	for(int i = 0 ; i < 51 ; i++){
		for(int j = 0 ; j < 51 ; j++){
			visit[i][j] = 0;
		}
	}
}

int main(void){

	cin >> col >> row;
	
	char c[51];
	for(int i = 1 ; i <= col ; i++){
		cin >> c;
		for(int j = 1 ; j <= row ; j++){
			if(c[j-1] == 'W')
				map[i][j] = 0;
			else
				map[i][j] = 1;
		}
	}

	for(int i = 1 ; i <= col ; i++){
		for(int j = 1 ; j <= row ; j++){
			if(map[i][j] != 0){
				bfs(i, j);
			}
		}
	}

	cout << maximum-1 << endl;

	return 0;
}