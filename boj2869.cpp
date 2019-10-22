//
// Created by tthoutan on 28/09/2019.
//

#include <iostream>

using namespace std;

int main(){

    int A,B,V;
    scanf("%d %d %d", &A, &B, &V);

    int restV = V-A;
    double perD = A-B;
    double totalD = restV/perD;
    int res = 0;

    if(totalD>(int)totalD){
        res = (int)totalD+2;
    }else{
        res = (int)totalD+1;
    }

    printf("%d", res);


    return 0;
}