//
// Created by tthoutan on 13/10/2019.
//

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int R,C,M;

// 1-s속력,2-d방향,3-z상어크기
int shark[101][101][5];
int shark_temp[101][101][5];

// 디버깅용
//void shark_print(){
//    for(int i=1; i<=R; i++){
//        for(int j=1; j<=C; j++){
//            if(shark[j][i][2]!=0){
//                printf("%d", shark[j][i][3]);
//            }else{
//                printf("-");
//            }
//        }
//        printf("\n");
//    }
//    printf("************\n");
//
//}

void shark_swap(int from_c, int from_r, int to_c, int to_r){
    if(shark_temp[to_c][to_r][3]<shark[from_c][from_r][3]){
        for (int i = 1; i <= 3; i++) {
            shark_temp[to_c][to_r][i] = shark[from_c][from_r][i];
        }
    }else{
        return;
    }
}

void go_shark(){
    for(int i=1; i<=C; i++){
        for(int j=1; j<=R; j++){
            if(shark[i][j][2]){
                int temp_s = shark[i][j][1];
                int temp_d = shark[i][j][2];
                int temp_r = j;
                int temp_c = i;
                while(temp_s){
                    if(temp_d==1){
                        if(temp_r-temp_s>=1){
                            temp_r-=temp_s;
                            temp_s=0;
                        }else{
                            temp_s=abs(temp_r-temp_s)+1;
                            temp_d=2;
                            temp_r=1;
                        }
                    }else if(temp_d==2){
                        if(temp_r+temp_s<=R){
                            temp_r+=temp_s;
                            temp_s=0;
                        }else{
                            temp_s=temp_r+temp_s-R;
                            temp_d=1;
                            temp_r=R;
                        }
                    }else if(temp_d==3){
                        if(temp_c+temp_s<=C){
                            temp_c+=temp_s;
                            temp_s=0;
                        }else{
                            temp_s=temp_c+temp_s-C;
                            temp_d=4;
                            temp_c=C;
                        }
                    }else{
                        if(temp_c-temp_s>=1){
                            temp_c-=temp_s;
                            temp_s=0;
                        }else{
                            temp_s=abs(temp_c-temp_s)+1;
                            temp_d=3;
                            temp_c=1;
                        }
                    }
                }
                shark[i][j][2] = temp_d;
                shark_swap(i,j,temp_c,temp_r);
            }
        }
    }
    memcpy(shark, shark_temp, sizeof(shark_temp));
    memset(shark_temp, 0, sizeof(shark_temp));

}

int main(){

    scanf("%d %d %d", &R, &C, &M);

    for(int i=1; i<=M; i++){
        int temp_r, temp_c;
        scanf("%d %d", &temp_r, &temp_c);
        for(int j=1; j<=3; j++){
            scanf("%d", &shark[temp_c][temp_r][j]);
        }
    }

//    shark_print();

    int res = 0;

    for(int i=1; i<=C; i++){
        for(int j=1; j<=R; j++){
            if(shark[i][j][2]){
                res+=shark[i][j][3];
                for(int k=1; k<=3; k++){
                    shark[i][j][k]=0;
                }
                break;
            }
        }
//        shark_print();
        go_shark();
//        shark_print();
    }

    printf("%d", res);

    return 0;
}