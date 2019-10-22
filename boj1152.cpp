//
// Created by tthoutan on 22/09/2019.
//
#include <iostream>
#include <string>
using namespace std;

string input[5];

int main(){

    for(int i=0; i<5; i++){
        cin >> input[i];
    }

    for(int i=0; i<15; i++){
        for(int j=0; j<5; j++){
            if(i<input[j].length()){
                printf("%c", input[j].at(i));
            }
        }
    }
    return 0;
}