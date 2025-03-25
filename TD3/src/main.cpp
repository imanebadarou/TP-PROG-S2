#include "td3.hpp"

int main(){

    // EXO 1 : 
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

    // EXO 2 :
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

    // EXO 3 :
    std::vector<int> vec_random = generate_random_vector(7, 10);
    std::vector<float> vec_float2 {4., 10., 3., 4., 7., 6., 1.};

    std::cout << std::endl << std::endl << "Tableau de int aléatoire : " << std::endl;
    for (int const elements : vec_random){
        std::cout << elements << " ";
    }
    std::cout << std::endl << "Tableau de float : " << std::endl;
    for (int const elements : vec_float2){
        std::cout << elements << " ";
    }
    std::cout << std::endl << std::endl;

    {
        ScopedTimer timer("Temps d'execution du tri par séléction (vec int)");
        selection_sort(vec_random);
    }
    {
        ScopedTimer timer("Temps d'execution du tri rapide (vec float)");
        quick_sort(vec_float2);
    }
    {
        ScopedTimer timer("Temps d'execution du std::sort (vec int)");
        std::sort(vec_random.begin(), vec_random.end());
    }

}