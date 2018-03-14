#include <iostream>
using namespace std;

int D[101][10];

long stair(int n){
	long long sum = 0;
	
	for(int i = 2 ; i <= n ; i++){
		
		for(int j = 0; j <= 9 ; j++){
			if(j+1 <= 9) D[i][j] += D[i-1][j+1];
			if(j-1 >= 0) D[i][j] += D[i-1][j-1];
            D[i][j] %= 1000000000;
		}
	}
	
	for(int k = 0 ; k < 10 ; k++){
		sum += D[n][k];
	}
	
	return sum%1000000000;
}

int main(void){
	int n;
	cin >> n;
	
	for(int i = 1 ; i < 10 ; i++){
		D[1][i] = 1;
	}
	
	cout << stair(n) << endl;
	return 0;
}
