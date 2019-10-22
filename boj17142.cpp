//
// Created by tthoutan on 14/10/2019.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

//연구소크기 N, 바이러스 개수 M
int N,M;

vector<pair<int,int>> virus_pos;
queue<pair<int,int>> virus_que;

int lab[55][55];
int temp_lab[55][55];
bool visit[55][55];
bool virus_select[11];
int dr[4] = {-1,0,1,0}; // 행 방향 위,오,아래,왼 [r][c]
int dc[4] = {0,1,0,-1}; // 열 방향 위,오,아래,왼 [r][c]

//디버깅용
//void print_lab() {
//    for (int i = 1; i <= N; i++) {
//        for (int j = 1; j <= N; j++) {
//            printf("%d ", temp_lab[i][j]);
//        }
//        printf("\n");
//    }
//}

int time_calc(){
    int res = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            res = max(temp_lab[i][j], res);
        }
    }
    return res;
}

bool go_virus(){
    memcpy(temp_lab, lab, sizeof(lab));
    int que_size = virus_que.size();
    int ans = 1;
    while(!virus_que.empty()) {

        auto pos = virus_que.front();
        virus_que.pop();
        que_size--;

        int r = pos.first;
        int c = pos.second;

        for (int i = 0; i <= 3; i++) {
            int temp_r = r + dr[i];
            int temp_c = c + dc[i];
            if (temp_r >= 1 && temp_r <= N && temp_c >= 1 && temp_c <= N && !visit[temp_r][temp_c]) {
                if (temp_lab[temp_r][temp_c] != -1 && temp_lab[temp_r][temp_c] != -2) {

                    temp_lab[temp_r][temp_c] = ans;
                    visit[temp_r][temp_c] = true;
                    virus_que.push(make_pair(temp_r, temp_c));

                }else if(temp_lab[temp_r][temp_c] == -1){

                    virus_que.push(make_pair(temp_r, temp_c));
                    visit[temp_r][temp_c] = true;

                }
            }
        }
        if(que_size==0){
            que_size=virus_que.size();
            ans++;
        }

    }

    memset(visit, false, sizeof(visit));

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(temp_lab[i][j]==0){
                return false;
            }
        }
    }

    return true;
}

int select_virus(int cur_idx, int cur_cnt){

    int res = 987654321;
    bool res_bool = false;

    if(cur_cnt == M){
        for(int i=0; i<10; i++){
            if(virus_select[i]){
                int temp_r = virus_pos[i].first;
                int temp_c = virus_pos[i].second;
                virus_que.push(make_pair(temp_r,temp_c));
                visit[temp_r][temp_c]=true;
            }
        }
        bool temp_bool = go_virus();
        if(temp_bool) {
            int time_tamp = time_calc();
            return time_tamp;
        }else{
            return -3;
        }
    }else if(cur_idx>=(int)virus_pos.size()){
        return -1;
    }

    for(int i=cur_idx; i<(int)virus_pos.size(); i++){
        virus_select[i] = true;
        int temp_ch = select_virus(i+1, cur_cnt+1);
        virus_select[i] = false;
        if(temp_ch >= 0){
            res_bool = true;
            res = min(temp_ch, res);
        }

    }

    if(res_bool){
        return res;
    }else{
        return -1;
    }

}

int main(){

    scanf("%d %d", &N, &M);

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            scanf("%d", &lab[i][j]);
            if(lab[i][j]==2){
                virus_pos.emplace_back(i,j);
                lab[i][j]=-1;
            }else if(lab[i][j]==1){
                lab[i][j]=-2;
            }
        }
    }

    int res = select_virus(0,0);

    printf("%d", res);


    return 0;
}