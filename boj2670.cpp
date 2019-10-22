//
// Created by tthoutan on 28/09/2019.
//

#include <iostream>
#include <algorithm>

using namespace std;

double input[10010];

int main(){

    int N;
    scanf("%d", &N);

    scanf("%lf", &input[1]);
    double res = input[1];
    double max_r = res;
    for(int i=2; i<=N; i++){
        scanf("%lf", &input[i]);

        if(res>1.0){
            res*=input[i];
        }else{
            res=input[i];
        }

//        max_r = max(max_r, res);
//        max_r = max(max_r, input[i]);
//        max_r = max(max_r, res*input[i]);
//        if(res*input[i]>1.0){
//            res*=input[i];
//        }else{
//            res=input[i];
//        }
//        max_r = max(max_r, input[i]);
//        max_r = max(max_r, res*input[i]);

//        0.8*1.3*1.4가 있을때 곱이 1.0 이상이면 res에 저장하는건 맨 앞에 1보다 작은수가 곱해지는걸 포함하고
//        곱하는 값이 1.0 이상일때 곱하는건 맨앞에 1보다 작은수가 곱해지는것을 허용 안함

        max_r = max(max_r, res);

    }

    printf("%.3lf", max_r);


    return 0;
}