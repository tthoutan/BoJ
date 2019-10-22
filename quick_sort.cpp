#include <iostream>
#include <vector>
using namespace std;

void partition(std::vector<int> &arr, int left_idx, int right_idx){

    if(left_idx>=right_idx){
        return;
    }

    int low = left_idx + 1;
    int high = right_idx;
    int pivot = left_idx;

    while(low < high){
        while(arr[low]<arr[pivot] && low <= high){
            low++;
        }
        while(arr[high]>arr[pivot] && high >= low){
            high--;
        }
        if(low < high) {
            int temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
        }
    }
    int temp = arr[high];
    arr[high] = arr[pivot];
    arr[pivot] = temp;
    pivot = high;

    // left_partition
    partition(arr, left_idx, pivot-1);
    // right_partition
    partition(arr, pivot+1, right_idx);

}

int main(){
    int N;
    cin >> N;
    vector<int> input_arr;
    for(int i=0; i<N; i++){
        int temp;
        cin >> temp;
        input_arr.push_back(temp);
    }
    partition(input_arr, 0, input_arr.size()-1);

    for(int i=0; i<N; i++){
        printf("%d\n", input_arr[i]);
    }
    return 0;
}
