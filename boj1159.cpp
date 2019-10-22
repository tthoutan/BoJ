//
// Created by tthoutan on 23/09/2019.
//

#include <iostream>

using namespace std;

int alphabet[27];

int main(){
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        char temp_name[31];
        scanf("%s", temp_name);
        alphabet[temp_name[0]-'a']++;
    }
    bool play = false;
    for(int i=0; i<26; i++){
        if(alphabet[i]>=5){
            play = true;
            break;
        }
    }
    if(play){
        for(int i=0; i<26; i++){
            if(alphabet[i]>=5){
                printf("%c", 'a'+i);
            }
        }
    }else{
        printf("PREDAJA");
    }
    return 0;
}