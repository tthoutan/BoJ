//
// Created by tthoutan on 17/10/2019.
//

#include <iostream>
#include <vector>


using namespace std;


int N, M;

int city_map[51][51];
bool select_chic[14];
int home_idx = 0;
int chic_idx = 0;

struct pos{
    int x;
    int y;
};

pos home_pos[101];
pos chicken_pos[14];

int distance_calc(){

    int res = 0;

    for(int i=0; i<home_idx; i++){
        int r = home_pos[i].x;
        int c = home_pos[i].y;
        int chic_dist = 10000;
        for(int j=0; j<chic_idx; j++){
            if(select_chic[j]) {
                int temp_r = chicken_pos[j].x;
                int temp_c = chicken_pos[j].y;
                int dis_r = temp_r - r;
                int dis_c = temp_c - c;

                dis_r = dis_r>0 ? dis_r : -dis_r;
                dis_c = dis_c>0 ? dis_c : -dis_c;

                chic_dist = min(dis_r+dis_c, chic_dist);
            }
        }
        res+=chic_dist;
    }

    return res;
}

int select_chicken(int cur_cnt, int cur_idx, int max_idx){

    int res = 987654321;

    if(cur_cnt==M){
        res = distance_calc();
        return res;
    }else if(cur_idx>=max_idx){
        return -1;
    }

    for(int i=cur_idx; i<max_idx; i++){
        select_chic[i]=true;
        int temp = select_chicken(cur_cnt+1, i+1, max_idx);
        select_chic[i]=false;

        if(temp!=-1){
            res = min(res,temp);
        }
    }

    return res;

}

int main(){

    scanf("%d %d", &N, &M);

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            scanf("%d", &city_map[i][j]);
            if(city_map[i][j]==1){
                home_pos[home_idx].x=i;
                home_pos[home_idx].y=j;
                home_idx++;
            }else if(city_map[i][j]==2){
                chicken_pos[chic_idx].x=i;
                chicken_pos[chic_idx].y=j;
                chic_idx++;
            }
        }
    }

    int res = select_chicken(0,0,chic_idx);

    printf("%d", res);

    return 0;
}