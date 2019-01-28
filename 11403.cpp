#include <iostream>

using namespace std;

int N;
int map[101][101] = {0,};
int ans[101][101] = {0,};
int visit[101][101] = {0,};

void dfs(int top, int a, int b){
	ans[top][b] = 1;
	visit[top][b] = 1;

	for(int i = 1 ; i <= N ; i++){
		if(map[b][i] == 1 && !visit[top][i]){
			dfs(top, b , i);
		}
	}
}

int main(void){
	cin >> N;

	for(int i = 1 ; i <= N ; i++){
		for(int j = 1 ; j <= N ; j++){
			cin >> map[i][j];
		}
	}

	for(int i = 1 ; i <= N ; i++){
		for(int j = 1 ; j <= N ; j++){
			if(map[i][j] == 1)
				dfs(i, i, j);
		}
	}

	for(int i = 1 ; i <= N ; i++){
		for(int j = 1 ; j <= N ; j++){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}