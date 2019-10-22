//
// Created by tthoutan on 24/09/2019.
//

#include <iostream>
#include <typeinfo>

using namespace std;

void print_line(int line, char* sentence){

}


int main(){

    int N;
    scanf("%d", &N);
//    for(int i=0; i<N; i++){
//        char temp[51]="";
//    }
    char str[5] = {'H','e','l','l','o'};
    const char *str_b = "Hello";
    printf("%s\n", str);
    const char str_a[6] = "Hello";
    cout << typeid("Hello").name() << endl;
    cout << typeid(str_a).name() << endl;
    cout << typeid(str).name() << endl;
    cout << typeid(str_b).name() << endl;
    std::cout << typeid(int*).name() << endl;
    char *str_c = "Hello";

    return 0;
}