#include <iostream>
#include "td3.hpp"

int main(){
    std::vector<int> vec {4, 10, 3, 4, 7, 6, 3, 8, 3};

    std::cout << "Tableau pas trié : " << std::endl;
    for (int const elements : vec){
        std::cout << elements << " ";
    }

    std::cout << std::endl << std::endl << "Tableau trié avec le tri par séléction : " << std::endl;
    selection_sort(vec);

    for (int const elements : vec){
        std::cout << elements << " ";
    }

    std::vector<float> vec_float {4., 10., 3., 4., 7., 6., 1.};
    std::cout << std::endl << std::endl << "Tableau de float pas trié : " << std::endl;
    for (int const elements : vec_float){
        std::cout << elements << " ";
    }

    std::cout << std::endl << std::endl << "Tableau trié avec le tri rapide : " << std::endl;
    quick_sort(vec_float);

    for (int const elements : vec_float){
        std::cout << elements << " ";
    }
}