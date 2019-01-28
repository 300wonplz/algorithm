// 문제 출처
// https://www.acmicpc.net/problem/1915
#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int map[1002][1002]={0};
int dp[1002][1002] = {0};
int maximum = 0;
char c[1002];


int main(void){
	cin >> n >> m;

	for(int i = 1 ; i <= n ; i ++){
		cin >> c;
		for(int j = 1 ; j <= m ; j++){
			map[i][j] = c[j-1] -'0';
		}
	}


	for(int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j <= m ; j++){
			if(map[i][j] == 1){
				dp[i][j] = 1;
			}
		}
	}

	for(int i = 2 ; i <= n ; i ++){
		for(int j = 2 ; j <= m ; j++){
			if(dp[i][j-1] &&dp[i-1][j-1] && dp[i-1][j] && dp[i][j]){
				dp[i][j] += min(dp[i][j-1], min(dp[i-1][j-1], dp[i-1][j]) );
			}
		}
	}


	for(int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j <= m ; j++){
			if(dp[i][j] > maximum){
				maximum = dp[i][j];
			}
		}
	}
	cout << maximum* maximum << endl;

	return 0;
}