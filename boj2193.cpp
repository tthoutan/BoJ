//
// Created by tthoutan on 24/09/2019.
//

#include <iostream>

using namespace std;

long long int cache[90];

long long int soo(int N){

    if(N==1){
        return 2;
    }else if(N==0){
        return 1;
    }

    if(cache[N]) return cache[N];

    return cache[N] = soo(N-1) + soo(N-2);
}

int main(){

    int N;
    scanf("%d", &N);

    long long int res;
    if(N<=2){
        res = 1;
    }else{
        res = soo(N-2);
    }

    printf("%lld", res);

    return 0;
}
