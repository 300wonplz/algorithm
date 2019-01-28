// 문제 출처
// https://www.acmicpc.net/problem/2293

#include <iostream>

using namespace std;

int val[101];
int n, k;
int dp[10002] = {0};

int main(void){

	cin >> n >> k;

	for(int i = 1 ; i <= n ; i++){
		cin >> val[i];
	}

	
	dp[0] = 1;

	for(int i = 1 ; i <= n ; i++){ 
		for(int j = 1 ; j <= k ; j++){
			if(j - val[i] >= 0){
				dp[j] += dp[j - val[i]];			
			}
		}
	}


	cout << dp[k] << endl;

	return 0;
}