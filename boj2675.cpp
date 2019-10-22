//
// Created by tthoutan on 22/09/2019.
//

#include <iostream>
#include <string>

using namespace std;

char input_c[21];

int main(){
    int T;
    scanf("%d", &T);

    for(int i=0; i<T; i++){
        int R;
        scanf("%d %s", &R, input_c);
        string s = input_c;
        for(int j=0; j<s.length(); j++){
            for(int k=0; k<R; k++){
                printf("%c", s.at(j));
            }
        }
        printf("\n");
    }

    return 0;
}