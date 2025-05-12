#include <iostream>
#include <algorithm>
#include <vector>

#include "templateVector.hpp"
#include "UrClient.hpp"
#include "IndClient.hpp"
#include "function.hpp"

int main() {

{    
    templatVector vec{1,23,3,2,2};

    for (size_t i = 0; i < vec.lenght(); ++i){
        std::cout << vec.at(i) << ' ';
    }
    std::cout << std::endl;

    vec.sort();

    for (size_t i = 0; i < vec.lenght(); ++i){
        std::cout << vec.at(i) << ' ';
    }
    std::cout << std::endl;
}

{    
    templatVector vec{'f','u','k','a','v','r'};

    for (size_t i = 0; i < vec.lenght(); ++i){
        std::cout << vec.at(i) << ' ';
    }
    std::cout << std::endl;

    vec.sort();

    for (size_t i = 0; i < vec.lenght(); ++i){
        std::cout << vec.at(i) << ' ';
    }
    std::cout << std::endl;
}    

    return 0;
}