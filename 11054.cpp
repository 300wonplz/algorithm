#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001] = {0};
int dp[2][1001] = {0};

int main(void){
	int size;
	cin >> size;
	
	for(int i = 1 ; i <= size; i++){
		cin >> arr[i];
	}

	for(int i = 1 ; i <= size ; i++){
		dp[0][i] = 1;

		for(int j = 1 ; j < i ; j++){
			if(arr[i] > arr[j]){
				dp[0][i] = max(dp[0][i], dp[0][j] + 1);
			}
		}

	}

	for(int i = size ; i >= 1 ; i--){
		dp[1][i] = 1;

		for(int j = size ; j >= i ; j--){
			if(arr[i] > arr[j]){
				dp[1][i] = max(dp[1][i], dp[1][j] + 1);
			}
		}
	}

	int max = 0;
	for(int i = 1 ; i <= size ; i++){
		if(dp[0][i]+dp[1][i] >= max){
			max = dp[0][i]+dp[1][i];
		}
	}
	
	cout << max-1 << endl;

	return 0;
}
