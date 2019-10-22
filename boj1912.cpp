//
// Created by tthoutan on 28/09/2019.
//

#include <iostream>

using namespace std;

int main(){

    int N;
    scanf("%d", &N);

    int res;
    scanf("%d", &res);
    int max_r = res;
    for(int i=1; i<N; i++){
        int temp;
        scanf("%d", &temp);

        if(res>0){
            res+=temp;
        }else{
            res = temp;
        }

        max_r = max(max_r, res);

    }

    printf("%d", max_r);

    return 0;
}