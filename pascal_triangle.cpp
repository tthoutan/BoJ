//
// Created by tthoutan on 25/09/2019.
//

#include <iostream>

using namespace std;


int pascal[100][100];

int main(){

    int n, r;
    scanf("%d %d", &n, &r);

    pascal[1][0] = 1;
    pascal[1][1] = 1;

    for(int i=2; i<=n; i++){
        for(int j=0; j<=i; j++){
            pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
            printf("%dC%d = %d + %d\n", i,j, pascal[i-1][j-1], pascal[i-1][j]);
        }
    }
    printf("%d", pascal[n][r]);


    return 0;
}