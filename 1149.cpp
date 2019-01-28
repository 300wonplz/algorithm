// 문제 출처
// https://www.acmicpc.net/problem/1149
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int dp[1001][3] = {0};
int house[1001][3];

int main(void){
	cin >> N;

	for(int i = 1 ; i <= N ; i++){
		for(int j = 0  ; j < 3 ; j++){
			cin >> house[i][j];
		}
	}

	dp[1][0] = house[1][0];
	dp[1][1] = house[1][1];
	dp[1][2] = house[1][2];

	for(int i = 1 ; i <= N ; i++){
		dp[i][0] = min(house[i][0] + dp[i-1][1], house[i][0] + dp[i-1][2]);
		dp[i][1] = min(house[i][1] + dp[i-1][0], house[i][1] + dp[i-1][2]);
		dp[i][2] = min(house[i][2] + dp[i-1][0], house[i][2] + dp[i-1][1]);
	}

	cout << min(dp[N][0],min(dp[N][1], dp[N][2])) << endl;

	

	return 0;
}