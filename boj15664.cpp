//
// Created by tthoutan on 10/10/2019.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> input_arr;
int res_arr[10];
int N,M;
set<vector<int>> res_set;
void go(int cur_idx, int cur_cnt){

    if(cur_cnt == M){
        vector<int> temp_vec;
        for (int i = 1; i <= M; i++) {
            temp_vec.push_back(res_arr[i]);
        }
        res_set.insert(temp_vec);
        return;
    }else if(cur_idx>=N){
        return;
    }
    for(int i=cur_idx; i<N; i++){
        res_arr[cur_cnt+1]=input_arr[i];
        go(i+1, cur_cnt+1);
    }

}

int main(){


    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        int temp;
        scanf("%d", &temp);
        input_arr.push_back(temp);
    }

    sort(input_arr.begin(), input_arr.end());

    go(0,0);

    for(auto &it : res_set){
        for(auto it_v : it){
            printf("%d ", it_v);
        }
        printf("\n");
    }

    return 0;
}