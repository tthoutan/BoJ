//
// Created by tthoutan on 25/09/2019.
//

#include <iostream>

using namespace std;

long long int DP[1010];

int main(){

    int N;
    scanf("%d", &N);

    DP[1] = 1;
    DP[2] = 3;

    for(int i=3; i<=N; i++){
        DP[i]=(DP[i-1]%10007+(2*DP[i-2])%10007)%10007;
    }

    printf("%lld", DP[N]);

    return 0;
}