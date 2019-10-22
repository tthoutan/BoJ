//
// Created by tthoutan on 15/10/2019.
//

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int N, L, R;

int capa_map[51][51];
bool visited[51][51];

queue<pair<int,int>> bfs_que;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool do_bfs(){

    bool res = false;
    int count = 0;
    int total_cap = 0;

    vector<pair<int,int>> move_vec;

    while(!bfs_que.empty()){
        auto pos = bfs_que.front();
        bfs_que.pop();
        int r = pos.first;
        int c = pos.second;
        count++;
        total_cap+=capa_map[r][c];
        move_vec.emplace_back(r,c);

        for(int i=0; i<4; i++){
            int temp_r = r+dr[i];
            int temp_c = c+dc[i];

            if(temp_r<1||temp_r>N||temp_c<1||temp_c>N||visited[temp_r][temp_c]) continue;

            int gap = abs(capa_map[r][c]-capa_map[temp_r][temp_c]);

            if(gap >= L && gap <=R) {
                visited[temp_r][temp_c] = true;
                bfs_que.push(make_pair(temp_r, temp_c));
            }
        }

    }

    int move_cap = total_cap/count;

    if(count>1) {
        for (auto p : move_vec) {
            capa_map[p.first][p.second] = move_cap;
        }
        res = true;
    }

    return res;

}

int do_move(){

    bool res = false;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(!visited[i][j]){
                bfs_que.push(make_pair(i,j));
                visited[i][j]=true;
                bool temp = do_bfs();
                if(temp){
                    res = true;
                }
            }
        }
    }

    if(res){
        return 1;
    }else{
        return 0;
    }
}


int main(){

    scanf("%d %d %d", &N, &L, &R);

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            scanf("%d", &capa_map[i][j]);
        }
    }

    int res=0;

    int temp=1;

    while(temp){
        temp = do_move();
        res+=temp;
        memset(visited, 0, sizeof(visited));
    }


    printf("%d", res);


    return 0;
}