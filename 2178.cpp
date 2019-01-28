// 문제 출처
// https://www.acmicpc.net/problem/2178

#include <iostream>
#include <queue>

using namespace std;

int N,M;
char input[102];
int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int map[101][101] = {0,};
int visit[101][101] = {0,};
queue<pair<int, int> > q;

void bfs(int a, int b){
	q.push(make_pair(a, b));

	while(!q.empty()){
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		for(int i = 0 ; i < 4 ; i++){
			int next_a = a + dir[i][0];
			int next_b = b + dir[i][1];

			if(next_a >= 1 && next_a <=N && next_b>=1 && next_b<=M && visit[next_a][next_b] == 0 && map[next_a][next_b] != 0){
				q.push(make_pair(next_a, next_b));
				visit[next_a][next_b] = 1;
				map[next_a][next_b] = map[a][b] + 1;
				// cout << next_a << "\t" << next_b << endl;
			}
		}
	}
}

int main(void){
	cin >> N >> M;

	for(int i = 1; i <= N ; i++){
		cin >> input;
		for(int j = 1 ; j <= M ; j++){
			map[i][j] = input[j-1] - '0';
		}
	}

	visit[1][1] = 1;
	bfs(1,1);

	cout << map[N][M] << endl;
	// for(int i = 1; i <= N ; i++){
	// 	for(int j = 1 ; j <= M ; j++){
	// 		cout << map[i][j] <<" ";
	// 	}
	// 	cout << endl;
	// }
	return 0;
}