//
// Created by tthoutan on 26/09/2019.
//

#include <iostream>

using namespace std;

long long int uphill[1010][11];

int main(){

    int N;
    scanf("%d", &N);

    for(int i=0; i<10; i++){
        uphill[1][i]++;
    }

    for(int i=2; i<=N; i++){
        for(int j=0; j<10; j++){
            for(int k=j; k<10; k++){
                uphill[i][k]+=uphill[i-1][j]%10007;
            }
        }
    }

    long long int res=0;

    for(int i=0; i<10; i++){
        res+=uphill[N][i]%10007;
    }

    printf("%lld", res%10007);

    return 0;
}