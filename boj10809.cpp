//
// Created by tthoutan on 22/09/2019.
//

#include <iostream>
#include <string>

using namespace std;

int alphabet[27];
char input_c[101];

int main(){
    scanf("%s", input_c);
    string s = input_c;

    for(int i=0; i<26; i++){
        alphabet[i] = s.find(i+'a');
        printf("%d ", alphabet[i]);
    }

    return 0;
}