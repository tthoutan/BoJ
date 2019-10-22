//
// Created by tthoutan on 28/09/2019.
//

#include <iostream>
#include <algorithm>
using namespace std;

int DP[10010][4];
int grape[10010];

int main(){

    int N;
    scanf("%d", &N);

    for(int i=1; i<=N; i++){
        scanf("%d", &grape[i]);
    }

    if(N==1){
        printf("%d", grape[1]);
        return 0;
    }else if(N==2){
        printf("%d", grape[1]+grape[2]);
        return 0;
    }

    DP[1][1] = grape[1];
    DP[2][2] = grape[1]+grape[2];
    DP[2][1] = grape[2];
    DP[2][0] = grape[1];
    DP[3][0] = DP[2][2];
    DP[3][1] = grape[1]+grape[3];
    DP[3][2] = grape[2]+grape[3];

    for(int i=4; i<=N; i++){
        DP[i][2] = DP[i-1][1]+grape[i];
        DP[i][1] = max(DP[i-2][1]+grape[i], DP[i-2][2]+grape[i]);
        DP[i][1] = max(DP[i][1], DP[i-2][0]+grape[i]);
        DP[i][0] = max(DP[i-1][2], DP[i-1][1]);
        DP[i][0] = max(DP[i][0], DP[i-1][0]);
    }

    int res = max(DP[N][0], DP[N][1]);
    res = max(DP[N][2], res);

    printf("%d", res);

    return 0;
}