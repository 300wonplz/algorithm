// 문제 출처
// https://www.acmicpc.net/problem/1520
#include <iostream>

using namespace std;

int M,N;
int map[501][501] = {0};
int dp[501][501];
int dir[4][2] = { {1, 0}, {-1,0}, {0, 1} ,{0,-1} };

int dfs(int a, int b){
	if(dp[a][b] != -1)
		return dp[a][b];
	
	if(a==1 && b == 1)
		return 1;

	dp[a][b] = 0;
	
	for(int i = 0 ; i < 4 ; i++){
			int next_a = a + dir[i][0];
			int next_b = b + dir[i][1];

			if(next_a >= 1 && next_a <= M && next_b >= 1 && next_b <= N && map[next_a][next_b] > map[a][b]){
				dp[a][b] += dfs(next_a, next_b);
			}
	}

	return dp[a][b];
}

int main(void){

	cin >> M >> N;

	for(int i =  1; i <= M; i++){
		for(int j = 1 ; j <= N ; j++){
			cin >> map[i][j];
		}
	}

	for(int i =  1; i <= M; i++){
		for(int j = 1 ; j <= N ; j++){
			dp[i][j] = -1;
		}
	}

	cout << dfs(M, N) << endl;

	return 0;
}