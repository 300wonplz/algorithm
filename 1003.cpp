// 문제 출처
// https://www.acmicpc.net/problem/1003
#include <iostream>

using namespace std;

int cnt0 = 0 , cnt1 = 0;
int N, input;
pair<int, int> dp[41];


int main(void){
	cin >> N;
	dp[0] = make_pair(1, 0);
	dp[1] = make_pair(0, 1);

	for(int i = 2 ; i <= 40 ; i++){
			dp[i] = make_pair(dp[i-1].first + dp[i-2].first , dp[i-1].second + dp[i-2].second);
	}

	for(int i = 0 ; i < N ; i ++){
		cin >> input;

		cout << dp[input].first << " " << dp[input].second << endl;
	}
	return 0;
}