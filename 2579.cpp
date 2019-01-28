//
//  2579.cpp
//  BOJ
//
//  Created by JHM on 2018. 8. 30..
//  Copyright © 2018년 JHM. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int stair[301] = {0};
int dp[301] = {0};

int main(void){
    int n;
    cin >> n;

    for(int i = 1 ; i <= n; i++){
        cin >> stair[i];
    }
    
    dp[1] = stair[1];
    dp[2] = stair[1] + stair[2];
    
    for(int i = 3 ; i <= n ; i++ ){
        dp[i] = max( stair[i]+stair[i-1]+dp[i-3], stair[i]+dp[i-2]);
    }
    
    cout << dp[n] << endl;
    
    return 0;
}
