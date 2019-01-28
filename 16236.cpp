// 문제 출처
// https://www.acmicpc.net/problem/16236
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int size, size_cnt;
int ans = 0;
int map[21][21] = {0,};
int visit[21][21] = {0, };
int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

struct fish
{
	int row;
	int col;
	int size;
	int eat;
	int distance;
};

queue<fish> q;
vector<fish> v;

bool cmp(fish a, fish b){
	if(a.distance == b.distance){
		if(a.row == b.row){
			return a.col < b.col;
		}else{
			return a.row < b.row;
		}
	}else{
		return a.distance < b.distance;
	}
}


void bfs(fish shark){
	q.push(shark);
	visit[shark.row][shark.col] = 1;

	while(!q.empty()){
		int row = q.front().row;
		int col = q.front().col;
		int size = q.front().size;
		int eat = q.front().eat;
		int distance = q.front().distance;
		q.pop();


		for(int i =0 ; i < 4 ; i++){
			int next_row = row + dir[i][0];
			int next_col = col + dir[i][1];
			fish next_fish;

			if(next_row >= 1 && next_row <= N && next_col >= 1 && next_col <= N && !visit[next_row][next_col]){
				if(map[next_row][next_col] == 0 || map[next_row][next_col] == size){
					visit[next_row][next_col] = 1;
					q.push((fish){next_row, next_col, size, eat, distance+1});
				}
				else if(map[next_row][next_col] < size){
					visit[next_row][next_col] = 1;
					v.push_back((fish){next_row, next_col, size, eat+1, distance+1});
				}
			}
		}
	}
}


int main(void){
	cin >> N;
	fish shark;

	for(int i = 1 ; i <= N ; i++){
		for(int j = 1 ; j <= N ; j++){
			cin >> map[i][j];

			if(map[i][j] == 9){
				map[i][j] = 0;
				shark = (fish){i, j, 2, 0 ,0};
			}
		}
	}


	while(1){
		v.clear();
		memset(visit, 0 , sizeof(visit));
		bfs(shark);

		if(v.size() == 0)
			break;

		sort(v.begin(), v.end(), cmp);

		if(v[0].size == v[0].eat){
			v[0].size++;
			v[0].eat = 0;
		}

		map[v[0].row][v[0].col] = 0;

		ans += v[0].distance;
		
		shark = (fish){v[0].row, v[0].col, v[0].size, v[0].eat, 0};
	}

	cout << ans << endl;



	return 0;
}