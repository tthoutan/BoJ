//
// Created by tthoutan on 27/09/2019.
//

#include <iostream>

using namespace std;



// dfs로 풀면 2^100 -> 대략 10^25보다 큼, SOF.
int dfs(int N, int cur_cnt, int last_num){

    if(last_num < 0 || last_num > 9){
        return 0;
    }
    if(cur_cnt == N){
        return 1;
    }

    return dfs(N, cur_cnt+1, last_num+1)%1000000000 + dfs(N, cur_cnt+1, last_num-1)%1000000000;

}

long long int DP[101][11];

int main(){

    int N;
    scanf("%d", &N);

    for(int i=1; i<10; i++){
        DP[1][i] = 1;
    }

    for(int i=2; i<=N; i++){
        for(int j=0; j<10; j++){
            DP[i][j] = (DP[i-1][j-1]%1000000000 + DP[i-1][j+1]%1000000000)%1000000000;
        }
    }

    long long int res = 0;

    for(int i=0; i<10; i++){
        res+=DP[N][i];
    }

    printf("%lld", res%1000000000);

    return 0;
}