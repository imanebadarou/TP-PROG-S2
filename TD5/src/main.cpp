#include "td5.hpp"

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    
    // EXO 2 : 
    std::cout<< "\nEXO 2:"<<std::endl;
    main_exo2();


    // EXO 3 : 

    std::cout<< "\nEXO 3:"<<std::endl;
    auto cards = get_cards(100);

    std::unordered_map<Card, int> card_counts;

    for (const auto& card : cards){
        card_counts[card]++;
    }

    for (const auto& pair : card_counts){
        std::cout << card_name(pair.first) << " : " << pair.second << " fois\n";
    }

    return 0;
}
