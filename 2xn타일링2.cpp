#include <iostream>
using namespace std;

int D[1000];

int tiling(int n){
	if(n == 1) return 1;
	if(n == 2) return 3;
	if(D[n] > 0) return D[n];
	
	D[n] = (tiling(n-1) + 2*tiling(n-2))%10007;
	
	return D[n];
}

int main(void){
	int input;
	cin >> input;
	
	printf("%d\n", tiling(input));
	
	return 0;
}
