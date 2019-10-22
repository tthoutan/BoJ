//
// Created by tthoutan on 10/10/2019.
//

#include <iostream>
#include <algorithm>
using namespace std;


int A[13];
int opera[5]; // +,-,*,/

int dfs_max(int max_cnt, int cur_val, int cur_opt[4], int cur_cnt){

    int fin_res=0;
    bool init = false;

    if(cur_cnt == max_cnt){
        return cur_val;
    }

    for(int i=0; i<4; i++){
        switch(i){
            case 0:
                cur_opt[0]++;
                if(cur_opt[0]<=opera[0]) {
                    int res = dfs_max(max_cnt, cur_val+A[cur_cnt], cur_opt, cur_cnt+1);
                    if(!init){
                        fin_res = res;
                        init = true;
                    }else{
                        fin_res = max(fin_res, res);
                    }
                }
                cur_opt[0]--;
                break;
            case 1:
                cur_opt[1]++;
                if(cur_opt[1]<=opera[1]) {
                    int res =dfs_max(max_cnt, cur_val-A[cur_cnt], cur_opt, cur_cnt+1);
                    if(!init){
                        fin_res = res;
                        init = true;
                    }else{
                        fin_res = max(fin_res, res);
                    }
                }
                cur_opt[1]--;
                break;
            case 2:
                cur_opt[2]++;
                if(cur_opt[2]<=opera[2]) {
                    int res = dfs_max(max_cnt, cur_val*A[cur_cnt], cur_opt, cur_cnt+1);
                    if(!init){
                        fin_res = res;
                        init = true;
                    }else{
                        fin_res = max(fin_res, res);
                    }
                }
                cur_opt[2]--;
                break;
            case 3:
                cur_opt[3]++;
                if(cur_opt[3]<=opera[3]) {
                    int res = dfs_max(max_cnt, cur_val/A[cur_cnt], cur_opt, cur_cnt+1);
                    if(!init){
                        fin_res = res;
                        init = true;
                    }else{
                        fin_res = max(fin_res, res);
                    }
                }
                cur_opt[3]--;
                break;
            default:
                printf("something went wrong");
                break;
        }
    }
    return fin_res;
}

int dfs_min(int max_cnt, int cur_val, int cur_opt[4], int cur_cnt){

    int fin_res=0;
    bool init = false;

    if(cur_cnt == max_cnt){
        return cur_val;
    }

    for(int i=0; i<4; i++){
        switch(i){
            case 0:
                cur_opt[0]++;
                if(cur_opt[0]<=opera[0]) {
                    int res = dfs_min(max_cnt, cur_val+A[cur_cnt], cur_opt, cur_cnt+1);
                    if(!init){
                        fin_res = res;
                        init = true;
                    }else{
                        fin_res = min(fin_res, res);
                    }
                }
                cur_opt[0]--;
                break;
            case 1:
                cur_opt[1]++;
                if(cur_opt[1]<=opera[1]) {
                    int res =dfs_min(max_cnt, cur_val-A[cur_cnt], cur_opt, cur_cnt+1);
                    if(!init){
                        fin_res = res;
                        init = true;
                    }else{
                        fin_res = min(fin_res, res);
                    }
                }
                cur_opt[1]--;
                break;
            case 2:
                cur_opt[2]++;
                if(cur_opt[2]<=opera[2]) {
                    int res = dfs_min(max_cnt, cur_val*A[cur_cnt], cur_opt, cur_cnt+1);
                    if(!init){
                        fin_res = res;
                        init = true;
                    }else{
                        fin_res = min(fin_res, res);
                    }
                }
                cur_opt[2]--;
                break;
            case 3:
                cur_opt[3]++;
                if(cur_opt[3]<=opera[3]) {
                    int res = dfs_min(max_cnt, cur_val/A[cur_cnt], cur_opt, cur_cnt+1);
                    if(!init){
                        fin_res = res;
                        init = true;
                    }else{
                        fin_res = min(fin_res, res);
                    }
                }
                cur_opt[3]--;
                break;
            default:
                printf("something went wrong");
                break;
        }
    }

    return fin_res;
}

int main(){

    int N;
    scanf("%d", &N);

    for(int i=0; i<N; i++){
        scanf("%d", &A[i]);
    }

    for(int i=0; i<4; i++){
        scanf("%d", &opera[i]);
    }

    int temp[4] = {0,0,0,0};
    int res_max = dfs_max(N, A[0], temp, 1);
    int res_min = dfs_min(N, A[0], temp, 1);

    printf("%d\n", res_max);
    printf("%d", res_min);


    return 0;
}