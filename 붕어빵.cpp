#include <iostream>
#include <algorithm>
using namespace std;

int D[1001] = {0};

int sell(int n, int price[]){
	int max = 0;
	
	if(n == 0) return 0;
	if(n == 1) return price[1];
	if(D[n] > 0) return D[n];
	
	for(int i = 1 ; i <= n; i++){
		D[n] = std::max(D[n],price[i] + sell(n-i, price));
	}

	return D[n];
}

int main(void){
	int n;
	cin >> n;
	
	int price[n+1];
	
	for(int i = 0; i < n ; i++){
		cin >> price[i+1];
	}
	
	printf("%d\n", sell(n,price));
	
	return 0;
}
