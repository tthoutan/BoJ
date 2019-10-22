//
// Created by tthoutan on 28/09/2019.
//

#include <vector>
#include <iostream>

using namespace std;

vector<int> temp_vec;

vector<int> ::iterator circular(vector<int> &vec,vector<int> ::iterator &iter, int K){
    for(int i=1; i<K; i++) {
        iter++;
        if (iter == vec.end()) {
            iter = vec.begin();
        }
    }
}
int main(){

    int N, K;
    scanf("%d %d", &N, &K);

    for(int i=1; i<=N; i++){
        temp_vec.push_back(i);
    }

    auto iter = temp_vec.begin();
    cout << "<";
    while(!temp_vec.empty()){
        circular(temp_vec, iter, K);
        if(temp_vec.size()!=1) {
            cout << *iter << ", ";
        }else{
            cout << *iter << ">";
        }
        auto q = temp_vec.erase(iter);
        iter = q;
        if(iter==temp_vec.end()){
            iter = temp_vec.begin();
        }
    }

    return 0;
}
