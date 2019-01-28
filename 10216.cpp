// 문제 출처
// https://www.acmicpc.net/problem/10216

#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

// int map[5001][5001] = {0,};
// int visit[5001][5001] = {0,};
int T, N, x, y, R, camp_counter = 0;

struct camp{
	int x;
	int y;
	int R;
	int visit;
};

vector<camp> v;
queue<camp> q;



void bfs(int idx){
	v[idx].visit = 1;
	q.push((camp){v[idx].x, v[idx].y, v[idx].R, v[idx].visit});

	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		int R = q.front().R;
		int visit = q.front().visit;
		q.pop();


		for(int i = idx ; i < v.size() ; i++){
			if(v[i].visit == 0){
				int distance = (x-v[i].x)*(x-v[i].x) + (y-v[i].y)*(y-v[i].y);
				if( distance <= (R + v[i].R) * (R + v[i].R)){
					v[i].visit = 1;
					q.push((camp){v[i].x, v[i].y, v[i].R, v[i].visit});
				}
			}
		}
	}
}



int main(void){

	cin >> T;
	
	for(int i = 1 ; i <= T ; i++){
		cin >> N;
		
		for(int j = 1 ; j <= N ; j++){
			cin >> x >> y >> R;
			v.push_back((camp){x, y, R, 0});
		}

		for(int k = 0 ; k < v.size() ; k++){
				if(v[k].visit == 0){
					camp_counter += 1;
					bfs(k);
				}
		}

		cout << camp_counter << endl;
		camp_counter = 0;
		v.clear();
	}

	

	return 0;
}