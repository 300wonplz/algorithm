#include <iostream>

using namespace std;

int main(void){
	bool flag = true;
	string input;
	cin >> input;

	for(int i = 0 ; i < input.length() / 2 ; i++){
		if(input[i] != input[input.length()-1-i])
			flag = false;
	}

	if(flag)
		cout << 1 << endl;
	else
		cout << 0 << endl;

	return 0;
}