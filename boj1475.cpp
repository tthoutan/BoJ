//
// Created by tthoutan on 24/09/2019.
//

#include <iostream>
#include <algorithm>

using namespace std;

int number[11];

int main(){
    int res = 0;
    string N;
    getline(cin, N);

    for(int i=0; i<N.length(); i++){
        number[N.at(i)-48]++;
    }

    number[6]+=number[9];
    if((float)number[6]/2>number[6]/2){
        number[6]/=2;
        number[6]++;
    }else{
        number[6]/=2;
    }

    for(int i=0; i<9; i++){
        res = max(number[i],res);
    }

    printf("%d", res);

    return 0;
}