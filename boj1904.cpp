//
// Created by tthoutan on 25/09/2019.
//

#include <iostream>

using namespace std;


long long int tail[1000010];

int main(){

    int N;
    scanf("%d", &N);

    tail[1] = 1;
    tail[2] = 2;

    for(int i=3; i<=N; i++){
        tail[i] = (tail[i-1]%15746 + tail[i-2]%15746)%15746;
    }

    printf("%lld", tail[N]);

    return 0;
}