#include "td4.hpp"

int main(){
    exo1();

    std::string str;
    std::cout << std::endl << "Entrez une phrase : ";
    std::cin >> str;
    int nb = nb_lettre(str);

    std::cout << "Le premier mot de votre phrase contient " << nb << " lettres." << std::endl;

    std::vector<std::string> vec = split_string(str);
    std::cout << vec[1];

    return 0;
}