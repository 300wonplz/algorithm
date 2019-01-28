// 문제 출처
// https://www.acmicpc.net/problem/9251

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

char s1[1002];
char s2[1002];
int dp[1002][1002] = {0,};

int main(void){
	cin >> s1;
	cin >> s2;

	for(int i = 1 ; i<=strlen(s1) ; i++){
		for(int j = 1 ; j <= strlen(s2) ; j++){
			if(s1[i-1] == s2[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);	
			}
		}
	}

	cout << dp[strlen(s1)][strlen(s2)] << endl;

	return 0;
}