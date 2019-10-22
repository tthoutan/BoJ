#include <iostream>

using namespace std;

#define MAX_N 101
#define MAX_M 101
int A[MAX_N][MAX_M];
int B[MAX_N][MAX_M];

int main(){

    int N, M;
    scanf("%d %d", &N, &M);

    for(int j=0; j<N; j++) {
        for (int k = 0; k < M; k++) {
            scanf("%d", &A[j][k]);
        }
    }
    for(int j=0; j<N; j++){
        for (int k=0; k<M; k++){
            scanf("%d", &B[j][k]);
        }
    }

    for(int j=0; j<N; j++){
        for(int k=0; k<M; k++){
            printf("%d ", A[j][k]+B[j][k]);
        }
        printf("\n");
    }

    return 0;
}