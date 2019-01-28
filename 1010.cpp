// 문제 출처
// https://www.acmicpc.net/problem/1010
#include <iostream>

using namespace std;

int T, N ,M;
long long int dp[30][30] = {0,};

int main(void){
	cin >> T;

	for(int i = 1 ; i <= 29 ; i++){
		dp[1][i] = i;
	}

	for(int i = 1 ; i <= 29 ; i++){
		dp[i][i] = 1;
	}

	for(int i = 2 ; i <= 29 ; i++){
		for(int j = 2 ; j <= 29 ; j++){
			for(int k = i-1 ; k <= j-1 ; k++){
				if(i < j)
					dp[i][j] += dp[i-1][k];
			}
		}
	}

	for(int i = 0 ; i < T ; i++){
		cin >> N >> M;
		cout << dp[N][M] << endl;
	}
	return 0;
}

//dp[i][j]  : i, j개 있을 때 다리지을 수 있는 경우의 수
//dp[5][10] = dp[4][9] + dp[4][8] + dp[4][7] + dp[4][6] + dp[4][5] + dp[4][4]