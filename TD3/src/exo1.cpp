#include "td3.hpp"

bool is_sorted(std::vector<int> const& vec) {
    return std::is_sorted(vec.begin(), vec.end());
}

void selection_sort(std::vector<int> & vec){
    for(int i; i < vec.size()-1; i++){
        int posMin = i;
        for(int j=i+1; j<vec.size(); j++){
            if(vec[j]<vec[posMin]){
                posMin = j;
            }
        }
        int posMin_temp = vec[posMin];
        vec[posMin] = vec[i];
        vec[i] = posMin_temp;
    }
    return;
}




