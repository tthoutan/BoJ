//
// Created by tthoutan on 09/10/2019.
//

#include <iostream>
#include <vector>

using namespace std;

int S[14];

void dfs(int cur_cnt, int cur_idx, int max_len, vector<int> cur_arr, vector<vector<int>> &vec_res){
    if(cur_cnt == 6){
        vec_res.push_back(cur_arr);
        return;
    }else if(cur_idx>max_len){
        return;
    }

    for(int i=cur_idx+1; i<=max_len; i++){
        vector<int> temp_vec = cur_arr;
        temp_vec.push_back(S[i]);
        dfs(cur_cnt+1, i, max_len, temp_vec, vec_res);
    }

}

int main(){

    int k;

    scanf("%d", &k);

    while(k!=0){
        vector<vector<int>> temp_vec;
        for(int i=0; i<k; i++){
            scanf("%d", &S[i+1]);
        }
        for(int i=1; i<=k-5; i++){
            vector<int> cur_vec;
            cur_vec.push_back(S[i]);
            dfs(1, i, k, cur_vec, temp_vec);
        }

        for(auto it=temp_vec.begin(); it!=temp_vec.end(); it++){
            for(auto x: *it){
                printf("%d ", x);
            }
            printf("\n");
        }

        printf("\n");
        scanf("%d", &k);
    }

    return 0;
}