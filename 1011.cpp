#include <iostream>
#include <cmath>

using namespace std;

int main(void){
	int T, x, y;
	int distance;
	int tmp;
	int ans;
	cin >> T;

	for(int i = 0 ;  i < T ; i++){
		cin >> x >> y;
		distance =  y - x;

		int j = 1;
		while(sqrt(distance) > j){
			j++;
		}

		tmp = ( j * j - (j-1) * (j-1) ) / 2;

		if(distance <= (j - 1) * ( j - 1 ) + tmp){
			cout << j * 2 - 2 << endl;
		}else{
			cout << j * 2 - 1 << endl;
		}
	}
	return 0;
}