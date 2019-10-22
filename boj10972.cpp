//
// Created by tthoutan on 09/10/2019.
//

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main(){

    int N;
    scanf("%d", &N);

    vector<int> temp_vec;
    for(int i=0; i<N; i++){
        int temp;
        scanf("%d", &temp);
        temp_vec.push_back(temp);
    }

    bool result = next_permutation(temp_vec.begin(), temp_vec.end());

    if(result) {
        for (auto it = temp_vec.begin(); it != temp_vec.end(); it++) {
            printf("%d ", *it);
        }
    }else{
        printf("%d", -1);
    }

    return 0;
}