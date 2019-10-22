//
// Created by tthoutan on 27/09/2019.
//

#include <iostream>
#include <algorithm>

using namespace std;

int spend[1010][4];

int main(){

    int N;

    scanf("%d", &N);

    scanf("%d %d %d", &spend[1][1], &spend[1][2], &spend[1][3]);
    for(int i=2; i<=N; i++){
        scanf("%d %d %d", &spend[i][1], &spend[i][2], &spend[i][3]);

        spend[i][1] += min(spend[i-1][2], spend[i-1][3]);
        spend[i][2] += min(spend[i-1][1], spend[i-1][3]);
        spend[i][3] += min(spend[i-1][1], spend[i-1][2]);

    }

    int res = min(spend[N][1], spend[N][2]);
    res = min(res, spend[N][3]);

    printf("%d", res);

    return 0;
}