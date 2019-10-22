//
// Created by tthoutan on 22/09/2019.
//

#include <iostream>
#include <string>
using namespace std;

int alphabet[26];
char input_c[101];
int main(){
    scanf("%s", input_c);
    string input = input_c;
    for(int i=0; i<input.length(); i++){
        int temp = input.at(i) - 97;
        alphabet[temp]++;
    }

    for(int i=0; i<26; i++){
        printf("%d ", alphabet[i]);
    }
    return 0;
}