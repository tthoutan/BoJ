//
// Created by tthoutan on 09/10/2019.
//

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <list>
#include <bitset>

using namespace std;

vector<int> vector_t;

int main(){

    vector_t = {1,2,3,4};

    auto it = vector_t.begin();

    vector_t.insert(it, 0);

    cout << *it << endl;

    it = vector_t.begin() + 2;
    vector_t.insert(it, 5, 6);

    cout << *it << endl;

    vector<int> vec_test = {1,2,3,4,5};

    for(auto it = vector_t.begin(); it!= vector_t.end(); it++){
        printf("%d", *it);
    }

    for(int x: vector_t){
        x = 2;
        printf("%d", x);
    } // call by value

    for(int &x: vector_t){
        printf("%d", x);
    } // call by ref

    vector<int> n_t(10, 2);

    for(int x: n_t){
        printf("%d", x);
    }

    int a = abs(-3);

    printf("%d", a);

    list<int> l = {2,1,3,4,-5,-6,-7};

    l.sort([](int &x, int &y){
        return abs(x) < abs(y);
    }); // 절대값 오름차순

    for(int x: l){
        printf("%d", x);
    }
    printf("\n");

    it = vector_t.begin();
    it = it +1;

    printf("%d",*it);

    it = it + 1;
    printf("%d", *it);

    bitset<10> b(88);
    cout << endl;

    b.reset(3);
    cout << b << endl;
    cout << b.test(4) << endl;
    return 0;
}