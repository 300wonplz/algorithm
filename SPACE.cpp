//
//  SPACE.cpp
//  SDS3
//
//  Created by JHM on 2018. 7. 22..
//  Copyright © 2018년 JHM. All rights reserved.
//

#include <iostream>
using namespace std;

int round;


int main(void){
    int result[25];
    
    int out[10];
    int N, M, r1, c1, r2, c2;
 
//    1 2 3
//    4 5 6
//    7 8 9
    int rMap[10][1];
    int cMap[10][1];
    
    cin >> round;

    for(int i = 0 ; i < round ; i++){
        cin >> N >> M >> r1 >> c1 >> r2 >> c2;
        
        rMap[1][0] = r2 - N;
        cMap[1][0] = c2 - M;
        
        rMap[2][0] = r2;
        cMap[2][0] = c2 - M;
        
        rMap[3][0] = r2 + N;
        cMap[3][0] = c2 - M;
        
        rMap[4][0] = r2 - N;
        cMap[4][0] = c2;
        
        rMap[5][0] = r2;
        cMap[5][0] = c2;
        
        rMap[6][0] = r2 + N;
        cMap[6][0] = c2;
        
        rMap[7][0] = r2 - N;
        cMap[7][0] = c2 + M;
        
        rMap[8][0] = r2;
        cMap[8][0] = c2 + M;
        
        rMap[9][0] = r2 + N;
        cMap[9][0] = c2 + M;
        
        for(int j = 1 ; j <= 9 ; j++){
            out[j] = abs(rMap[j][0] - r1) + abs(cMap[j][0] - c1);
        }
        
        int min = 99999999;
        
        for(int k = 1 ; k <= 9 ; k ++){
            if(out[k] <= min){
                min = out[k];
            }
        }
        
        result[i] = min;
    }
    
    for(int i = 0 ; i < round ; i++){
        cout << "#" << i+1 << " " << result[i] << endl;
    }
    
    return 0;
}
