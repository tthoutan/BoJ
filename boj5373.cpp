//
// Created by tthoutan on 18/10/2019.
//

#include <iostream>
#include <string>
using namespace std;


int T, N;


// 1=white(윗) 2=green(왼) 3=blue(오) 4=red(앞) 5=orange(뒤) 6=yellow(밑)

int qube_arr[55];

char init[7]="wgbroy";


int rotate_map[7][12] = {
        {0,0,0,0,0,0,0,0,0,0,0,0},
        //U
        {45,44,43,12,15,18,28,29,30,25,22,19},
        //L
        {43,40,37,48,51,54,34,31,28,7,4,1},
        //R
        {39,42,45,3,6,9,30,33,36,52,49,46},
        //F
        {9,8,7,18,17,16,54,53,52,27,26,25},
        //B
        {46,47,48,10,11,12,1,2,3,19,20,21},
        //D
        {37,38,39,21,24,27,36,35,34,16,13,10}
};

void self_rotate(int i){
    int qube_temp[9];

    for(int j=0; j<=8; j++){
        qube_temp[j] = qube_arr[(i-1)*9+j+1];
    }

    int temp = 0;
    for(int j=3; j>0; j--){
        for(int k=0; k<3; k++){
            qube_arr[(i-1)*9+j+3*k] = qube_temp[temp];
            temp++;
        }
    }
}

void rotate_around(int i){

    int que[12];

    for(int k=0; k<12; k++){
        que[k] = qube_arr[rotate_map[i][k]];
    }

    for(int k=0; k<12; k++){
        qube_arr[rotate_map[i][k]] = que[(k+3)%12];
    }


}



int main(){

    scanf("%d", &T);

    // 큐브 초기화


    // 테스트케이스 시작
    while(T--){

        for(int i=0; i<6; i++){
            for(int j=1; j<=9; j++){
                qube_arr[i*9+j]=init[i];
            }
        }

        scanf("%d", &N);

        while(N--){
            string temp_s;
            cin >> temp_s;
            switch(temp_s.at(0)){
                case 'U':
                    if(temp_s.at(1)=='+'){
                        rotate_around(1);
                        self_rotate(1);
                    }else{
                        for(int k=1; k<=3; k++){
                            rotate_around(1);
                            self_rotate(1);
                        }
                    }
                    break;
                case 'L':
                    if(temp_s.at(1)=='+'){
                        rotate_around(2);
                        self_rotate(2);
                    }else{
                        for(int k=1; k<=3; k++){
                            rotate_around(2);
                            self_rotate(2);
                        }
                    }
                    break;
                case 'R':
                    if(temp_s.at(1)=='+'){
                        rotate_around(3);
                        self_rotate(3);
                    }else{
                        for(int k=1; k<=3; k++){
                            rotate_around(3);
                            self_rotate(3);
                        }
                    }
                    break;
                case 'B':
                    if(temp_s.at(1)=='+'){
                        rotate_around(5);
                        self_rotate(5);
                    }else{
                        for(int k=1; k<=3; k++){
                            rotate_around(5);
                            self_rotate(5);
                        }
                    }
                    break;
                case 'F':
                    if(temp_s.at(1)=='+'){
                        rotate_around(4);
                        self_rotate(4);
                    }else{
                        for(int k=1; k<=3; k++){
                            rotate_around(4);
                            self_rotate(4);
                        }
                    }
                    break;
                case 'D':
                    if(temp_s.at(1)=='+'){
                        rotate_around(6);
                        self_rotate(6);
                    }else{
                        for(int k=1; k<=3; k++){
                            rotate_around(6);
                            self_rotate(6);
                        }
                    }
                    break;
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 1; j <= 3; j++) {
                printf("%c", qube_arr[i * 3 + j]);
            }
            printf("\n");
        }

    }
}