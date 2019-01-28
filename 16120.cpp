#include <iostream>

using namespace std;

// char c[1000001];
string c;
char s[1000001];

int main(void){
	cin >> c;

	int i = 1;
	int j = 1;
	while( i <=  c.length() ){
		s[j++]  = c[i-1];

		if(j > 4 && s[j-1] == 'P' && s[j-2] == 'A' && s[j-3] == 'P' && s[j-4] == 'P' )
			j -= 3;


		i++;
	}


	if(j==2 && s[1] == 'P')
		cout << "PPAP" << endl;
	else
		cout << "NP" << endl;


	return 0;
}