// 문제 출처
// https://www.acmicpc.net/problem/1002
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void){
	int N;
	float x1, y1, r1, x2, y2, r2;
	float distance, plus, minus;
	cin >> N;

	for(int i = 0 ; i < N ; i++){
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		distance = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
		plus = (r1+r2) * (r1+r2);
		minus = (r1 - r2) * (r1 - r2);
		
		if(distance == 0 && r1 == r2)
			cout << "-1" << endl;
		else if(distance == plus || distance == minus)
			cout << "1" << endl;
		else if(distance > plus || distance < minus)
			cout << "0"<< endl;
		else if(distance < plus || distance > minus)
			cout << "2" << endl;
		else
			cout << "0" << endl;
			
	}

	return 0;
}