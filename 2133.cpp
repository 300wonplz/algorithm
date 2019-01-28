#include <iostream>

using namespace std;

int dp[31] = {0,};

int main(void){
	int N;
	cin >> N;
	
	dp[0] = 1;
	dp[2] = 3;
	
	for(int i = 4; i <=30 ; i+=2){
		
		dp[i] = (dp[i-2] * 3) + (dp[i-4] * 2);
		
		for(int j = 6  ; j <=i ; j+=2){
			dp[i] += dp[i-j] * 2;
		}
	}
	
	cout << dp[N] << endl;
	
	return 0;
}
