#include <iostream>
#include <string>

using namespace std;

int count_N[10];

int main(){

    int N = 1;
    for(int i=0; i<3; i++){
        int temp;
        scanf("%d", &temp);
        N*=temp;
    }

    string s = to_string(N);

    for(int i=0; i<(int)s.length(); i++){
        int temp = s.at(i)-48;
        count_N[temp]++;
    }

    for(int i=0; i<10; i++){
        printf("%d\n", count_N[i]);
    }
    return 0;
}