// 문제 출처
// https://www.acmicpc.net/problem/2011
#include <iostream>
#include <string>
using namespace std;

int arr[5001] = {0};
int dp[5001] = {0};

int main(void){
	string s;
	cin >> s;
	
	int size = s.length();
	
	for(int i = 1 ; i <= s.length() ; i++){
		arr[i] = s[i-1] -'0';
	}
	
	dp[0] = 1;
	if(arr[1] != 0){
		dp[1] = 1;	
	}
	
	for(int i = 2 ; i <= size ; i++){
		if(arr[i] != 0 ){
			dp[i] = (dp[i] + dp[i-1]) % 1000000;
		}
		
		int check = arr[i-1] * 10 + arr[i];
		
		if(10 <= check && check <= 26){
			dp[i] = (dp[i] + dp[i-2]) % 1000000;
		}
	}
	
	cout << dp[size] << endl;
	return 0;
}
