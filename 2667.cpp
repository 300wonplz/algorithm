// 문제 출처
// https://www.acmicpc.net/problem/2667
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int map[26][26] = {0};
int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
int house[1000] = {0};
int complex = 1;
int visit[26][26] = {0};
queue< pair<int, int> > q;

int check_boundary(int next_x, int next_y, int size){
	return next_x >= 1 && next_x <= size && next_y >=1 && next_y <=size;
}

void bfs(int x, int y, int size){
	q.push(pair<int, int>(x, y));
	
	map[x][y] = complex;
	house[complex-1]++;
	visit[x][y] = 1;
	

	while(!q.empty()){
		int position_x = q.front().first;
		int position_y = q.front().second;
		q.pop();

		for(int i = 0 ; i < 4 ; i++){
			int next_x = position_x + dir[i][0];
			int next_y = position_y + dir[i][1];

			if(check_boundary(next_x, next_y, size) && map[next_x][next_y] && !visit[next_x][next_y]){
				q.push(pair<int, int>(next_x, next_y));
				map[next_x][next_y] = complex;
				visit[next_x][next_y] = 1;
				house[complex-1]++;
			}
		}

	}
	complex++;
}

int main(void){
	int size;

	cin >> size;

	for(int i = 1 ; i <= size ; i++){
		char c[size];
		cin >> c;
		for(int j = 1 ; j <= size ; j++){
			map[i][j] = c[j-1] - '0';
		}
	}


	for(int i = 1 ; i <= size ; i++){
		for(int j = 1 ; j <= size ; j++){
			if( map[i][j] && !visit[i][j]){
				bfs(i, j, size);
			}
		}
	}

	cout << complex-1 << endl;
	sort(house, house+complex-1);
	for(int i = 0 ; i < complex-1 ; i++){
		cout << house[i] << endl;
	}

	return 0;
}

