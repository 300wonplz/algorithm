#include <iostream>
using namespace std;

long long D[1001][11];

long ascent(int n){
	long long sum = 0;
	
	for(int i = 2 ; i <= n ; i++){
		
		for(int j = 0; j <= 9 ; j++){
			for(int k = 0 ; k <= j ; k++){
				D[i][j] += D[i-1][k];
				D[i][j] %= 10007;
			}
		}
	}
	
	for(int l = 0 ; l < 10 ; l++){
		sum += D[n][l];
	}
	
	return sum%10007;
}

int main(void){
	int n;
	cin >> n;
	
	for(int i = 0 ; i < 10 ; i++){
		D[1][i] = 1;
	}
	
	cout << ascent(n)%10007 << endl;
	return 0;
}
