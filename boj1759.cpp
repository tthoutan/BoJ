//
// Created by tthoutan on 09/10/2019.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> in_arr;
int temp[20];

void dfs(int max_cnt, int cur_cnt, int cur_idx){

    if(cur_cnt == max_cnt){
        int temp_cnt = 0;
        for(int i=1; i<=max_cnt; i++){
            if(temp[i]=='a'||temp[i]=='e'||temp[i]=='i'||temp[i]=='o'||temp[i]=='u'){
                temp_cnt++;
            }
        }
        if(temp_cnt>=1 && max_cnt-temp_cnt>=2){
            for(int i=1; i<=max_cnt; i++){
                printf("%c", temp[i]);
            }
            printf("\n");
        }
    }else if(cur_idx>=in_arr.size()){
        return;
    }

    for(int i=cur_idx; i<(int)in_arr.size(); i++) {
        temp[cur_cnt+1] = in_arr[i];
        dfs(max_cnt, cur_cnt + 1, i+1);
    }

}

int main(){

    int L, C;

    scanf("%d %d\n", &L, &C);

    for(int i=0; i<C; i++) {
        char temp;
        cin >> temp;
        in_arr.push_back(temp);
    }

    sort(in_arr.begin(), in_arr.end());

    dfs(L, 0, 0);


    return 0;
}