// Learning C++ 
// Exercise 02_11
// Type Casting Examples, by Eduardo Corpeño 

#include <iostream>
#include <cstdint>

int main(){
    int fahrenheit = 100;
    int celsuis;

    celsuis = ((float)5 / 9.0) * (fahrenheit - 32);

    std::cout << std::endl;
    std::cout << "Fahrenheit: " << fahrenheit << std::endl;
    std::cout << "Celsuis: " << celsuis << std::endl;    

    float weight = 10.99;

    std::cout << std::endl;
    std::cout << "Float: " << weight << std::endl;
    std::cout << "Integer part: " << (int) weight << std::endl; 
    std::cout << "Fractional part: " << (int)((weight - (int)weight)*10000) << std::endl; 

    std::cout << std::endl << std::endl;
    return (0);
}
