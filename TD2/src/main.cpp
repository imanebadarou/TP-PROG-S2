#include "exo1.hpp"
#include "exo2.hpp"

int main(){

    // EXO 1 :
    std::string exp;
    std::cout<<"Entrez votre expression NPI : ";
    std::getline(std::cin, exp);

    std::vector<std::string> tokens_exp = split_string(exp);
    float result = npi_evaluate(tokens_exp);

    std::cout<< exp << " = " << result << std::endl;


    // EXO 2 :
    std::string exp2;
    std::cout<<"Entrez votre expression NPI (avec struct Token): ";
    std::getline(std::cin, exp2);


    std::vector<Token> tokens_exp1 = tokenize(split_string(exp2));
    float result2 = npi_evaluate(tokens_exp);

    std::cout<< exp2 << " = " << result2 << std::endl;

}