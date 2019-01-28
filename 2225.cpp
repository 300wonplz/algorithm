//
//  2225.cpp
//  BOJ
//
//  Created by JHM on 2018. 8. 30..
//  Copyright © 2018년 JHM. All rights reserved.
//

#include <iostream>

using namespace std;

int dp[201][201] = {0};

int main(void){
    int N, K;
    
    cin >> N >> K;
    
    for(int i = 0 ; i <= N ; i++){
        dp[1][i] = 1;
    }
    
    for(int i = 2; i <= K ; i++){
        for(int j = 0 ; j <= N ; j++){
            for(int l = 0 ; l <= j ; l++){
                dp[i][j] = ( dp[i][j] + dp[i-1][j-l] ) % 1000000000;
            }
        }
    }
    
    cout << dp[K][N] << endl;
    
    return 0;
}
