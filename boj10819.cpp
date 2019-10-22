//
// Created by tthoutan on 09/10/2019.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> in_arr;

int main(){

    int N;
    scanf("%d", &N);

    for(int i=0; i<N; i++){
        int temp;
        scanf("%d", &temp);
        in_arr.push_back(temp);
    }

    sort(in_arr.begin(), in_arr.end());

    int max_res = 0;
    do{
        int temp_sum = 0;
        for(auto it = ++in_arr.begin(); it!=in_arr.end(); it++){
            auto temp = it;
            temp--;
            temp_sum += abs(*it-*temp);
        }
        max_res = max(temp_sum, max_res);
    }while(next_permutation(in_arr.begin(), in_arr.end()));

    printf("%d", max_res);

    return 0;
}