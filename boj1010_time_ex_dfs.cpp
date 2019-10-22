//
// Created by tthoutan on 23/09/2019.
//

#include <iostream>

using namespace std;

int dfs(int st_idx, int max_idx, int max_cnt, int cnt){

    if(cnt==max_cnt){
        return 1;
    }else if(st_idx>=max_idx){
        return 0;
    }

    int result = 0;

    for(int i=st_idx; i<max_idx-max_cnt+cnt+1; i++){
        result += dfs(i+1, max_idx, max_cnt,cnt+1);
    }

    return result;
}

int main(){
    int T,N,M;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&N,&M);
        long long int res = dfs(0, M, N,0);
        printf("%lld\n", res);
    }


    return 0;
}