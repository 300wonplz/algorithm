#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001] = {0};
int arr[10001] = {0};


int main(void){
	int size;
	cin >> size;

	for(int i = 1 ; i <= size ; i++){
		cin >> arr[i];
	}

	for(int i = 1 ; i <= size ; i++){
		for(int j = 1 ; j <= i ; j++){
			dp[i] = max(dp[i], arr[j] + dp[i-j]);
		}
	}

	cout << dp[size] << endl;

	return 0;
}