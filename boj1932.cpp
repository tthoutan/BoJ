//
// Created by tthoutan on 28/09/2019.
//

#include <iostream>
#include <algorithm>
using namespace std;

int input[505][505];
int DP[505][505];


int main(){

    int N;
    scanf("%d", &N);

    for(int i=1; i<=N; i++){
        for(int j=1; j<=i; j++){
            scanf("%d", &input[i][j]);
        }
    }

    DP[1][1] = input[1][1];
    DP[2][1] = DP[1][1] + input[2][1];
    DP[2][2] = DP[1][1] + input[2][2];

    for(int i=3; i<=N; i++){
        for(int j=1; j<=i; j++){
            DP[i][j] = max(DP[i-1][j-1], DP[i-1][j]) + input[i][j];
        }
    }

    int res = DP[N][1];
    for(int i=2; i<=N; i++){
        res = max(res, DP[N][i]);
    }

    printf("%d", res);

    return 0;
}