#include "td3.hpp"


int main(){

    // EXO 1 : 
    std::vector<int> vec {4, 10, 3, 4, 7, 6, 3, 8, 3};

    std::cout << "Tableau pas trié : " << std::endl;
    for (int const elements : vec){
        std::cout << elements << " ";
    }

    std::cout << std::endl << "Tableau trié avec le tri par séléction : " << std::endl;
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

    std::cout << std::endl << "Tableau trié avec le tri rapide : " << std::endl;
    quick_sort(vec_float);

    for (int const elements : vec_float){
        std::cout << elements << " ";
    }

    // EXO 3 :
    std::vector<int> vec_random = generate_random_vector(7, 10);
    std::vector<float> vec_float2 {4., 10., 3., 4., 7., 6., 1.};

    // std::cout << std::endl << std::endl << "Tableau de int aléatoire : " << std::endl;
    // for (int const elements : vec_random){
    //     std::cout << elements << " ";
    // }
    // std::cout << std::endl << "Tableau de float : " << std::endl;
    // for (int const elements : vec_float2){
    //     std::cout << elements << " ";
    // }
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

    // EXO 4 :
    std::vector<int> vec_search1 {1, 2, 2, 3, 4, 8, 12};
    std::vector<int> vec_search2 {2, 2, 3, 4, 5, 8, 12, 15, 16};
    std::vector<int> vec_search3 {1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << std::endl << "Tableau trié 1 : " << std::endl;
    for (int const elements : vec_search1){
        std::cout << elements << " ";
    }
    int indice1 = search(vec_search1, 8);
    std::cout << std::endl << "Recherche dichotomique : La valeur 8 est à l'indice " << indice1 << std::endl;

    std::cout << std::endl << "Tableau trié 2 : " << std::endl;
    for (int const elements : vec_search2){
        std::cout << elements << " ";
    }
    int indice2 = search(vec_search2, 16);
    std::cout << std::endl << "Recherche dichotomique : La valeur 16 est à l'indice " << indice2 << std::endl;

    std::cout << std::endl << "Tableau trié 3 : " << std::endl;
    for (int const elements : vec_search3){
        std::cout << elements << " ";
    }
    int indice3 = search(vec_search3, 10);
    std::cout << std::endl << "Recherche dichotomique : La valeur 10 est à l'indice " << indice3 << std::endl;

}