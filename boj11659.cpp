//
// Created by tthoutan on 26/09/2019.
//

#include <iostream>

using namespace std;

int soo[100001];
int accum[100001];


int main(){

    int N, M;
    scanf("%d %d", &N, &M);

    for(int i=1; i<N+1; i++){
        scanf("%d", &soo[i]);
    }

    accum[1] = soo[1];

    for(int i=1; i<N; i++){
        accum[i+1] = accum[i] + soo[i+1];
    }


    while(M--){
        int i,j;
        scanf("%d %d", &i, &j);
        printf("%d\n", accum[j]-accum[i-1]);
    }

    return 0;
}