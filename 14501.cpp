// 문제 출처
// https://www.acmicpc.net/problem/14501
#include <iostream>

using namespace std;

int N, T, P;
int times[16];
int pay[16];
int dp[16] = {0, };

int main(void){
	cin >> N;

	for(int i = 1 ; i <= N ; i++){
		cin >> T >> P;
		times[i] = T;
		pay[i] = P;
		
		if(i + times[i] <= N+1)
			dp[i] = pay[i];
	}

	for(int i = 1 ; i <= N ; i++){
		for(int j = 1 ; j < i ; j++){
			if( (i-j >= times[j] ) && (i + times[i] <= N+1))
				dp[i] = max(dp[i] , pay[i] + dp[j]);
		}
	}

	int max = 0;
	for(int i =1 ; i <= N ; i++){
		if(dp[i] > max){
			max = dp[i];
		}
	}

	cout << max << endl;

	return 0;
}

// dp[i] = i번째 일일때 얻을 수 있는 최대 수익
// dp[6] = max(6일 까지의 최대 수익, 1~5일까지의 최대수익 + 6일의 수익)