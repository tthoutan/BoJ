//
// Created by tthoutan on 14/10/2019.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

//N=보드의 크기, M=처음에 심은 나무의 수, K=지난 시간
int N, M, K;

int add_board[12][12];
int base_board[12][12];

struct wood{
    vector<int> age;
//    int age;
//    bool operator <(const wood &w) const{
//        return age < w.age;
//    }
};

struct dead{
    int r;
    int c;
    int age;
};

wood woods[12][12];
vector<dead> dead_woods;

int dr[8] = {-1,-1,-1,0,0,1,1,1};
int dc[8] = {-1,0,1,-1,1,-1,0,1};

//디버깅용
//void print_woods(){
//    printf("woods:\n");
//    for(auto x: woods){
//        printf("{%d,%d,%d}\n",x.r,x.c,x.age);
//    }
//    printf("dead_woods:\n");
//    for(auto x: dead_woods){
//        printf("{%d,%d,%d}\n",x.r,x.c,x.age);
//    }
//
//}
//디버깅용
//void print_base(){
//    for(int i=1; i<=N; i++){
//        for(int j=1; j<=N; j++){
//            printf("%d ", base_board[i][j]);
//        }
//        printf("\n");
//    }
//}

void spring_go(){

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            for(int k=0; k<(int)woods[i][j].age.size(); k++){
                if(base_board[i][j]<woods[i][j].age[k]){
                    dead temp_d={};
                    temp_d.r=i;
                    temp_d.c=j;
                    temp_d.age=woods[i][j].age[k];
                    dead_woods.push_back(temp_d);
                    woods[i][j].age.erase(woods[i][j].age.begin()+k);
                    k--;
                }else{
                    base_board[i][j]-=woods[i][j].age[k];
                    woods[i][j].age[k]++;
                }
            }
        }
    }
//    for(auto it = woods.begin(); it!=woods.end(); it++){
//        if(base_board[it->r][it->c]<it->age){
//            dead_woods.push_back(*it);
//            auto temp = it;
//            temp--;
//            woods.erase(it);
//            it=temp;
//        }else{
//            base_board[it->r][it->c]-=it->age;
//            it->age++;
//        }
//    }

}

void summer_go(){
    for(auto it : dead_woods){
        base_board[it.r][it.c]+=it.age/2;
    }
    dead_woods = vector<dead>();
}

void autumn_go(){

//    int temp_size=woods.size();
//    auto it= woods.end();
//    it++;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            for(auto x : woods[i][j].age){
                if(x%5==0&&x!=0){
                    for(int k=0; k<8; k++) {
                        int temp_r = i + dr[k];
                        int temp_c = j + dc[k];

                        if (temp_r < 1 || temp_r > N || temp_c < 1 || temp_c > N) continue;

                        woods[temp_r][temp_c].age.insert(woods[temp_r][temp_c].age.begin(), 1);
                    }

                }
            }
        }
    }
//    for(int j=0; j<temp_size; j++){
//
//        if(woods[j].first.age%5==0){
//            for(int i=0; i<8; i++){
//                int temp_r = woods[j].first.r + dr[i];
//                int temp_c = woods[j].first.c + dc[i];
//
//                if(temp_r<1 || temp_r>N || temp_c<1 || temp_c>N) continue;
//
//                wood temp_wood = {};
//                temp_wood.r = temp_r;
//                temp_wood.c = temp_c;
//                temp_wood.age = 1;
//                woods.push_back(temp_wood);
//
//            }
//        }
//    }
//
//    sort(woods.begin(), woods.end());

}

void winter_go(){

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            base_board[i][j]+=add_board[i][j];
        }
    }

}



int main(){

    scanf("%d %d %d", &N, &M, &K);

    // add_board 입력(매년 추가되는 양분의 정보)
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            base_board[i][j]=5;
            scanf("%d", &add_board[i][j]);
        }
    }

    // woods 입력
    for(int i=1; i<=M; i++){
        int x,y,z;
        scanf("%d %d %d", &x, &y, &z);

        woods[x][y].age.push_back(z);

    }

    while(K--){
        spring_go();
        summer_go();
        autumn_go();
        winter_go();
    }

    //K년이 지나고 난 후 살아남은 나무의 수 출력

    int res =0;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){

            res+=woods[i][j].age.size();

        }
    }



    printf("%d", res);

    return 0;
}