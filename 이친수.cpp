#include <iostream>
using namespace std;

long D[90];

long echin(int n){
	long long sum = 0;
	
	for(int i = 3 ; i <= n ; i++){
		D[i] = D[i-1] + D[i-2];
	}
	
	return D[n];
}

int main(void){
	int n;
	cin >> n;
	
	D[1] = 1;
	D[2] = 1;
	
	cout << echin(n) << endl;
	return 0;
}
