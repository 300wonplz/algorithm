#include <iostream>

using namespace std;

int main(void){

	for(int i = 0 ; i < 100 ; i++){
		char s[101];
		cin.getline(s,101,'\n');
		cout << s << endl;
	}

	return 0;
}