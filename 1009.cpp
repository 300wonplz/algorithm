// 문제 출처
// https://www.acmicpc.net/problem/1009
#include <iostream>
#include <cmath>

using namespace std;

int main(void){
	int N, a, b;
	long long int data;
	cin >> N;

	for(int i = 0 ; i < N ; i++){
		cin >> a >> b;
		data = a;
		for(int j = 0 ; j < b-1 ; j++){
			data = (data * a) % 10;
		}

		if(data == 0){
			cout << "10" << endl;
		}else{
			cout << data << endl;
		}
	}
	return 0;
}

