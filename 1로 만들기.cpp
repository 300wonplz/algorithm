#include <iostream>
using namespace std;

int D[1000000] = {0};

int makeone(int N){
	if(N == 1){
		return 0;
	}
	
	if(D[N] > 0){
		return D[N];
	}
	
	D[N] = makeone(N-1) + 1;
	
	if(N%3 == 0){
		int temp = makeone(N/3) + 1;
		if(D[N] > temp){
			D[N] = temp;
		}
	}
	
	if(N%2 == 0){
		int temp = makeone(N/2) + 1;
		if(D[N] > temp){
			D[N] = temp;
		}
	}
	
	return D[N];
}


int main(void){
	int input;
	cin >> input;
	
	printf("%d\n", makeone(input));
	
	return 0;
}
