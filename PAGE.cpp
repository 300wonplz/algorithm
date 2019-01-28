//
//  PAGE.cpp
//  SDS
//
//  Created by JHM on 2018. 7. 22..
//  Copyright © 2018년 JHM. All rights reserved.
//

#include <iostream>
using namespace std;

int result[50] = {0};
int k_page[1000];

int main(void){
    int round;
    int n, s, j, k;
    
    cin >> round;
    
    
    for(int i = 0 ; i < round ; i++){
        cin >> n >> s >> j >> k;
        
        for(int j = 0 ; j < k ; j++){
            cin >> k_page[j];
        }
        
        while(s <= n){
            for(int l = 0 ; l < k ; l++){
                if(s == k_page[l]){
                    result[i]++;
                    break;
                }
            }
            s += j+1;
        }
    }
    
    
    for(int i = 0 ; i < round; i++){
        cout << "#" << i+1 << " " << result[i] << endl;
    }
    
    return 0;
}
