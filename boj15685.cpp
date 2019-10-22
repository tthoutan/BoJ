//
// Created by tthoutan on 18/10/2019.
//

#include <iostream>
#include <vector>

using namespace std;


bool map[101][101];

int dc[4] = {1,0,-1,0};
int dr[4] = {0,-1,0,1};

vector<int> dragon_curve(int d, int gen){

    vector<int> ans = {d};

    for(int i=1; i<=gen; i++){

        vector<int> temp_v = vector<int>(ans);

        reverse(temp_v.begin(), temp_v.end());

        for(auto &temp_i: temp_v){
            temp_i = (temp_i+1)%4;
        }

        ans.insert(ans.end(), temp_v.begin(), temp_v.end());

    }

    return ans;

}

int main(){

    int N;

    scanf("%d", &N);
    while(N--){
        int c, r, dir, gen;
        scanf("%d %d %d %d", &c, &r, &dir, &gen);
        auto temp_vec = dragon_curve(dir,gen);

        map[r][c] = true;
        for(auto x : temp_vec){
            c+=dc[x];
            r+=dr[x];
            map[r][c]=true;
        }

    }

    int res = 0;

    for(int i=0; i<=99; i++){
        for(int j=0; j<=99; j++){
            if(map[i][j] && map[i+1][j] && map[i][j+1] && map[i+1][j+1]){
                res++;
            }
        }
    }

    printf("%d", res);

    return 0;
}