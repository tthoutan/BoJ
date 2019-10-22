#include <iostream>
#include <ctime>

using namespace std;

int main(){
    time_t curr_time;
    struct tm *curr_tm;

    curr_time = time(NULL);
    curr_time+=9*60*60
    curr_tm = localtime(&curr_time);

    printf("%4d-%02d-%02d", curr_tm -> tm_year+1900, curr_tm -> tm_mon+1, curr_tm -> tm_mday);
    return 0;
}