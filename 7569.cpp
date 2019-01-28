// 문제 출처
// https://www.acmicpc.net/problem/7569
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int dir[6][3] = { {1,0,0}, {-1,0,0}, {0,1,0}, {0,-1,0}, {0,0,1}, {0,0,-1} };
int map[102][102][102] = {0};
int visit[102][102][102] = {0};
int day = 0;
int M,N,H;

queue< pair<int, pair<int, int> > > q;

bool check_dir(int next_a, int next_b, int next_c){
	return next_a <= M && next_b <= N && next_c <= H && next_a >=1 && next_b >=1 && next_c>=1 ? true : false;
}

void bfs(){

	while(!q.empty()){

		int a = q.front().first;
		int b = q.front().second.first;
		int c = q.front().second.second;
		q.pop();

		for(int i = 0 ; i < 6 ; i++){
			int next_a = a + dir[i][0];
			int next_b = b + dir[i][1];
			int next_c = c + dir[i][2];

			if(check_dir(next_a, next_b, next_c) && !visit[next_a][next_b][next_c]){
				q.push(make_pair(next_a, make_pair(next_b, next_c)));
				map[next_a][next_b][next_c] = map[a][b][c] +1;
				visit[next_a][next_b][next_c] = 1;
			}

			
			if(map[next_a][next_b][next_c] >= day)
				day = map[next_a][next_b][next_c];

		}
	}

}

int main(void){

	cin >> M >> N >> H;
	
	for(int k = 1 ; k <= H ; k++){
		for(int j = 1 ; j <= N ; j++){
			for(int i =1 ; i <=M ; i++){
				cin >> map[i][j][k];
			}
		}
	}

	for(int k = 1 ; k <= H ; k++){
		for(int j = 1 ; j <= N ; j++){
			for(int i =1 ; i <=M ; i++){
				if(map[i][j][k] == 1){
					visit[i][j][k] = 1;
					q.push(make_pair(i, make_pair(j, k)));
				}else if(map[i][j][k] == -1){
					visit[i][j][k] = 1;
				}
			}
		}
	}

	bfs();

	for(int k = 1 ; k <= H ; k++){
		for(int j = 1 ; j <= N ; j++){
			for(int i =1 ; i <=M ; i++){
				if(map[i][j][k] == 0){
					day = 0;
				}
			}
		}
	}

	cout << day-1 << endl;

	return 0;
}