//
// Created by tthoutan on 18/10/2019.
//

#include <iostream>
#include <queue>

using namespace std;


int dr[4] = {-1, 0, 0, 1};
int dc[4] = {0, -1, 1, 0};

struct fish{
    int pos_r;
    int pos_c;
    int len;
    bool operator <(const fish &oth_fish) const{
        if(len==oth_fish.len){
            if(pos_r==oth_fish.pos_r){
                return pos_c > oth_fish.pos_c;
            }
            return pos_r > oth_fish.pos_r;
        }
        return len > oth_fish.len;
    }
};

struct shark{
    int pos_r;
    int pos_c;
    int size;
    int eat;
};

bool visited[21][21];
int fish_map[21][21];
int N;
int res = 0;
priority_queue<fish> pq;
queue<pair<int,int>> bfs_q;

shark baby_shark = {};

void shark_eat(){
    baby_shark.eat++;
    if(baby_shark.eat==baby_shark.size){
        baby_shark.size++;
        baby_shark.eat=0;
    }
}

bool check_map(){
    bool res = false;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(fish_map[i][j]<baby_shark.size){
                return true;
            }
        }
    }
    return res;
}

bool go_shark(int len) {

//
//    int shark_r = baby_shark.pos_r;
//    int shark_c = baby_shark.pos_c;
//    visited[shark_r][shark_c] = true;

    bool res_b=false;

    if (pq.empty()) {
        if (bfs_q.empty()){
            return false;
        }
        int temp_size = bfs_q.size();
        while (temp_size--) {
            int cur_r = bfs_q.front().first;
            int cur_c = bfs_q.front().second;
            bfs_q.pop();

            for (int i = 0; i < 4; i++) {
                int temp_r = cur_r + dr[i];
                int temp_c = cur_c + dc[i];

                if (visited[temp_r][temp_c] || temp_r < 1 || temp_r > N || temp_c < 1 || temp_c > N) continue;

                visited[temp_r][temp_c] = true;

                if (fish_map[temp_r][temp_c] == baby_shark.size || fish_map[temp_r][temp_c] == 0) {
                    bfs_q.push(make_pair(temp_r, temp_c));
                } else if (fish_map[temp_r][temp_c] < baby_shark.size) {
                    fish temp_f = {};
                    temp_f.pos_r = temp_r;
                    temp_f.pos_c = temp_c;
                    temp_f.len = len;
                    pq.push(temp_f);
                }
            }
        }
        res_b = go_shark(len+1);
        return res_b;
    }else{
        auto x = pq.top();
        shark_eat();
        baby_shark.pos_r = x.pos_r;
        baby_shark.pos_c = x.pos_c;
        res+=x.len;
        fish_map[x.pos_r][x.pos_c]=0;
        memset(visited, 0, sizeof(visited));
        pq = priority_queue<fish>();
        bfs_q = queue<pair<int,int>>();

        return true;
    }
}


int main(){

    scanf("%d", &N);

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            scanf("%d", &fish_map[i][j]);
            if(fish_map[i][j]==9){
                baby_shark.pos_r=i;
                baby_shark.pos_c=j;
                baby_shark.size=2;
                baby_shark.eat=0;
                visited[i][j]=true;
                fish_map[i][j]=0;
            }
        }
    }

    bfs_q.push(make_pair(baby_shark.pos_r, baby_shark.pos_c));

    while(go_shark(1)){
        bfs_q.push(make_pair(baby_shark.pos_r, baby_shark.pos_c));
        if(!check_map()) break;
    }

    printf("%d", res);



    return 0;
}