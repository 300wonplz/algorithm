// 문제 출처
// https://www.acmicpc.net/problem/14905
#include <iostream>

using namespace std;
#define HUNDRED_MILLION 100000000

bool primeArray[100000001];



int main(void){
	int input;

	//에라토스테네스의 체
	for(int i = 0 ; i <= HUNDRED_MILLION ; i++){
		primeArray[i] = true;
	}

	for(int i = 2 ; i*i <= HUNDRED_MILLION ; i++){
		if(primeArray[i]){
			for(int j = i * i ; j <= HUNDRED_MILLION ; j+=i){
				primeArray[j] = false;
			}
		}
	}

	while(cin >> input){

		if(input < 8){
			cout << "Impossible." << endl;
		}else{
			if(input % 2 == 0){
				cout << "2 2 ";
				input -= 4;
			}else{
				cout << "2 3 ";
				input -= 5;
			}

			for(int i = 2 ; i <= input ; i++){
				if(primeArray[i] && primeArray[input-i]){
						cout << i <<" "<< input-i <<endl;
						break;
				}
			}

		}
	}	

	return 0;
}

