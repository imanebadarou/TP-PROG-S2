#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <iostream> 
#include <cctype>


std::vector<std::string> split_string(std::string const& s){
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>()); 
}

bool is_digit(std::string const& s){
    for(char i:s){
        if(!(isdigit(i))){
            return false;
        }
    }
    return true;
}


bool is_floating(std::string const& s){
    for(char i:s){
        if(!(isdigit(i) && i != '.')){
            return false;
        }
    }
    return true;
}

float npi_evaluate(std::vector<std::string> const& tokens){
    std::stack<float> stack;

    for(std::string i:tokens){
        if(is_floating(i)){
            stack.push(std::stof(i));
        }
        else{
            float rightOperand { stack.top() };
            stack.pop();
            float leftOperand { stack.top() };
            stack.pop();

            float result { 
                i == "+" ? leftOperand + rightOperand :
                i == "-" ? leftOperand - rightOperand :
                i == "*" ? leftOperand * rightOperand :
                i == "/" ? leftOperand / rightOperand : 0   
            };
            stack.push(result);
        }
    }
    if(stack.size() != 1){
        std::cout<<"Erreur dans l'expression en NPI"<<std::endl;
        return 0;
    }
    else{
        return stack.top();
    }
}

int main(){
    std::string exp;
    std::cout<<"Entrez votre expression NPI : ";
    std::getline(std::cin, exp);

    

    std::vector<std::string> tokens_exp = split_string(exp);
    float result = npi_evaluate(tokens_exp);

    std::cout<< exp << " = " << result << std::endl;

}
