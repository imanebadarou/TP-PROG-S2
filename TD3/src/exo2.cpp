#include "td3.hpp"

size_t quick_sort_partition(std::vector<float> & vec, size_t left, size_t right, size_t const pivot){
    float pivot_temp = vec[pivot];
    vec[pivot] = vec[right];
    vec[right] = pivot_temp;

    int j = left;
    for(int i = left; i <= right-1; i++){
        if(vec[i] <= vec[right]){
            std::swap(vec[i], vec[j]);
            j++;
        }
    } 
    std::swap(vec[right], vec[j]);
    return j;
}


void quick_sort(std::vector<float> & vec, size_t const left, size_t const right){
    if(left < right){
        size_t pivot = quick_sort_partition(vec, left, right, (left+right)/2);
        quick_sort(vec, left, pivot-1);
        quick_sort(vec, pivot+1, right);
    }
}

void quick_sort(std::vector<float> & vec) {
    quick_sort(vec, 0, vec.size() -1);
}
