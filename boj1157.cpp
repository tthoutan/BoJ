//
// Created by tthoutan on 22/09/2019.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int alphabet[27];
char input_c[1000001];

int main(){
    scanf("%s", input_c);
    for(int i=0; input_c[i]; i++){
        if(input_c[i]>'Z'){
            alphabet[input_c[i]-'a']++;
        }else{
            alphabet[input_c[i]-'A']++;
        }
    }

    int maxv=alphabet[0];
    for(int i=1; i<26; i++){
        maxv = max(alphabet[i],maxv);
    }
    int max_cnt = 0;
    int index = 0;
    for(int i=0; i<26; i++){
        if(alphabet[i]==maxv){
            index = i;
            max_cnt++;
        }
    }
    if(max_cnt>1){
        printf("?");
    }else{
        printf("%c", index+'A');
    }

    return 0;
}