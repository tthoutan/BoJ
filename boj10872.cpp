//
// Created by tthoutan on 23/09/2019.
//

#include <iostream>

using namespace std;

int factorial_func(int N){
    if(N <= 1){
        return 1;
    }else{
        return N*factorial_func(N-1);
    }
}

int main(){

    int N;
    scanf("%d", &N);

    int res = factorial_func(N);

    printf("%d", res);

    return 0;
}