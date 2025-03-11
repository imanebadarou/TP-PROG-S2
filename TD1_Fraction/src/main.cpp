#include <iostream>
#include "fraction.hpp"

int main()
{
    Fraction f1 { 3, 4 };
    Fraction f2 { 1, 2 };

    std::cout << "f1 = ";
    f1.display();
    std::cout << " f2 = ";
    f2.display();
    std::cout << std::endl;

    Fraction f3 { f1 + f2 };

    std::cout << std::endl << "f1 + f2 = " << f3 << std::endl;

    std::cout << std::endl << "f1 - f2 = " << f1 - f2 << std::endl;

    std::cout << std::endl << "f1 * f2 = " << f1 * f2 << std::endl;

    std::cout << std::endl << "f1 /f2 = " << f1 / f2 << std::endl;

    std::cout << std::endl << "1/6 + 2/6 = " << add({1, 6}, {2, 6}) << std::endl;

    std::cout << std::endl << f1 << " += " << f2 << " = " << (f1+=f2) << std::endl;
    std::cout << std::endl << f1 << " -= " << f2 << " = " << (f1-=f2) << std::endl;
    std::cout << std::endl << f1 << " *= " << f2 << " = " << (f1*=f2) << std::endl;
    std::cout << std::endl << f1 << " /= " << f2 << " = " << (f1/=f2) << std::endl;

    Fraction f4 {1, 2};
    float d1 {static_cast<float>(f4)};
    std::cout << std::endl << "f4 = "<< f4 <<std::endl<< "float(f4) = " << d1 << std::endl;


    if (f1==f2){
        std::cout << std::endl << f1 << " == "<< f2 << std::endl;
    }
    else{
        std::cout << std::endl << f1 << " != "<< f2 << std::endl;
    }


    if (f1<f2){
        std::cout << std::endl << f1 << " < "<< f2 << std::endl;
    }
    else{
        std::cout << std::endl << f1 << " > "<< f2 << std::endl;
    }
    

    return 0;
}