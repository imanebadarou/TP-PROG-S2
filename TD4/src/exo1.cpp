#include "td4.hpp"

std::vector<int> generate_random_vector(size_t const size, int const max = 100) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { 
        return std::rand() % max;
    } );
    return vec;
}

void exo1(){
    std::vector<int> vec = generate_random_vector(10, 100);

    std::vector<int>::iterator begin_iterator {vec.begin()};
    std::vector<int>::iterator end_iterator {vec.end()};

    int val_recherchee;
    int val_occurence;

    for (std::vector<int>::iterator it = begin_iterator; it != end_iterator; ++it){
        std::cout << *it << " ";
    }

    std::cout << std::endl;

    std::cout << "Entrez la valeur à rechercher : ";
    std::cin >> val_recherchee;

    auto it {std::find(vec.begin(), vec.end(), val_recherchee)};

    if (it != vec.end()){
        std::cout << "L'element se trouve dans le tableau à l'indice " << std::distance(vec.begin(), it) << std::endl;
    }
    else{
        std::cout << "L'element ne se trouve pas dans le tableau." << std::endl;
    }

    std::cout << std::endl << "Entrez la valeur dont vous cherchez son occurence : ";
    std::cin >> val_occurence;

    const int num_items = std::count(vec.cbegin(), vec.cend(), val_occurence);
    std::cout << "Il y a " << num_items << " fois le nombre " << val_occurence << std::endl << std::endl;


    std::sort(vec.begin(), vec.end());

    std::cout << "Le tableau trié : " << std::endl;
    for (int element : vec){
        std::cout << element << " ";
    }

    int sum { std::accumulate(vec.begin(), vec.end(), 0, [](int acc, int current_element) { return acc + current_element; }) };
    std::cout << std::endl << std::endl << "La somme des valeurs du tableau est " << sum << std::endl;


}