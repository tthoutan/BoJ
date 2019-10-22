//
// Created by tthoutan on 09/10/2019.
//

#include <iostream>

using namespace std;

bool not_sosu[1000010];

int main(){

    int N;

    scanf("%d", &N);

    for(int i=3; i<1000000; i+=2){
        if(!not_sosu[i]){
            for(int j=2; i*j<1000000; j++){
                not_sosu[i*j]=true;
            }
        }
    }

    while(N!=0){
        bool find = false;
        for(int i=1; (2*i+1)<=N; i++){
            int j = 2*i+1;
            if(not_sosu[j]){
                continue;
            }else{
                if(not_sosu[N-j]){
                    continue;
                }else{
                    printf("%d = %d + %d\n",N,j,N-j);
                    find = true;
                    break;
                }
            }
        }

        if(!find){
            printf("Goldbach's conjecture is wrong.");
        }

        scanf("%d", &N);
    }

    return 0;
}