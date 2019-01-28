// 문제 출처
// https://www.acmicpc.net/problem/9465
#include <iostream>
#include <algorithm>

using namespace std;

int dp[2][100001] = {0};
int cost[2][100001] = {0};

int main(void){
	int round;
	cin >> round;

	for(int i = 0 ; i < round ; i++){
		int N;
		cin >> N;
		
		for(int j = 1 ; j <= N ; j++){
			cin >> cost[0][j];
		}

		for(int k = 1 ; k <= N ; k++){
			cin >> cost[1][k];
		}


		dp[0][1] = cost[0][1];
		dp[1][1] = cost[1][1];
		dp[0][2] = cost[1][1] + cost[0][2];
		dp[1][2] = cost[0][1] + cost[1][2];

		for(int l = 3 ; l <= N ; l++){
			dp[0][l] = max(cost[0][l]+dp[1][l-1], cost[0][l]+dp[1][l-2]);
			dp[1][l] = max(cost[1][l]+dp[0][l-1], cost[1][l]+dp[0][l-2]);
		}

		cout <<max(dp[0][N], dp[1][N]) << endl;

	}

	

	return 0;
}

