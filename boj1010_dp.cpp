//
// Created by tthoutan on 23/09/2019.
//

#include <iostream>

using namespace std;

int d[31][31];

int combination(int n, int m){

    if(n==m||n==0){
        return 1;
    }
    if (d[m][n]) return d[m][n];
    return d[m][n]=combination(n-1,m-1) + combination(n,m-1);
}

int main(){
    int T,N,M;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &N, &M);
        long long int res = combination(N,M);
        printf("%lld\n", res);
    }

}