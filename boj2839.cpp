//
// Created by tthoutan on 23/09/2019.
//

#include <iostream>
#include <string>

using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    int cnt = 0;

    while(N>0) {
        if (N % 5 != 0) {
            N -= 3;
            cnt++;
        }else{
            cnt+=N/5;
            N=0;
            break;
        }
    }
    if(N==0) {
        printf("%d", cnt);
    }else{
        printf("%d",-1);
    }
    return 0;
}