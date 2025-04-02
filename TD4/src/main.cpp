#include "td4.hpp"

int main(){
    // exo1();

    std::string str;
    std::cout << std::endl << "EXO 2 : Entrez une phrase : ";
    std::getline(std::cin, str);
    //str = "Bonjour alo";
    int nb = nb_lettre(str);

    std::cout << "Le premier mot de votre phrase contient " << nb << " lettres." << std::endl;

    std::vector<std::string> vec = split_string(str);

    for(std::string mot:vec){
        std::cout << mot << ", ";
    }

    return 0;
}
