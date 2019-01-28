// 문제 출처
// https://www.acmicpc.net/problem/10942
#include <iostream>

using namespace std;

int N;
int num[2001] = {0,};
int M;
int S, E;
int dp[2001][2001];

int isPal(int start, int end){
	if(dp[start][end] != -1)
		return dp[start][end];
	

	if( (num[start] == num[end]) && isPal(start+1, end-1) ){
		dp[start][end] = 1;
		return 1;
	}else{
		dp[start][end] = 0;
		return 0;
	}
}

int main(void){
	string s;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	fill( &dp[0][0], &dp[2000][2001], -1 );


	cin >> N;

	for(int i = 1 ; i <= N ; i++){
		cin >> num[i];
	}

	for(int i =1 ; i <= 2000 ; i++){
		dp[i][i] = 1;

		if(num[i] == num[i+1])
			dp[i][i+1] = 1;
		else
			dp[i][i+1] = 0;
	}



	cin >> M;

	for(int i = 1 ; i <= M ; i++){
		cin >> S >> E;

		if(isPal(S, E))
			s += "1\n";
		else
			s += "0\n";
	}

	cout << s;


	return 0;
}

// dp[i][j] =   s,j 가 i,j일경우 펠린드롬이면 1 아니면 0;
// dp[i][j] = dp[i+1][j-1]이 참이고 num[i] == num[j]도 참일때 참 아니면 거짓