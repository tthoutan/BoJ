//
// Created by tthoutan on 10/10/2019.
//

#include <iostream>
#include <set>

using namespace std;

int N,M;

set<int> input_set;
int res_arr[12];

void go(int cur_cnt){

    if(cur_cnt==M){
        for(int i=0; i<M; i++){
            printf("%d ", res_arr[i]);
        }
        printf("\n");
        return;
    }

    for(auto it : input_set){
        res_arr[cur_cnt] = it;
        go(cur_cnt+1);
    }

}

int main(){

    scanf("%d %d", &N, &M);

    for(int i=0; i<N; i++){
        int temp;
        scanf("%d", &temp);
        input_set.insert(temp);
    }

    go(0);

    return 0;
}