//
// Created by tthoutan on 23/09/2019.
//

#include <iostream>
#include <algorithm>

using namespace std;
int GCD(int m, int n){

    int rest = m%n;
    if(rest==0){
        return n;
    }else{
        return GCD(n, rest);
    }

}

int LCM(int m, int n){

    return m*n/GCD(m,n);

}


int main(){
    int M,N;
    scanf("%d %d", &M, &N);

    int temp = max(M,N);
    N = min(M,N);
    M = temp;

    int gcd = GCD(M,N);
    int lcm = LCM(M,N);

    printf("%d\n%d", gcd, lcm);

    return 0;
}