//
// Created by tthoutan on 13/10/2019.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


// r=행 c=열 k=목표
int r,c,k;
int cur_row = 3;
int cur_col = 3;

int board[105][105];

//디버깅용
//void print_board(){
//
//    for(int i=1; i<=10; i++){
//        for(int j=1; j<=10; j++){
//            printf("%d ", board[i][j]);
//        }
//        printf("\n");
//    }
//}

bool cmp(const pair<int, int> &a, const pair<int, int> &b){

    if(a.first!=b.first){
        return a.first < b.first;
    }else{
        return a.second < b.second;
    }

}

void go_R(){
    for(int i=1; i<=cur_row; i++){

        vector<int> temp_v;

        int cnt_tab[105]={0,};

        for(int s=1; s<=cur_col; s++){
            cnt_tab[board[i][s]]++;
        }

        vector<pair<int, int>> temp_pair;

        set<int> temp_set;

        for(int m=1; m<=cur_col; m++){
            if(board[i][m]!=0) {
                temp_set.insert(board[i][m]);
            }
        }

        for(int x : temp_set) {
            temp_pair.emplace_back(cnt_tab[x], x);
        }

        sort(temp_pair.begin(), temp_pair.end(), cmp);

        for(auto it : temp_pair) {
            temp_v.push_back(it.second);
            temp_v.push_back(it.first);
        }

        int j = (int)temp_v.size();

        if(j>100){
            j=100;
        }

        for(int t=1; t<=j; t++){
            board[i][t] = temp_v[t-1];
        }

        if(j<cur_col){
            for(int t=j+1; t<=cur_col; t++){
                board[i][t] = 0;
            }
        }else{
            cur_col = j;
        }

    }
}

void go_C(){
    for(int i=1; i<=cur_col; i++){

        vector<int> temp_v;

        int cnt_tab[105]={0,};

        for(int s=1; s<=cur_row; s++){
            cnt_tab[board[s][i]]++;
        }


        vector<pair<int, int>> temp_pair;

        set<int> temp_set;

        for(int m=1; m<=cur_row; m++){
            if(board[m][i]!=0) {
                temp_set.insert(board[m][i]);
            }
        }

        for(int x : temp_set) {
            temp_pair.emplace_back(cnt_tab[x], x);
        }

        sort(temp_pair.begin(), temp_pair.end(), cmp);

        for(auto it : temp_pair){
            temp_v.push_back(it.second);
            temp_v.push_back(it.first);
        }

        int j = (int)temp_v.size();

        if(j>100){
            j=100;
        }

        for(int t=1; t<=j; t++){
            board[t][i] = temp_v[t-1];
        }

        if(j<cur_row){
            for(int t=j+1; t<=cur_row; t++){
                board[t][i] = 0;
            }
        }else{
            cur_row = j;
        }
    }
}

int main(){

    scanf("%d %d %d", &r, &c, &k);

    for(int i=1; i<=3; i++){
        for(int j=1; j<=3; j++){
            scanf("%d", &board[i][j]);
        }
    }

    int time = 0;

    while(board[r][c]!=k){
        if(time>100){
            printf("%d", -1);
            return 0;
        }
        time++;
        if(cur_row>=cur_col){
            go_R();
        }else{
            go_C();
        }
    }


    printf("%d", time);

    return 0;
}