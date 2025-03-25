#include "exo1.hpp"

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
            float rightOperand = stack.top();
            stack.pop();
            float leftOperand = stack.top();
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

