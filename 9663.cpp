// 문제 출처
// https://www.acmicpc.net/problem/9663
#include <iostream>

using namespace std;

int N, cnt = 0;
bool col[16];
bool rd[31];
bool ld[31];

void dfs(int row){
	if(row > N){
		cnt++;
		return;
	}

	for(int i = 1 ; i <= N ; i++){
		if( !col[i] && !rd[(row-i) + (N-1)] && !ld[row+i]){
			col[i] = rd[(row-i) + (N-1)] = ld[row+i] = true;
			dfs(row+1);
			col[i] = rd[(row-i) + (N-1)] = ld[row+i] = false;
		}
	}

}

int main(void){
	cin >> N;
	
	dfs(1);

	cout << cnt << endl;

	return 0;
}