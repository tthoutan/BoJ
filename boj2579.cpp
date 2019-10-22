//
// Created by tthoutan on 28/09/2019.
//

#include <iostream>

using namespace std;


int DP[301][3];
int stair[301];

int main(){

    int N;
    scanf("%d", &N);

    for(int i=1; i<=N; i++){
        scanf("%d", &stair[i]);
    }

    DP[1][1] = stair[1];
    DP[2][1] = stair[2];
    DP[2][2] = stair[1]+stair[2];
    DP[3][1] = stair[1]+stair[3];
    DP[3][2] = stair[2]+stair[3];

    for(int i=4; i<=N; i++){
        DP[i][1] = max(DP[i-2][1], DP[i-2][2]) + stair[i];
        DP[i][2] = DP[i-1][1] + stair[i];
    }

    int res = max(DP[N][1], DP[N][2]);

    printf("%d", res);

    return 0;
}
