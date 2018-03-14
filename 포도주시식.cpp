#include <iostream>
#include <algorithm>
using namespace std;

int D[10001];

int main(void){
	int n;
	cin >> n;
	
	int wine[n+1];
	for(int i = 1 ; i <= n ; i++){
		cin >> wine[i];
	}
	
	D[1] = wine[1];
	D[2] = wine[1] + wine[2];
	D[3] = max(max(wine[1]+wine[2],wine[1]+wine[3]), wine[2]+wine[3]);
	
	for(int i = 4 ; i <= n ; i++){
		D[i] = max(max(D[i-1], wine[i] + D[i-2]), wine[i]+wine[i-1]+D[i-3]);
	}
	
	
	cout<< D[n] << endl;
	
	return 0;
}
