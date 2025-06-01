#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <functional>
#include <random>
#include <algorithm>
#include <iterator>

// EXO 1 : 
size_t folding_string_hash(std::string const& s, size_t max);
size_t folding_string_ordered_hash(std::string const& s, size_t max);
size_t polynomial_rolling_hash(std::string const& s, size_t p, size_t m);


// EXO 2 : 

enum class Insect {
    ClassicBee,
    Ladybug,
    Butterfly,
    Dragonfly,
    Ant,
    Grasshopper,
    Beetle,
    Wasp,
    Caterpillar,
    Spider,
    GuimielBee
};

std::vector<std::pair<Insect, int>> get_insect_observations(
    size_t const number_of_observations,
    std::vector<float> const& insect_probabilities,
    unsigned int const seed = std::random_device{}()
);

std::vector<float> probabilities_from_count(std::vector<int> const& counts);
void main_exo2();


// EXO 3 :

enum class CardKind {
    Heart,
    Diamond,
    Club,
    Spade,
};

enum class CardValue {
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
};

struct Card {
    CardKind kind;
    CardValue value;

    bool operator==(const Card& other) const {
        return kind == other.kind && value == other.value;
    }

    size_t hash() const {
        return static_cast<size_t>(static_cast<int>(kind) * 13 + static_cast<int>(value));
    }
};

namespace std {
    template<>
    struct hash<Card> {
        size_t operator()(Card const& card) const {
            return card.hash();
        }
    };
}


std::vector<Card> get_cards(size_t const size);
std::string card_name(Card const& card);