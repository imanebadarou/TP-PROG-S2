#include "td5.hpp"

size_t folding_string_hash(std::string const& s, size_t max){
    size_t somme = 0;
    for (char c : s) {
        somme += static_cast<size_t>(c);
    }
    return somme % max;
}

size_t folding_string_ordered_hash(std::string const& s, size_t max){
    size_t somme = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        somme += static_cast<size_t>(s[i]) * (i + 1);
    }
    return somme % max;
}

size_t polynomial_rolling_hash(std::string const& s, size_t p, size_t m){
    size_t hash = 0;
    size_t power = 1;

    for (char c : s) {
        hash = (hash + static_cast<size_t>(c) * power) % m;
        power = (power*p)%m;
    }

    return hash;
}