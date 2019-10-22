#include <iostream>

using namespace std;

#define MAX_N 101
#define MAX_M 101

int canvas[MAX_N][MAX_M];

int main(){
    int N;
    scanf("%d", &N);

    for(int i=0; i<N; i++){
        int tempN, tempM;
        scanf("%d %d", &tempN, &tempM);
        for(int j=tempN+1; j<tempN+11; j++){
            for(int k=tempM+1; k<tempM+11; k++){
                canvas[j][k]++;
            }
        }
    }

    int result = 100*N;
    for(int i=1; i<MAX_N; i++){
        for(int j=1; j<MAX_M; j++){
            if(canvas[i][j]>1){
                result-=canvas[i][j]-1;
            }
        }
    }

    printf("%d", result);

    return 0;
}
