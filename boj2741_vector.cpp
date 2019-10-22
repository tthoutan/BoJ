//
// Created by tthoutan on 28/09/2019.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> vec_int;

int main(){

    int N;
    cin >> N;

    for(int i=1; i<=N; i++){
        vec_int.push_back(i);
    }

    for(auto iter = vec_int.begin(); iter!=vec_int.end(); iter++){
        cout << *iter << "\n";
    }

    return 0;
}