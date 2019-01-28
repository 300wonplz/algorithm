//
//  SURVIVOR.cpp
//  SDS
//
//  Created by JHM on 2018. 7. 22..
//  Copyright © 2018년 JHM. All rights reserved.
//

#include <iostream>
using namespace std;

int map[10][10];
int result[20];

bool check_boundary(int a, int b, int map[10][10], int round){
    if(a==0 && b==0){
        if(map[a][b] != 0 && map[a+1][b] != 0 && map[a][b+1] != 0 && map[a+1][b+1] != 0){
            return true;
        }else{
            return false;
        }
    }else if(a==round-1 && b==0){
        if(map[a][b] != 0 && map[a-1][b] != 0 && map[a][b+1] != 0 && map[a-1][b+1] != 0){
            return true;
        }else{
            return false;
        }
    }else if(a==0 && b == round-1){
        if(map[a][b] != 0 && map[a+1][b] != 0 && map[a][b-1] != 0 && map[a+1][b-1] != 0){
            return true;
        }else{
            return false;
        }
    }else if(a==round-1 && b==round-1){
        if(map[a][b] != 0 && map[a-1][b] != 0 && map[a][b-1] != 0 && map[a-1][b-1] != 0){
            return true;
        }else{
            return false;
        }
    }else if(a==0){
        if(map[a][b] != 0 && map[a][b+1] != 0 && map[a][b-1] != 0 && map[a+1][b-1] != 0 && map[a+1][b] != 0 && map[a+1][b+1] != 0){
            return true;
        }else{
            return false;
        }
    }else if(a==round-1){
        if(map[a][b] != 0 && map[a][b+1] != 0 && map[a][b-1] != 0 && map[a-1][b-1] != 0 && map[a-1][b] != 0 && map[a-1][b+1] != 0){
            return true;
        }else{
            return false;
        }
    }else if(b==0){
        if(map[a][b] != 0 && map[a+1][b] != 0 && map[a-1][b] != 0 && map[a][b+1] != 0 && map[a-1][b+1] != 0 && map[a+1][b+1] != 0){
            return true;
        }else{
            return false;
        }
    }else{
        if(map[a][b] != 0 && map[a+1][b] != 0 && map[a-1][b] != 0 && map[a][b-1] != 0 && map[a-1][b-1] != 0 && map[a+1][b-1] != 0){
            return true;
        }else{
            return false;
        }
    }
}

bool check_inside(int a, int b, int map[10][10], int round){
    if(map[a-1][b-1] != 0 && map[a][b-1] != 0 && map[a+1][b-1] != 0 && map[a-1][b] != 0 && map[a][b] != 0 && map[a+1][b] != 0 && map[a-1][b+1] != 0 && map[a][b+1] != 0 && map[a+1][b+1] != 0){
        return true;
    }else{
        return false;
    }
}

int main(void){
    
    int round;
    int size;
    cin >> round;
    
    for(int i = 0 ; i < round ; i++){
        cin >> size;
        
        for(int j = 0 ; j < size ; j++){
            for(int k = 0 ; k < size ; k++){
                cin >> map[j][k];
            }
        }
        
        for(int a = 0 ; a < size ; a++){
            for(int b = 0 ; b < size ; b++){
                if(a == 0 || a == round-1 || b == 0 || b == round-1){
                    if(check_boundary(a, b, map, round)){
                        result[i] += 1;
                    }
                }else{
                    if(check_inside(a, b, map, round)){
                        result[i] += 1;
                    }
                }
            }
        }
        
        cout << "#" << i+1 << " " << result[i] << endl;
    }
    
    return 0;
}
