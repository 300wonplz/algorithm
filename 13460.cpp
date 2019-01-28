#include <iostream>
#include <queue>

using namespace std;

int N, M;
int count = 0;
char tmp_map[11][11];
int map[11][11];
int visit[11][11];
int dir[4][2] = {{1,0} , {0,1}, {-1, 0}, {0, -1}};

queue< pair <int ,pair<int, int> > > q;

void bfs(){
	while(!q.empty()){
		int direction = q.front().first;
		int a = q.front().second.first;
		int b = q.front().second.second;
		q.pop();

		for(int i = 0 ; i < 4 ; i++){
			int next_a = a + dir[i][0];
			int next_b = b + dir[i][1];

			if(next_a >=1 && next_a <= N && next_b >=1 && next_b <= M && map[next_a][next_b] != -1){
				if(map[next_a][next_b] > 0  || map[next_a][next_b] == 2){
					if(map[i][j] == -2){
						q.push(make_pair(i, make_pair(a, b)));
					}
					else{
						
					}
				}
			}

		}
	}
}

int main(void){
	cin >> N >> M;

	for(int i = 1 ; i <= N ; i++){
		for(int j =1 ; j <= M ; j++){
			cin >> tmp_map[i][j];
		}
	}

	for(int i = 1 ; i <= N ; i++){
		for(int j =1 ; j <= M ; j++){
			if(tmp_map[i][j] == '#'){
				map[i][j] = -1;
			}
			else if(tmp_map[i][j] == '.'){
				map[i][j] = 0;
			}
			else if(tmp_map[i][j] == 'O'){
				map[i][j] = -3;
			}
			else if(tmp_map[i][j] == 'R'){
				map[i][j] = 1;
			}
			else if(tmp_map[i][j] == 'B'){
				map[i][j] = -2;
			}
		}
	}

	for(int i = 1 ; i <= N ; i++){
		for(int j =1 ; j <= M ; j++){
			if(map[i][j] == -3 || map[i][j] == -2){
				for(int k = 0 ; k < 4 ; k++){
					int next_i = i + dir[4][0];
					int next_j = j + dir[4][1];

					if(next_i >= 1 && next_i <= N && next_j >= 1 && next_j <= M && map[next_i][next_j] != -1){
						if(map[i][j] == 1){
							visit[i][j] = 1;
						}
						q.push(make_pair(k , make_pair(i, j)));
					}
				}
			}
		}
	}

	return 0;
}