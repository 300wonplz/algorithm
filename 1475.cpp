// 문제 출처
// https://www.acmicpc.net/problem/1475
#include <iostream>
#include <string>
using namespace std;

int arr[1000001] = {0};
int ncount[10] = {0};

int main(void){

	int size;
	string input;
	cin >> input;

	size = input.length();

	for(int i = 0 ; i < size ; i++){
		arr[i] = input[i] - '0';
	}

	for(int i = 0 ; i < size ; i++){
		ncount[arr[i]]++;
	}


	ncount[6] += ncount[9];
	
	if(ncount[6] % 2 == 0){
		ncount[6] = ncount[6] / 2;
	}else{
		ncount[6] = (ncount[6] / 2) + 1;
	}


	int max = 0;
	for(int i = 0 ; i <= 8 ; i++){
		if(ncount[i] >= max){
			max = ncount[i];
		}
	}

	cout << max << endl;

	return 0;
}