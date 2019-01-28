// 문제 출처 '거울 설치'
// https://www.acmicpc.net/problem/2151
#include <iostream>

using namespace std;

int result = 99999;
int cnt = 0;
int N;

int dir[53][53] = {0}; // 1이면 다음 진행방향이 col, -1이면 row
char map[53][53];
bool visit[53][53];

void dfs(int a, int b){
	
}

int main(void){
	cin >> N;

	int a, b;
	
	for(int i = 1 ; i <= N ; i++){
		for(int j = 1 ; j <= N ; j++){
			cin >> map[i][j];
		}
	}

	
	// for(int i = 1 ; i <= N ; i++){
	// 	for(int j = 1 ; j <= N ; j++){
	// 		cout << map[i][j];
	// 	}
	// 	cout << endl;
	// }

	return 0;
}