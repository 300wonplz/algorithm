#include <iostream>
#include <queue>

using namespace std;

int M,N;
long long int cnt = 0;
int map[501][501] = {0};
int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
queue<pair<int, int> > q;

void bfs(){
	q.push(make_pair(1, 1));

	while(!q.empty()){
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		for(int i = 0 ; i < 4 ; i++){
			int next_a = a + dir[i][0];
			int next_b = b + dir[i][1];

			if(next_a >= 1 && next_a <= M && next_b >= 1 && next_b <= N && map[next_a][next_b] < map[a][b]){
				if(next_a == M && next_b == N){
					cnt++;
				}else{
					q.push(make_pair(next_a, next_b));
				}
			}
		}

	}
}

int main(void){
	cin >> M >> N;

	for(int i =  1; i <= M; i++){
		for(int j = 1 ; j <= N ; j++){
			cin >> map[i][j];
		}
	}

	bfs();

	cout << cnt << endl;

	return 0;
}