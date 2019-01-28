// 문제 출처
// https://www.acmicpc.net/problem/3055
#include <iostream>
#include <queue>

using namespace std;

int R, C;

char tmp[52][52];
int map[52][52];
int visit[52][52];
int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int result = 0;

queue< pair<int, int> > q;

bool check_dir(int next_a, int next_b){
	return next_a >=1 && next_a <= R && next_b >= 1 && next_b <= C;
}

void bfs(){
	while(!q.empty()){
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		for(int i = 0 ; i < 4 ; i++){
			int next_a = a + dir[i][0];
			int next_b = b + dir[i][1];

			if(map[a][b] == -1){
				//물일경우
				if(check_dir(next_a, next_b) && !visit[next_a][next_b]){
					q.push(make_pair(next_a, next_b));
					map[next_a][next_b] = -1;
					visit[next_a][next_b] = -1;
				}
			}else if(map[a][b] > 0){
				//비버일 경우
				if(check_dir(next_a, next_b) && !visit[next_a][next_b] && visit[next_a][next_b] != -2){
					q.push(make_pair(next_a, next_b));
					map[next_a][next_b] = map[a][b] + 1;
					visit[next_a][next_b] = 1;
				}else if(check_dir(next_a, next_b) && visit[next_a][next_b] == -2){
					q.push(make_pair(next_a, next_b));
					map[next_a][next_b] = map[a][b] + 1;
					visit[next_a][next_b] = 1;

					if(map[next_a][next_b] > result)
						result = map[next_a][next_b];
					return;
				}
			}

			if(map[next_a][next_b] > result)
				result = map[next_a][next_b];
		}
	}
}

int main(void){
	cin >> R >> C;

	for(int i = 1 ; i <= R ; i++){
		for(int j = 1 ; j <= C ; j++){
			cin >> tmp[i][j];
		}
	}


	for(int i = 1 ; i <= R ; i++){
		for(int j = 1 ; j <= C ; j++){
			 if(tmp[i][j] == '.')
			 	map[i][j] = 0;
			 else if(tmp[i][j] == '*')
			 	map[i][j] = -1;
			 else if(tmp[i][j] == 'D')
			 	map[i][j] = -2;
			 else if(tmp[i][j] == 'X')
			 	map[i][j] = -3;
			 else
			 	map[i][j] = 1;
		}
	}

	for(int i = 1 ; i <= R ; i++){
		for(int j = 1 ; j <= C ; j++){
			 if(map[i][j] == -1){
			 	visit[i][j] = -1;
			 	q.push(make_pair(i, j));
			 }
		}
	}

	for(int i = 1 ; i <= R ; i++){
		for(int j = 1 ; j <= C ; j++){
			 if(map[i][j] == -1){
			 	visit[i][j] = -1;
			 	q.push(make_pair(i, j));
			 }else if(map[i][j] == -2){
			 	visit[i][j] = -2;
			 }else if(map[i][j] == -3){
			 	visit[i][j] = -3;
			 }
		}
	}

	for(int i = 1 ; i <= R ; i++){
		for(int j = 1 ; j <= C ; j++){
			 if(map[i][j] == 1){
			 	visit[i][j] = 1;
			 	q.push(make_pair(i, j));
			 }
		}
	}

	bfs();

	bool check = true;
	for(int i = 1 ; i <= R ; i++){
		for(int j = 1 ; j <= C ; j++){
			 if(map[i][j] == -2){
			 	check = false;
			 }
		}
	}

	if(check)
		cout << result-1 << endl;
	else
		cout << "KAKTUS" << endl;
	

	return 0;
}