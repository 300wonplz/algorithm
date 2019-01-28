// 문제 출처
// https://www.acmicpc.net/problem/2606
#include <iostream>
#include <queue>

using namespace std;

bool map[101][101] = {false};
bool visit[101] = {false};
int result = 0;
queue<int> q;

void bfs(int start, int count){
	q.push(start);
	visit[start] = true;

	while(!q.empty()){
		int position = q.front();
		q.pop();

		for(int i = 1 ; i <= count ; i++){
			if( map[position][i] && !visit[i]){
				q.push(i);
				visit[i] = true;
				result+=1;
			}
		}
	}

}

int main(void){
	int count;
	cin >> count;

	int pair;
	cin >> pair;

	int x, y;
	for(int i = 0 ; i < pair ; i ++){
		cin >> x >> y;
		map[x][y] = true;
		map[y][x] = true;
	}

	bfs(1, count);

	cout << result << endl;

	return 0;
}