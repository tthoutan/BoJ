//
// Created by tthoutan on 24/09/2019.
//

#include <iostream>
#include <string>
using namespace std;

int main(){

    int N;
    scanf("%d", &N);
    cin.ignore();

    for(int i=0; i<N; i++){
        string s;
        getline(cin, s);
        printf("%d. %s\n", i+1, s.c_str());
    }


    return 0;
}