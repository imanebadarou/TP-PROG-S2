#include "td4.hpp"


int nb_lettre(std::string const& str){
    auto const is_space = [](char letter){ return letter == ' '; };
    auto it = std::find_if(str.begin(), str.end(), is_space);
    
    return std::distance(str.begin(), it);
}


std::vector<std::string> split_string(std::string const& str){
    std::vector <std::string> vec;
    std::string mot;

    for (int i = 0; i < str.size(); i++){
        if (str[i] == ' '){
            vec.push_back(mot);
            mot.clear();
        }
        else{
            mot += str[i];
        }
    }
    return vec;
}
