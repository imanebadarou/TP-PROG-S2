#include "td5.hpp"


std::vector<Card> get_cards(size_t const size) {
    std::vector<Card> cards {};
    cards.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        cards.push_back({static_cast<CardKind>(rand() % 4), static_cast<CardValue>(rand() % 13)});
    }
    return cards;
}

std::string card_name(Card const& card){
    std::string name;
    int card_value = static_cast<int>(card.value) + 2;

    if (card_value <= 10){
        name += std::to_string(card_value);
    }
    else if (card_value == 11) {
        name += 'J';
    }
    else if (card_value == 12) {
        name += 'Q';
    }
    else if (card_value == 13) {
        name += 'K';
    }
    else if (card_value == 14) {
        name += 'A';
    }
    name += " of ";

    switch (card.kind){
        case CardKind::Heart:
            name += "Heart"; break;
        case CardKind::Diamond:
            name += "Diamond"; break;
        case CardKind::Club:
            name += "Club"; break;
        case CardKind::Spade:
            name += "Spade"; break;
    }
    return name;
}
