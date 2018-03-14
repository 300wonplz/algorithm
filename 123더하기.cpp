#include <iostream>
using namespace std;

int D[11];

int add123(int n){
	if(n == 1) return 1;
	if(n == 2) return 2;
	if(n == 3) return 4;
	if(D[n] > 0) return D[n];
	
	D[n] = add123(n-1) + add123(n-2) + add123(n-3);
	
	return D[n];
}

int main(void){
	int n,input;
	cin >> n;
	int ans[n];
	
	for(int i = 0 ; i < n ; i++){
		cin >> input;
		ans[i] = add123(input);
	}
	
	for(int i = 0 ; i < n ; i++){
		printf("%d\n", ans[i]);
	}
	
	return 0;
}
