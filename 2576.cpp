// 문제 출처
// https://www.acmicpc.net/problem/2576
#include <iostream>

using namespace std;

int main(void){
	int sum = 0;
	int min = 999;
	int N;

	for(int i = 1 ; i <= 7 ; i++){
		cin >> N;
		if(N % 2 != 0){
			sum += N;
			if(N < min)
				min = N;
		}
	}

	if(sum == 0)
		cout << "-1" << endl;
	else{
		cout << sum << endl;
		cout << min << endl;
	}

	return 0;
}