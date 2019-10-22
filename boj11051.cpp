//
// Created by tthoutan on 25/09/2019.
//

#include <iostream>

using namespace std;

long long int pascal[1010][1010];

int main(){

    int N, K;

    scanf("%d %d", &N, &K);

    pascal[1][0] = 1;
    pascal[1][1] = 1;

    for(int i=2; i<=N; i++){
        for(int j=0; j<=i; j++){
            pascal[i][j] = pascal[i-1][j-1]%10007 + pascal[i-1][j]%10007;
        }
    }

    printf("%lld", pascal[N][K]%10007);

    return 0;
}