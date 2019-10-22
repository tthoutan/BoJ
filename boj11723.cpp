//
// Created by tthoutan on 10/10/2019.
//

#include <iostream>
#include <bitset>

using namespace std;

int main(){


    bitset<20> S(0);

    int M;
    scanf("%d", &M);

    while(M--){
        char temp[10];
        int temp_in;
        scanf("%s", temp);
        switch(temp[0]){
            case 'a': {
                if (temp[1] == 'd') {
                    scanf("%d", &temp_in);
                    temp_in--;
                    S.set(temp_in);
                } else {
                    S.set();
                }
                break;
            }
            case 'r': {
                scanf("%d", &temp_in);
                temp_in--;
                S.reset(temp_in);
                break;
            }
            case 'c': {
                scanf("%d", &temp_in);
                temp_in--;
                printf("%d\n", S.test(temp_in));
                break;
            }
            case 't': {
                scanf("%d", &temp_in);
                temp_in--;
                S.flip(temp_in);
                break;
            }
            case 'e': {
                S.reset();
                break;
            }
        }
    }

    return 0;
}