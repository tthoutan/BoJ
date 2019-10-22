//
// Created by tthoutan on 18/10/2019.
//

#include <iostream>
#include <vector>

using namespace std;

int N,M,H;

//세로선 1~N-1칸까지, 가로선 H칸 까지
bool ladder_map[12][31];
vector<pair<int,int>> possible_vec;



void print_ladder(){
    for(int i=1; i<=H; i++){
        for(int j=1; j<=N; j++){
            printf("%d ", ladder_map[j][i]);
        }
        printf("\n");
    }
}

bool go_check(){

    bool res = true;

    for(int i=1; i<=N; i++){
        int temp_N = i;
        int temp_H=1;
        while(temp_H<=H) {
            if (ladder_map[temp_N][temp_H]) {
                temp_N++;
                temp_H++;
            }else if(ladder_map[temp_N-1][temp_H]){
                temp_N--;
                temp_H++;
            }else{
                temp_H++;
            }
        }
        if(temp_N!=i){
            res = false;
            break;
        }
    }
    return res;

}

int select_ladder(int cur_cnt, int max_cnt, int cur_idx){

    int res = 0;
    if(cur_cnt==max_cnt){
        if(go_check()) {
            return max_cnt;
        }
        else return -1;
    }

    for(int i=cur_idx; i<=(int)possible_vec.size(); i++){

        int temp_n = possible_vec[i].first;
        int temp_h = possible_vec[i].second;

        if(ladder_map[temp_n][temp_h] || ladder_map[temp_n-1][temp_h] || ladder_map[temp_n+1][temp_h]) continue;
        ladder_map[temp_n][temp_h] = true;
        res = select_ladder(cur_cnt+1, max_cnt,i+1);
        ladder_map[temp_n][temp_h] = false;
        if(res>=1){
            break;
        }
    }

    if(res==0){
        return -1;
    }else{
        return res;
    }
}

int main(){

    scanf("%d %d %d", &N, &M, &H);

    for(int i=1; i<=M; i++){
        int j,k;
        scanf("%d %d", &j, &k);
        ladder_map[k][j] = true;
    }

    for(int i=1; i<=H; i++){
        for(int j=1; j<=N-1; j++){
            if(!ladder_map[j][i]){
                possible_vec.emplace_back(j,i);
            }
        }
    }

    int res = 0;

    for(int i=0; i<=3; i++){
        res = select_ladder(0, i, 0);
        if(res>=0){
            break;
        }
    }

    printf("%d", res);


    return 0;
}