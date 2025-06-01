#include "td5.hpp"

std::vector<Insect> const insect_values {
    Insect::ClassicBee,
    Insect::Ladybug,
    Insect::Butterfly,
    Insect::Dragonfly,
    Insect::Ant,
    Insect::Grasshopper,
    Insect::Beetle,
    Insect::Wasp,
    Insect::Caterpillar,
    Insect::Spider,
    Insect::GuimielBee
};

std::unordered_map<Insect, std::string> const insect_to_string = {
    {Insect::ClassicBee, "ClassicBee"},
    {Insect::Ladybug, "Ladybug"},
    {Insect::Butterfly, "Butterfly"},
    {Insect::Dragonfly, "Dragonfly"},
    {Insect::Ant, "Ant"},
    {Insect::Grasshopper, "Grasshopper"},
    {Insect::Beetle, "Beetle"},
    {Insect::Wasp, "Wasp"},
    {Insect::Caterpillar, "Caterpillar"},
    {Insect::Spider, "Spider"},
    {Insect::GuimielBee, "GuimielBee"}
};

std::vector<int> const expected_insect_counts {
    75,
    50,
    100,
    20,
    400,
    150,
    60,
    10,
    40,
    90,
    5,
};

std::vector<std::pair<Insect, int>> get_insect_observations(
    size_t const number_of_observations,
    std::vector<float> const& insect_probabilities,
    unsigned int const seed){
    std::default_random_engine random_engine{seed};

    auto rand_insect_index { std::bind(std::discrete_distribution<size_t>{insect_probabilities.begin(), insect_probabilities.end()}, random_engine) };
    
    std::vector<std::pair<Insect, int>> observations {};
    observations.reserve(number_of_observations);

    for(size_t i {0}; i < number_of_observations; ++i) {
        size_t const random_insect_index { rand_insect_index() };
        Insect const random_insect { insect_values[random_insect_index] };
        
        if(!observations.empty() && observations.back().first == random_insect) {
            observations.back().second++;
            i -= 1;
        } else {
            observations.push_back({random_insect, 1});
        }
    }

    return observations;
}

std::vector<float> probabilities_from_count(std::vector<int> const& counts){
    std::vector<float> proba;
    proba.reserve(counts.size());

    int total = std::accumulate(counts.begin(), counts.end(), 0);

    if (total == 0){
        return std::vector<float>(counts.size(), 0.0f);
    }

    for (int count : counts){
        proba.push_back(static_cast<float>(count)/static_cast<float>(total));
    }
    return proba;
}

void main_exo2(){
    std::vector<float> insect_probabilities = {0.075f, 0.05f, 0.1f, 0.02f, 0.4f, 0.15f, 0.06f, 0.01f, 0.04f, 0.09f, 0.005f};

    size_t number_of_observations = 10000;

    auto observations = get_insect_observations(number_of_observations, insect_probabilities);

    std::unordered_map<Insect, int> insect_count_map;

    for (const auto& observation : observations) {
        insect_count_map[observation.first] += observation.second;
    }

    std::vector<int> counts;
    for (const auto& insect : insect_values) {
        if (insect_count_map.find(insect) != insect_count_map.end()) {
            counts.push_back(insect_count_map[insect]);
        } else {
            counts.push_back(0);
        }
    }

    std::vector<float> observed_probabilities = probabilities_from_count(counts);

    std::cout << "Probabilities of observed insects vs expected probabilities\n";
    float threshold = 0.01f;

    for (size_t i = 0; i < insect_values.size(); ++i) {
        float observed_prob = observed_probabilities[i];
        float expected_prob = insect_probabilities[i];
        std::cout << insect_to_string.at(insect_values[i]) << " : "
                << observed_prob << " vs " << expected_prob << " ";

        if (std::abs(observed_prob - expected_prob) <= threshold) {
            std::cout << "OK\n";
        } else {
            std::cout << "BAD\n";
        }
    }
}