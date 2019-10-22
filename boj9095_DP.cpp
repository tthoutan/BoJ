//
// Created by tthoutan on 27/09/2019.
//

#include <iostream>

using namespace std;


int ways[11]={0,1,2,4};

int main(){

    int T;
    scanf("%d", &T);

    while(T--){
        int N;
        scanf("%d", &N);

        for(int i=4; i<=N; i++){
            ways[i] = ways[i-1]+ways[i-2]+ways[i-3];
        }

        printf("%d\n", ways[N]);


    }

    return 0;
}