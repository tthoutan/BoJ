//
// Created by tthoutan on 24/09/2019.
//

#include <iostream>

using namespace std;

long long int com[1010][1010];

long long int combination(int n, int r){

    if(n==r || r==0){
        return 1;
    }
    if(com[n][r]) return com[n][r];

    return com[n][r] = combination(n-1, r-1)%10007 + combination(n-1,r)%10007;

}

int main(){

    int N;
    scanf("%d", &N);

    long long int res=0;

    for(int i=0; i<=N/2; i++){
        res+=combination(N-i,i);
    }

    printf("%lld", res%10007);

    return 0;
}
