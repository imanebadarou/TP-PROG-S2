#include "exo2.hpp"


std::vector<std::string> split_string(std::string const& s){
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>()); 
}

Token make_token(float value){
    Token token;
    token.type = TokenType::OPERAND;
    token.value = value;
    return token;
}

Token make_token(Operator op){
    Token token;
    token.type = TokenType::OPERATOR;
    token.op = op;
    return token;
}

std::vector<Token> tokenize(std::vector<std::string> const& words){
    std::vector<Token> tokens;
    for(std::string word : words){
        if(word == "+"){
            tokens.push_back(make_token(Operator::ADD));
        }
        else if(word == "-"){
            tokens.push_back(make_token(Operator::SUB));
        }
        else if(word == "*"){
            tokens.push_back(make_token(Operator::MUL));
        }
        else if(word == "/"){
            tokens.push_back(make_token(Operator::DIV));
        }
        else{
            tokens.push_back(make_token(std::stof(word)));
        }
    }
    return tokens;
}

float npi_evaluate(std::vector<Token> const& tokens){
    std::stack<float> stack;

    for(Token token:tokens){
        if(token.type == TokenType::OPERAND){
            stack.push(token.value);
        }
        else{
            float rightOperand { stack.top() };
            stack.pop();
            float leftOperand { stack.top() };
            stack.pop();

            float result { 
                token.op == Operator::ADD ? leftOperand + rightOperand :
                token.op == Operator::SUB ? leftOperand - rightOperand :
                token.op == Operator::MUL ? leftOperand * rightOperand :
                token.op == Operator::DIV ? leftOperand / rightOperand : 0   
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

    

    std::vector<Token> tokens_exp = tokenize(split_string(exp));
    float result = npi_evaluate(tokens_exp);

    std::cout<< exp << " = " << result << std::endl;
}