#include <iostream>

using namespace std;

#define MAX_N 10+1
int input[MAX_N];

int main(){
    int result = 0;
    for(int i=1; i<MAX_N; i++){
        int temp;
        scanf("%d", &temp);
        input[i] = temp%42;
    }

    for(int i=0; i<42; i++){
        int count = 0;
        for(int j=1; j<MAX_N; j++){
            if(input[j] == i){
                count++;
            }
        }
        if(count >= 1){
            result++;
        }
    }
    printf("%d\n", result);
    for(int i=1; i<MAX_N; i++){
        printf("%d\n", input[i]);
    }

    return 0;
}