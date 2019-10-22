#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    int temp;
    int first = 0;
    int last = 0;
    int maxv = 0;
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            scanf("%d", &temp);
        } else {
            int next;
            scanf("%d", &next);
            if (temp < next && first == 0) {
                first = temp;
            } else if (temp >= next && first != 0) {
                last = temp;
                maxv = max(last - first, maxv);
                first = 0;
            }
            temp = next;
        }
    }
    if(maxv!=0){
        printf("%d", maxv);
    }else{
        printf("%d", 0);
    }
}