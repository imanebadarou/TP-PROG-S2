#include "td4.hpp"

bool palindrome(std::string const& str){
    //on compare le tableau de str.begin à str.end avec le tableau de str.rbegin à str.rend
    if(std::equal(str.begin(), str.end(), str.rbegin(), str.rend())){ 
        return true;
    }
    else{
        return false;
    }
}