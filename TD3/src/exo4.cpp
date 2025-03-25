#include "td3.hpp"

int search(std::vector<int> const& vec, int val){
    int left = 0;
    int right = vec.size()-1;
    int middle = (left + right) / 2;

    while(left <= right){
        if(val == vec[middle]){
            return middle;
        }
        else if(val < vec[middle]){
            right = middle - 1;
            
        }
        else{
            left = middle + 1;
        }
        middle = (left + right) / 2;
    }
    return -1;
}