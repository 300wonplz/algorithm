#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001] = {0};
int dp[1001] = {0};

int main(void){
	int size;
	cin >> size;
	
	for(int i = 1 ; i <= size; i++){
		cin >> arr[i];
	}
	
	for(int i = 1 ; i <= size ; i++ ){
		dp[i] = 1;
		
		for(int j = 1 ; j <= i ; j++){
			if(arr[i] > arr[j]){
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
	}

	int max = 0;

	for(int i = 1 ; i <= size ; i++){
		if(dp[i] >= max){
			max = dp[i];
		}
	}
	
	cout << max << endl;
	
	return 0;
}
